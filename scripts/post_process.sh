#!/bin/bash


usage()
{
    echo "Usage: $0 [-s | --sort] [-t | --tf_name]
            where:
                -s | --sort     : sort the events
                -t | --tf_name  : replace kernels names wit corresponding TF op name
" 1>&2; exit 1; }

while true; do
    case "$1" in
        -s | --sort ) SORT=true; shift;;
        -t | --tf_name ) TF_NAME=true; shift;;
        -h | --help ) usage; shift;;
        -- ) shift; break ;;
        * ) break ;;
    esac
done


if [ -z "$SORT" ]; then
    echo "Don't sort events" 
else
    python3 sort_events.py
fi

if [ -z "$TF_NAME" ]; then 
    echo "Don't replace kernels name with TF ops"
else
    python3 retrieve_tf_op_name.py
fi 

python3 vtid.py