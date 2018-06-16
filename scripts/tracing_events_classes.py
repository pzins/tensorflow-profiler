import babeltrace
import babeltrace.reader as btr
import babeltrace.writer as btw

# Create field declarations
# Field declarations
uint64_fd = btw.IntegerFieldDeclaration(64)
uint64_fd.signed = False

int64_fd = btw.IntegerFieldDeclaration(64)
int64_fd.signed = True

uint32_fd = btw.IntegerFieldDeclaration(32)
uint32_fd.signed = False

uint16_fd = btw.IntegerFieldDeclaration(16)
uint16_fd.signed = False

int32_fd = btw.IntegerFieldDeclaration(32)
int32_fd.signed = True

float_fd = btw.FloatingPointFieldDeclaration()

huint64_fd = btw.IntegerFieldDeclaration(64)
huint64_fd.base = babeltrace.writer.IntegerBase.HEX
huint64_fd.signed = False

string_fd = btw.StringFieldDeclaration()

dim_array32_fd = btw.ArrayFieldDeclaration(uint32_fd, 3)
dim_array16_fd = btw.ArrayFieldDeclaration(uint16_fd, 3)
# Create event classes
event_classes = {}



# openclTracer
event_classes['openclTracer:function_entry'] = btw.EventClass('openclTracer:function_entry')
event_classes['openclTracer:function_entry'].add_field(string_fd, 'cat')
event_classes['openclTracer:function_entry'].add_field(string_fd, 'name')

event_classes['openclTracer:function_exit'] = btw.EventClass('openclTracer:function_exit')
event_classes['openclTracer:function_exit'].add_field(string_fd, 'cat')
event_classes['openclTracer:function_exit'].add_field(string_fd, 'name')

event_classes['openclTracer:callback'] = btw.EventClass('openclTracer:callback')

event_classes['openclTracer:kernel_queued'] = btw.EventClass('openclTracer:kernel_queued')
event_classes['openclTracer:kernel_queued'].add_field(string_fd, 'cat')
event_classes['openclTracer:kernel_queued'].add_field(string_fd, 'name')
event_classes['openclTracer:kernel_queued'].add_field(uint64_fd, 'timestamp')

event_classes['openclTracer:kernel_submitted'] = btw.EventClass('openclTracer:kernel_submitted')
event_classes['openclTracer:kernel_submitted'].add_field(string_fd, 'cat')
event_classes['openclTracer:kernel_submitted'].add_field(string_fd, 'name')
event_classes['openclTracer:kernel_submitted'].add_field(uint64_fd, 'timestamp')

event_classes['openclTracer:kernel_begin'] = btw.EventClass('openclTracer:kernel_begin')
event_classes['openclTracer:kernel_begin'].add_field(string_fd, 'cat')
event_classes['openclTracer:kernel_begin'].add_field(string_fd, 'name')
event_classes['openclTracer:kernel_begin'].add_field(string_fd, 'tf_name')
event_classes['openclTracer:kernel_begin'].add_field(uint64_fd, 'timestamp')

event_classes['openclTracer:kernel_end'] = btw.EventClass('openclTracer:kernel_end')
event_classes['openclTracer:kernel_end'].add_field(string_fd, 'cat')
event_classes['openclTracer:kernel_end'].add_field(string_fd, 'name')
event_classes['openclTracer:kernel_end'].add_field(uint64_fd, 'timestamp')

event_classes['openclTracer:device_queued'] = btw.EventClass('openclTracer:device_queued')
event_classes['openclTracer:device_queued'].add_field(string_fd, 'cat')
event_classes['openclTracer:device_queued'].add_field(string_fd, 'name')
event_classes['openclTracer:device_queued'].add_field(uint64_fd, 'timestamp')

event_classes['openclTracer:device_submitted'] = btw.EventClass('openclTracer:device_submitted')
event_classes['openclTracer:device_submitted'].add_field(string_fd, 'cat')
event_classes['openclTracer:device_submitted'].add_field(string_fd, 'name')
event_classes['openclTracer:device_submitted'].add_field(uint64_fd, 'timestamp')

event_classes['openclTracer:device_begin'] = btw.EventClass('openclTracer:device_begin')
event_classes['openclTracer:device_begin'].add_field(string_fd, 'cat')
event_classes['openclTracer:device_begin'].add_field(string_fd, 'name')
event_classes['openclTracer:device_begin'].add_field(uint64_fd, 'timestamp')

event_classes['openclTracer:device_end'] = btw.EventClass('openclTracer:device_end')
event_classes['openclTracer:device_end'].add_field(string_fd, 'cat')
event_classes['openclTracer:device_end'].add_field(string_fd, 'name')
event_classes['openclTracer:device_end'].add_field(uint64_fd, 'timestamp')



# interceptionTracer
event_classes['interceptionTracer:kernel_begin'] = btw.EventClass('interceptionTracer:kernel_begin')
event_classes['interceptionTracer:kernel_begin'].add_field(string_fd, 'cat')
event_classes['interceptionTracer:kernel_begin'].add_field(uint64_fd, 'kernel_object')
event_classes['interceptionTracer:kernel_begin'].add_field(string_fd, 'name')
event_classes['interceptionTracer:kernel_begin'].add_field(string_fd, 'tf_name')
event_classes['interceptionTracer:kernel_begin'].add_field(uint64_fd, 'agent_handle')
event_classes['interceptionTracer:kernel_begin'].add_field(uint64_fd, 'queue_id')
event_classes['interceptionTracer:kernel_begin'].add_field(uint64_fd, 'timestamp')

event_classes['interceptionTracer:kernel_end'] = btw.EventClass('interceptionTracer:kernel_end')
event_classes['interceptionTracer:kernel_end'].add_field(string_fd, 'cat')
event_classes['interceptionTracer:kernel_end'].add_field(uint64_fd, 'kernel_object')
event_classes['interceptionTracer:kernel_end'].add_field(string_fd, 'name')
event_classes['interceptionTracer:kernel_end'].add_field(string_fd, 'tf_name')
event_classes['interceptionTracer:kernel_end'].add_field(uint64_fd, 'agent_handle')
event_classes['interceptionTracer:kernel_end'].add_field(uint64_fd, 'queue_id')
event_classes['interceptionTracer:kernel_end'].add_field(uint64_fd, 'timestamp')

event_classes['interceptionTracer:runtime_initialized'] = btw.EventClass('interceptionTracer:runtime_initialized')
event_classes['interceptionTracer:runtime_initialized'].add_field(string_fd, 'cat')

event_classes['interceptionTracer:runtime_shut_down'] = btw.EventClass('interceptionTracer:runtime_shut_down')
event_classes['interceptionTracer:runtime_shut_down'].add_field(string_fd, 'cat')

event_classes['interceptionTracer:queue_created'] = btw.EventClass('interceptionTracer:queue_created')
event_classes['interceptionTracer:queue_created'].add_field(string_fd, 'cat')
event_classes['interceptionTracer:queue_created'].add_field(uint64_fd, 'agent_handle')
event_classes['interceptionTracer:queue_created'].add_field(uint64_fd, 'queue_id')

event_classes['interceptionTracer:queue_destroyed'] = btw.EventClass('interceptionTracer:queue_destroyed')
event_classes['interceptionTracer:queue_destroyed'].add_field(string_fd, 'cat')
event_classes['interceptionTracer:queue_destroyed'].add_field(uint64_fd, 'queue_id')

event_classes['interceptionTracer:aql_packet_submitted'] = btw.EventClass('interceptionTracer:aql_packet_submitted')
event_classes['interceptionTracer:aql_packet_submitted'].add_field(string_fd, 'cat')
event_classes['interceptionTracer:aql_packet_submitted'].add_field(uint64_fd, 'packet_id')
event_classes['interceptionTracer:aql_packet_submitted'].add_field(string_fd, 'packet_type')
event_classes['interceptionTracer:aql_packet_submitted'].add_field(uint64_fd, 'agent_handle')
event_classes['interceptionTracer:aql_packet_submitted'].add_field(uint64_fd, 'queue_id')

event_classes['interceptionTracer:aql_kernel_dispatch_packet_submitted'] = btw.EventClass('interceptionTracer:aql_kernel_dispatch_packet_submitted')
event_classes['interceptionTracer:aql_kernel_dispatch_packet_submitted'].add_field(string_fd, 'cat')
event_classes['interceptionTracer:aql_kernel_dispatch_packet_submitted'].add_field(uint64_fd, 'packet_id')
event_classes['interceptionTracer:aql_kernel_dispatch_packet_submitted'].add_field(uint64_fd, 'agent_handle')
event_classes['interceptionTracer:aql_kernel_dispatch_packet_submitted'].add_field(uint64_fd, 'queue_id')
event_classes['interceptionTracer:aql_kernel_dispatch_packet_submitted'].add_field(uint64_fd, 'kernel_object')
event_classes['interceptionTracer:aql_kernel_dispatch_packet_submitted'].add_field(string_fd, 'kernel_name')

event_classes['interceptionTracer:kernel_parameters'] = btw.EventClass('interceptionTracer:kernel_parameters')
event_classes['interceptionTracer:kernel_parameters'].add_field(dim_array16_fd, 'workgroup_size')
event_classes['interceptionTracer:kernel_parameters'].add_field(dim_array32_fd, 'grid_size')
event_classes['interceptionTracer:kernel_parameters'].add_field(uint32_fd, 'static_group_segment_size')
event_classes['interceptionTracer:kernel_parameters'].add_field(uint32_fd, 'private_segment_size')

event_classes['interceptionTracer:perf_counter_uint32'] = btw.EventClass('interceptionTracer:perf_counter_uint32')
event_classes['interceptionTracer:perf_counter_uint32'].add_field(string_fd, 'cat')
event_classes['interceptionTracer:perf_counter_uint32'].add_field(uint64_fd, 'kernel_object')
event_classes['interceptionTracer:perf_counter_uint32'].add_field(uint32_fd, 'counter_index')
event_classes['interceptionTracer:perf_counter_uint32'].add_field(string_fd, 'counter_name')
event_classes['interceptionTracer:perf_counter_uint32'].add_field(uint32_fd, 'value')

event_classes['interceptionTracer:perf_counter_uint64'] = btw.EventClass('interceptionTracer:perf_counter_uint64')
event_classes['interceptionTracer:perf_counter_uint64'].add_field(string_fd, 'cat')
event_classes['interceptionTracer:perf_counter_uint64'].add_field(uint64_fd, 'kernel_object')
event_classes['interceptionTracer:perf_counter_uint64'].add_field(uint32_fd, 'counter_index')
event_classes['interceptionTracer:perf_counter_uint64'].add_field(string_fd, 'counter_name')
event_classes['interceptionTracer:perf_counter_uint64'].add_field(uint64_fd, 'value')

event_classes['interceptionTracer:perf_counter_float32'] = btw.EventClass('interceptionTracer:perf_counter_float32')
event_classes['interceptionTracer:perf_counter_float32'].add_field(string_fd, 'cat')
event_classes['interceptionTracer:perf_counter_float32'].add_field(uint64_fd, 'kernel_object')
event_classes['interceptionTracer:perf_counter_float32'].add_field(uint32_fd, 'counter_index')
event_classes['interceptionTracer:perf_counter_float32'].add_field(string_fd, 'counter_name')
event_classes['interceptionTracer:perf_counter_float32'].add_field(float_fd, 'value')

event_classes['interceptionTracer:perf_counter_float64'] = btw.EventClass('interceptionTracer:perf_counter_float64')
event_classes['interceptionTracer:perf_counter_float64'].add_field(string_fd, 'cat')
event_classes['interceptionTracer:perf_counter_float64'].add_field(uint64_fd, 'kernel_object')
event_classes['interceptionTracer:perf_counter_float64'].add_field(uint32_fd, 'counter_index')
event_classes['interceptionTracer:perf_counter_float64'].add_field(string_fd, 'counter_name')
event_classes['interceptionTracer:perf_counter_float64'].add_field(float_fd, 'value')



# hsaTracer
event_classes['hsaTracer:function_entry'] = btw.EventClass('hsaTracer:function_entry')
event_classes['hsaTracer:function_entry'].add_field(string_fd, 'cat')
event_classes['hsaTracer:function_entry'].add_field(string_fd, 'name')

event_classes['hsaTracer:function_exit'] = btw.EventClass('hsaTracer:function_exit')
event_classes['hsaTracer:function_exit'].add_field(string_fd, 'cat')
event_classes['hsaTracer:function_exit'].add_field(string_fd, 'name')

event_classes['hsaTracer:pool_memory_allocate'] = btw.EventClass('hsaTracer:pool_memory_allocate')
event_classes['hsaTracer:pool_memory_allocate'].add_field(uint64_fd, 'handle')
event_classes['hsaTracer:pool_memory_allocate'].add_field(uint64_fd, 'ptr')
event_classes['hsaTracer:pool_memory_allocate'].add_field(uint64_fd, 'size')

event_classes['hsaTracer:pool_memory_free'] = btw.EventClass('hsaTracer:pool_memory_free')
event_classes['hsaTracer:pool_memory_free'].add_field(uint64_fd, 'handle')
event_classes['hsaTracer:pool_memory_free'].add_field(uint64_fd, 'ptr')
event_classes['hsaTracer:pool_memory_free'].add_field(int64_fd, 'size')



# hipTracer
event_classes['hipTracer:function_entry'] = btw.EventClass('hipTracer:function_entry')
event_classes['hipTracer:function_entry'].add_field(string_fd, 'cat')
event_classes['hipTracer:function_entry'].add_field(string_fd, 'name')

event_classes['hipTracer:function_exit'] = btw.EventClass('hipTracer:function_exit')
event_classes['hipTracer:function_exit'].add_field(string_fd, 'cat')
event_classes['hipTracer:function_exit'].add_field(string_fd, 'name')



# grpcTracer
event_classes['grpcTracer:EncodeRecvTensorResponseToByteBuffer'] = btw.EventClass('grpcTracer:EncodeRecvTensorResponseToByteBuffer')
event_classes['grpcTracer:EncodeRecvTensorResponseToByteBuffer'].add_field(string_fd, 'cat')
event_classes['grpcTracer:EncodeRecvTensorResponseToByteBuffer'].add_field(string_fd, 'name')
event_classes['grpcTracer:EncodeRecvTensorResponseToByteBuffer'].add_field(uint64_fd, 'size')

event_classes['grpcTracer:EncodeTensorToByteBuffer'] = btw.EventClass('grpcTracer:EncodeTensorToByteBuffer')
event_classes['grpcTracer:EncodeTensorToByteBuffer'].add_field(string_fd, 'cat')
event_classes['grpcTracer:EncodeTensorToByteBuffer'].add_field(string_fd, 'name')
event_classes['grpcTracer:EncodeTensorToByteBuffer'].add_field(uint64_fd, 'size')


event_classes['grpcTracer:receive_request'] = btw.EventClass('grpcTracer:receive_request')
event_classes['grpcTracer:receive_request'].add_field(string_fd, 'name')
event_classes['grpcTracer:send_request'] = btw.EventClass('grpcTracer:send_request')
event_classes['grpcTracer:send_request'].add_field(string_fd, 'name')

event_classes['grpcTracer:receive_RecvTensor_request'] = btw.EventClass('grpcTracer:receive_RecvTensor_request')
event_classes['grpcTracer:receive_RecvTensor_request'].add_field(string_fd, 'cat')
event_classes['grpcTracer:receive_RecvTensor_request'].add_field(string_fd, 'name')
event_classes['grpcTracer:receive_RecvTensor_request'].add_field(string_fd, 'rendezvous_key')
event_classes['grpcTracer:receive_RecvTensor_request'].add_field(uint64_fd, 'step_id')
event_classes['grpcTracer:receive_RecvTensor_request'].add_field(uint32_fd, 'bus_id')

event_classes['grpcTracer:send_RecvTensor_request'] = btw.EventClass('grpcTracer:send_RecvTensor_request')
event_classes['grpcTracer:send_RecvTensor_request'].add_field(string_fd, 'cat')
event_classes['grpcTracer:send_RecvTensor_request'].add_field(string_fd, 'name')
event_classes['grpcTracer:send_RecvTensor_request'].add_field(string_fd, 'rendezvous_key')
event_classes['grpcTracer:send_RecvTensor_request'].add_field(string_fd, 'tensor')
event_classes['grpcTracer:send_RecvTensor_request'].add_field(string_fd, 'src_device')
event_classes['grpcTracer:send_RecvTensor_request'].add_field(string_fd, 'dst_device')
event_classes['grpcTracer:send_RecvTensor_request'].add_field(string_fd, 'request')
event_classes['grpcTracer:send_RecvTensor_request'].add_field(string_fd, 'response')

event_classes['grpcTracer:set_proto_from_gpu_start'] = btw.EventClass('grpcTracer:set_proto_from_gpu_start')
event_classes['grpcTracer:set_proto_from_gpu_start'].add_field(string_fd, 'cat')
event_classes['grpcTracer:set_proto_from_gpu_start'].add_field(string_fd, 'name')
event_classes['grpcTracer:set_proto_from_gpu_start'].add_field(string_fd, 'rendezvous_key')

event_classes['grpcTracer:set_proto_from_gpu_end'] = btw.EventClass('grpcTracer:set_proto_from_gpu_end')
event_classes['grpcTracer:set_proto_from_gpu_end'].add_field(string_fd, 'cat')
event_classes['grpcTracer:set_proto_from_gpu_end'].add_field(string_fd, 'name')
event_classes['grpcTracer:set_proto_from_gpu_end'].add_field(string_fd, 'rendezvous_key')

event_classes['grpcTracer:prepare_response_tensor_start'] = btw.EventClass('grpcTracer:prepare_response_tensor_start')
event_classes['grpcTracer:prepare_response_tensor_start'].add_field(string_fd, 'cat')
event_classes['grpcTracer:prepare_response_tensor_start'].add_field(string_fd, 'name')
event_classes['grpcTracer:prepare_response_tensor_start'].add_field(string_fd, 'rendezvous_key')

event_classes['grpcTracer:prepare_response_tensor_end'] = btw.EventClass('grpcTracer:prepare_response_tensor_end')
event_classes['grpcTracer:prepare_response_tensor_end'].add_field(string_fd, 'cat')
event_classes['grpcTracer:prepare_response_tensor_end'].add_field(string_fd, 'name')
event_classes['grpcTracer:prepare_response_tensor_end'].add_field(string_fd, 'rendezvous_key')

event_classes['grpcTracer:send_request_tensor_start'] = btw.EventClass('grpcTracer:send_request_tensor_start')
event_classes['grpcTracer:send_request_tensor_start'].add_field(string_fd, 'cat')
event_classes['grpcTracer:send_request_tensor_start'].add_field(string_fd, 'name')
event_classes['grpcTracer:send_request_tensor_start'].add_field(string_fd, 'rendezvous_key')

event_classes['grpcTracer:send_request_tensor_end'] = btw.EventClass('grpcTracer:send_request_tensor_end')
event_classes['grpcTracer:send_request_tensor_end'].add_field(string_fd, 'cat')
event_classes['grpcTracer:send_request_tensor_end'].add_field(string_fd, 'name')
event_classes['grpcTracer:send_request_tensor_end'].add_field(string_fd, 'rendezvous_key')


# streamTracer
event_classes['streamTracer:memcpy_start'] = btw.EventClass('streamTracer:memcpy_start')
event_classes['streamTracer:memcpy_start'].add_field(string_fd, 'cat')
event_classes['streamTracer:memcpy_start'].add_field(string_fd, 'name')
event_classes['streamTracer:memcpy_start'].add_field(uint64_fd, 'size')

event_classes['streamTracer:memcpy_end'] = btw.EventClass('streamTracer:memcpy_end')
event_classes['streamTracer:memcpy_end'].add_field(string_fd, 'cat')
event_classes['streamTracer:memcpy_end'].add_field(string_fd, 'name')


event_classes['testTracer:start'] = btw.EventClass('testTracer:start')
event_classes['testTracer:start'].add_field(string_fd, 'cat')
event_classes['testTracer:start'].add_field(string_fd, 'name')

event_classes['testTracer:end'] = btw.EventClass('testTracer:end')
event_classes['testTracer:end'].add_field(string_fd, 'cat')
event_classes['testTracer:end'].add_field(string_fd, 'name')


# hcTracer
event_classes['hcTracer:kernel_begin'] = btw.EventClass('hcTracer:kernel_begin')
event_classes['hcTracer:kernel_begin'].add_field(string_fd, 'cat')
event_classes['hcTracer:kernel_begin'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:kernel_begin'].add_field(string_fd, 'name')
event_classes['hcTracer:kernel_begin'].add_field(string_fd, 'long_name')
event_classes['hcTracer:kernel_begin'].add_field(string_fd, 'tf_name')
event_classes['hcTracer:kernel_begin'].add_field(dim_array16_fd, 'workgroup_size')
event_classes['hcTracer:kernel_begin'].add_field(dim_array32_fd, 'grid_size')
event_classes['hcTracer:kernel_begin'].add_field(uint32_fd, 'static_group_segment_size')
event_classes['hcTracer:kernel_begin'].add_field(uint32_fd, 'private_segment_size')
event_classes['hcTracer:kernel_begin'].add_field(uint32_fd, 'workitem_vgpr_count')

event_classes['hcTracer:kernel_end'] = btw.EventClass('hcTracer:kernel_end')
event_classes['hcTracer:kernel_end'].add_field(string_fd, 'cat')
event_classes['hcTracer:kernel_end'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:kernel_end'].add_field(string_fd, 'name')
event_classes['hcTracer:kernel_end'].add_field(string_fd, 'long_name')
event_classes['hcTracer:kernel_end'].add_field(string_fd, 'tf_name')
event_classes['hcTracer:kernel_end'].add_field(dim_array16_fd, 'workgroup_size')
event_classes['hcTracer:kernel_end'].add_field(dim_array32_fd, 'grid_size')
event_classes['hcTracer:kernel_end'].add_field(uint32_fd, 'static_group_segment_size')
event_classes['hcTracer:kernel_end'].add_field(uint32_fd, 'private_segment_size')
event_classes['hcTracer:kernel_end'].add_field(uint32_fd, 'workitem_vgpr_count')

event_classes['hcTracer:kernel_log_begin'] = btw.EventClass('hcTracer:kernel_log_begin')
event_classes['hcTracer:kernel_log_begin'].add_field(string_fd, 'cat')
event_classes['hcTracer:kernel_log_begin'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:kernel_log_begin'].add_field(string_fd, 'name')
event_classes['hcTracer:kernel_log_begin'].add_field(string_fd, 'tf_name')
event_classes['hcTracer:kernel_log_begin'].add_field(string_fd, 'id')

event_classes['hcTracer:kernel_log_end'] = btw.EventClass('hcTracer:kernel_log_end')
event_classes['hcTracer:kernel_log_end'].add_field(string_fd, 'cat')
event_classes['hcTracer:kernel_log_end'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:kernel_log_end'].add_field(string_fd, 'name')
event_classes['hcTracer:kernel_log_end'].add_field(string_fd, 'tf_name')
event_classes['hcTracer:kernel_log_end'].add_field(string_fd, 'id')

event_classes['hcTracer:barrier_log_begin'] = btw.EventClass('hcTracer:barrier_log_begin')
event_classes['hcTracer:barrier_log_begin'].add_field(string_fd, 'cat')
event_classes['hcTracer:barrier_log_begin'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:barrier_log_begin'].add_field(string_fd, 'name')
event_classes['hcTracer:barrier_log_begin'].add_field(string_fd, 'id')

event_classes['hcTracer:barrier_log_end'] = btw.EventClass('hcTracer:barrier_log_end')
event_classes['hcTracer:barrier_log_end'].add_field(string_fd, 'cat')
event_classes['hcTracer:barrier_log_end'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:barrier_log_end'].add_field(string_fd, 'name')
event_classes['hcTracer:barrier_log_end'].add_field(string_fd, 'id')

event_classes['hcTracer:async_memcpy_log_begin'] = btw.EventClass('hcTracer:async_memcpy_log_begin')
event_classes['hcTracer:async_memcpy_log_begin'].add_field(string_fd, 'cat')
event_classes['hcTracer:async_memcpy_log_begin'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:async_memcpy_log_begin'].add_field(string_fd, 'name')
event_classes['hcTracer:async_memcpy_log_begin'].add_field(int64_fd, 'size_bytes')
event_classes['hcTracer:async_memcpy_log_begin'].add_field(float_fd, 'size_megabytes')
event_classes['hcTracer:async_memcpy_log_begin'].add_field(float_fd, 'throughput')

event_classes['hcTracer:async_memcpy_log_end'] = btw.EventClass('hcTracer:async_memcpy_log_end')
event_classes['hcTracer:async_memcpy_log_end'].add_field(string_fd, 'cat')
event_classes['hcTracer:async_memcpy_log_end'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:async_memcpy_log_end'].add_field(string_fd, 'name')

event_classes['hcTracer:async_memcpyslo_log_begin'] = btw.EventClass('hcTracer:async_memcpyslo_log_begin')
event_classes['hcTracer:async_memcpyslo_log_begin'].add_field(string_fd, 'cat')
event_classes['hcTracer:async_memcpyslo_log_begin'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:async_memcpyslo_log_begin'].add_field(string_fd, 'name')
event_classes['hcTracer:async_memcpyslo_log_begin'].add_field(int64_fd, 'size_bytes')
event_classes['hcTracer:async_memcpyslo_log_begin'].add_field(float_fd, 'size_megabytes')
event_classes['hcTracer:async_memcpyslo_log_begin'].add_field(float_fd, 'throughput')

event_classes['hcTracer:async_memcpyslo_log_end'] = btw.EventClass('hcTracer:async_memcpyslo_log_end')
event_classes['hcTracer:async_memcpyslo_log_end'].add_field(string_fd, 'cat')
event_classes['hcTracer:async_memcpyslo_log_end'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:async_memcpyslo_log_end'].add_field(string_fd, 'name')


event_classes['hcTracer:unpinned_memory_engine_copy_entry'] = btw.EventClass('hcTracer:unpinned_memory_engine_copy_entry')
event_classes['hcTracer:unpinned_memory_engine_copy_entry'].add_field(string_fd, 'cat')
event_classes['hcTracer:unpinned_memory_engine_copy_entry'].add_field(string_fd, 'name')
event_classes['hcTracer:unpinned_memory_engine_copy_entry'].add_field(int64_fd, 'size_bytes')

event_classes['hcTracer:unpinned_memory_engine_copy_exit'] = btw.EventClass('hcTracer:unpinned_memory_engine_copy_exit')
event_classes['hcTracer:unpinned_memory_engine_copy_exit'].add_field(string_fd, 'cat')
event_classes['hcTracer:unpinned_memory_engine_copy_exit'].add_field(string_fd, 'name')
event_classes['hcTracer:unpinned_memory_engine_copy_exit'].add_field(int64_fd, 'size_bytes')

event_classes['hcTracer:async_memcpy_begin'] = btw.EventClass('hcTracer:async_memcpy_begin')
event_classes['hcTracer:async_memcpy_begin'].add_field(string_fd, 'cat')
event_classes['hcTracer:async_memcpy_begin'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:async_memcpy_begin'].add_field(string_fd, 'name')
event_classes['hcTracer:async_memcpy_begin'].add_field(int64_fd, 'size_bytes')
event_classes['hcTracer:async_memcpy_begin'].add_field(float_fd, 'size_megabytes')
event_classes['hcTracer:async_memcpy_begin'].add_field(float_fd, 'throughput')
event_classes['hcTracer:async_memcpy_begin'].add_field(uint32_fd, 'isAsync')
event_classes['hcTracer:async_memcpy_begin'].add_field(uint32_fd, 'isSingleStepCopy')
event_classes['hcTracer:async_memcpy_begin'].add_field(uint32_fd, 'isPeerToPeer')
event_classes['hcTracer:async_memcpy_begin'].add_field(uint32_fd, 'isActiveWait')

event_classes['hcTracer:async_memcpy_end'] = btw.EventClass('hcTracer:async_memcpy_end')
event_classes['hcTracer:async_memcpy_end'].add_field(string_fd, 'cat')
event_classes['hcTracer:async_memcpy_end'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:async_memcpy_end'].add_field(string_fd, 'name')

event_classes['hcTracer:async_memcpyslo_begin'] = btw.EventClass('hcTracer:async_memcpyslo_begin')
event_classes['hcTracer:async_memcpyslo_begin'].add_field(string_fd, 'cat')
event_classes['hcTracer:async_memcpyslo_begin'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:async_memcpyslo_begin'].add_field(string_fd, 'name')
event_classes['hcTracer:async_memcpyslo_begin'].add_field(int64_fd, 'size_bytes')
event_classes['hcTracer:async_memcpyslo_begin'].add_field(float_fd, 'size_megabytes')
event_classes['hcTracer:async_memcpyslo_begin'].add_field(float_fd, 'throughput')
event_classes['hcTracer:async_memcpyslo_begin'].add_field(uint32_fd, 'isAsync')
event_classes['hcTracer:async_memcpyslo_begin'].add_field(uint32_fd, 'isSingleStepCopy')
event_classes['hcTracer:async_memcpyslo_begin'].add_field(uint32_fd, 'isPeerToPeer')
event_classes['hcTracer:async_memcpyslo_begin'].add_field(uint32_fd, 'isActiveWait')

event_classes['hcTracer:async_memcpyslo_end'] = btw.EventClass('hcTracer:async_memcpyslo_end')
event_classes['hcTracer:async_memcpyslo_end'].add_field(string_fd, 'cat')
event_classes['hcTracer:async_memcpyslo_end'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:async_memcpyslo_end'].add_field(string_fd, 'name')

event_classes['hcTracer:barrier_begin'] = btw.EventClass('hcTracer:barrier_begin')
event_classes['hcTracer:barrier_begin'].add_field(string_fd, 'cat')
event_classes['hcTracer:barrier_begin'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:barrier_begin'].add_field(string_fd, 'name')
event_classes['hcTracer:barrier_begin'].add_field(uint32_fd, 'dep_count')
event_classes['hcTracer:barrier_begin'].add_field(uint32_fd, 'acquire')
event_classes['hcTracer:barrier_begin'].add_field(uint32_fd, 'release')

event_classes['hcTracer:barrier_end'] = btw.EventClass('hcTracer:barrier_end')
event_classes['hcTracer:barrier_end'].add_field(string_fd, 'cat')
event_classes['hcTracer:barrier_end'].add_field(string_fd, 'name')
event_classes['hcTracer:barrier_end'].add_field(uint64_fd, 'timestamp')
event_classes['hcTracer:barrier_end'].add_field(uint32_fd, 'dep_count')
event_classes['hcTracer:barrier_end'].add_field(uint32_fd, 'acquire')
event_classes['hcTracer:barrier_end'].add_field(uint32_fd, 'release')


event_classes['hcTracer:queue_stats'] = btw.EventClass('hcTracer:queue_stats')
event_classes['hcTracer:queue_stats'].add_field(string_fd, 'queue_id')
event_classes['hcTracer:queue_stats'].add_field(uint64_fd, 'size')



# tensorflowTracer

# Tracepoints : entry / exit
event_classes['tensorflowTracer:process_entry'] = btw.EventClass('tensorflowTracer:process_entry')
event_classes['tensorflowTracer:process_entry'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:process_entry'].add_field(string_fd, 'name')
event_classes['tensorflowTracer:process_entry'].add_field(uint64_fd, 'schedule')

event_classes['tensorflowTracer:process_exit'] = btw.EventClass('tensorflowTracer:process_exit')
event_classes['tensorflowTracer:process_exit'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:process_exit'].add_field(string_fd, 'name')
event_classes['tensorflowTracer:process_exit'].add_field(uint64_fd, 'schedule')

event_classes['tensorflowTracer:inline_ready_entry'] = btw.EventClass('tensorflowTracer:inline_ready_entry')
event_classes['tensorflowTracer:inline_ready_entry'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:inline_ready_entry'].add_field(string_fd, 'name')

event_classes['tensorflowTracer:inline_ready_exit'] = btw.EventClass('tensorflowTracer:inline_ready_exit')
event_classes['tensorflowTracer:inline_ready_exit'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:inline_ready_exit'].add_field(string_fd, 'name')

event_classes['tensorflowTracer:push_succ_entry'] = btw.EventClass('tensorflowTracer:push_succ_entry')
event_classes['tensorflowTracer:push_succ_entry'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:push_succ_entry'].add_field(string_fd, 'name')

event_classes['tensorflowTracer:push_succ_exit'] = btw.EventClass('tensorflowTracer:push_succ_exit')
event_classes['tensorflowTracer:push_succ_exit'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:push_succ_exit'].add_field(string_fd, 'name')
event_classes['tensorflowTracer:push_succ_exit'].add_field(uint32_fd, 'is_ready')


# Tracepoints : start / end
event_classes['tensorflowTracer:session_start'] = btw.EventClass('tensorflowTracer:session_start')
event_classes['tensorflowTracer:session_start'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:session_start'].add_field(string_fd, 'name')
event_classes['tensorflowTracer:session_start'].add_field(uint32_fd, 'count')

event_classes['tensorflowTracer:session_end'] = btw.EventClass('tensorflowTracer:session_end')
event_classes['tensorflowTracer:session_end'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:session_end'].add_field(string_fd, 'name')
event_classes['tensorflowTracer:session_end'].add_field(uint32_fd, 'count')

event_classes['tensorflowTracer:operation_start'] = btw.EventClass('tensorflowTracer:operation_start')
event_classes['tensorflowTracer:operation_start'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:operation_start'].add_field(string_fd, 'placement')
event_classes['tensorflowTracer:operation_start'].add_field(string_fd, 'name')

event_classes['tensorflowTracer:operation_end'] = btw.EventClass('tensorflowTracer:operation_end')
event_classes['tensorflowTracer:operation_end'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:operation_end'].add_field(string_fd, 'placement')
event_classes['tensorflowTracer:operation_end'].add_field(string_fd, 'name')

event_classes['tensorflowTracer:async_operation_start'] = btw.EventClass('tensorflowTracer:async_operation_start')
event_classes['tensorflowTracer:async_operation_start'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:async_operation_start'].add_field(string_fd, 'placement')
event_classes['tensorflowTracer:async_operation_start'].add_field(string_fd, 'name')

event_classes['tensorflowTracer:async_operation_end'] = btw.EventClass('tensorflowTracer:async_operation_end')
event_classes['tensorflowTracer:async_operation_end'].add_field(string_fd, 'placement')
event_classes['tensorflowTracer:async_operation_end'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:async_operation_end'].add_field(string_fd, 'name')

event_classes['tensorflowTracer:rdv_send'] = btw.EventClass('tensorflowTracer:rdv_send')
event_classes['tensorflowTracer:rdv_send'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:rdv_send'].add_field(string_fd, 'name')

event_classes['tensorflowTracer:rdv_recv'] = btw.EventClass('tensorflowTracer:rdv_recv')
event_classes['tensorflowTracer:rdv_recv'].add_field(string_fd, 'cat')
event_classes['tensorflowTracer:rdv_recv'].add_field(string_fd, 'name')


# Tracepoints : XY Charts
event_classes['tensorflowTracer:bfc_allocator_stats'] = btw.EventClass('tensorflowTracer:bfc_allocator_stats')
event_classes['tensorflowTracer:bfc_allocator_stats'].add_field(string_fd, 'allocator_name')
event_classes['tensorflowTracer:bfc_allocator_stats'].add_field(uint64_fd, 'num_allocs')
event_classes['tensorflowTracer:bfc_allocator_stats'].add_field(uint64_fd, 'bytes_in_use')
event_classes['tensorflowTracer:bfc_allocator_stats'].add_field(uint64_fd, 'max_bytes_in_use')
event_classes['tensorflowTracer:bfc_allocator_stats'].add_field(uint64_fd, 'max_alloc_size')

event_classes['tensorflowTracer:bfc_chunks_stats'] = btw.EventClass('tensorflowTracer:bfc_chunks_stats')
event_classes['tensorflowTracer:bfc_chunks_stats'].add_field(string_fd, 'allocator_name')
event_classes['tensorflowTracer:bfc_chunks_stats'].add_field(uint64_fd, 'total_bytes_in_use')
event_classes['tensorflowTracer:bfc_chunks_stats'].add_field(uint64_fd, 'total_requested_bytes_in_use')
event_classes['tensorflowTracer:bfc_chunks_stats'].add_field(int64_fd, 'total_wasted_bytes_in_use')
event_classes['tensorflowTracer:bfc_chunks_stats'].add_field(uint64_fd, 'total_bytes')
event_classes['tensorflowTracer:bfc_chunks_stats'].add_field(uint64_fd, 'total_requested_bytes')
event_classes['tensorflowTracer:bfc_chunks_stats'].add_field(int64_fd, 'total_wasted_bytes')
event_classes['tensorflowTracer:bfc_chunks_stats'].add_field(uint64_fd, 'chunks')
event_classes['tensorflowTracer:bfc_chunks_stats'].add_field(uint64_fd, 'in_use_chunks')
event_classes['tensorflowTracer:bfc_chunks_stats'].add_field(uint64_fd, 'free_chunks')


event_classes['tensorflowTracer:bfc_bins_stats'] = btw.EventClass('tensorflowTracer:bfc_bins_stats')
event_classes['tensorflowTracer:bfc_bins_stats'].add_field(string_fd, 'allocator_name')
event_classes['tensorflowTracer:bfc_bins_stats'].add_field(uint64_fd, 'bin_numero')
event_classes['tensorflowTracer:bfc_bins_stats'].add_field(uint64_fd, 'total_chunks_in_bin')
event_classes['tensorflowTracer:bfc_bins_stats'].add_field(uint64_fd, 'total_chunks_in_use')
event_classes['tensorflowTracer:bfc_bins_stats'].add_field(uint64_fd, 'total_bytes_in_bin')
event_classes['tensorflowTracer:bfc_bins_stats'].add_field(uint64_fd, 'total_bytes_in_use')
event_classes['tensorflowTracer:bfc_bins_stats'].add_field(uint64_fd, 'total_requested_bytes_in_use')

event_classes['tensorflowTracer:memory_allocate'] = btw.EventClass('tensorflowTracer:memory_allocate')
event_classes['tensorflowTracer:memory_allocate'].add_field(string_fd, 'device')
event_classes['tensorflowTracer:memory_allocate'].add_field(string_fd, 'ptr')
event_classes['tensorflowTracer:memory_allocate'].add_field(uint64_fd, 'bytes')

event_classes['tensorflowTracer:memory_deallocate'] = btw.EventClass('tensorflowTracer:memory_deallocate')
event_classes['tensorflowTracer:memory_deallocate'].add_field(string_fd, 'device')
event_classes['tensorflowTracer:memory_deallocate'].add_field(string_fd, 'ptr')
event_classes['tensorflowTracer:memory_deallocate'].add_field(uint64_fd, 'bytes')

event_classes['lttng_python:event'] = btw.EventClass('lttng_python:event')
event_classes['lttng_python:event'].add_field(string_fd, 'asctime')
event_classes['lttng_python:event'].add_field(string_fd, 'msg')
event_classes['lttng_python:event'].add_field(string_fd, 'logger_name')
event_classes['lttng_python:event'].add_field(string_fd, 'funcName')
event_classes['lttng_python:event'].add_field(uint32_fd, 'lineno')
event_classes['lttng_python:event'].add_field(uint32_fd, 'int_loglevel')
event_classes['lttng_python:event'].add_field(uint64_fd, 'thread')
event_classes['lttng_python:event'].add_field(string_fd, 'threadName')


# cudaTracer
event_classes['cudaTracer:runtime_api_entry'] = btw.EventClass('cudaTracer:runtime_api_entry')
event_classes['cudaTracer:runtime_api_entry'].add_field(string_fd, 'cat')
event_classes['cudaTracer:runtime_api_entry'].add_field(string_fd, 'name')
event_classes['cudaTracer:runtime_api_entry'].add_field(uint64_fd, 'timestamp')
event_classes['cudaTracer:runtime_api_entry'].add_field(uint64_fd, 'threadId')

event_classes['cudaTracer:runtime_api_exit'] = btw.EventClass('cudaTracer:runtime_api_exit')
event_classes['cudaTracer:runtime_api_exit'].add_field(string_fd, 'cat')
event_classes['cudaTracer:runtime_api_exit'].add_field(string_fd, 'name')
event_classes['cudaTracer:runtime_api_exit'].add_field(uint64_fd, 'timestamp')
event_classes['cudaTracer:runtime_api_exit'].add_field(uint64_fd, 'threadId')

event_classes['cudaTracer:driver_api_entry'] = btw.EventClass('cudaTracer:driver_api_entry')
event_classes['cudaTracer:driver_api_entry'].add_field(string_fd, 'cat')
event_classes['cudaTracer:driver_api_entry'].add_field(string_fd, 'name')
event_classes['cudaTracer:driver_api_entry'].add_field(uint64_fd, 'timestamp')
event_classes['cudaTracer:driver_api_entry'].add_field(uint64_fd, 'threadId')

event_classes['cudaTracer:driver_api_exit'] = btw.EventClass('cudaTracer:driver_api_exit')
event_classes['cudaTracer:driver_api_exit'].add_field(string_fd, 'cat')
event_classes['cudaTracer:driver_api_exit'].add_field(string_fd, 'name')
event_classes['cudaTracer:driver_api_exit'].add_field(uint64_fd, 'timestamp')
event_classes['cudaTracer:driver_api_exit'].add_field(uint64_fd, 'threadId')

event_classes['cudaTracer:kernel_begin'] = btw.EventClass('cudaTracer:kernel_begin')
event_classes['cudaTracer:kernel_begin'].add_field(string_fd, 'cat')
event_classes['cudaTracer:kernel_begin'].add_field(string_fd, 'name')
event_classes['cudaTracer:kernel_begin'].add_field(uint64_fd, 'timestamp')

event_classes['cudaTracer:kernel_end'] = btw.EventClass('cudaTracer:kernel_end')
event_classes['cudaTracer:kernel_end'].add_field(string_fd, 'cat')
event_classes['cudaTracer:kernel_end'].add_field(string_fd, 'name')
event_classes['cudaTracer:kernel_end'].add_field(uint64_fd, 'timestamp')

event_classes['cudaTracer:kernel_queued'] = btw.EventClass('cudaTracer:kernel_queued')
event_classes['cudaTracer:kernel_queued'].add_field(string_fd, 'cat')
event_classes['cudaTracer:kernel_queued'].add_field(string_fd, 'name')
event_classes['cudaTracer:kernel_queued'].add_field(uint64_fd, 'timestamp')

event_classes['cudaTracer:memcpy_begin'] = btw.EventClass('cudaTracer:memcpy_begin')
event_classes['cudaTracer:memcpy_begin'].add_field(string_fd, 'cat')
event_classes['cudaTracer:memcpy_begin'].add_field(string_fd, 'name')
event_classes['cudaTracer:memcpy_begin'].add_field(string_fd, 'details')
event_classes['cudaTracer:memcpy_begin'].add_field(uint64_fd, 'timestamp')

event_classes['cudaTracer:memcpy_end'] = btw.EventClass('cudaTracer:memcpy_end')
event_classes['cudaTracer:memcpy_end'].add_field(string_fd, 'cat')
event_classes['cudaTracer:memcpy_end'].add_field(string_fd, 'name')
event_classes['cudaTracer:memcpy_end'].add_field(string_fd, 'details')
event_classes['cudaTracer:memcpy_end'].add_field(uint64_fd, 'timestamp')
