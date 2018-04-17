#!/bin/bash

echo "========= START LTTNG ========="

# constants
NUM_SUBBUFF_UST=100
SUBBUFF_SIZE_UST=131072
NUM_SUBBUFF_KERNEL=1000
SUBBUFF_SIZE_KERNEL=131072


usage() { echo "Usage: $0 [-n <int>] [-s <int>] [-m <int>] [-r <int>] [-k] [-p] [-g]" 1>&2; exit 1; }

# possible targets
kernel_tracing="False"
python_tracing="False"
grpc_tracing="False"

# parse arguments
while getopts ':n:s:m:r:kpg' o; do
    case "${o}" in
        n)
            n=${OPTARG}
            ;;
        s)
            s=${OPTARG}
            ;;
        m)
            m=${OPTARG}
            ;;
        r)
            r=${OPTARG}
            ;;
        k)
            kernel_tracing="True"
            ;;
        p)
            python_tracing="True"
            ;;
        g)
            grpc_tracing="True"
            ;;
        *)
            usage
            ;;
    esac
done

# if no provided value, use default values
if [ -z "${n}" ] || [ -z "${s}" ] || [ -z "${m}" ] || [ -z "${r}" ]; then
    n=$NUM_SUBBUFF_UST
    s=$SUBBUFF_SIZE_UST
    m=$NUM_SUBBUFF_KERNEL
    r=$SUBBUFF_SIZE_KERNEL
fi

# decide if sudo is needed
if [ "${kernel_tracing}" == "True" ] || [ "${python_tracing}" == "True" ] || [ "${grpc_tracing}" == "True" ]
then
    is_sudo="sudo"
else
    is_sudo=""
fi

# lttng commands
trace_name="tensorflow-$(date '+%Y%m%d-%H%M%S')"
$is_sudo lttng create tensorflow --output="/home/pierre/dev/tensorflow-profiler/lttng-traces/$trace_name"

if [ "${is_sudo}" == "sudo" ]; then
        $is_sudo lttng enable-channel -k kernelchannel --num-subbuf=${m} --subbuf-size=${r}
        if [ "${kernel_tracing}" == "True" ]; then
            $is_sudo lttng enable-event -k -a --channel=kernelchannel
        elif [ "${grpc_tracing}" == "True" ]; then
            $is_sudo lttng enable-event -k net_dev_queue --channel=kernelchannel
            $is_sudo lttng enable-event -k net_if_receive_skb --channel=kernelchannel
        fi
fi
$is_sudo lttng enable-channel -u ustchannel --num-subbuf=${n} --subbuf-size=${s}

$is_sudo lttng enable-event --userspace "cuptiTracer:*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "hsa_runtime:*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "hsaTracer:*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "hccTracer:*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "hipTracer:*" --channel=ustchannel

$is_sudo lttng enable-event --userspace "tensorflowTracer:*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "streamTracer:*" --channel=ustchannel

if [ "${grpc_tracing}" == "True" ]; then
    $is_sudo lttng enable-event --userspace "grpcTracer:*" --channel=ustchannel
fi

if [ "${python_tracing}" == "True" ]; then
    $is_sudo lttng enable-event --python my-begin-logger
    $is_sudo lttng enable-event --python my-end-logger
fi

$is_sudo lttng add-context -u -t vtid

$is_sudo lttng start