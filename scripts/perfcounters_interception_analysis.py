#!/usr/bin/python3
import babeltrace
import babeltrace.reader as btr
import babeltrace.writer as btw
import re
import argparse

# parse arguments
parser = argparse.ArgumentParser(description="Post processing of perfcounters trace")
parser.add_argument("--pc_trace", help="set the input perfcounters trace", required=True)
parser.add_argument("--profile_trace", help="set the input profiling trace", required=True)
parser.add_argument("--output", help="set the output csv file", default="./pc_stats.csv")
args = parser.parse_args()


from tracing_events_classes import event_classes
from collections import OrderedDict
# Add the input trace to the collection
collection = btr.TraceCollection()

# Set the input traces containing perfcounters events
path = args.pc_trace
if path[-1] == "/":
    path = path[:-1]
collection.add_trace(path, 'ctf')

# If the profile trace is different also add it
if args.profile_trace != args.pc_trace:
    path = args.profile_trace
    if path[-1] == "/":
        path = path[:-1]
    collection.add_trace(path, 'ctf')


# Kernel header containing attirbutes from profile trace
class KernelHeader():
    def __init__(self, index, name, timestamp, session, index_in_session):
        self.index = index
        self.name = name
        self.timestamp = timestamp
        self.session = session
        self.index_in_session = index_in_session
    
    def exportCsv(self):
        return str(self.index) + ";" + str(self.timestamp) + ";" +\
               self.name + ";" + str(self.session) + ";" +\
                str(self.index_in_session) + ";"
    
    def headerCsv(self):
        return "index;timestamp;kernel name;session;index in session;"

# Kernel containing preformance counters values
class Kernel():
    def __init__(self):
        self.counters = OrderedDict()
    def setCounter(self, name, value):
        self.counters[name] = value
    def exportCsv(self):
        res = ""
        for i in self.counters:
            res += str(self.counters[i]) + ";"
        return res[:-1] + "\n"
    
    def headerCsv(self):
        for i in self.counters:
            res += i + ";"
        return res[:-1] + "\n"


# list of all the kernels in perfcounter trace and profile trace
kernels_pc = []
kernels_profile = []

# count session, kernel index for the whole trace and kernel index for the session
session_cnt = 0
kernel_cnt = 0
kernel_in_session_cnt = 0

# loop over the events
for r_event in collection.events:
    name = r_event.name
    # we start a new kernel
    if name == "interceptionTracer:kernel_parameters":
        kernels_pc.append(Kernel())
        kernels_pc[-1].setCounter("workgroup_size", r_event["workgroup_size"])
        kernels_pc[-1].setCounter("grid_size", r_event["grid_size"])
        kernels_pc[-1].setCounter("static_group_segment_size", r_event["static_group_segment_size"])
        kernels_pc[-1].setCounter("private_segment_size", r_event["private_segment_size"])
    # adding all the counters values for the kernel
    elif "interceptionTracer" in name and "perf_counter" in name:
        kernels_pc[-1].setCounter(r_event["counter_name"], r_event["value"])

    elif "tensorflowTracer:session_start" in name:
        session_cnt += 1
    elif "tensorflowTracer:session_end" in name:
        kernel_in_session_cnt = 0
    elif "kernel" in name and "begin" in name:
        kernels_profile.append(KernelHeader(kernel_cnt, r_event["name"], \
                            r_event.timestamp, kernel_in_session_cnt,\
                            session_cnt))
        kernel_cnt += 1
        kernel_in_session_cnt += 1
        
# check there are the number of kernels in both list
assert(len(kernels_pc) == len(kernels_profile))

# write the results
with open(args.output, "w") as f:
    f.write(kernels_profile[0].headerCsv() + kernels_pc[0].headerCsv())
    for k in range(len(kernels_pc)):
        f.write(kernels_profile[k].exportCsv() + kernels_pc[k].exportCsv())