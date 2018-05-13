# Tensorflow profiler
Tracing and profiling tool for TensorFlow.
Support CUDA, HIP and SYCL TensorFlow

# Requirements
- Install LTTng : https://lttng.org/
- Install Babeltrace and python bindings : https://github.com/pzins/babeltrace (checkout branch "conversion_atp_to_ctf")

# Building the tracers
1. Go to tracers folder
2. `make`

# Installing TensorFlow
The first step is to install an instrumented version of TensorFlow;
- TensorFlow 1.6 CUDA : https://github.com/pzins/tensorflow
- TensorFlow 1.3 HIP/ROCM : https://github.com/pzins/tensorflow-rocm
- TensorFlow 1.0 HIP/ROCM : https://github.com/pzins/hiptensorflow
- TensorFlow 1.6 SYCL : https://github.com/pzins/tensorflow-sycl

1. you need to checkout __lttng__ branch
2. Follow the classic instructions to build TensorFlow.

# Tracing API
## TensorFlow with CUDA
Nothing addictional is needed

## TensorFlow with HIP
Install the ROCm platform : https://rocm.github.io/ROCmInstall.html

### HSA tracing :
1. Clone, checkout __lttng__ branch and build ROCR-Runtime : https://github.com/pzins/ROCR-Runtime
2. Replace /opt/rocm/hsa/lib/libhsa-runtime64.so with the builded libhsa-runtime64.so

It's also possible to profile HSA API with interception libraries.

### HIP tracing :
1. Clone, checkout __lttng__ branch and build HIP : https://github.com/pzins/HIP



## Asynchronous events
The first possiblity is to rebuild an instrumented version of HC.
- Clone, checkout __lttng__ branch and build HC : https://github.com/pzins/hcc

Sometimes, it's not possible to rebuild it, so there are 2 options :
1. Using log output from HC and parsing it (automated in scripts)
2. Using interception libraries


# Interception libraries
These libraries can be LD_PRELOADED to get some informations :
1. HSA API
2. GPU kernels begin/end
3. Performance counters

Build instructions :
1. Go to tensorflow-profiler/interception-libraries
2. make
3. Output libraries are in tensorflow-profiler/interception-libraries/lib/
4. Before running your application : set the libraries you want into LD_PRELOAD


# Scripts
There are several possibilities to profile an application

### Automated version
tf_tracer.sh

### Manual version
Use scripts into scripts/

- start_tracing.sh : start lttng tracing
- stop_tracing.sh : stop lttng tracing
- set_env.sh : set the environment before tracing. Needed if using HIP/ROCm
- post_process.sh : post processing script
    - Replace all the asynchronous events at the correct position
    - Match all the GPU kernels with the corresponding TensorFlow operation
- trace_analysis : get textual statistics of a trace
- perfcounters_analysis.py : parse RCP performance counters and match the value with the callstack trace
- perfcounters_interception_analysis.py : Parse and create CSV file with the performance counters trace obtained with interception libraries



# Distributed TensorFlow
Only support basic "in model" parallelism, when you have a worker and a master and you split your graph on the two machines.

The instrumentation is available only with
TensorFlow 1.0 ROCM/HIP
TensorFlow 1.3 ROCM/HIP
TensorFlow 1.6 SYCL

Scripts :
1. fabfile.y : Fabric file to automate an execution
2. scripts/grpc_worker.sh : Used by the fabfile, for the worker computer
2. scripts/grpc_master.sh : Used by the fabfile, for the master computer
