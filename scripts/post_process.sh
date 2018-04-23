#!/bin/bash


usage()
{
    echo "Usage: $0 [-s | --sort] [-t | --tf_name] [-g | --gpu_log]
            where:
                -s | --sort     : sort the events
                -t | --tf_name  : replace kernels names wit corresponding TF op name
                -g | --gpu_log  : log file created by HC with GPU information (kernels, barriers, memcpy)
" 1>&2; exit 1; }

while true; do
    case "$1" in
        -s | --sort ) SORT=true; shift;;
        -t | --tf_name ) TF_NAME=true; shift;;
        -g | --gpu_log ) GPU_LOG="$2"; shift 2;;
        -h | --help ) usage; shift;;
        -- ) shift; break ;;
        * ) break ;;
    esac
done


if [ -z "$SORT" ]; then
    echo "Don't sort events"
else
    if [ -z "$GPU_LOG" ]; then
        python3 sort_events.py
    else
        python3 sort_events.py --gpu_log $GPU_LOG
    fi
fi

if [ -z "$TF_NAME" ]; then
    echo "Don't replace kernels name with TF ops"
else
    python3 retrieve_tf_op_name.py
fi

python3 vtid.py
