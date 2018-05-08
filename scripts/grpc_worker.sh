#!/bin/bash

# parse arguments
usage()
{
    echo "Usage: $0 [-f | --file] [-i | --ip]
            where:
                -f | --file : tensorflow script name
                -i | --ip   : IP address of the master
" 1>&2; exit 1; }

while true; do
    case "$1" in
        -f | --file ) tf_program_name="$2"; shift 2;;
        -i | --ip ) other_computer_ip="$2"; shift 2;;
        -h | --help ) usage; shift;;
        -- ) shift; break ;;
        * ) break ;;
    esac
done

# define some variables
if [ -z "${other_computer_ip}" ] || [ -z "${tf_program_name}" ]
then
    usage
fi
scripts_dir=`pwd`

# set the environment
source set_env.sh --hip --hc 2

# start tracing
bash start_tracing.sh -g

# go to TensorFlow script and start the program
tf_program_dir=`dirname "$tf_program_name"`
cd $tf_program_dir

# python3 $tf_program_name w
python3 $tf_program_name w 2> /dev/null
# python3 $tf_program_name w > /dev/null 2>&1

# go to scripts directory
cd $scripts_dir
# stop tracing
bash stop_tracing.sh -k
# post process trace
bash post_process.sh -s -t


# copy the kernel and post processed UST traces to the master
kernel_traces=`ls -t ../lttng-traces | head -1`
ssh -A $other_computer_ip mkdir ~/traces_grpc
scp -r ../lttng-traces/$kernel_traces "$other_computer_ip":~/traces_grpc/"$kernel_traces"_remote
scp -r ../results "$other_computer_ip":~/traces_grpc/results_remote
