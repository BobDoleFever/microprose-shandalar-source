/*
 * shandalar/api_manifest.h - Win32 Compatibility API Manifest & Diagnostics
 */
#ifndef SHANDALAR_API_MANIFEST_H
#define SHANDALAR_API_MANIFEST_H

#include "windows_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum ApiSubsystem {
    API_SUB_USER        = 1,
    API_SUB_GDI         = 2,
    API_SUB_KERNEL      = 3,
    API_SUB_CONFIG      = 4,
    API_SUB_MULTIMEDIA  = 5,
    API_SUB_CRT         = 6
} ApiSubsystem;

typedef struct ApiEntry {
    const char   *name;
    ApiSubsystem  subsystem;
    int           caller_count;
    const char   *owning_binaries;
    bool          is_implemented;
} ApiEntry;

/* Total count of registered Win32 compatibility APIs */
#define SHANDALAR_API_MANIFEST_COUNT 358

/* Retrieve the complete manifest table */
const ApiEntry* Platform_GetApiManifest(size_t *out_count);

/* Find entry by API name */
const ApiEntry* Platform_FindApiEntry(const char *name);

/* Diagnostic trace: logs call to unsupported or stubbed API once */
void Platform_TraceApi(const char *api_name, const char *caller_context);

/* Enable / disable verbose API tracing */
void Platform_SetApiTraceEnabled(bool enabled);
bool Platform_IsApiTraceEnabled(void);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_API_MANIFEST_H */
