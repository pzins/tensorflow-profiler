import os
import argparse


# parse argument to get the program name and path
parser = argparse.ArgumentParser(description="Fix a missing '_'")
parser.add_argument("--trace", help="set the trace")
args = parser.parse_args()

# Set the input traces
if args.trace == None:
    out_path = os.getcwd() + "/../results"
else:
    out_path = args.trace


out_metadata = []
with open(out_path + "/metadata", "r") as f:
    lines = f.readlines()
    for i in lines:
        if "vtid" in i and "_vtid" not in i:
            i = i.replace("vtid", "_vtid")
        out_metadata.append(i)

with open(out_path + "/metadata", "w") as f:
    f.writelines(out_metadata)
