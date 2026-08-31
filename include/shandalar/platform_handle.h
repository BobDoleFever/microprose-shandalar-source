/*
 * shandalar/platform_handle.h - Type-Tagged 32-bit Handle Manager
 *
 * Provides safe, type-validated 32-bit integer IDs for all Win32 handles
 * (HWND, HDC, HGDIOBJ, HBITMAP, HPALETTE, HBRUSH, HPEN, HFONT, HRGN,
 * HMENU, HICON, HCURSOR, HACCEL, HANDLE for files/mappings/threads/etc.)
 * to ensure 100% 64-bit safety when stored in 32-bit recovered game structs.
 */
#ifndef SHANDALAR_PLATFORM_HANDLE_H
#define SHANDALAR_PLATFORM_HANDLE_H

#include "windows_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum HandleType {
    HANDLE_TYPE_NONE        = 0,
    HANDLE_TYPE_HWND        = 1,
    HANDLE_TYPE_HDC         = 2,
    HANDLE_TYPE_HBITMAP     = 3,
    HANDLE_TYPE_HPALETTE    = 4,
    HANDLE_TYPE_HFONT       = 5,
    HANDLE_TYPE_HPEN        = 6,
    HANDLE_TYPE_HBRUSH      = 7,
    HANDLE_TYPE_HRGN        = 8,
    HANDLE_TYPE_HICON       = 9,
    HANDLE_TYPE_HCURSOR     = 10,
    HANDLE_TYPE_HMENU       = 11,
    HANDLE_TYPE_HACCEL      = 12,
    HANDLE_TYPE_FILE        = 13,
    HANDLE_TYPE_MAPPING     = 14,
    HANDLE_TYPE_THREAD      = 15,
    HANDLE_TYPE_EVENT       = 16,
    HANDLE_TYPE_TIMER       = 17,
    HANDLE_TYPE_MODULE      = 18,
    HANDLE_TYPE_GLOBAL_MEM  = 19,
    HANDLE_TYPE_MMIO        = 20,
    HANDLE_TYPE_AVIFILE     = 21,
    HANDLE_TYPE_AVISTREAM   = 22,
    HANDLE_TYPE_DRAWDIB     = 23,
    HANDLE_TYPE_IC          = 24,
    HANDLE_TYPE_MCIWND      = 25,
    /* Special pseudo-type mask for any GDI object (DeleteObject, GetObjectA, SelectObject) */
    HANDLE_TYPE_ANY_GDI     = 0x7FFF
} HandleType;

typedef void (*HandleDestructor)(void *object_ptr);

/* Initialize the handle subsystem (thread-safe) */
void Platform_HandleInit(void);

/* Clean up the entire handle subsystem and free all allocated objects */
void Platform_HandleShutdown(void);

/*
 * Allocate a new 32-bit handle of the given type, associating it with object_ptr.
 * Returns a typed handle (e.g. HWND, HDC, HANDLE) or NULL / 0 on allocation failure.
 */
HANDLE Platform_AllocHandle(HandleType type, void *object_ptr, HandleDestructor dtor);

/*
 * Look up the object pointer for a handle, validating that its type matches expected_type.
 * If expected_type is HANDLE_TYPE_ANY_GDI, allows HBITMAP, HPALETTE, HFONT, HPEN, HBRUSH, HRGN.
 * Returns NULL if the handle is invalid or the type does not match.
 */
void* Platform_ResolveHandle(HANDLE handle, HandleType expected_type);

/*
 * Check if handle is valid and matches expected_type without returning object pointer.
 */
BOOL Platform_ValidateHandle(HANDLE handle, HandleType expected_type);

/*
 * Retrieve the actual type of an active handle. Returns HANDLE_TYPE_NONE if invalid.
 */
HandleType Platform_GetHandleType(HANDLE handle);

/*
 * Destroy and free a handle and invoke its destructor callback on object_ptr.
 * Returns TRUE on success, FALSE if handle is invalid or type mismatched.
 */
BOOL Platform_FreeHandle(HANDLE handle, HandleType expected_type);

/*
 * Mark a handle as a permanent stock object so Platform_FreeHandle will not destroy it.
 */
void Platform_SetHandleStock(HANDLE handle, BOOL is_stock);

/*
 * Check if a handle is marked as a stock object.
 */
BOOL Platform_IsHandleStock(HANDLE handle);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_PLATFORM_HANDLE_H */
