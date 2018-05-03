#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER openclTracer

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./clust_tp.h"

#if !defined(_CLUST_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _CLUST_TP_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
		openclTracer,
		callback,
		TP_ARGS(),
		TP_FIELDS()
)
TRACEPOINT_EVENT(
		openclTracer,
		kernel_queued,
    TP_ARGS(
			const char*, name_arg,
			const char*, cat_arg,
      ulong, timestamp_arg
    ),
    TP_FIELDS(
			      ctf_string(name, name_arg)
						ctf_string(cat, cat_arg)
            ctf_integer(ulong, timestamp, timestamp_arg)
    )
)
TRACEPOINT_EVENT(
		openclTracer,
		kernel_submitted,
    TP_ARGS(
			const char*, name_arg,
			const char*, cat_arg,
      ulong, timestamp_arg
    ),
    TP_FIELDS(
			      ctf_string(name, name_arg)
						ctf_string(cat, cat_arg)
            ctf_integer(ulong, timestamp, timestamp_arg)
    )
)
TRACEPOINT_EVENT(
		openclTracer,
		kernel_begin,
    TP_ARGS(
			const char*, name_arg,
			const char*, cat_arg,
      ulong, timestamp_arg
    ),
    TP_FIELDS(
			      ctf_string(name, name_arg)
						ctf_string(cat, cat_arg)
            ctf_integer(ulong, timestamp, timestamp_arg)
    )
)

TRACEPOINT_EVENT(
		openclTracer,
		kernel_end,
    TP_ARGS(
			const char*, name_arg,
			const char*, cat_arg,
      ulong, timestamp_arg
    ),
    TP_FIELDS(
			      ctf_string(name, name_arg)
						ctf_string(cat, cat_arg)
            ctf_integer(ulong, timestamp, timestamp_arg)
    )
)

TRACEPOINT_EVENT(
		openclTracer,
		device_begin,
    TP_ARGS(
			const char*, name_arg,
			const char*, cat_arg,
      ulong, timestamp_arg
    ),
    TP_FIELDS(
			      ctf_string(name, name_arg)
						ctf_string(cat, cat_arg)
            ctf_integer(ulong, timestamp, timestamp_arg)
    )
)
TRACEPOINT_EVENT(
		openclTracer,
		device_queued,
    TP_ARGS(
			const char*, name_arg,
			const char*, cat_arg,
      ulong, timestamp_arg
    ),
    TP_FIELDS(
			      ctf_string(name, name_arg)
						ctf_string(cat, cat_arg)
            ctf_integer(ulong, timestamp, timestamp_arg)
    )
)
TRACEPOINT_EVENT(
		openclTracer,
		device_submitted,
    TP_ARGS(
			const char*, name_arg,
			const char*, cat_arg,
      ulong, timestamp_arg
    ),
    TP_FIELDS(
			      ctf_string(name, name_arg)
						ctf_string(cat, cat_arg)
            ctf_integer(ulong, timestamp, timestamp_arg)
    )
)
TRACEPOINT_EVENT(
		openclTracer,
		device_end,
    TP_ARGS(
			const char*, name_arg,
			const char*, cat_arg,
      ulong, timestamp_arg
    ),
    TP_FIELDS(
			      ctf_string(name, name_arg)
						ctf_string(cat, cat_arg)
            ctf_integer(ulong, timestamp, timestamp_arg)
    )
)

TRACEPOINT_EVENT(
		openclTracer,
		clust_device_event,
    TP_ARGS(
			const char*, name_arg,
			const char*, cat_arg,
      ulong, queue_arg,
			int, command_arg,
			ulong, queued_arg,
			ulong, submit_arg,
			ulong, start_arg,
			ulong, end_arg
    ),
    TP_FIELDS(
			      ctf_string(name, name_arg)
						ctf_string(cat, cat_arg)
            ctf_integer_hex(ulong, queue_field, queue_arg)
            ctf_integer(int, command_field, command_arg)
            ctf_integer(ulong, queued_field, queued_arg)
            ctf_integer(ulong, submit_field, submit_arg)
            ctf_integer(ulong, start_field, start_arg)
            ctf_integer(ulong, end_field, end_arg)
    )
)

TRACEPOINT_EVENT(
	openclTracer,
	function_entry,
	TP_ARGS(
		const char*, name_arg,
		const char*, cat_arg
	),
	TP_FIELDS(
		ctf_string(name, name_arg)
		ctf_string(cat, cat_arg)
	)
)

TRACEPOINT_EVENT(
	openclTracer,
	function_exit,
TP_ARGS(
		const char*, name_arg,
		const char*, cat_arg
	),
	TP_FIELDS(
		ctf_string(name, name_arg)
		ctf_string(cat, cat_arg)
	)
)

#endif /* _CLUST_TP_H */

#include <lttng/tracepoint-event.h>
