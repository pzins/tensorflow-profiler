#!/bin/bash


# constants
NUM_SUBBUFF_UST=100
SUBBUFF_SIZE_UST=131072
NUM_SUBBUFF_KERNEL=1000
SUBBUFF_SIZE_KERNEL=131072


usage()
{
    echo "Usage: $0 [-k | --kernel] [-p | --python] [-g | --grpc] [---num_subbuff_ust <int>] [---subbuff_size_ust <int>] [---num_subbuff_kernel <int>] [---subbuff_size_kernel <int>]

            where:
                -k | --kernel           : activate kernel tracing
                -p | --python           : activate python tracing
                -g | --grpc             : activate grpc tracing
                --num_subbuff_ust       : lttng number of subbuffer UST
                --subbuff_size_ust      : lttng size of subbuffers UST
                --num_subbuff_kernel    : lttng number of subbuffer KERNEL
                --subbuff_size_kernel   : lttng size of subbuffers KERNEL
" 1>&2; exit 1; }

# possible targets
kernel_tracing="False"
python_tracing="False"
grpc_tracing="False"

while true; do
  case "$1" in
    -k | --kernel ) kernel_tracing="True"; shift;;
    -p | --python ) python_tracing="True"; shift;;
    -g | --grpc ) grpc_tracing="True"; shift;;
    --num_subbuff_ust ) num_subbuff_ust="$2"; shift 2;;
    --subbuff_size_ust ) subbuff_size_ust="$2"; shift 2;;
    --num_subbuff_kernel ) num_subbuff_kernel="$2"; shift 2;;
    --subbuff_size_kernel ) subbuff_size_kernel="$2"; shift 2;;
    -h | --help ) usage; shift;;
    -- ) shift; break ;;
    * ) break ;;
  esac
done

# if no provided value, use default values
if [ -z "${num_subbuff_ust}" ] || [ -z "${subbuff_size_ust}" ] || [ -z "${num_subbuff_kernel}" ] || [ -z "${subbuff_size_kernel}" ]; then
    num_subbuff_ust=$NUM_SUBBUFF_UST
    subbuff_size_ust=$SUBBUFF_SIZE_UST
    num_subbuff_kernel=$NUM_SUBBUFF_KERNEL
    subbuff_size_kernel=$SUBBUFF_SIZE_KERNEL
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
        $is_sudo lttng enable-channel -k kernelchannel --num-subbuf=${num_subbuff_kernel} --subbuf-size=${subbuff_size_kernel}
        if [ "${kernel_tracing}" == "True" ]; then
            $is_sudo lttng enable-event -k -a --channel=kernelchannel
        elif [ "${grpc_tracing}" == "True" ]; then
            $is_sudo lttng enable-event -k net_dev_queue --channel=kernelchannel
            $is_sudo lttng enable-event -k net_if_receive_skb --channel=kernelchannel
        fi
fi
$is_sudo lttng enable-channel -u ustchannel --num-subbuf=${num_subbuff_ust} --subbuf-size=${subbuff_size_ust}

$is_sudo lttng enable-event --userspace "cudaTracer:*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "interceptionTracer:*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "eigenTracer:*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "hsaTracer:*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "hcTracer:*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "hipTracer:*" --channel=ustchannel

$is_sudo lttng enable-event --userspace "streamTracer:*" --channel=ustchannel

# TensorFlow enable events
# $is_sudo lttng enable-event --userspace "tensorflowTracer:*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "tensorflowTracer:process*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "tensorflowTracer:inline_ready*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "tensorflowTracer:push_succ*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "tensorflowTracer:session*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "tensorflowTracer:*operation*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "tensorflowTracer:rdv*" --channel=ustchannel
$is_sudo lttng enable-event --userspace "tensorflowTracer:bfc_allocator_stats" --channel=ustchannel
$is_sudo lttng enable-event --userspace "tensorflowTracer:bfc_chunks_stats" --channel=ustchannel
# $is_sudo lttng enable-event --userspace "tensorflowTracer:bfc_bins_stats" --channel=ustchannel
$is_sudo lttng enable-event --userspace "tensorflowTracer:memory_allocate" --channel=ustchannel
$is_sudo lttng enable-event --userspace "tensorflowTracer:memory_deallocate " --channel=ustchannel



if [ "${grpc_tracing}" == "True" ]; then
    $is_sudo lttng enable-event --userspace "grpcTracer:*" --channel=ustchannel
fi

if [ "${python_tracing}" == "True" ]; then
    $is_sudo lttng enable-event --python my-begin-logger
    $is_sudo lttng enable-event --python my-end-logger
fi

$is_sudo lttng add-context -u -t vtid

$is_sudo lttng start
