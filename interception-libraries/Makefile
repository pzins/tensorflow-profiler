INCLUDES = -Iinclude/ -I/opt/rocm/include/hsa/ -IGPA/Src/GPUPerfAPI-Common
LIBDIRS = -L/opt/rocm/hsa/lib/ -L/opt/rocm/profiler/bin
LIBS = -ldl -lpthread -llttng-ust -lhsa-runtime-tools64 -lhsa-runtime64 -lGPUPerfAPIHSA
MODULES = call_stack kernel_times queue_profiling perf_counters


all: tracepoints util $(MODULES)

tracepoints:
	gcc -c -o obj/hsa_tracepoints.o -fPIC src/hsa_tracepoints.c $(INCLUDES)

util:
	g++ -c -std=c++11 -o obj/util.o -fPIC src/util.cpp $(INCLUDES) $(LIBDIRS) $(LIBS)

$(MODULES):
	g++ -g -std=c++11 -shared -o lib/hsa_$@.so obj/hsa_tracepoints.o obj/util.o -fPIC src/hsa_$@.cpp $(INCLUDES) $(LIBDIRS) $(LIBS) -fpermissive

clean:
	$(RM) obj/*.o lib/*.so
