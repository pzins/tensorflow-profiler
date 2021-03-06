#include "util.h"

hsa_status_t hsa_init()
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_init");
  decltype(hsa_init) *orig = (decltype(hsa_init)*) dlsym(RTLD_NEXT, "hsa_init");
  hsa_status_t retval = orig();
  tracepoint(interceptionTracer, runtime_initialized, "queue_profiling");
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_init");
  return retval;
}

hsa_status_t hsa_shut_down()
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_shut_down");
  decltype(hsa_shut_down) *orig = (decltype(hsa_shut_down)*) dlsym(RTLD_NEXT, "hsa_shut_down");
  hsa_status_t retval = orig();
  tracepoint(interceptionTracer, runtime_shut_down, "queue_profiling");
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_shut_down");
  return retval;
}

// hsa_status_t hsa_system_get_info(hsa_system_info_t attribute, void *value)
// {
//   tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_system_get_info");
//   decltype(hsa_system_get_info) *orig = (decltype(hsa_system_get_info)*) dlsym(RTLD_NEXT, "hsa_system_get_info");
//   hsa_status_t retval = orig(attribute, value);
//   tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_system_get_info");
//   return retval;
// }




hsa_status_t hsa_extension_get_name(uint16_t extension, const char** name)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_extension_get_name");
  decltype(hsa_extension_get_name) *orig = (decltype(hsa_extension_get_name)*) dlsym(RTLD_NEXT, "hsa_extension_get_name");
  hsa_status_t retval = orig(extension, name);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_extension_get_name");
  return retval;
}

hsa_status_t hsa_system_extension_supported(uint16_t extension, uint16_t version_major,
                                                      uint16_t version_minor, bool* result)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_system_extension_supported");
  decltype(hsa_system_extension_supported) *orig = (decltype(hsa_system_extension_supported)*) dlsym(RTLD_NEXT, "hsa_system_extension_supported");
  hsa_status_t retval = orig(extension, version_major, version_minor, result);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_system_extension_supported");
  return retval;
}

hsa_status_t hsa_system_major_extension_supported(uint16_t extension,
                                                            uint16_t version_major,
                                                            uint16_t* version_minor, bool* result)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_system_major_extension_supported");
  decltype(hsa_system_major_extension_supported) *orig = (decltype(hsa_system_major_extension_supported)*) dlsym(RTLD_NEXT, "hsa_system_major_extension_supported");
  hsa_status_t retval = orig(extension, version_major, version_minor, result);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_system_major_extension_supported");
  return retval;
}

hsa_status_t hsa_system_get_extension_table(uint16_t extension, uint16_t version_major,
    uint16_t version_minor, void *table)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_system_get_extension_table");
  decltype(hsa_system_get_extension_table) *orig = (decltype(hsa_system_get_extension_table)*) dlsym(RTLD_NEXT, "hsa_system_get_extension_table");
  hsa_status_t retval = orig(extension, version_major, version_minor, table);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_system_get_extension_table");
  return retval;
}

hsa_status_t hsa_system_get_major_extension_table(uint16_t extension,
                                                            uint16_t version_major,
                                                            size_t table_length, void* table)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_system_get_major_extension_table");
  decltype(hsa_system_get_major_extension_table) *orig = (decltype(hsa_system_get_major_extension_table)*) dlsym(RTLD_NEXT, "hsa_system_get_major_extension_table");
  hsa_status_t retval = orig(extension, version_major, table_length, table);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_system_get_major_extension_table");
  return retval;
}

hsa_status_t hsa_iterate_agents(hsa_status_t (*callback)(hsa_agent_t agent, void *data),
    void *data)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_iterate_agents");
  decltype(hsa_iterate_agents) *orig = (decltype(hsa_iterate_agents)*) dlsym(RTLD_NEXT, "hsa_iterate_agents");
  hsa_status_t retval = orig(callback, data);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_iterate_agents");
  return retval;
}

hsa_status_t hsa_agent_get_info(hsa_agent_t agent,
    hsa_agent_info_t attribute,
    void *value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_agent_get_info");
  decltype(hsa_agent_get_info) *orig = (decltype(hsa_agent_get_info)*) dlsym(RTLD_NEXT, "hsa_agent_get_info");
  hsa_status_t retval = orig(agent, attribute, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_agent_get_info");
  return retval;
}

hsa_status_t hsa_agent_get_exception_policies(hsa_agent_t agent,
    hsa_profile_t profile,
    uint16_t *mask)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_agent_get_exception_policies");
  decltype(hsa_agent_get_exception_policies) *orig = (decltype(hsa_agent_get_exception_policies)*) dlsym(RTLD_NEXT, "hsa_agent_get_exception_policies");
  hsa_status_t retval = orig(agent, profile, mask);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_agent_get_exception_policies");
  return retval;
}

hsa_status_t hsa_cache_get_info(hsa_cache_t cache, hsa_cache_info_t attribute,
                                          void* value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_cache_get_info");
  decltype(hsa_cache_get_info) *orig = (decltype(hsa_cache_get_info)*) dlsym(RTLD_NEXT, "hsa_cache_get_info");
  hsa_status_t retval = orig(cache, attribute, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_cache_get_info");
  return retval;
}

hsa_status_t hsa_agent_iterate_caches(
      hsa_agent_t agent, hsa_status_t (*callback)(hsa_cache_t cache, void* data), void* value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_agent_iterate_caches");
  decltype(hsa_agent_iterate_caches) *orig = (decltype(hsa_agent_iterate_caches)*) dlsym(RTLD_NEXT, "hsa_agent_iterate_caches");
  hsa_status_t retval = orig(agent, callback, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_agent_iterate_caches");
  return retval;
}

hsa_status_t hsa_agent_extension_supported(uint16_t extension, hsa_agent_t agent,
    uint16_t version_major,
    uint16_t version_minor, bool *result)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_agent_extension_supported");
  decltype(hsa_agent_extension_supported) *orig = (decltype(hsa_agent_extension_supported)*) dlsym(RTLD_NEXT, "hsa_agent_extension_supported");
  hsa_status_t retval = orig(extension, agent, version_major, version_minor, result);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_agent_extension_supported");
  return retval;
}

hsa_status_t hsa_agent_major_extension_supported(uint16_t extension, hsa_agent_t agent,
                                                           uint16_t version_major,
                                                           uint16_t* version_minor, bool* result)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_agent_major_extension_supported");
  decltype(hsa_agent_major_extension_supported) *orig = (decltype(hsa_agent_major_extension_supported)*) dlsym(RTLD_NEXT, "hsa_agent_major_extension_supported");
  hsa_status_t retval = orig(extension, agent, version_major, version_minor, result);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_agent_major_extension_supported");
  return retval;
}

hsa_status_t hsa_queue_create(hsa_agent_t agent, uint32_t size, hsa_queue_type32_t type,
    void (*callback)(hsa_status_t status, hsa_queue_t *source,
    void *data),
    void *data, uint32_t private_segment_size,
    uint32_t group_segment_size, hsa_queue_t **queue)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_create");
  decltype(hsa_queue_create) *orig = (decltype(hsa_queue_create)*) dlsym(RTLD_NEXT, "hsa_queue_create");
  hsa_status_t retval = orig(agent, size, type, callback, data, private_segment_size, group_segment_size, queue);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_create");
  return retval;
}

hsa_status_t hsa_soft_queue_create(hsa_region_t region, uint32_t size,
    hsa_queue_type32_t type, uint32_t features,
    hsa_signal_t completion_signal, hsa_queue_t **queue)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_soft_queue_create");
  decltype(hsa_soft_queue_create) *orig = (decltype(hsa_soft_queue_create)*) dlsym(RTLD_NEXT, "hsa_soft_queue_create");
  hsa_status_t retval = orig(region, size, type, features, completion_signal, queue);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_soft_queue_create");
  return retval;
}

hsa_status_t hsa_queue_destroy(hsa_queue_t *queue)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_destroy");
  decltype(hsa_queue_destroy) *orig = (decltype(hsa_queue_destroy)*) dlsym(RTLD_NEXT, "hsa_queue_destroy");
  hsa_status_t retval = orig(queue);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_destroy");
  return retval;
}

hsa_status_t hsa_queue_inactivate(hsa_queue_t *queue)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_inactivate");
  decltype(hsa_queue_inactivate) *orig = (decltype(hsa_queue_inactivate)*) dlsym(RTLD_NEXT, "hsa_queue_inactivate");
  hsa_status_t retval = orig(queue);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_inactivate");
  return retval;
}

uint64_t hsa_queue_load_read_index_scacquire(const hsa_queue_t* queue)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_load_read_index_scacquire");
  decltype(hsa_queue_load_read_index_scacquire) *orig = (decltype(hsa_queue_load_read_index_scacquire)*) dlsym(RTLD_NEXT, "hsa_queue_load_read_index_scacquire");
  uint64_t retval = orig(queue);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_load_read_index_scacquire");
  return retval;
}

uint64_t hsa_queue_load_read_index_relaxed(const hsa_queue_t *queue)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_load_read_index_relaxed");
  decltype(hsa_queue_load_read_index_relaxed) *orig = (decltype(hsa_queue_load_read_index_relaxed)*) dlsym(RTLD_NEXT, "hsa_queue_load_read_index_relaxed");
  uint64_t retval = orig(queue);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_load_read_index_relaxed");
  return retval;
}

uint64_t hsa_queue_load_write_index_scacquire(const hsa_queue_t* queue)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_load_write_index_scacquire");
  decltype(hsa_queue_load_write_index_scacquire) *orig = (decltype(hsa_queue_load_write_index_scacquire)*) dlsym(RTLD_NEXT, "hsa_queue_load_write_index_scacquire");
  uint64_t retval = orig(queue);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_load_write_index_scacquire");
  return retval;
}

uint64_t hsa_queue_load_write_index_relaxed(const hsa_queue_t *queue)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_load_write_index_relaxed");
  decltype(hsa_queue_load_write_index_relaxed) *orig = (decltype(hsa_queue_load_write_index_relaxed)*) dlsym(RTLD_NEXT, "hsa_queue_load_write_index_relaxed");
  uint64_t retval = orig(queue);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_load_write_index_relaxed");
  return retval;
}

void hsa_queue_store_write_index_relaxed(const hsa_queue_t *queue,
    uint64_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_store_write_index_relaxed");
  decltype(hsa_queue_store_write_index_relaxed) *orig = (decltype(hsa_queue_store_write_index_relaxed)*) dlsym(RTLD_NEXT, "hsa_queue_store_write_index_relaxed");
  orig(queue, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_store_write_index_relaxed");
}

void hsa_queue_store_write_index_screlease(const hsa_queue_t* queue, uint64_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_store_write_index_screlease");
  decltype(hsa_queue_store_write_index_screlease) *orig = (decltype(hsa_queue_store_write_index_screlease)*) dlsym(RTLD_NEXT, "hsa_queue_store_write_index_screlease");
  orig(queue, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_store_write_index_screlease");
}

uint64_t hsa_queue_cas_write_index_scacq_screl(const hsa_queue_t* queue,
                                                         uint64_t expected, uint64_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_cas_write_index_scacq_screl");
  decltype(hsa_queue_cas_write_index_scacq_screl) *orig = (decltype(hsa_queue_cas_write_index_scacq_screl)*) dlsym(RTLD_NEXT, "hsa_queue_cas_write_index_scacq_screl");
  uint64_t retval = orig(queue, expected, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_cas_write_index_scacq_screl");
  return retval;
}

uint64_t hsa_queue_cas_write_index_scacquire(const hsa_queue_t* queue, uint64_t expected,
                                                       uint64_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_cas_write_index_scacquire");
  decltype(hsa_queue_cas_write_index_scacquire) *orig = (decltype(hsa_queue_cas_write_index_scacquire)*) dlsym(RTLD_NEXT, "hsa_queue_cas_write_index_scacquire");
  uint64_t retval = orig(queue, expected, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_cas_write_index_scacquire");
  return retval;
}

uint64_t hsa_queue_cas_write_index_relaxed(const hsa_queue_t *queue,
    uint64_t expected,
    uint64_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_cas_write_index_relaxed");
  decltype(hsa_queue_cas_write_index_relaxed) *orig = (decltype(hsa_queue_cas_write_index_relaxed)*) dlsym(RTLD_NEXT, "hsa_queue_cas_write_index_relaxed");
  uint64_t retval = orig(queue, expected, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_cas_write_index_relaxed");
  return retval;
}

uint64_t hsa_queue_cas_write_index_screlease(const hsa_queue_t* queue, uint64_t expected,
                                                       uint64_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_cas_write_index_screlease");
  decltype(hsa_queue_cas_write_index_screlease) *orig = (decltype(hsa_queue_cas_write_index_screlease)*) dlsym(RTLD_NEXT, "hsa_queue_cas_write_index_screlease");
  uint64_t retval = orig(queue, expected, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_cas_write_index_screlease");
  return retval;
}

uint64_t hsa_queue_add_write_index_scacq_screl(const hsa_queue_t* queue, uint64_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_add_write_index_scacq_screl");
  decltype(hsa_queue_add_write_index_scacq_screl) *orig = (decltype(hsa_queue_add_write_index_scacq_screl)*) dlsym(RTLD_NEXT, "hsa_queue_add_write_index_scacq_screl");
  uint64_t retval = orig(queue, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_add_write_index_scacq_screl");
  return retval;
}

uint64_t hsa_queue_add_write_index_scacquire(const hsa_queue_t* queue, uint64_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_add_write_index_scacquire");
  decltype(hsa_queue_add_write_index_scacquire) *orig = (decltype(hsa_queue_add_write_index_scacquire)*) dlsym(RTLD_NEXT, "hsa_queue_add_write_index_scacquire");
  uint64_t retval = orig(queue, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_add_write_index_scacquire");
  return retval;
}

uint64_t hsa_queue_add_write_index_relaxed(const hsa_queue_t *queue, uint64_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_add_write_index_relaxed");
  decltype(hsa_queue_add_write_index_relaxed) *orig = (decltype(hsa_queue_add_write_index_relaxed)*) dlsym(RTLD_NEXT, "hsa_queue_add_write_index_relaxed");
  uint64_t retval = orig(queue, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_add_write_index_relaxed");
  return retval;
}

uint64_t hsa_queue_add_write_index_screlease(const hsa_queue_t* queue, uint64_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_add_write_index_screlease");
  decltype(hsa_queue_add_write_index_screlease) *orig = (decltype(hsa_queue_add_write_index_screlease)*) dlsym(RTLD_NEXT, "hsa_queue_add_write_index_screlease");
  uint64_t retval = orig(queue, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_add_write_index_screlease");
  return retval;
}

void hsa_queue_store_read_index_relaxed(const hsa_queue_t *queue,
    uint64_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_store_read_index_relaxed");
  decltype(hsa_queue_store_read_index_relaxed) *orig = (decltype(hsa_queue_store_read_index_relaxed)*) dlsym(RTLD_NEXT, "hsa_queue_store_read_index_relaxed");
  orig(queue, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_store_read_index_relaxed");
}

void hsa_queue_store_read_index_screlease(const hsa_queue_t* queue, uint64_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_queue_store_read_index_screlease");
  decltype(hsa_queue_store_read_index_screlease) *orig = (decltype(hsa_queue_store_read_index_screlease)*) dlsym(RTLD_NEXT, "hsa_queue_store_read_index_screlease");
  orig(queue, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_queue_store_read_index_screlease");
}

hsa_status_t hsa_agent_iterate_regions(
    hsa_agent_t agent,
    hsa_status_t (*callback)(hsa_region_t region, void *data), void *data)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_agent_iterate_regions");
  decltype(hsa_agent_iterate_regions) *orig = (decltype(hsa_agent_iterate_regions)*) dlsym(RTLD_NEXT, "hsa_agent_iterate_regions");
  hsa_status_t retval = orig(agent, callback, data);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_agent_iterate_regions");
  return retval;
}

hsa_status_t hsa_region_get_info(hsa_region_t region,
    hsa_region_info_t attribute,
    void *value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_region_get_info");
  decltype(hsa_region_get_info) *orig = (decltype(hsa_region_get_info)*) dlsym(RTLD_NEXT, "hsa_region_get_info");
  hsa_status_t retval = orig(region, attribute, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_region_get_info");
  return retval;
}

hsa_status_t hsa_memory_register(void *address, size_t size)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_memory_register");
  decltype(hsa_memory_register) *orig = (decltype(hsa_memory_register)*) dlsym(RTLD_NEXT, "hsa_memory_register");
  hsa_status_t retval = orig(address, size);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_memory_register");
  return retval;
}

hsa_status_t hsa_memory_deregister(void *address, size_t size)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_memory_deregister");
  decltype(hsa_memory_deregister) *orig = (decltype(hsa_memory_deregister)*) dlsym(RTLD_NEXT, "hsa_memory_deregister");
  hsa_status_t retval = orig(address, size);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_memory_deregister");
  return retval;
}

hsa_status_t hsa_memory_allocate(hsa_region_t region, size_t size, void **ptr)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_memory_allocate");
  decltype(hsa_memory_allocate) *orig = (decltype(hsa_memory_allocate)*) dlsym(RTLD_NEXT, "hsa_memory_allocate");
  hsa_status_t retval = orig(region, size, ptr);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_memory_allocate");
  return retval;
}

hsa_status_t hsa_memory_free(void *ptr)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_memory_free");
  decltype(hsa_memory_free) *orig = (decltype(hsa_memory_free)*) dlsym(RTLD_NEXT, "hsa_memory_free");
  hsa_status_t retval = orig(ptr);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_memory_free");
  return retval;
}

hsa_status_t hsa_memory_copy(void *dst, const void *src, size_t size)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_memory_copy");
  decltype(hsa_memory_copy) *orig = (decltype(hsa_memory_copy)*) dlsym(RTLD_NEXT, "hsa_memory_copy");
  hsa_status_t retval = orig(dst, src, size);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_memory_copy");
  return retval;
}

hsa_status_t hsa_memory_assign_agent(void *ptr, hsa_agent_t agent,
    hsa_access_permission_t access)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_memory_assign_agent");
  decltype(hsa_memory_assign_agent) *orig = (decltype(hsa_memory_assign_agent)*) dlsym(RTLD_NEXT, "hsa_memory_assign_agent");
  hsa_status_t retval = orig(ptr, agent, access);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_memory_assign_agent");
  return retval;
}

hsa_status_t hsa_signal_create(hsa_signal_value_t initial_value, uint32_t num_consumers,
    const hsa_agent_t *consumers, hsa_signal_t *signal)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_create");
  decltype(hsa_signal_create) *orig = (decltype(hsa_signal_create)*) dlsym(RTLD_NEXT, "hsa_signal_create");
  hsa_status_t retval = orig(initial_value, num_consumers, consumers, signal);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_create");
  return retval;
}

hsa_status_t hsa_signal_destroy(hsa_signal_t signal)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_destroy");
  decltype(hsa_signal_destroy) *orig = (decltype(hsa_signal_destroy)*) dlsym(RTLD_NEXT, "hsa_signal_destroy");
  hsa_status_t retval = orig(signal);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_destroy");
  return retval;
}

hsa_signal_value_t hsa_signal_load_relaxed(hsa_signal_t signal)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_load_relaxed");
  decltype(hsa_signal_load_relaxed) *orig = (decltype(hsa_signal_load_relaxed)*) dlsym(RTLD_NEXT, "hsa_signal_load_relaxed");
  hsa_signal_value_t retval = orig(signal);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_load_relaxed");
  return retval;
}

hsa_signal_value_t hsa_signal_load_scacquire(hsa_signal_t signal)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_load_scacquire");
  decltype(hsa_signal_load_scacquire) *orig = (decltype(hsa_signal_load_scacquire)*) dlsym(RTLD_NEXT, "hsa_signal_load_scacquire");
  hsa_signal_value_t retval = orig(signal);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_load_scacquire");
  return retval;
}

void hsa_signal_store_relaxed(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_store_relaxed");
  decltype(hsa_signal_store_relaxed) *orig = (decltype(hsa_signal_store_relaxed)*) dlsym(RTLD_NEXT, "hsa_signal_store_relaxed");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_store_relaxed");
}

void hsa_signal_store_screlease(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_store_screlease");
  decltype(hsa_signal_store_screlease) *orig = (decltype(hsa_signal_store_screlease)*) dlsym(RTLD_NEXT, "hsa_signal_store_screlease");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_store_screlease");
}

void hsa_signal_silent_store_relaxed(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_silent_store_relaxed");
  decltype(hsa_signal_silent_store_relaxed) *orig = (decltype(hsa_signal_silent_store_relaxed)*) dlsym(RTLD_NEXT, "hsa_signal_silent_store_relaxed");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_silent_store_relaxed");
}

void hsa_signal_silent_store_screlease(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_silent_store_screlease");
  decltype(hsa_signal_silent_store_screlease) *orig = (decltype(hsa_signal_silent_store_screlease)*) dlsym(RTLD_NEXT, "hsa_signal_silent_store_screlease");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_silent_store_screlease");
}

hsa_signal_value_t hsa_signal_wait_relaxed(hsa_signal_t signal,
    hsa_signal_condition_t condition,
    hsa_signal_value_t compare_value,
    uint64_t timeout_hint,
    hsa_wait_state_t wait_expectancy_hint)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_wait_relaxed");
  decltype(hsa_signal_wait_relaxed) *orig = (decltype(hsa_signal_wait_relaxed)*) dlsym(RTLD_NEXT, "hsa_signal_wait_relaxed");
  hsa_signal_value_t retval = orig(signal, condition, compare_value, timeout_hint, wait_expectancy_hint);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_wait_relaxed");
  return retval;
}

hsa_signal_value_t hsa_signal_wait_scacquire(hsa_signal_t signal,
                                                       hsa_signal_condition_t condition,
                                                       hsa_signal_value_t compare_value,
                                                       uint64_t timeout_hint,
                                                       hsa_wait_state_t wait_expectancy_hint)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_wait_scacquire");
  decltype(hsa_signal_wait_scacquire) *orig = (decltype(hsa_signal_wait_scacquire)*) dlsym(RTLD_NEXT, "hsa_signal_wait_scacquire");
  hsa_signal_value_t retval = orig(signal, condition, compare_value, timeout_hint, wait_expectancy_hint);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_wait_scacquire");
  return retval;
}

hsa_status_t hsa_signal_group_create(uint32_t num_signals, const hsa_signal_t* signals,
                                               uint32_t num_consumers, const hsa_agent_t* consumers,
                                               hsa_signal_group_t* signal_group)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_group_create");
  decltype(hsa_signal_group_create) *orig = (decltype(hsa_signal_group_create)*) dlsym(RTLD_NEXT, "hsa_signal_group_create");
  hsa_status_t retval = orig(num_signals, signals, num_consumers, consumers, signal_group);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_group_create");
  return retval;
}

hsa_status_t hsa_signal_group_destroy(hsa_signal_group_t signal_group)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_group_destroy");
  decltype(hsa_signal_group_destroy) *orig = (decltype(hsa_signal_group_destroy)*) dlsym(RTLD_NEXT, "hsa_signal_group_destroy");
  hsa_status_t retval = orig(signal_group);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_group_destroy");
  return retval;
}

hsa_status_t hsa_signal_group_wait_any_scacquire(hsa_signal_group_t signal_group,
                                                           const hsa_signal_condition_t* conditions,
                                                           const hsa_signal_value_t* compare_values,
                                                           hsa_wait_state_t wait_state_hint,
                                                           hsa_signal_t* signal,
                                                           hsa_signal_value_t* value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_group_wait_any_scacquire");
  decltype(hsa_signal_group_wait_any_scacquire) *orig = (decltype(hsa_signal_group_wait_any_scacquire)*) dlsym(RTLD_NEXT, "hsa_signal_group_wait_any_scacquire");
  hsa_status_t retval = orig(signal_group, conditions, compare_values, wait_state_hint, signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_group_wait_any_scacquire");
  return retval;
}

hsa_status_t hsa_signal_group_wait_any_relaxed(hsa_signal_group_t signal_group,
                                                         const hsa_signal_condition_t* conditions,
                                                         const hsa_signal_value_t* compare_values,
                                                         hsa_wait_state_t wait_state_hint,
                                                         hsa_signal_t* signal,
                                                         hsa_signal_value_t* value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_group_wait_any_relaxed");
  decltype(hsa_signal_group_wait_any_relaxed) *orig = (decltype(hsa_signal_group_wait_any_relaxed)*) dlsym(RTLD_NEXT, "hsa_signal_group_wait_any_relaxed");
  hsa_status_t retval = orig(signal_group, conditions, compare_values, wait_state_hint, signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_group_wait_any_relaxed");
  return retval;
}
void hsa_signal_and_relaxed(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_and_relaxed");
  decltype(hsa_signal_and_relaxed) *orig = (decltype(hsa_signal_and_relaxed)*) dlsym(RTLD_NEXT, "hsa_signal_and_relaxed");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_and_relaxed");
}

void hsa_signal_and_scacquire(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_and_scacquire");
  decltype(hsa_signal_and_scacquire) *orig = (decltype(hsa_signal_and_scacquire)*) dlsym(RTLD_NEXT, "hsa_signal_and_scacquire");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_and_scacquire");
}

void hsa_signal_and_screlease(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_and_screlease");
  decltype(hsa_signal_and_screlease) *orig = (decltype(hsa_signal_and_screlease)*) dlsym(RTLD_NEXT, "hsa_signal_and_screlease");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_and_screlease");
}

void hsa_signal_and_scacq_screl(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_and_scacq_screl");
  decltype(hsa_signal_and_scacq_screl) *orig = (decltype(hsa_signal_and_scacq_screl)*) dlsym(RTLD_NEXT, "hsa_signal_and_scacq_screl");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_and_scacq_screl");
}

void hsa_signal_or_relaxed(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_or_relaxed");
  decltype(hsa_signal_or_relaxed) *orig = (decltype(hsa_signal_or_relaxed)*) dlsym(RTLD_NEXT, "hsa_signal_or_relaxed");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_or_relaxed");
}

void hsa_signal_or_scacquire(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_or_scacquire");
  decltype(hsa_signal_or_scacquire) *orig = (decltype(hsa_signal_or_scacquire)*) dlsym(RTLD_NEXT, "hsa_signal_or_scacquire");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_or_scacquire");
}

void hsa_signal_or_screlease(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_or_screlease");
  decltype(hsa_signal_or_screlease) *orig = (decltype(hsa_signal_or_screlease)*) dlsym(RTLD_NEXT, "hsa_signal_or_screlease");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_or_screlease");
}

void hsa_signal_or_scacq_screl(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_or_scacq_screl");
  decltype(hsa_signal_or_scacq_screl) *orig = (decltype(hsa_signal_or_scacq_screl)*) dlsym(RTLD_NEXT, "hsa_signal_or_scacq_screl");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_or_scacq_screl");
}

void hsa_signal_xor_relaxed(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_xor_relaxed");
  decltype(hsa_signal_xor_relaxed) *orig = (decltype(hsa_signal_xor_relaxed)*) dlsym(RTLD_NEXT, "hsa_signal_xor_relaxed");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_xor_relaxed");
}

void hsa_signal_xor_scacquire(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_xor_scacquire");
  decltype(hsa_signal_xor_scacquire) *orig = (decltype(hsa_signal_xor_scacquire)*) dlsym(RTLD_NEXT, "hsa_signal_xor_scacquire");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_xor_scacquire");
}

void hsa_signal_xor_screlease(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_xor_screlease");
  decltype(hsa_signal_xor_screlease) *orig = (decltype(hsa_signal_xor_screlease)*) dlsym(RTLD_NEXT, "hsa_signal_xor_screlease");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_xor_screlease");
}

void hsa_signal_xor_scacq_screl(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_xor_scacq_screl");
  decltype(hsa_signal_xor_scacq_screl) *orig = (decltype(hsa_signal_xor_scacq_screl)*) dlsym(RTLD_NEXT, "hsa_signal_xor_scacq_screl");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_xor_scacq_screl");
}

void hsa_signal_add_relaxed(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_add_relaxed");
  decltype(hsa_signal_add_relaxed) *orig = (decltype(hsa_signal_add_relaxed)*) dlsym(RTLD_NEXT, "hsa_signal_add_relaxed");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_add_relaxed");
}

void hsa_signal_add_scacquire(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_add_scacquire");
  decltype(hsa_signal_add_scacquire) *orig = (decltype(hsa_signal_add_scacquire)*) dlsym(RTLD_NEXT, "hsa_signal_add_scacquire");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_add_scacquire");
}

void hsa_signal_add_screlease(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_add_screlease");
  decltype(hsa_signal_add_screlease) *orig = (decltype(hsa_signal_add_screlease)*) dlsym(RTLD_NEXT, "hsa_signal_add_screlease");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_add_screlease");
}

void hsa_signal_add_scacq_screl(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_add_scacq_screl");
  decltype(hsa_signal_add_scacq_screl) *orig = (decltype(hsa_signal_add_scacq_screl)*) dlsym(RTLD_NEXT, "hsa_signal_add_scacq_screl");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_add_scacq_screl");
}

void hsa_signal_subtract_relaxed(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_subtract_relaxed");
  decltype(hsa_signal_subtract_relaxed) *orig = (decltype(hsa_signal_subtract_relaxed)*) dlsym(RTLD_NEXT, "hsa_signal_subtract_relaxed");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_subtract_relaxed");
}

void hsa_signal_subtract_scacquire(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_subtract_scacquire");
  decltype(hsa_signal_subtract_scacquire) *orig = (decltype(hsa_signal_subtract_scacquire)*) dlsym(RTLD_NEXT, "hsa_signal_subtract_scacquire");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_subtract_scacquire");
}

void hsa_signal_subtract_screlease(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_subtract_screlease");
  decltype(hsa_signal_subtract_screlease) *orig = (decltype(hsa_signal_subtract_screlease)*) dlsym(RTLD_NEXT, "hsa_signal_subtract_screlease");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_subtract_screlease");
}

void hsa_signal_subtract_scacq_screl(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_subtract_scacq_screl");
  decltype(hsa_signal_subtract_scacq_screl) *orig = (decltype(hsa_signal_subtract_scacq_screl)*) dlsym(RTLD_NEXT, "hsa_signal_subtract_scacq_screl");
  orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_subtract_scacq_screl");
}

hsa_signal_value_t hsa_signal_exchange_relaxed(hsa_signal_t signal, hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_exchange_relaxed");
  decltype(hsa_signal_exchange_relaxed) *orig = (decltype(hsa_signal_exchange_relaxed)*) dlsym(RTLD_NEXT, "hsa_signal_exchange_relaxed");
  hsa_signal_value_t retval = orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_exchange_relaxed");
  return retval;
}

hsa_signal_value_t hsa_signal_exchange_scacquire(hsa_signal_t signal,
                                                           hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_exchange_scacquire");
  decltype(hsa_signal_exchange_scacquire) *orig = (decltype(hsa_signal_exchange_scacquire)*) dlsym(RTLD_NEXT, "hsa_signal_exchange_scacquire");
  hsa_signal_value_t retval = orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_exchange_scacquire");
  return retval;
}

hsa_signal_value_t hsa_signal_exchange_screlease(hsa_signal_t signal,
                                                           hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_exchange_screlease");
  decltype(hsa_signal_exchange_screlease) *orig = (decltype(hsa_signal_exchange_screlease)*) dlsym(RTLD_NEXT, "hsa_signal_exchange_screlease");
  hsa_signal_value_t retval = orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_exchange_screlease");
  return retval;
}

hsa_signal_value_t hsa_signal_exchange_scacq_screl(hsa_signal_t signal,
                                                             hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_exchange_scacq_screl");
  decltype(hsa_signal_exchange_scacq_screl) *orig = (decltype(hsa_signal_exchange_scacq_screl)*) dlsym(RTLD_NEXT, "hsa_signal_exchange_scacq_screl");
  hsa_signal_value_t retval = orig(signal, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_exchange_scacq_screl");
  return retval;
}

hsa_signal_value_t hsa_signal_cas_relaxed(hsa_signal_t signal,
    hsa_signal_value_t expected,
    hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_cas_relaxed");
  decltype(hsa_signal_cas_relaxed) *orig = (decltype(hsa_signal_cas_relaxed)*) dlsym(RTLD_NEXT, "hsa_signal_cas_relaxed");
  hsa_signal_value_t retval = orig(signal, expected, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_cas_relaxed");
  return retval;
}

hsa_signal_value_t hsa_signal_cas_scacquire(hsa_signal_t signal,
                                                      hsa_signal_value_t expected,
                                                      hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_cas_scacquire");
  decltype(hsa_signal_cas_scacquire) *orig = (decltype(hsa_signal_cas_scacquire)*) dlsym(RTLD_NEXT, "hsa_signal_cas_scacquire");
  hsa_signal_value_t retval = orig(signal, expected, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_cas_scacquire");
  return retval;
}

hsa_signal_value_t hsa_signal_cas_screlease(hsa_signal_t signal,
                                                      hsa_signal_value_t expected,
                                                      hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_cas_screlease");
  decltype(hsa_signal_cas_screlease) *orig = (decltype(hsa_signal_cas_screlease)*) dlsym(RTLD_NEXT, "hsa_signal_cas_screlease");
  hsa_signal_value_t retval = orig(signal, expected, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_cas_screlease");
  return retval;
}

hsa_signal_value_t hsa_signal_cas_scacq_screl(hsa_signal_t signal,
                                                        hsa_signal_value_t expected,
                                                        hsa_signal_value_t value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_signal_cas_scacq_screl");
  decltype(hsa_signal_cas_scacq_screl) *orig = (decltype(hsa_signal_cas_scacq_screl)*) dlsym(RTLD_NEXT, "hsa_signal_cas_scacq_screl");
  hsa_signal_value_t retval = orig(signal, expected, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_signal_cas_scacq_screl");
  return retval;
}

hsa_status_t hsa_isa_from_name(
      const char *name,
      hsa_isa_t *isa)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_isa_from_name");
  decltype(hsa_isa_from_name) *orig = (decltype(hsa_isa_from_name)*) dlsym(RTLD_NEXT, "hsa_isa_from_name");
  hsa_status_t retval = orig(name, isa);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_isa_from_name");
  return retval;
}

hsa_status_t hsa_agent_iterate_isas(
      hsa_agent_t agent,
      hsa_status_t (*callback)(hsa_isa_t isa,
                               void *data),
      void *data)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_agent_iterate_isas");
  decltype(hsa_agent_iterate_isas) *orig = (decltype(hsa_agent_iterate_isas)*) dlsym(RTLD_NEXT, "hsa_agent_iterate_isas");
  hsa_status_t retval = orig(agent, callback, data);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_agent_iterate_isas");
  return retval;
}

hsa_status_t hsa_isa_get_info(
      hsa_isa_t isa,
      hsa_isa_info_t attribute,
      uint32_t index,
      void *value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_isa_get_info");
  decltype(hsa_isa_get_info) *orig = (decltype(hsa_isa_get_info)*) dlsym(RTLD_NEXT, "hsa_isa_get_info");
  hsa_status_t retval = orig(isa, attribute, index, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_isa_get_info");
  return retval;
}

hsa_status_t hsa_isa_get_info_alt(
      hsa_isa_t isa,
      hsa_isa_info_t attribute,
      void *value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_isa_get_info_alt");
  decltype(hsa_isa_get_info_alt) *orig = (decltype(hsa_isa_get_info_alt)*) dlsym(RTLD_NEXT, "hsa_isa_get_info_alt");
  hsa_status_t retval = orig(isa, attribute, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_isa_get_info_alt");
  return retval;
}

hsa_status_t hsa_isa_get_exception_policies(
      hsa_isa_t isa,
      hsa_profile_t profile,
      uint16_t *mask)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_isa_get_exception_policies");
  decltype(hsa_isa_get_exception_policies) *orig = (decltype(hsa_isa_get_exception_policies)*) dlsym(RTLD_NEXT, "hsa_isa_get_exception_policies");
  hsa_status_t retval = orig(isa, profile, mask);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_isa_get_exception_policies");
  return retval;
}

hsa_status_t hsa_isa_get_round_method(
      hsa_isa_t isa,
      hsa_fp_type_t fp_type,
      hsa_flush_mode_t flush_mode,
      hsa_round_method_t *round_method)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_isa_get_round_method");
  decltype(hsa_isa_get_round_method) *orig = (decltype(hsa_isa_get_round_method)*) dlsym(RTLD_NEXT, "hsa_isa_get_round_method");
  hsa_status_t retval = orig(isa, fp_type, flush_mode, round_method);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_isa_get_round_method");
  return retval;
}

hsa_status_t hsa_wavefront_get_info(
      hsa_wavefront_t wavefront,
      hsa_wavefront_info_t attribute,
      void *value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_wavefront_get_info");
  decltype(hsa_wavefront_get_info) *orig = (decltype(hsa_wavefront_get_info)*) dlsym(RTLD_NEXT, "hsa_wavefront_get_info");
  hsa_status_t retval = orig(wavefront, attribute, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_wavefront_get_info");
  return retval;
}

hsa_status_t hsa_isa_iterate_wavefronts(
      hsa_isa_t isa,
      hsa_status_t (*callback)(hsa_wavefront_t wavefront,
                               void *data),
      void *data)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_isa_iterate_wavefronts");
  decltype(hsa_isa_iterate_wavefronts) *orig = (decltype(hsa_isa_iterate_wavefronts)*) dlsym(RTLD_NEXT, "hsa_isa_iterate_wavefronts");
  hsa_status_t retval = orig(isa, callback, data);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_isa_iterate_wavefronts");
  return retval;
}

hsa_status_t hsa_isa_compatible(
      hsa_isa_t code_object_isa,
      hsa_isa_t agent_isa,
      bool *result)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_isa_compatible");
  decltype(hsa_isa_compatible) *orig = (decltype(hsa_isa_compatible)*) dlsym(RTLD_NEXT, "hsa_isa_compatible");
  hsa_status_t retval = orig(code_object_isa, agent_isa, result);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_isa_compatible");
  return retval;
}

hsa_status_t hsa_code_object_serialize(
      hsa_code_object_t code_object,
      hsa_status_t (*alloc_callback)(size_t size,
                                     hsa_callback_data_t data,
                                     void **address),
      hsa_callback_data_t callback_data,
      const char *options,
      void **serialized_code_object,
      size_t *serialized_code_object_size)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_code_object_serialize");
  decltype(hsa_code_object_serialize) *orig = (decltype(hsa_code_object_serialize)*) dlsym(RTLD_NEXT, "hsa_code_object_serialize");
  hsa_status_t retval = orig(code_object, alloc_callback, callback_data, options, serialized_code_object, serialized_code_object_size);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_code_object_serialize");
  return retval;
}

hsa_status_t hsa_code_object_deserialize(
      void *serialized_code_object,
      size_t serialized_code_object_size,
      const char *options,
      hsa_code_object_t *code_object)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_code_object_deserialize");
  decltype(hsa_code_object_deserialize) *orig = (decltype(hsa_code_object_deserialize)*) dlsym(RTLD_NEXT, "hsa_code_object_deserialize");
  hsa_status_t retval = orig(serialized_code_object, serialized_code_object_size, options, code_object);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_code_object_deserialize");
  return retval;
}

hsa_status_t hsa_code_object_destroy(
      hsa_code_object_t code_object)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_code_object_destroy");
  decltype(hsa_code_object_destroy) *orig = (decltype(hsa_code_object_destroy)*) dlsym(RTLD_NEXT, "hsa_code_object_destroy");
  hsa_status_t retval = orig(code_object);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_code_object_destroy");
  return retval;
}

hsa_status_t hsa_code_object_get_info(
      hsa_code_object_t code_object,
      hsa_code_object_info_t attribute,
      void *value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_code_object_get_info");
  decltype(hsa_code_object_get_info) *orig = (decltype(hsa_code_object_get_info)*) dlsym(RTLD_NEXT, "hsa_code_object_get_info");
  hsa_status_t retval = orig(code_object, attribute, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_code_object_get_info");
  return retval;
}

hsa_status_t hsa_code_object_get_symbol(
      hsa_code_object_t code_object,
      const char *symbol_name,
      hsa_code_symbol_t *symbol)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_code_object_get_symbol");
  decltype(hsa_code_object_get_symbol) *orig = (decltype(hsa_code_object_get_symbol)*) dlsym(RTLD_NEXT, "hsa_code_object_get_symbol");
  hsa_status_t retval = orig(code_object, symbol_name, symbol);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_code_object_get_symbol");
  return retval;
}

hsa_status_t hsa_code_object_get_symbol_from_name(
      hsa_code_object_t code_object,
      const char *module_name,
      const char *symbol_name,
      hsa_code_symbol_t *symbol)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_code_object_get_symbol_from_name");
  decltype(hsa_code_object_get_symbol_from_name) *orig = (decltype(hsa_code_object_get_symbol_from_name)*) dlsym(RTLD_NEXT, "hsa_code_object_get_symbol_from_name");
  hsa_status_t retval = orig(code_object, module_name, symbol_name, symbol);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_code_object_get_symbol_from_name");
  return retval;
}

hsa_status_t hsa_code_symbol_get_info(
      hsa_code_symbol_t code_symbol,
      hsa_code_symbol_info_t attribute,
      void *value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_code_symbol_get_info");
  decltype(hsa_code_symbol_get_info) *orig = (decltype(hsa_code_symbol_get_info)*) dlsym(RTLD_NEXT, "hsa_code_symbol_get_info");
  hsa_status_t retval = orig(code_symbol, attribute, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_code_symbol_get_info");
  return retval;
}

hsa_status_t hsa_code_object_iterate_symbols(
      hsa_code_object_t code_object,
      hsa_status_t (*callback)(hsa_code_object_t code_object,
                               hsa_code_symbol_t symbol,
                               void *data),
      void *data)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_code_object_iterate_symbols");
  decltype(hsa_code_object_iterate_symbols) *orig = (decltype(hsa_code_object_iterate_symbols)*) dlsym(RTLD_NEXT, "hsa_code_object_iterate_symbols");
  hsa_status_t retval = orig(code_object, callback, data);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_code_object_iterate_symbols");
  return retval;
}

hsa_status_t hsa_code_object_reader_create_from_file(
      hsa_file_t file,
      hsa_code_object_reader_t *code_object_reader)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_code_object_reader_create_from_file");
  decltype(hsa_code_object_reader_create_from_file) *orig = (decltype(hsa_code_object_reader_create_from_file)*) dlsym(RTLD_NEXT, "hsa_code_object_reader_create_from_file");
  hsa_status_t retval = orig(file, code_object_reader);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_code_object_reader_create_from_file");
  return retval;
}

hsa_status_t hsa_code_object_reader_create_from_memory(
      const void *code_object,
      size_t size,
      hsa_code_object_reader_t *code_object_reader)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_code_object_reader_create_from_memory");
  decltype(hsa_code_object_reader_create_from_memory) *orig = (decltype(hsa_code_object_reader_create_from_memory)*) dlsym(RTLD_NEXT, "hsa_code_object_reader_create_from_memory");
  hsa_status_t retval = orig(code_object, size, code_object_reader);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_code_object_reader_create_from_memory");
  return retval;
}

hsa_status_t hsa_code_object_reader_destroy(
      hsa_code_object_reader_t code_object_reader)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_code_object_reader_destroy");
  decltype(hsa_code_object_reader_destroy) *orig = (decltype(hsa_code_object_reader_destroy)*) dlsym(RTLD_NEXT, "hsa_code_object_reader_destroy");
  hsa_status_t retval = orig(code_object_reader);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_code_object_reader_destroy");
  return retval;
}

hsa_status_t hsa_executable_create(
      hsa_profile_t profile,
      hsa_executable_state_t executable_state,
      const char *options,
      hsa_executable_t *executable)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_create");
  decltype(hsa_executable_create) *orig = (decltype(hsa_executable_create)*) dlsym(RTLD_NEXT, "hsa_executable_create");
  hsa_status_t retval = orig(profile, executable_state, options, executable);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_create");
  return retval;
}

hsa_status_t hsa_executable_create_alt(
      hsa_profile_t profile,
      hsa_default_float_rounding_mode_t default_float_rounding_mode,
      const char *options,
      hsa_executable_t *executable)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_create_alt");
  decltype(hsa_executable_create_alt) *orig = (decltype(hsa_executable_create_alt)*) dlsym(RTLD_NEXT, "hsa_executable_create_alt");
  hsa_status_t retval = orig(profile, default_float_rounding_mode, options, executable);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_create_alt");
  return retval;
}

hsa_status_t hsa_executable_destroy(
      hsa_executable_t executable)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_destroy");
  decltype(hsa_executable_destroy) *orig = (decltype(hsa_executable_destroy)*) dlsym(RTLD_NEXT, "hsa_executable_destroy");
  hsa_status_t retval = orig(executable);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_destroy");
  return retval;
}

hsa_status_t hsa_executable_load_code_object(
      hsa_executable_t executable,
      hsa_agent_t agent,
      hsa_code_object_t code_object,
      const char *options)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_load_code_object");
  decltype(hsa_executable_load_code_object) *orig = (decltype(hsa_executable_load_code_object)*) dlsym(RTLD_NEXT, "hsa_executable_load_code_object");
  hsa_status_t retval = orig(executable, agent, code_object, options);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_load_code_object");
  return retval;
}

hsa_status_t hsa_executable_load_program_code_object(
      hsa_executable_t executable,
      hsa_code_object_reader_t code_object_reader,
      const char *options,
      hsa_loaded_code_object_t *loaded_code_object)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_load_program_code_object");
  decltype(hsa_executable_load_program_code_object) *orig = (decltype(hsa_executable_load_program_code_object)*) dlsym(RTLD_NEXT, "hsa_executable_load_program_code_object");
  hsa_status_t retval = orig(executable, code_object_reader, options, loaded_code_object);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_load_program_code_object");
  return retval;
}

hsa_status_t hsa_executable_load_agent_code_object(
      hsa_executable_t executable,
      hsa_agent_t agent,
      hsa_code_object_reader_t code_object_reader,
      const char *options,
      hsa_loaded_code_object_t *loaded_code_object)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_load_agent_code_object");
  decltype(hsa_executable_load_agent_code_object) *orig = (decltype(hsa_executable_load_agent_code_object)*) dlsym(RTLD_NEXT, "hsa_executable_load_agent_code_object");
  hsa_status_t retval = orig(executable, agent, code_object_reader, options, loaded_code_object);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_load_agent_code_object");
  return retval;
}

hsa_status_t hsa_executable_freeze(
      hsa_executable_t executable,
      const char *options)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_freeze");
  decltype(hsa_executable_freeze) *orig = (decltype(hsa_executable_freeze)*) dlsym(RTLD_NEXT, "hsa_executable_freeze");
  hsa_status_t retval = orig(executable, options);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_freeze");
  return retval;
}

hsa_status_t hsa_executable_get_info(
      hsa_executable_t executable,
      hsa_executable_info_t attribute,
      void *value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_get_info");
  decltype(hsa_executable_get_info) *orig = (decltype(hsa_executable_get_info)*) dlsym(RTLD_NEXT, "hsa_executable_get_info");
  hsa_status_t retval = orig(executable, attribute, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_get_info");
  return retval;
}

hsa_status_t hsa_executable_global_variable_define(
      hsa_executable_t executable,
      const char *variable_name,
      void *address)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_global_variable_define");
  decltype(hsa_executable_global_variable_define) *orig = (decltype(hsa_executable_global_variable_define)*) dlsym(RTLD_NEXT, "hsa_executable_global_variable_define");
  hsa_status_t retval = orig(executable, variable_name, address);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_global_variable_define");
  return retval;
}

hsa_status_t hsa_executable_agent_global_variable_define(
      hsa_executable_t executable,
      hsa_agent_t agent,
      const char *variable_name,
      void *address)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_agent_global_variable_define");
  decltype(hsa_executable_agent_global_variable_define) *orig = (decltype(hsa_executable_agent_global_variable_define)*) dlsym(RTLD_NEXT, "hsa_executable_agent_global_variable_define");
  hsa_status_t retval = orig(executable, agent, variable_name, address);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_agent_global_variable_define");
  return retval;
}

hsa_status_t hsa_executable_readonly_variable_define(
      hsa_executable_t executable,
      hsa_agent_t agent,
      const char *variable_name,
      void *address)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_readonly_variable_define");
  decltype(hsa_executable_readonly_variable_define) *orig = (decltype(hsa_executable_readonly_variable_define)*) dlsym(RTLD_NEXT, "hsa_executable_readonly_variable_define");
  hsa_status_t retval = orig(executable, agent, variable_name, address);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_readonly_variable_define");
  return retval;
}

hsa_status_t hsa_executable_validate(
      hsa_executable_t executable,
      uint32_t *result)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_validate");
  decltype(hsa_executable_validate) *orig = (decltype(hsa_executable_validate)*) dlsym(RTLD_NEXT, "hsa_executable_validate");
  hsa_status_t retval = orig(executable, result);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_validate");
  return retval;
}

hsa_status_t hsa_executable_validate_alt(
      hsa_executable_t executable,
      const char *options,
      uint32_t *result)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_validate_alt");
  decltype(hsa_executable_validate_alt) *orig = (decltype(hsa_executable_validate_alt)*) dlsym(RTLD_NEXT, "hsa_executable_validate_alt");
  hsa_status_t retval = orig(executable, options, result);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_validate_alt");
  return retval;
}

hsa_status_t hsa_executable_get_symbol(
      hsa_executable_t executable,
      const char *module_name,
      const char *symbol_name,
      hsa_agent_t agent,
      int32_t call_convention,
      hsa_executable_symbol_t *symbol)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_get_symbol");
  decltype(hsa_executable_get_symbol) *orig = (decltype(hsa_executable_get_symbol)*) dlsym(RTLD_NEXT, "hsa_executable_get_symbol");
  hsa_status_t retval = orig(executable, module_name, symbol_name, agent, call_convention, symbol);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_get_symbol");
  return retval;
}

hsa_status_t hsa_executable_get_symbol_by_name(
      hsa_executable_t executable,
      const char *symbol_name,
      const hsa_agent_t *agent,
      hsa_executable_symbol_t *symbol)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_get_symbol_by_name");
  decltype(hsa_executable_get_symbol_by_name) *orig = (decltype(hsa_executable_get_symbol_by_name)*) dlsym(RTLD_NEXT, "hsa_executable_get_symbol_by_name");
  hsa_status_t retval = orig(executable, symbol_name, agent, symbol);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_get_symbol_by_name");
  return retval;
}

hsa_status_t hsa_executable_symbol_get_info(
      hsa_executable_symbol_t executable_symbol,
      hsa_executable_symbol_info_t attribute,
      void *value)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_symbol_get_info");
  decltype(hsa_executable_symbol_get_info) *orig = (decltype(hsa_executable_symbol_get_info)*) dlsym(RTLD_NEXT, "hsa_executable_symbol_get_info");
  hsa_status_t retval = orig(executable_symbol, attribute, value);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_symbol_get_info");
  return retval;
}

hsa_status_t hsa_executable_iterate_symbols(
      hsa_executable_t executable,
      hsa_status_t (*callback)(hsa_executable_t executable,
                               hsa_executable_symbol_t symbol,
                               void *data),
      void *data)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_iterate_symbols");
  decltype(hsa_executable_iterate_symbols) *orig = (decltype(hsa_executable_iterate_symbols)*) dlsym(RTLD_NEXT, "hsa_executable_iterate_symbols");
  hsa_status_t retval = orig(executable, callback, data);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_iterate_symbols");
  return retval;
}

hsa_status_t hsa_executable_iterate_agent_symbols(
      hsa_executable_t executable,
      hsa_agent_t agent,
      hsa_status_t (*callback)(hsa_executable_t exec,
                               hsa_agent_t agent,
                               hsa_executable_symbol_t symbol,
                               void *data),
      void *data)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_iterate_agent_symbols");
  decltype(hsa_executable_iterate_agent_symbols) *orig = (decltype(hsa_executable_iterate_agent_symbols)*) dlsym(RTLD_NEXT, "hsa_executable_iterate_agent_symbols");
  hsa_status_t retval = orig(executable, agent, callback, data);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_iterate_agent_symbols");
  return retval;
}

hsa_status_t hsa_executable_iterate_program_symbols(
      hsa_executable_t executable,
      hsa_status_t (*callback)(hsa_executable_t exec,
                               hsa_executable_symbol_t symbol,
                               void *data),
      void *data)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_executable_iterate_program_symbols");
  decltype(hsa_executable_iterate_program_symbols) *orig = (decltype(hsa_executable_iterate_program_symbols)*) dlsym(RTLD_NEXT, "hsa_executable_iterate_program_symbols");
  hsa_status_t retval = orig(executable, callback, data);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_executable_iterate_program_symbols");
  return retval;
}

hsa_status_t hsa_status_string(
      hsa_status_t status,
      const char **status_string)
{
  tracepoint(interceptionTracer, function_entry, "hsa_api", "hsa_status_string");
  decltype(hsa_status_string) *orig = (decltype(hsa_status_string)*) dlsym(RTLD_NEXT, "hsa_status_string");
  hsa_status_t retval = orig(status, status_string);
  tracepoint(interceptionTracer, function_exit, "hsa_api", "hsa_status_string");
  return retval;
}