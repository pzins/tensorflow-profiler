#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER hcTracer

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./hcTracer.h"

#if !defined(_hcTRACER_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _hcTRACER_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
    hcTracer,
    kernel_begin,
    TP_ARGS(
        const char*, cat_arg,
        uint64_t, timestamp_arg,
        const char*, name_arg,
        const char*, long_name_arg,
        const char*, tf_name_arg,
        uint16_t*, workgroup_size_arg,
        uint32_t*, grid_size_arg,
        uint64_t, static_group_segment_size_arg,
        uint64_t, private_segment_size_arg,
        uint64_t, workitem_vgpr_count_arg
    ),
    TP_FIELDS(
        ctf_string(cat, cat_arg)
        ctf_integer(uint64_t, timestamp, timestamp_arg)
        ctf_string(name, name_arg)
        ctf_string(long_name, long_name_arg)
        ctf_string(tf_name, tf_name_arg)
        ctf_array(uint16_t, workgroup_size, workgroup_size_arg, 3)
        ctf_array(uint32_t, grid_size, grid_size_arg, 3)
        ctf_integer(uint64_t, static_group_segment_size, static_group_segment_size_arg)
        ctf_integer(uint64_t, private_segment_size, private_segment_size_arg)
        ctf_integer(uint64_t, workitem_vgpr_count, workitem_vgpr_count_arg)
    )
)
TRACEPOINT_EVENT(
    hcTracer,
    kernel_end,
    TP_ARGS(
        const char*, cat_arg,
        uint64_t, timestamp_arg,
        const char*, name_arg,
        const char*, long_name_arg,
        const char*, tf_name_arg,
        uint16_t*, workgroup_size_arg,
        uint32_t*, grid_size_arg,
        uint64_t, static_group_segment_size_arg,
        uint64_t, private_segment_size_arg,
        uint64_t, workitem_vgpr_count_arg
    ),
    TP_FIELDS(
        ctf_string(cat, cat_arg)
        ctf_integer(uint64_t, timestamp, timestamp_arg)
        ctf_string(name, name_arg)
        ctf_string(long_name, long_name_arg)
        ctf_string(tf_name, tf_name_arg)
        ctf_array(uint16_t, workgroup_size, workgroup_size_arg, 3)
        ctf_array(uint32_t, grid_size, grid_size_arg, 3)
        ctf_integer(uint64_t, static_group_segment_size, static_group_segment_size_arg)
        ctf_integer(uint64_t, private_segment_size, private_segment_size_arg)
        ctf_integer(uint64_t, workitem_vgpr_count, workitem_vgpr_count_arg)
    )
)


TRACEPOINT_EVENT(
    hcTracer,
    async_memcpy_begin,
    TP_ARGS(
        const char*, cat_arg,
        uint64_t, timestamp_arg,
        const char*, name_arg,
        int64_t, size_bytes_arg,
        float, size_megabytes_arg,
        float, throughput_arg,
        uint32_t, isAsync_arg,
        uint32_t, isSingleStepCopy_arg,
        uint32_t, isPeerToPeer_arg,
        uint32_t, isActiveWait_arg
    ),
    TP_FIELDS(
        ctf_string(cat, cat_arg)
        ctf_integer(uint64_t, timestamp, timestamp_arg)
        ctf_string(name, name_arg)
        ctf_integer(int64_t, size_bytes, size_bytes_arg)
        ctf_float(float, size_megabytes, size_megabytes_arg)
        ctf_float(double, throughput, throughput_arg)
        ctf_integer(uint32_t, isAsync, isAsync_arg)
        ctf_integer(uint32_t, isSingleStepCopy, isSingleStepCopy_arg)
        ctf_integer(uint32_t, isPeerToPeer, isPeerToPeer_arg)
        ctf_integer(uint32_t, isActiveWait, isActiveWait_arg)
    )
)
TRACEPOINT_EVENT(
    hcTracer,
    async_memcpy_end,
    TP_ARGS(
        const char*, cat_arg,
        uint64_t, timestamp_arg,
        const char*, name_arg
    ),
    TP_FIELDS(
        ctf_string(cat, cat_arg)
        ctf_integer(uint64_t, timestamp, timestamp_arg)
        ctf_string(name, name_arg)
    )
)

TRACEPOINT_EVENT(
    hcTracer,
    async_memcpyslo_begin,
    TP_ARGS(
        const char*, cat_arg,
        uint64_t, timestamp_arg,
        const char*, name_arg,
        int, size_bytes_arg,
        float, size_megabytes_arg,
        float, throughput_arg,
        uint32_t, isAsync_arg,
        uint32_t, isSingleStepCopy_arg,
        uint32_t, isPeerToPeer_arg,
        uint32_t, isActiveWait_arg
    ),
    TP_FIELDS(
        ctf_string(cat, cat_arg)
        ctf_integer(uint64_t, timestamp, timestamp_arg)
        ctf_string(name, name_arg)
        ctf_integer(int, size_bytes, size_bytes_arg)
        ctf_float(float, size_megabytes, size_megabytes_arg)
        ctf_float(double, throughput, throughput_arg)
        ctf_integer(uint32_t, isAsync, isAsync_arg)
        ctf_integer(uint32_t, isSingleStepCopy, isSingleStepCopy_arg)
        ctf_integer(uint32_t, isPeerToPeer, isPeerToPeer_arg)
        ctf_integer(uint32_t, isActiveWait, isActiveWait_arg)
    )
)
TRACEPOINT_EVENT(
    hcTracer,
    async_memcpyslo_end,
    TP_ARGS(
        const char*, cat_arg,
        uint64_t, timestamp_arg,
        const char*, name_arg
    ),
    TP_FIELDS(
        ctf_string(cat, cat_arg)
        ctf_integer(uint64_t, timestamp, timestamp_arg)
        ctf_string(name, name_arg)
    )
)


TRACEPOINT_EVENT(
    hcTracer,
    barrier_begin,
    TP_ARGS(
        const char*, cat_arg,
        uint64_t, timestamp_arg,
        const char*, name_arg,
        int, dep_count_arg,
        int, acquire_arg,
        int, release_arg
    ),
    TP_FIELDS(
        ctf_string(cat, cat_arg)
        ctf_integer(uint64_t, timestamp, timestamp_arg)
        ctf_string(name, name_arg)
        ctf_integer(uint64_t, dep_count, dep_count_arg)
        ctf_integer(uint64_t, acquire, acquire_arg)
        ctf_integer(uint64_t, release, release_arg)
    )
)

TRACEPOINT_EVENT(
    hcTracer,
    barrier_end,
    TP_ARGS(
        const char*, cat_arg,
        uint64_t, timestamp,
        const char*, name_arg,
        int, dep_count_arg,
        int, acquire_arg,
        int, release_arg
    ),
    TP_FIELDS(
        ctf_string(cat, cat_arg)
        ctf_integer(uint64_t, timestamp, timestamp)
        ctf_string(name, name_arg)
        ctf_integer(uint64_t, dep_count, dep_count_arg)
        ctf_integer(uint64_t, acquire, acquire_arg)
        ctf_integer(uint64_t, release, release_arg)
    )
)

TRACEPOINT_EVENT(
    hcTracer,
    unpinned_memory_engine_copy_entry,
    TP_ARGS(
        const char*, cat_arg,
        const char*, name_arg,
        uint64_t, size_bytes_arg
    ),
    TP_FIELDS(
        ctf_string(cat, cat_arg)
        ctf_string(name, name_arg)
        ctf_integer(uint64_t, size_bytes, size_bytes_arg)
    )
)
TRACEPOINT_EVENT(
    hcTracer,
    unpinned_memory_engine_copy_exit,
    TP_ARGS(
        const char*, cat_arg,
        const char*, name_arg,
        uint64_t, size_bytes_arg
    ),
    TP_FIELDS(
        ctf_string(cat, cat_arg)
        ctf_string(name, name_arg)
        ctf_integer(uint64_t, size_bytes, size_bytes_arg)
    )
)


TRACEPOINT_EVENT(
	hcTracer,
	queue_stats,
	TP_ARGS(
		const char*, queue_id_arg,
        uint64_t, size_arg
	),
	TP_FIELDS(
		ctf_string(queue_id, queue_id_arg)
        ctf_integer(uint64_t, size, size_arg)
	)
)

#endif

#include <lttng/tracepoint-event.h>
