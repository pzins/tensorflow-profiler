from __future__ import with_statement
from fabric.api import *
from fabric.contrib.console import confirm
from fabric.context_managers import cd, env
import os

if "PSWD" not in os.environ:
    print("Environment variable PSWD with the password should be set")
    exit(0)

# example of command
# fab main:cnn_distributed.py,132.207.72.22,132.207.72.31

@task
@parallel
def startTracing(tf_file, ip_m, ip_w):
    if env.host == ip_m:
        run("cd ~/dev/tensorflow-profiler/scripts/ ; bash grpc_master.sh -f " + tf_file + " -i " + ip_w)
    if env.host == ip_w:
        run("cd ~/dev/tensorflow-profiler/scripts/ ; bash grpc_worker.sh -f " + tf_file + " -i " + ip_m)

@task
def main(tf_file="/home/pierre/Dropbox/dev/distributed/in_model_parallelism/cnn_distributed.py",
         ip_m="192.168.1.3",
         ip_w="192.168.1.5"):
         # ip_m="132.207.72.22",
         # ip_w="132.207.72.31"):
    
    _HOSTS = [ ip_m, ip_w ] 
    with settings(password=os.environ["PSWD"]):
        results = execute(startTracing, tf_file, ip_m, ip_w, hosts=_HOSTS)

