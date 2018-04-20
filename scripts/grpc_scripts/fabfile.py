from __future__ import with_statement
from fabric.api import *
from fabric.contrib.console import confirm
from fabric.context_managers import cd, env
computer_1_ip = "132.207.72.22"
computer_2_ip = "132.207.72.31"

computer_1_ip = "192.168.1.3"
computer_2_ip = "192.168.1.5"

tf_program_name = "cnn_distributed"


_HOSTS = [ computer_2_ip, computer_1_ip ] 
env.hosts = computer_2_ip
env.shell = "/usr/bin/fish -l -i -c"

@task
@parallel
def startTracing():
    if env.host == computer_1_ip:
        run("cd ~/dev/tensorflow-profiler/scripts/; bash grpc_master.sh")
    if env.host == computer_2_ip:
        run("cd ~/dev/tensorflow-profiler/scripts/ ; bash grpc_worker.sh")
    

@task
def main():
    with settings(password="pierreol"):
        results = execute(startTracing, hosts=_HOSTS)

