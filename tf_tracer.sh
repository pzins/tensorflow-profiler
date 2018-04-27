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
" 1>&2; exit 1; }

while true; do
    case "$1" in
        -q | --quiet ) quiet_mode=true; shift ;;
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

# get scripts directory
cd scripts
scripts_dir=`pwd`

# set environment
source set_env.sh --hip --hc $hc

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
    python3 $tf_program_name $tf_program_args > /dev/null 2>&1
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
    bash post_process.sh -s -t -k /tmp/tensorflow-profiler-gpu-log.log
else
    bash post_process.sh -s -t
fi