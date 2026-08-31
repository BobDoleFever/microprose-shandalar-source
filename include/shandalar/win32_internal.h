/*
 * shandalar/win32_internal.h - Internal data structures and helpers for Win32 compatibility layer
 */
#ifndef SHANDALAR_WIN32_INTERNAL_H
#define SHANDALAR_WIN32_INTERNAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>
#include <SDL.h>

#include "windows_types.h"
#include "shandalar/platform_handle.h"
#include "shandalar/api_manifest.h"
#include "shandalar/display_shim.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Logical Window Structure
 */
typedef struct LogicalWindow {
    HWND            hwnd;
    char            class_name[64];
    WNDPROC         wndproc;
    HWND            parent;
    HWND            first_child;
    HWND            next_sibling;
    HWND            prev_sibling;
    HWND            owner;

    RECT            rect;          /* Window rect in screen/parent coordinates */
    RECT            client_rect;   /* Client rect (0, 0, width, height) */
    DWORD           style;
    DWORD           ex_style;
    int             id;
    char            text[256];
    bool            is_visible;
    bool            is_enabled;
    LONG_PTR        user_data;
    uint8_t         extra_bytes[128];

    /* Dialog specific */
    bool            is_dialog;
    INT_PTR         dialog_result;
    DLGPROC         dlgproc;

    /* Scrollbars */
    int             scroll_h_pos, scroll_h_min, scroll_h_max;
    int             scroll_v_pos, scroll_v_min, scroll_v_max;

    /* Button / Check state */
    int             check_state;

    /* Invalidation / Repaint */
    RECT            update_rect;
    bool            needs_paint;

    /* Dedicated 8-bit framebuffer backbuffer if window DC */
    uint8_t        *surface_pixels;
    int             surface_pitch;
} LogicalWindow;

/*
 * Window Class Registration Structure
 */
typedef struct LogicalWindowClass {
    char            class_name[64];
    WNDPROC         wndproc;
    UINT            style;
    int             cbClsExtra;
    int             cbWndExtra;
    HINSTANCE       hInstance;
    HICON           hIcon;
    HCURSOR         hCursor;
    HBRUSH          hbrBackground;
    char            menu_name[64];
} LogicalWindowClass;

/*
 * GDI Structures
 */
typedef struct GdiBitmap {
    HBITMAP          hbmp;
    int              width;
    int              height;
    int              bpp;
    int              pitch;
    uint8_t         *bits;
    bool             owns_bits;
    bool             is_dib;
    bool             is_top_down;
    BITMAPINFOHEADER header;
    RGBQUAD          colors[256];
    UINT             color_count;
} GdiBitmap;

typedef struct GdiPalette {
    HPALETTE         hpal;
    UINT             count;
    PALETTEENTRY     entries[256];
} GdiPalette;

typedef struct GdiPen {
    HPEN             hpen;
    UINT             style;
    int              width;
    COLORREF         color;
} GdiPen;

typedef struct GdiBrush {
    HBRUSH           hbrush;
    UINT             style;
    COLORREF         color;
    ULONG_PTR        hatch;
    HBITMAP          pattern;
} GdiBrush;

typedef struct GdiFont {
    HFONT            hfont;
    LOGFONTA         logfont;
} GdiFont;

typedef struct GdiRegion {
    HRGN             hrgn;
    RECT             rect;
    bool             is_null;
} GdiRegion;

typedef struct GdiDC {
    HDC              hdc;
    bool             is_memory_dc;
    HWND             hwnd;            /* Target window if window DC */
    uint8_t         *pixels;          /* Target surface pixel buffer */
    int              width;
    int              height;
    int              pitch;

    HBITMAP          selected_bitmap;
    HBRUSH           selected_brush;
    HPEN             selected_pen;
    HFONT            selected_font;
    HPALETTE         selected_palette;
    HRGN             selected_region;

    RECT             clip_rect;
    int              bk_mode;         /* OPAQUE / TRANSPARENT */
    COLORREF         bk_color;
    COLORREF         text_color;
    UINT             text_align;
    int              rop2;
    int              map_mode;
    POINT            view_org;
    POINT            win_org;
    POINT            current_pos;

    struct GdiDC    *saved_state;     /* Stack for SaveDC / RestoreDC */
} GdiDC;

/*
 * Menu Item Structure
 */
typedef struct LogicalMenuItem {
    UINT             id;
    char             text[128];
    UINT             flags;
    HMENU            submenu;
    bool             is_separator;
    bool             is_checked;
    bool             is_enabled;
} LogicalMenuItem;

typedef struct LogicalMenu {
    HMENU            hmenu;
    LogicalMenuItem *items;
    size_t           item_count;
    size_t           item_capacity;
} LogicalMenu;

/*
 * Accelerator Table Structure
 */
typedef struct LogicalAccelTable {
    HACCEL           haccel;
    ACCEL           *accels;
    int              count;
} LogicalAccelTable;

/*
 * File / Mapping Structures
 */
typedef struct Win32File {
    HANDLE           hfile;
    FILE            *fp;
    int              fd;
    char             path[512];
    DWORD            access;
    DWORD            share;
    DWORD            disposition;
} Win32File;

typedef struct Win32Mapping {
    HANDLE           hmap;
    HANDLE           hfile;
    DWORD            protect;
    DWORD            max_size_low;
    DWORD            max_size_high;
    size_t           size;
    void            *mapped_data;
} Win32Mapping;

typedef struct Win32Thread {
    HANDLE           hthread;
    SDL_Thread      *sdl_thread;
    void            *start_addr;
    void            *param;
    DWORD            thread_id;
    DWORD            exit_code;
    bool             is_finished;
} Win32Thread;

/*
 * Internal subsystem hooks
 */
LogicalWindow* User_GetWindow(HWND hwnd);
LogicalWindowClass* User_FindClass(const char *name);
void User_InternalInit(void);
void User_InternalShutdown(void);
HWND User_GetActiveWindowInternal(void);
HWND User_GetFocusInternal(void);
HWND User_GetCaptureInternal(void);

void Message_InternalInit(void);
void Message_InternalShutdown(void);
void Message_PostPaint(HWND hwnd);
void Message_DispatchTimers(void);

GdiDC* Gdi_GetDC(HDC hdc);
void Gdi_InternalInit(void);
void Gdi_InternalShutdown(void);
void Gdi_PresentWindow(HWND hwnd);

void Kernel_InternalInit(void);
void Kernel_InternalShutdown(void);

void Config_InternalInit(void);
void Config_InternalShutdown(void);

void Multimedia_InternalInit(void);
void Multimedia_InternalShutdown(void);

/* Shared path resolver helper */
const char* Platform_ResolveAssetPath(const char *rel_or_abs_path);
void Platform_NormalizePath(char *path);
void Platform_SetAssetRoot(const char *root_path);
const char* Platform_GetAssetRoot(void);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_WIN32_INTERNAL_H */
