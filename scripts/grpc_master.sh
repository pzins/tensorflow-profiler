#!/bin/bash

usage()
{
    echo "Usage: $0 [-f | --file] [-i | --ip]
            where:
                -f | --file : tensorflow script name
                -i | --ip   : IP address of the worker
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

if [ -z "${other_computer_ip}" ]
then
    other_computer_ip="192.168.1.5"
    other_computer_ip="132.207.72.31"
fi
if [ -z "${tf_program_name}" ]
then
    tf_program_name="cnn_distributed.py"
fi

scripts_dir=`pwd`

bash start_tracing.sh -g

bash set_env.sh --hip --hc 1
cd /home/pierre/Dropbox/dev/distributed/in_model_parallelism/
python3 $tf_program_name m
# python3 $tf_program_name m > /dev/null 2>&1

res=`ssh "$other_computer_ip" ps -aux | grep cnn_distributed | grep -v grep | awk '{print $2}'`
ssh $other_computer_ip kill -SIGKILL $res

cd $scripts_dir
bash stop_tracing.sh -k
bash post_process.sh -s -t

mkdir traces_grpc
cp -r ../results ~/traces_grpc
kernel_traces=`ls -t ../lttng-traces | head -1`
cp -r ../lttng-traces/$kernel_traces ~/traces_grpc