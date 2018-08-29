#!/usr/bin/python3
import argparse
import numpy as np

# parse arguments
parser = argparse.ArgumentParser(description="Compute statistics")
parser.add_argument("--trace", help="set the input trace", required=True)
parser.add_argument("--output", help="set the output csv file")
args = parser.parse_args()

if args.output == None:
    outfile = "stats.csv"
else:
    outfile = args.output

path = args.trace

import babeltrace.reader as btr
import babeltrace.writer as btw
from tracing_events_classes import event_classes
from collections import defaultdict
import re
# Add the input trace to the collection
collection = btr.TraceCollection()

# Set the input traces
if path[-1] == "/":
    path = path[:-1]
collection.add_trace(path, 'ctf')



# represent one Analysis : like tf operations, hcc kernels, session runs, ...
class Module():
    def __init__(self, name, begin, end, unique_id):
        self.name = name
        # begin and end event regex
        self.begin_event = re.compile(begin)
        self.end_event = re.compile(end)

        # unique id to do the link between start and end events
        self.unique_id = unique_id

        # will contain all the states from the trace
        self.states = []
        # list containing temporary State with only start event set, waiting for a
        # corresponding end event
        self.open_state = []
    def states_size(self):
        return len(self.states)

# Represent a State from ctf events
class State():
    def __init__(self):
        self.begin_event = 0
        self.end_event = 0
        self.timestamps = [0, 0]
        self.session = 0
    def __init__(self, begin_ev):
        self.begin_event = begin_ev
        self.end_event = 0
        self.timestamps = [begin_ev.timestamp, 0]
        self.session = 0
    def setSession(self, sess):
        self.session = sess
    def setBeginEvent(self, ev):
        self.begin_event = ev
    def setEndEvent(self, ev):
        self.end_event = ev
    def setBeginTimestamp(self, tt):
        self.timestamps[0] = tt
    def setEndTimestamp(self, tt):
        self.timestamps[1] = tt
    def isMatchingEndEvent(self, end_event, unique_id):
        if self.begin_event == 0:
            return False
        return self.begin_event[unique_id] == end_event[unique_id]
    def duration(self):
        return self.timestamps[1] - self.timestamps[0]
    
# define the modules we want
modules = [
            # Module("sessions", "tensorflowTracer:session_start", "tensorflowTracer:session_end", "count"),
            # Module("hip_kernels", "hcTracer:kernel_begin", "hcTracer:kernel_end", "name"),
            # Module("operations", "tensorflowTracer:operation_start", "tensorflowTracer:operation_end", "name"),
            Module("cuda_kernels", "cudaTracer:kernel_begin", "cudaTracer:kernel_end", "name"),
          ]

# loop over the events
for r_event in collection.events:
    name = r_event.name
    # loop over the modules
    for mod in modules:
        # begin test of the module
        if re.match(mod.begin_event, name):
            s = State(r_event)
            s.setSession(modules[0].states_size() + 1)
            mod.open_state.append(s)

        # end test of the module
        if re.match(mod.end_event, name):
            matching_index = -1
            # find a waiting state
            for i in range(len(mod.open_state)):
                if mod.open_state[i].isMatchingEndEvent(r_event, mod.unique_id):
                    mod.open_state[i].setEndEvent(r_event)
                    mod.open_state[i].setEndTimestamp(r_event.timestamp)
                    mod.open_state[i].setSession(modules[0].states_size() + 1)
                    matching_index = i
                    break

            # if no waiting state correspond to an end event. Not possible, so
            # we have errors
            if matching_index == -1:
                print("Error no matching event, for this end")
                exit(1)

            mod.states.append(mod.open_state[matching_index])
            del mod.open_state[matching_index]

# sort the State according to their duration for each module
for mod in modules:
    mod.states.sort(key=lambda x: x.timestamps[1] - x.timestamps[0], reverse=True)


# Additional datatructure to store all the durations for each elements
# to compute the standard deviation
# the values could also give the mean for each operation and could replace my running
# mean
# ONLY WORKS IF ONLY 1 MODULE IS USED
elements_duration = defaultdict(list)


# we want to skip the first 2 sessions
# The first session run is Variable initilization
# The second session run is longer because of GPU initilization, kernel compilation, ...
skip_sessions = [1, 2]
with open(outfile, "w") as f:
    # print
    f.write("begin_timestamp;end_timestamp;name;duration;session\n")
    for mod in modules:
        f.write("MODULE;" + mod.name + "\n")
        # if ROCm platform, we want to use tf_name, not real GPU kernels name
        # if CUDA : name is already TensorFlow Op name, so directly use "name" field
        name_field = "name"
        if "hip_kernels" in mod.name:
            name_field = "tf_name"
        
        mean_values = {} # dict to store all the events, grouped by name
        f.write("\n\n")
        
        for i in mod.states:
            # skip some session runs
            if i.session in skip_sessions:
                continue
            elements_duration[i.begin_event[name_field]].append(i.duration())
            
            # write an entry
            f.write(str(i.timestamps[0]) + ";" + str(i.timestamps[1]) + ";"\
                        + i.begin_event[name_field] + ";" + str(i.timestamps[1] - \
                        i.timestamps[0]) + ";" + str(i.session) + "\n")
            
            # update the mean value for each event
            # first time we envounter this event
            if i.begin_event[name_field] not in mean_values:
                mean_values[i.begin_event[name_field]] = (i.duration(), 1)
            # we already have envountered this event, so update the mean
            else:
                mean_values[i.begin_event[name_field]] = \
                            ((mean_values[i.begin_event[name_field]][0] * mean_values[i.begin_event[name_field]][1] + i.duration())\
                            / (mean_values[i.begin_event[name_field]][1] + 1), \
                            mean_values[i.begin_event[name_field]][1] + 1)
        
        # write all the events, each event is unique and the duration is a mean
        f.write("\n")
        res = sorted(mean_values, key=mean_values.__getitem__, reverse=True)
        for i in res:
            f.write(";;" + i + ";" + str(mean_values[i][0]) + ";" + str(mean_values[i][1]) + "\n")
        f.write("\n\n\n")
        
        
        for i in elements_duration:
            # print(i, elements_duration[i])
            # print(np.std(elements_duration[i]))
            f.write(";;" + i + ";" + str(np.std(elements_duration[i])) + ";" + \
                        str(np.mean(elements_duration[i])) + ";" + \
                        str(len(elements_duration[i])) + "\n")



