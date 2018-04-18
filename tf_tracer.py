import os
import subprocess
import argparse
import getpass
from scripts.utils import debugPrint

# parse argument to get the program name and path
parser = argparse.ArgumentParser(description="Profile a TensorFlow application")
parser.add_argument("--tf_script", help="Set the TensorFlow script")
parser.add_argument("--kernels_mode", required=True, help="How we collet gpu kernels information")
parser.add_argument("--num_subbuff_ust", type=str, help="Lttng number of subbuffer UST")
parser.add_argument("--subbuff_size_ust", type=str, help="Lttng size of subbuffers UST")
parser.add_argument("--num_subbuff_kernel", type=str, help="Lttng number of subbuffer KERNEL")
parser.add_argument("--subbuff_size_kernel", type=str, help="Lttng size of subbuffers KERNEL")
parser.add_argument("-k", action='store_true', help="Activate linux kernel tracing")
parser.add_argument("-p", action='store_true', help="Activate python tracing")
parser.add_argument("-g", action='store_true', help="Activate GRPC tracing")
args = parser.parse_args()

debugPrint("START TENSORFLOW PROFILER")

# tensorflow script
tensorflow_script = args.tf_script.split("/")[-1]
tensorflow_script_path = args.tf_script[:-len(tensorflow_script)]


# constants
NUM_SUBBUFF_UST = "1000"
SUBBUFF_SIZE_UST = "131072"
NUM_SUBBUFF_KERNEL = "1000"
SUBBUFF_SIZE_KERNEL = "131072"

# prepare directories
current_directory = os.getcwd()
scripts_directory = current_directory + "/scripts"
trace_output_folder = current_directory + "/lttng-traces"
tmp_directory = "/tmp/tensorflow-profiling"
if not os.path.isdir(trace_output_folder):
    os.system("mkdir " + trace_output_folder)
if not os.path.isdir(tmp_directory):
    os.system(tmp_directory)



class TracingModule():
    def __init__(self, env, pre_run_scripts, post_run_scripts, program, program_directory, args, kernels_logs=""):
        self.env = env
        self.pre_run_scripts = pre_run_scripts
        self.post_run_scripts = post_run_scripts
        self.program = program
        self.program_directory = program_directory
        self.args = args
        self.kernels_logs = kernels_logs
    
    def preRun(self):
        res = "cd " + scripts_directory + "; "
        for i in self.pre_run_scripts:
            res += "bash " + i + "; "
        return res
    
    def postRun(self):
        if self.args.k == True or self.args.p == True or self.args.g == True:
            res = "sudo lttng destroy; sudo chown -R " + getpass.getuser() + " " + os.getcwd() + "/lttng-traces; "
        else:
            res = "lttng destroy; "
        res += "cd " + scripts_directory + "; "

        for i in self.post_run_scripts:
            res += "python3 " + i + "; "
        return res
        
    def run(self):
        if self.kernels_logs == "":
            res = "cd " + self.program_directory + "; " + "python3 " + self.program + "; "
        else:
            res = "cd " + self.program_directory + "; " + "python3 " + self.program + " > " + self.kernels_logs + " 2>&1;"
        return res
        

# Environment variables
env_hip = "HIP_PROFILE_API" 
env_hip_val = "2"
env_hcc = "HCC_PROFILE" 
env_hcc_val = "2"
env_queue = "HCC_DB" 
env_queue_val = "20"
env_hsa_tools_lib = "HSA_TOOLS_LIB" 
env_hsa_tools_lib_val = "libhsa-runtime-tools64.so.1"
env_no_kernel_time = "HSA_SERVICE_GET_KERNEL_TIMES"
env_no_kernel_time_val = "0"
env_hsa_emulate = "HSA_EMULATE_AQL" 
env_hsa_emulate_val = "1"
env_kernel_time = "LD_PRELOAD" 
env_kernel_time_val = "/home/pierre/dev/dorsal/paul/lib/hsa_kernel_times.so"
env_queue_profiling = "LD_PRELOAD" 
env_queue_profiling_val = "/home/pierre/dev/dorsal/paul/lib/hsa_queue_profiling.so"

# Post processing scripts
sorting = "sort_events.py"
tf_op_name = "retrieve_tf_op_name.py"
fix_metadata = "vtid.py"

# Start tracing scripts
start_tracing = "start_tracing.sh "

# parse start tracing arguments
start_tracing_args = " "
if not args.num_subbuff_ust:
    args.num_subbuff_ust = NUM_SUBBUFF_UST
if not args.subbuff_size_ust:
    args.subbuff_size_ust = SUBBUFF_SIZE_UST
if not args.num_subbuff_kernel:
    args.num_subbuff_kernel = NUM_SUBBUFF_KERNEL
if not args.subbuff_size_kernel:
    args.subbuff_size_kernel = SUBBUFF_SIZE_KERNEL
start_tracing_args += "-n " + args.num_subbuff_ust + " -s " + args.subbuff_size_ust + " "\
    +  "-m " + args.num_subbuff_kernel + " -r " + args.subbuff_size_kernel + " " 
if args.k:
    start_tracing_args += "-k "
if args.p:
    start_tracing_args += "-p "
if args.g:
    start_tracing_args += "-g "
# add the arguments to the command
start_tracing += start_tracing_args



if args.kernels_mode == "hc_log":
    # create the module
    tm = TracingModule(
        env=[(env_hip, env_hip_val), (env_hcc, env_hcc_val)],
        pre_run_scripts=[start_tracing],
        post_run_scripts=[sorting + " --parse_kernel_log=/tmp/tensorflow-profiling/hc_out", tf_op_name, fix_metadata],
        program=tensorflow_script,
        program_directory=tensorflow_script_path,
        args=args,
        kernels_logs="/tmp/tensorflow-profiling/hc_out")

elif args.kernels_mode == "hc_instr":
    # create the module
    tm = TracingModule(
                    env=[(env_hip, env_hip_val), (env_hcc, env_hcc_val)],
                    pre_run_scripts=[start_tracing],
                    post_run_scripts=[sorting, tf_op_name, fix_metadata],
                    program=tensorflow_script,
                    program_directory=tensorflow_script_path, 
                    args=args)

else:
    # create the module
    tm = TracingModule(
            env=[(env_hip, env_hip_val), (env_hsa_tools_lib, env_hsa_tools_lib_val), (env_kernel_time, env_kernel_time_val)],
            pre_run_scripts=[start_tracing],
            post_run_scripts=[sorting, tf_op_name, fix_metadata],
            program=tensorflow_script,
            program_directory=tensorflow_script_path,
            args=args)



# set the environment variables
for i in tm.env:
    os.environ[i[0]] = i[1]

# debug
# print(tm.preRun())
# print(tm.run())
# print(tm.postRun())
# input()

# start running
subprocess.run(tm.preRun() + tm.run() + tm.postRun(), shell=True)


"""
install lttng

git clone TF or TF AMD
git apply patch
configure + build TF

CUDA does not require additional thing
HIP : clone HIP ROCR-Runtime HCC (optional)
apply pathes to both : 
build them and install HIP, HCC. ROCR-runtime : either copy to /opt/... or use it with LD_PRELOAD 

run tf_tracer.py
"""

