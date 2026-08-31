/*
 * src/platform/platform_handle.c - Type-Tagged 32-bit Handle Manager Implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>

#include "shandalar/platform_handle.h"

#define INITIAL_HANDLE_CAPACITY 2048
#define MAX_HANDLE_CAPACITY     65536

typedef struct HandleEntry {
    HandleType       type;
    void            *ptr;
    HandleDestructor dtor;
    uint32_t         generation;
    bool             in_use;
    bool             is_stock;
} HandleEntry;

static struct {
    HandleEntry     *entries;
    size_t           capacity;
    size_t           count;
    size_t           next_free_index;
    pthread_mutex_t  lock;
    bool             is_initialized;
} g_HandleTable = {0};

static bool IsGdiType(HandleType t)
{
    return (t == HANDLE_TYPE_HBITMAP ||
            t == HANDLE_TYPE_HPALETTE ||
            t == HANDLE_TYPE_HFONT ||
            t == HANDLE_TYPE_HPEN ||
            t == HANDLE_TYPE_HBRUSH ||
            t == HANDLE_TYPE_HRGN);
}

void Platform_HandleInit(void)
{
    if (g_HandleTable.is_initialized) return;

    pthread_mutex_init(&g_HandleTable.lock, NULL);
    pthread_mutex_lock(&g_HandleTable.lock);

    g_HandleTable.capacity = INITIAL_HANDLE_CAPACITY;
    g_HandleTable.entries = (HandleEntry *)calloc(g_HandleTable.capacity, sizeof(HandleEntry));
    g_HandleTable.count = 0;
    g_HandleTable.next_free_index = 0;
    g_HandleTable.is_initialized = true;

    pthread_mutex_unlock(&g_HandleTable.lock);
}

void Platform_HandleShutdown(void)
{
    if (!g_HandleTable.is_initialized) return;

    pthread_mutex_lock(&g_HandleTable.lock);
    for (size_t i = 0; i < g_HandleTable.capacity; i++) {
        if (g_HandleTable.entries[i].in_use) {
            if (g_HandleTable.entries[i].dtor && g_HandleTable.entries[i].ptr) {
                g_HandleTable.entries[i].dtor(g_HandleTable.entries[i].ptr);
            }
            g_HandleTable.entries[i].in_use = false;
            g_HandleTable.entries[i].ptr = NULL;
        }
    }
    free(g_HandleTable.entries);
    g_HandleTable.entries = NULL;
    g_HandleTable.capacity = 0;
    g_HandleTable.count = 0;
    g_HandleTable.is_initialized = false;
    pthread_mutex_unlock(&g_HandleTable.lock);
    pthread_mutex_destroy(&g_HandleTable.lock);
}

static bool EnsureCapacity_Locked(void)
{
    if (g_HandleTable.count < g_HandleTable.capacity) {
        return true;
    }

    size_t new_cap = g_HandleTable.capacity * 2;
    if (new_cap > MAX_HANDLE_CAPACITY) return false;

    HandleEntry *new_entries = (HandleEntry *)realloc(g_HandleTable.entries, new_cap * sizeof(HandleEntry));
    if (!new_entries) return false;

    memset(&new_entries[g_HandleTable.capacity], 0, (new_cap - g_HandleTable.capacity) * sizeof(HandleEntry));
    g_HandleTable.entries = new_entries;
    g_HandleTable.capacity = new_cap;
    return true;
}

HANDLE Platform_AllocHandle(HandleType type, void *object_ptr, HandleDestructor dtor)
{
    if (!g_HandleTable.is_initialized) {
        Platform_HandleInit();
    }

    pthread_mutex_lock(&g_HandleTable.lock);

    if (!EnsureCapacity_Locked()) {
        pthread_mutex_unlock(&g_HandleTable.lock);
        return NULL;
    }

    size_t index = g_HandleTable.next_free_index;
    size_t checked = 0;

    while (checked < g_HandleTable.capacity) {
        if (!g_HandleTable.entries[index].in_use) {
            break;
        }
        index = (index + 1) % g_HandleTable.capacity;
        checked++;
    }

    if (checked >= g_HandleTable.capacity) {
        pthread_mutex_unlock(&g_HandleTable.lock);
        return NULL;
    }

    g_HandleTable.entries[index].type = type;
    g_HandleTable.entries[index].ptr = object_ptr;
    g_HandleTable.entries[index].dtor = dtor;
    g_HandleTable.entries[index].generation++;
    g_HandleTable.entries[index].in_use = true;
    g_HandleTable.entries[index].is_stock = false;
    g_HandleTable.count++;
    g_HandleTable.next_free_index = (index + 1) % g_HandleTable.capacity;

    uint32_t handle_id = (uint32_t)(index + 1);
    pthread_mutex_unlock(&g_HandleTable.lock);

    return (HANDLE)(uintptr_t)handle_id;
}

static size_t HandleToIndex(HANDLE handle)
{
    uintptr_t val = (uintptr_t)handle;
    if (val == 0 || val == (uintptr_t)-1 || val > g_HandleTable.capacity) {
        return (size_t)-1;
    }
    return (size_t)(val - 1);
}

void* Platform_ResolveHandle(HANDLE handle, HandleType expected_type)
{
    if (!g_HandleTable.is_initialized || !handle || handle == INVALID_HANDLE_VALUE) {
        return NULL;
    }

    pthread_mutex_lock(&g_HandleTable.lock);

    size_t idx = HandleToIndex(handle);
    if (idx == (size_t)-1 || !g_HandleTable.entries[idx].in_use) {
        pthread_mutex_unlock(&g_HandleTable.lock);
        return NULL;
    }

    HandleType actual_type = g_HandleTable.entries[idx].type;
    bool match = (expected_type == HANDLE_TYPE_NONE) ||
                 (expected_type == actual_type) ||
                 (expected_type == HANDLE_TYPE_ANY_GDI && IsGdiType(actual_type));

    void *ptr = match ? g_HandleTable.entries[idx].ptr : NULL;

    pthread_mutex_unlock(&g_HandleTable.lock);
    return ptr;
}

BOOL Platform_ValidateHandle(HANDLE handle, HandleType expected_type)
{
    return Platform_ResolveHandle(handle, expected_type) != NULL;
}

HandleType Platform_GetHandleType(HANDLE handle)
{
    if (!g_HandleTable.is_initialized || !handle || handle == INVALID_HANDLE_VALUE) {
        return HANDLE_TYPE_NONE;
    }

    pthread_mutex_lock(&g_HandleTable.lock);
    size_t idx = HandleToIndex(handle);
    HandleType t = (idx != (size_t)-1 && g_HandleTable.entries[idx].in_use) ?
                   g_HandleTable.entries[idx].type : HANDLE_TYPE_NONE;
    pthread_mutex_unlock(&g_HandleTable.lock);
    return t;
}

BOOL Platform_FreeHandle(HANDLE handle, HandleType expected_type)
{
    if (!g_HandleTable.is_initialized || !handle || handle == INVALID_HANDLE_VALUE) {
        return FALSE;
    }

    pthread_mutex_lock(&g_HandleTable.lock);

    size_t idx = HandleToIndex(handle);
    if (idx == (size_t)-1 || !g_HandleTable.entries[idx].in_use) {
        pthread_mutex_unlock(&g_HandleTable.lock);
        return FALSE;
    }

    HandleType actual_type = g_HandleTable.entries[idx].type;
    bool match = (expected_type == HANDLE_TYPE_NONE) ||
                 (expected_type == actual_type) ||
                 (expected_type == HANDLE_TYPE_ANY_GDI && IsGdiType(actual_type));

    if (!match) {
        pthread_mutex_unlock(&g_HandleTable.lock);
        return FALSE;
    }

    /* Do not delete stock objects */
    if (g_HandleTable.entries[idx].is_stock) {
        pthread_mutex_unlock(&g_HandleTable.lock);
        return TRUE;
    }

    void *ptr = g_HandleTable.entries[idx].ptr;
    HandleDestructor dtor = g_HandleTable.entries[idx].dtor;

    g_HandleTable.entries[idx].in_use = false;
    g_HandleTable.entries[idx].ptr = NULL;
    g_HandleTable.entries[idx].dtor = NULL;
    g_HandleTable.entries[idx].type = HANDLE_TYPE_NONE;
    g_HandleTable.count--;

    pthread_mutex_unlock(&g_HandleTable.lock);

    if (dtor && ptr) {
        dtor(ptr);
    }

    return TRUE;
}

void Platform_SetHandleStock(HANDLE handle, BOOL is_stock)
{
    if (!g_HandleTable.is_initialized || !handle) return;

    pthread_mutex_lock(&g_HandleTable.lock);
    size_t idx = HandleToIndex(handle);
    if (idx != (size_t)-1 && g_HandleTable.entries[idx].in_use) {
        g_HandleTable.entries[idx].is_stock = is_stock ? true : false;
    }
    pthread_mutex_unlock(&g_HandleTable.lock);
}

BOOL Platform_IsHandleStock(HANDLE handle)
{
    if (!g_HandleTable.is_initialized || !handle) return FALSE;

    pthread_mutex_lock(&g_HandleTable.lock);
    size_t idx = HandleToIndex(handle);
    BOOL is_stock = (idx != (size_t)-1 && g_HandleTable.entries[idx].in_use && g_HandleTable.entries[idx].is_stock);
    pthread_mutex_unlock(&g_HandleTable.lock);
    return is_stock;
}
