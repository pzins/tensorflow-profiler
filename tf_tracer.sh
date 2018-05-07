# parse arguments
usage()
{
    echo "Usage: $0 [-f | --file] [-h | --hc] [-q | --quiet]
            where:
                -f | --file     : tensorflow script name
                --hc=[1-3]      :   1 = set HSA_TOOLS_LIB and LD_PRELOAD environment variables
                                    2 = set HCC_PROFILE environment variable : use HC instrumentation (default)
                                    3 = set HCC_PROFILE environment variable : use HC logs file
                -q | --quiet    : quiet mode for TensorFlow application
                -a | --args     : arguments to pass to TensorFlow application
                --cuda          : cuda mode [incompatible with sycl mode]
                --sycl          : sycl mode [incompatible with cuda mode]
" 1>&2; exit 1; }

while true; do
    case "$1" in
        -q | --quiet ) quiet_mode=true; shift ;;
        --cuda ) cuda_mode=true; shift ;;
        --sycl ) sycl_mode=true; shift ;;
        -f | --file ) tf_program_name="$2"; shift 2;;
        -a | --args ) tf_program_args="$2"; shift 2;;
        --hc ) hc="$2"; shift 2;;
        -h | --help ) usage; shift;;
        -- ) shift; break ;;
        * ) break ;;
    esac
done

# check variables
if [ -z "${tf_program_name}" ]
then
    usage
fi
if [ -z "${hc}" ]
then
    hc=2
fi
if [ -z "${tf_program_args}" ]
then
    tf_program_args=""
fi
if [ "${cuda_mode}" == true ] && [ "${sycl_mode}" == true ]
then
    usage
fi
if [ "${cuda_mode}" == true ]
then
    quiet_mode=false
    hc=0
fi
if [ "${sycl_mode}" == true ]
then
    quiet_mode=false
    hc=0
fi


# get scripts directory
cd scripts
scripts_dir=`pwd`

# set environment if not cuda mode
if [ -z "${cuda_mode}" ]
then
    if [ "${sycl_mode}" == true ];
    then
        source set_env.sh --sycl
    else
        source set_env.sh --hip --hc $hc
    fi
fi

# start tracing
bash start_tracing.sh

# go to TensorFlow script path
tf_program_dir=`dirname "$tf_program_name"`
cd $tf_program_dir

# run TensorFlow applciation
if [ "${hc}" == "3" ]
then
    python3 $tf_program_name $tf_program_args > /tmp/tensorflow-profiler-gpu-log.log 2>&1
# need to stay after HC == 3 case because quiet mode will discard all the log
elif [ "${quiet_mode}" == true ]
then
    python3 $tf_program_name $tf_program_args 2> /dev/null
else
    python3 $tf_program_name $tf_program_args
fi

# go back to scripts directory
cd $scripts_dir

# stop tracing
bash stop_tracing.sh
# post process trace
if [ "${hc}" == "3" ]
then
    bash post_process.sh -s -t -k /tmp/tensorflow-profiler-gpu-log.log --tf_name
else
    if [ "${cuda_mode}" == true ]
    then
        bash post_process.sh -s --cuda
    else
        bash post_process.sh -s -t --tf_name
    fi
fi
