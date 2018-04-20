#!/bin/bash

tf_program_name="cnn_distributed"
scripts_dir=`pwd`

bash start_tracing.sh -g

bash set_env.sh --hip --hc 1
cd /home/pierre/Dropbox/dev/distributed/in_model_parallelism/
python3 $tf_program_name.py w > /dev/null 2>&1


cd $scripts_dir
bash stop_tracing.sh -k
bash post_process.sh -s -t

kernel_traces=`ls -t ../lttng-traces | head -1`

ssh -A 192.168.1.3 mkdir ~/traces_grpc
scp -r ../lttng-traces/$kernel_traces 192.168.1.3:~/traces_grpc/$kernel_traces_remote
scp -r ../results 192.168.1.3:~/traces_grpc
