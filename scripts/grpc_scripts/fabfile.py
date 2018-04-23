from __future__ import with_statement
from fabric.api import *
from fabric.contrib.console import confirm
from fabric.context_managers import cd, env


@task
@parallel
def startTracing(tf_file, ip_m, ip_w):
    if env.host == ip_m:
        run("cd ~/dev/tensorflow-profiler/scripts/ ; sleep 10; bash grpc_master.sh -f " + tf_file + " -i " + ip_w)
    if env.host == ip_w:
        run("cd ~/dev/tensorflow-profiler/scripts/ ; bash grpc_worker.sh -f " + tf_file + " -i " + ip_m)


@task
def main(tf_file="cnn_distributed.py", ip_m="132.207.72.22", ip_w="132.207.72.31"):
    
    _HOSTS = [ ip_m, ip_w ] 
    # env.hosts = computer_2_ip
    env.shell = "/usr/bin/fish -l -i -c"
    print(tf_file)
    print(ip_m)
    print(ip_w)
    input()
    with settings(password="pierreol"):
        results = execute(startTracing, tf_file, ip_m, ip_w, hosts=_HOSTS)

