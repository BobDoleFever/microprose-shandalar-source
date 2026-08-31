/*
 * src/platform/win32_config.c - Win32 Configuration (INI Profiles, Registry Emulation, Path Policy)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

#include "windows_types.h"
#include "shandalar/platform_handle.h"
#include "shandalar/win32_internal.h"
#include "shandalar/win32_compat.h"

#define MAX_REG_KEYS 128
#define MAX_REG_VALS 256

typedef struct RegValue {
    char     name[64];
    DWORD    type;
    uint8_t  data[256];
    DWORD    size;
} RegValue;

typedef struct RegKeyNode {
    char     path[256];
    RegValue values[16];
    size_t   value_count;
} RegKeyNode;

static struct {
    RegKeyNode      keys[MAX_REG_KEYS];
    size_t          key_count;
    char            asset_root[512];
    pthread_mutex_t lock;
    bool            is_initialized;
} g_CfgState = {0};

void Config_InternalInit(void)
{
    if (g_CfgState.is_initialized) return;

    pthread_mutex_init(&g_CfgState.lock, NULL);
    pthread_mutex_lock(&g_CfgState.lock);

    g_CfgState.key_count = 0;
    const char *env_root = getenv("SHANDALAR_DATA_DIR");
    if (env_root && strlen(env_root) > 0) {
        strncpy(g_CfgState.asset_root, env_root, sizeof(g_CfgState.asset_root) - 1);
    } else {
        /* Default to current working directory or known location */
        strncpy(g_CfgState.asset_root, ".", sizeof(g_CfgState.asset_root) - 1);
    }

    g_CfgState.is_initialized = true;
    pthread_mutex_unlock(&g_CfgState.lock);
}

void Config_InternalShutdown(void)
{
    if (!g_CfgState.is_initialized) return;
    pthread_mutex_destroy(&g_CfgState.lock);
    g_CfgState.is_initialized = false;
}

void Platform_SetAssetRoot(const char *root_path)
{
    Config_InternalInit();
    pthread_mutex_lock(&g_CfgState.lock);
    if (root_path) {
        strncpy(g_CfgState.asset_root, root_path, sizeof(g_CfgState.asset_root) - 1);
    }
    pthread_mutex_unlock(&g_CfgState.lock);
}

const char* Platform_GetAssetRoot(void)
{
    Config_InternalInit();
    return g_CfgState.asset_root;
}

void Platform_NormalizePath(char *path)
{
    if (!path) return;
    for (size_t i = 0; path[i]; i++) {
        if (path[i] == '\\') path[i] = '/';
    }
}

/*
 * Case-insensitive file lookup for case-sensitive filesystems
 */
static bool FindCaseInsensitive(const char *dir_path, const char *target_filename, char *out_path, size_t out_size)
{
    DIR *d = opendir(dir_path);
    if (!d) return false;

    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        if (strcasecmp(entry->d_name, target_filename) == 0) {
            snprintf(out_path, out_size, "%s/%s", dir_path, entry->d_name);
            closedir(d);
            return true;
        }
    }

    closedir(d);
    return false;
}

const char* Platform_ResolveAssetPath(const char *rel_or_abs_path)
{
    Config_InternalInit();
    if (!rel_or_abs_path) return "";

    static __thread char s_Resolved[1024];
    char normalized[1024];
    strncpy(normalized, rel_or_abs_path, sizeof(normalized) - 1);
    normalized[sizeof(normalized) - 1] = '\0';
    Platform_NormalizePath(normalized);

    /* 1. If path directly exists, return it */
    struct stat st;
    if (stat(normalized, &st) == 0) {
        strncpy(s_Resolved, normalized, sizeof(s_Resolved) - 1);
        return s_Resolved;
    }

    /* 2. Check within configured asset root */
    char candidate[1024];
    snprintf(candidate, sizeof(candidate), "%s/%s", g_CfgState.asset_root, normalized);
    if (stat(candidate, &st) == 0) {
        strncpy(s_Resolved, candidate, sizeof(s_Resolved) - 1);
        return s_Resolved;
    }

    /* 3. Try case-insensitive lookup in current directory and asset root */
    char *last_slash = strrchr(normalized, '/');
    const char *dir = ".";
    const char *fname = normalized;
    if (last_slash) {
        *last_slash = '\0';
        dir = normalized;
        fname = last_slash + 1;
    }

    if (FindCaseInsensitive(dir, fname, s_Resolved, sizeof(s_Resolved))) {
        return s_Resolved;
    }

    char root_dir[1024];
    snprintf(root_dir, sizeof(root_dir), "%s/%s", g_CfgState.asset_root, dir);
    if (FindCaseInsensitive(root_dir, fname, s_Resolved, sizeof(s_Resolved))) {
        return s_Resolved;
    }

    /* Fallback: return normalized path */
    strncpy(s_Resolved, normalized, sizeof(s_Resolved) - 1);
    return s_Resolved;
}

/* ==========================================================================
 * INI Profile Operations
 * ========================================================================== */

static void TrimWhitespace(char *str)
{
    if (!str) return;
    char *end;
    while (isspace((unsigned char)*str)) str++;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
}

UINT GetPrivateProfileIntA(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName)
{
    char buf[64];
    if (GetPrivateProfileStringA(lpAppName, lpKeyName, "", buf, sizeof(buf), lpFileName) == 0) {
        return (UINT)nDefault;
    }
    char *endptr;
    long val = strtol(buf, &endptr, 10);
    if (endptr == buf) return (UINT)nDefault;
    return (UINT)val;
}

DWORD GetPrivateProfileStringA(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault,
                              LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName)
{
    if (!lpReturnedString || nSize == 0) return 0;

    const char *def = lpDefault ? lpDefault : "";
    if (!lpFileName || !lpAppName || !lpKeyName) {
        strncpy(lpReturnedString, def, nSize - 1);
        lpReturnedString[nSize - 1] = '\0';
        return (DWORD)strlen(lpReturnedString);
    }

    const char *resolved = Platform_ResolveAssetPath(lpFileName);
    FILE *fp = fopen(resolved, "r");
    if (!fp) {
        strncpy(lpReturnedString, def, nSize - 1);
        lpReturnedString[nSize - 1] = '\0';
        return (DWORD)strlen(lpReturnedString);
    }

    char line[512];
    bool in_section = false;
    char section_header[128];
    snprintf(section_header, sizeof(section_header), "[%s]", lpAppName);

    while (fgets(line, sizeof(line), fp)) {
        TrimWhitespace(line);
        if (line[0] == ';' || line[0] == '#' || line[0] == '\0') continue;

        if (line[0] == '[') {
            in_section = (strcasecmp(line, section_header) == 0);
            continue;
        }

        if (in_section) {
            char *eq = strchr(line, '=');
            if (eq) {
                *eq = '\0';
                char *key = line;
                char *val = eq + 1;
                TrimWhitespace(key);
                TrimWhitespace(val);

                if (strcasecmp(key, lpKeyName) == 0) {
                    fclose(fp);
                    strncpy(lpReturnedString, val, nSize - 1);
                    lpReturnedString[nSize - 1] = '\0';
                    return (DWORD)strlen(lpReturnedString);
                }
            }
        }
    }

    fclose(fp);
    strncpy(lpReturnedString, def, nSize - 1);
    lpReturnedString[nSize - 1] = '\0';
    return (DWORD)strlen(lpReturnedString);
}

/* ==========================================================================
 * Registry Emulation
 * ========================================================================== */

LONG RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult)
{
    (void)hKey;
    (void)ulOptions;
    (void)samDesired;
    Config_InternalInit();

    if (!phkResult) return ERROR_INVALID_PARAMETER;
    *phkResult = (HKEY)(intptr_t)1;
    return ERROR_SUCCESS;
}

LONG RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass,
                     DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
                     PHKEY phkResult, LPDWORD lpdwDisposition)
{
    (void)hKey;
    (void)lpSubKey;
    (void)Reserved;
    (void)lpClass;
    (void)dwOptions;
    (void)samDesired;
    (void)lpSecurityAttributes;
    Config_InternalInit();

    if (lpdwDisposition) *lpdwDisposition = 1; /* REG_CREATED_NEW_KEY */
    if (phkResult) *phkResult = (HKEY)(intptr_t)1;
    return ERROR_SUCCESS;
}

LONG RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved,
                      LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
    (void)hKey;
    (void)lpReserved;
    Config_InternalInit();

    if (!lpValueName) return ERROR_INVALID_PARAMETER;

    pthread_mutex_lock(&g_CfgState.lock);
    for (size_t k = 0; k < g_CfgState.key_count; k++) {
        RegKeyNode *node = &g_CfgState.keys[k];
        for (size_t v = 0; v < node->value_count; v++) {
            if (strcasecmp(node->values[v].name, lpValueName) == 0) {
                if (lpType) *lpType = node->values[v].type;
                if (lpData && lpcbData) {
                    DWORD copy_sz = (*lpcbData < node->values[v].size) ? *lpcbData : node->values[v].size;
                    memcpy(lpData, node->values[v].data, copy_sz);
                }
                if (lpcbData) *lpcbData = node->values[v].size;
                pthread_mutex_unlock(&g_CfgState.lock);
                return ERROR_SUCCESS;
            }
        }
    }
    pthread_mutex_unlock(&g_CfgState.lock);

    return ERROR_FILE_NOT_FOUND;
}

LONG RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType,
                    const BYTE *lpData, DWORD cbData)
{
    (void)hKey;
    (void)Reserved;
    Config_InternalInit();

    if (!lpValueName || !lpData) return ERROR_INVALID_PARAMETER;

    pthread_mutex_lock(&g_CfgState.lock);

    RegKeyNode *node = (g_CfgState.key_count > 0) ? &g_CfgState.keys[0] : NULL;
    if (!node && g_CfgState.key_count < MAX_REG_KEYS) {
        node = &g_CfgState.keys[g_CfgState.key_count++];
        memset(node, 0, sizeof(*node));
    }

    if (node) {
        for (size_t i = 0; i < node->value_count; i++) {
            if (strcasecmp(node->values[i].name, lpValueName) == 0) {
                node->values[i].type = dwType;
                DWORD copy_sz = (cbData < sizeof(node->values[i].data)) ? cbData : (DWORD)sizeof(node->values[i].data);
                memcpy(node->values[i].data, lpData, copy_sz);
                node->values[i].size = copy_sz;
                pthread_mutex_unlock(&g_CfgState.lock);
                return ERROR_SUCCESS;
            }
        }

        if (node->value_count < 16) {
            size_t idx = node->value_count++;
            strncpy(node->values[idx].name, lpValueName, sizeof(node->values[idx].name) - 1);
            node->values[idx].type = dwType;
            DWORD copy_sz = (cbData < sizeof(node->values[idx].data)) ? cbData : (DWORD)sizeof(node->values[idx].data);
            memcpy(node->values[idx].data, lpData, copy_sz);
            node->values[idx].size = copy_sz;
        }
    }

    pthread_mutex_unlock(&g_CfgState.lock);
    return ERROR_SUCCESS;
}

LONG RegCloseKey(HKEY hKey)
{
    (void)hKey;
    return ERROR_SUCCESS;
}

LONG RegFlushKey(HKEY hKey)
{
    (void)hKey;
    return ERROR_SUCCESS;
}
