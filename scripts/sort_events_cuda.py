#!/usr/bin/python3
import babeltrace
import babeltrace.reader as btr
import babeltrace.writer as btw
import sys
from tracing_events_classes import event_classes
from collections import defaultdict
import time
import os
from collections import defaultdict
import argparse
from cbid_cuda import correlation_cbid
from utils import debugPrint



# parse argument to get the program name and path
parser = argparse.ArgumentParser(description="Sort events")
parser.add_argument("--input_trace", help="set the input trace")
parser.add_argument("--output_trace", help="set the output trace destination")
parser.add_argument("--gpu_log", help="log file created by HC with GPU information (kernels, barriers, memcpy)")
args = parser.parse_args()

debugPrint("SORT EVENTS")
# Add the input trace to the collection
collection = btr.TraceCollection()

# Set the input traces
if args.input_trace == None:
    directory = os.getcwd() + "/../lttng-traces/"
    path = max([os.path.join(directory,d) for d in os.listdir(directory)], key=os.path.getmtime)
else:
    path = args.input_trace
if path[-1] == "/":
    path = path[:-1]
collection.add_trace(path + "/ust/uid/1000/64-bit", 'ctf')

# Set the output trace
if args.output_trace == None:
    out_path = "/tmp/tensorflow-profiler"
else:
    out_path = args.output_trace
if not os.path.isdir(out_path):
    os.system("mkdir " + out_path)
writer = btw.Writer(out_path)



# Clock
clock_offset = 0
metadata_file = path + "/ust/uid/1000/64-bit/metadata"
with open(metadata_file, "r", errors='ignore') as f:
    lines = f.readlines()
    for l in lines:
        if "offset = " in l:
            clock_offset = int(l.split()[-1][:-1])


clock = btw.Clock('monotonic')
clock.description = 'Monotonic clock from AMD RCP'
# clock.offset = 1511453049028864041
writer.add_clock(clock)

writer.add_environment_field("hostname", "pierre")
writer.add_environment_field("domain", "ust")
writer.add_environment_field("tracer_name", "lttng-ust")
writer.add_environment_field("tracer_major", 2)
writer.add_environment_field("tracer_minor", 7)

# Create stream class
main_stream_class = btw.StreamClass('main_stream')
main_stream_class.clock = clock

# Create stream
for event_class in event_classes.values():
    main_stream_class.add_event_class(event_class)
main_stream = writer.create_stream(main_stream_class)

# Create events, based on event classes

init_time = None
cntol = 0
events = defaultdict(list)


driver_dic, runtime_dic = correlation_cbid()

for r_event in collection.events:
    name = r_event.name
    event_time = r_event.timestamp
    w_event = btw.Event(event_classes[name])

    fields = r_event.field_list_with_scope(babeltrace.common.CTFScope.EVENT_FIELDS)
    w_event = btw.Event(event_classes[name])


    for f in fields:
        # print(name, f, r_event[f])
        w_event.payload(f).value = r_event[f]


    if "queue" not in name and ("cuptiTracer:kernel" in name or "cuptiTracer:memcpy" in name):
        event_time = r_event["timestamp"] * 1000

    # organize threads
    threadId = r_event.field_with_scope("vtid", babeltrace.common.CTFScope.STREAM_EVENT_CONTEXT)

    if "cuptiTracer:runtime" in name:
        w_event.payload("name").value = runtime_dic[r_event["name"]]
        event_time = r_event["timestamp"]
        threadId = int(str(r_event["threadId"])[-4:])

    if "cuptiTracer:driver" in name:
        w_event.payload("name").value = driver_dic[r_event["name"]]
        event_time = r_event["timestamp"]
        threadId = int(str(r_event["threadId"])[-4:])


    if event_time in events:
        print("timestamp already exists")
        cntol += 1

    events[event_time].append([w_event, threadId])


timestamps = list(events.keys())
timestamps.sort()

debugPrint("WRITE TRACE")
for timestamp in timestamps:
    clock.time = timestamp
    for i in range(len(events[timestamp])):
        ev = events[timestamp][i][0]
        ev.tid(events[timestamp][i][1])
        # print(timestamp)
        main_stream.append_event(ev)

# Flush the stream
main_stream.flush()
