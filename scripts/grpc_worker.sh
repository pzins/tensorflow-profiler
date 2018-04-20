#!/bin/bash

other_computer_ip="192.168.1.3"
other_computer_ip="132.207.72.22"
tf_program_name="cnn_distributed"
scripts_dir=`pwd`

bash start_tracing.sh -g

bash set_env.sh --hip --hc 1
cd /home/pierre/Dropbox/dev/distributed/in_model_parallelism/
python3 $tf_program_name.py w
# python3 $tf_program_name.py w > /dev/null 2>&1


cd $scripts_dir
bash stop_tracing.sh -k
bash post_process.sh -s -t

kernel_traces=`ls -t ../lttng-traces | head -1`

ssh -A $other_computer_ip mkdir ~/traces_grpc
scp -r ../lttng-traces/$kernel_traces "$other_computer_ip":~/traces_grpc/"$kernel_traces"_remote
scp -r ../results "$other_computer_ip":~/traces_grpc/results_remote
