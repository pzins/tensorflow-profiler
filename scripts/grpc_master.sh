#!/bin/bash

tf_program_name="cnn_distributed"
scripts_dir=`pwd`

bash start_tracing.sh -g

bash set_env.sh --hip --hc 1
cd /home/pierre/Dropbox/dev/distributed/in_model_parallelism/
# python3 $tf_program_name.py m
python3 $tf_program_name.py m > /dev/null 2>&1

res=`ssh 192.168.1.5 ps -aux | grep cnn_distributed | grep -v grep | awk '{print $2}'`
ssh 192.168.1.5 kill -SIGKILL $res

cd $scripts_dir
bash stop_tracing.sh -k
bash post_process.sh -s -t

mkdir traces_grpc
cp -r ../results ~/traces_grpc
kernel_traces=`ls -t ../lttng-traces | head -1`
cp -r ../lttng-traces/$kernel_traces ~/traces_grpc