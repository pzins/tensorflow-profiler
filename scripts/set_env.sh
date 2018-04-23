#!/bin/bash

# env_hip="HIP_PROFILE_API" 
# env_hip_val="2"
# env_hcc="HCC_PROFILE" 
# env_hcc_val="2"
# env_queue="HCC_DB" 
# env_queue_val="20"
# env_hsa_tools_lib="HSA_TOOLS_LIB" 
# env_hsa_tools_lib_val="libhsa-runtime-tools64.so.1"
# env_no_kernel_time="HSA_SERVICE_GET_KERNEL_TIMES"
# env_no_kernel_time_val="0"
# env_hsa_emulate="HSA_EMULATE_AQL" 
# env_hsa_emulate_val="1"
# env_kernel_time="LD_PRELOAD" 
# env_kernel_time_val="/home/pierre/dev/dorsal/paul/lib/hsa_kernel_times.so"
# env_queue_profiling="LD_PRELOAD" 
# env_queue_profiling_val="/home/pierre/dev/dorsal/paul/lib/hsa_queue_profiling.so"



usage()
{ 
    echo "Usage: $0 [--hip] [--hc <int>[1-3]] [--hsa <int>[1-2]]
            where:
            --hip           : activate HIP API profiling
            --hc=[1-3]  : 1 = set HSA_TOOLS_LIB and LD_PRELOAD environment variables
                          2 = set HCC_PROFILE environment variable : use HC instrumentation
                          3 = set HCC_PROFILE environment variable : use HC logs file
            --hsa=[1-2] : 1 = ...
" 1>&2; exit 1; }


while true; do
  case "$1" in
    --hip ) HIP=true; shift;;
    --hc ) HC="$2"; shift 2;;
    --hsa ) HSA="$2"; shift 2;;
    -h | --help ) usage; shift;;
    -- ) shift; break ;;
    * ) break ;;
  esac
done


if [ -z "$HIP" ]; then HIP=false;fi 
if [ -z "$HC" ]; then HC=1;fi 
if [ -z "$HSA" ]; then HSA=1;fi

# echo $HIP
# echo $HC
# echo $HSA

if [ "$HC" -le 0 ] || [ "$HC" -ge 4 ]; then
    echo "--hc option : 1, 2, 3";
    exit 1;
fi

if [ "$HSA" -le 0 ] || [ "$HSA" -ge 3 ]; then
    echo "--hsa option : 1 or 2";
    exit 1;
fi

if [ "$HIP" == true ];
then
    echo "HIP_PROFILE_API"
    export HIP_PROFILE_API=2
fi

if [ "$HC" == "1" ];
then
    echo "HSA_TOOLS_LIB"
    export HSA_TOOLS_LIB="libhsa-runtime-tools64.so.1"
    echo "LD_PRELOAD"
    scripts_dir=`pwd`
    export LD_PRELOAD="$scripts_dir/../intercepting-libraries/lib/hsa_kernel_times.so"
else
    echo "HCC_PROFILE"
    export HCC_PROFILE=2
fi






