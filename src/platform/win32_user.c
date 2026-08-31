/*
 * src/platform/win32_user.c - Win32 User Subsystem (Window Tree, Classes, Controls, Menus, Dialogs)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#include <SDL.h>

#include "windows_types.h"
#include "shandalar/platform_handle.h"
#include "shandalar/win32_internal.h"
#include "shandalar/win32_compat.h"
#include "shandalar/display_shim.h"

#define MAX_WINDOW_CLASSES 64

static struct {
    LogicalWindowClass classes[MAX_WINDOW_CLASSES];
    size_t             class_count;
    HWND               active_window;
    HWND               focus_window;
    HWND               capture_window;
    HWND               desktop_window;
    POINT              cursor_pos;
    bool               cursor_visible;
    HCURSOR            current_cursor;
    bool               is_initialized;
    pthread_mutex_t    lock;
} g_UserState = {0};

/* Forward declaration */
extern LRESULT DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
extern LRESULT SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

static void WindowDestructor(void *ptr)
{
    LogicalWindow *w = (LogicalWindow *)ptr;
    if (!w) return;
    if (w->surface_pixels) {
        free(w->surface_pixels);
        w->surface_pixels = NULL;
    }
    free(w);
}

static void MenuDestructor(void *ptr)
{
    LogicalMenu *m = (LogicalMenu *)ptr;
    if (!m) return;
    if (m->items) {
        free(m->items);
        m->items = NULL;
    }
    free(m);
}

static void AccelDestructor(void *ptr)
{
    LogicalAccelTable *a = (LogicalAccelTable *)ptr;
    if (!a) return;
    if (a->accels) {
        free(a->accels);
        a->accels = NULL;
    }
    free(a);
}

void User_InternalInit(void)
{
    if (g_UserState.is_initialized) return;

    pthread_mutex_init(&g_UserState.lock, NULL);
    pthread_mutex_lock(&g_UserState.lock);

    g_UserState.class_count = 0;
    g_UserState.active_window = NULL;
    g_UserState.focus_window = NULL;
    g_UserState.capture_window = NULL;
    g_UserState.cursor_pos.x = 320;
    g_UserState.cursor_pos.y = 240;
    g_UserState.cursor_visible = true;
    g_UserState.current_cursor = NULL;
    g_UserState.is_initialized = true;

    pthread_mutex_unlock(&g_UserState.lock);

    /* Register standard built-in control classes */
    WNDCLASSA wc;
    memset(&wc, 0, sizeof(wc));
    wc.lpfnWndProc = DefWindowProcA;

    const char *builtin_classes[] = {
        "BUTTON", "STATIC", "EDIT", "LISTBOX", "COMBOBOX", "SCROLLBAR", "#32770"
    };

    for (size_t i = 0; i < sizeof(builtin_classes)/sizeof(builtin_classes[0]); i++) {
        wc.lpszClassName = builtin_classes[i];
        RegisterClassA(&wc);
    }
}

void User_InternalShutdown(void)
{
    if (!g_UserState.is_initialized) return;
    pthread_mutex_destroy(&g_UserState.lock);
    g_UserState.is_initialized = false;
}

LogicalWindow* User_GetWindow(HWND hwnd)
{
    return (LogicalWindow *)Platform_ResolveHandle(hwnd, HANDLE_TYPE_HWND);
}

LogicalWindowClass* User_FindClass(const char *name)
{
    if (!name) return NULL;
    pthread_mutex_lock(&g_UserState.lock);
    for (size_t i = 0; i < g_UserState.class_count; i++) {
        if (strcasecmp(g_UserState.classes[i].class_name, name) == 0) {
            pthread_mutex_unlock(&g_UserState.lock);
            return &g_UserState.classes[i];
        }
    }
    pthread_mutex_unlock(&g_UserState.lock);
    return NULL;
}

HWND User_GetActiveWindowInternal(void)
{
    return g_UserState.active_window;
}

HWND User_GetFocusInternal(void)
{
    return g_UserState.focus_window;
}

HWND User_GetCaptureInternal(void)
{
    return g_UserState.capture_window;
}

/* ==========================================================================
 * Window Class Registration
 * ========================================================================== */

ATOM RegisterClassA(const WNDCLASSA *lpWndClass)
{
    if (!lpWndClass || !lpWndClass->lpszClassName) return 0;
    User_InternalInit();

    pthread_mutex_lock(&g_UserState.lock);
    for (size_t i = 0; i < g_UserState.class_count; i++) {
        if (strcasecmp(g_UserState.classes[i].class_name, lpWndClass->lpszClassName) == 0) {
            /* Update existing */
            g_UserState.classes[i].wndproc = lpWndClass->lpfnWndProc ? (WNDPROC)lpWndClass->lpfnWndProc : DefWindowProcA;
            g_UserState.classes[i].style = lpWndClass->style;
            g_UserState.classes[i].cbClsExtra = lpWndClass->cbClsExtra;
            g_UserState.classes[i].cbWndExtra = lpWndClass->cbWndExtra;
            g_UserState.classes[i].hInstance = lpWndClass->hInstance;
            g_UserState.classes[i].hIcon = lpWndClass->hIcon;
            g_UserState.classes[i].hCursor = lpWndClass->hCursor;
            g_UserState.classes[i].hbrBackground = lpWndClass->hbrBackground;
            if (lpWndClass->lpszMenuName) {
                strncpy(g_UserState.classes[i].menu_name, lpWndClass->lpszMenuName, 63);
            }
            pthread_mutex_unlock(&g_UserState.lock);
            return (ATOM)(i + 1);
        }
    }

    if (g_UserState.class_count >= MAX_WINDOW_CLASSES) {
        pthread_mutex_unlock(&g_UserState.lock);
        return 0;
    }

    size_t idx = g_UserState.class_count++;
    LogicalWindowClass *c = &g_UserState.classes[idx];
    memset(c, 0, sizeof(*c));
    strncpy(c->class_name, lpWndClass->lpszClassName, 63);
    c->wndproc = lpWndClass->lpfnWndProc ? (WNDPROC)lpWndClass->lpfnWndProc : DefWindowProcA;
    c->style = lpWndClass->style;
    c->cbClsExtra = lpWndClass->cbClsExtra;
    c->cbWndExtra = lpWndClass->cbWndExtra;
    c->hInstance = lpWndClass->hInstance;
    c->hIcon = lpWndClass->hIcon;
    c->hCursor = lpWndClass->hCursor;
    c->hbrBackground = lpWndClass->hbrBackground;
    if (lpWndClass->lpszMenuName) {
        strncpy(c->menu_name, lpWndClass->lpszMenuName, 63);
    }

    pthread_mutex_unlock(&g_UserState.lock);
    return (ATOM)(idx + 1);
}

BOOL UnregisterClassA(LPCSTR lpClassName, HINSTANCE hInstance)
{
    (void)hInstance;
    if (!lpClassName) return FALSE;

    pthread_mutex_lock(&g_UserState.lock);
    for (size_t i = 0; i < g_UserState.class_count; i++) {
        if (strcasecmp(g_UserState.classes[i].class_name, lpClassName) == 0) {
            for (size_t j = i; j + 1 < g_UserState.class_count; j++) {
                g_UserState.classes[j] = g_UserState.classes[j + 1];
            }
            g_UserState.class_count--;
            pthread_mutex_unlock(&g_UserState.lock);
            return TRUE;
        }
    }
    pthread_mutex_unlock(&g_UserState.lock);
    return FALSE;
}

int GetClassNameA(HWND hWnd, LPSTR lpClassName, int nMaxCount)
{
    if (!lpClassName || nMaxCount <= 0) return 0;
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return 0;

    strncpy(lpClassName, w->class_name, nMaxCount - 1);
    lpClassName[nMaxCount - 1] = '\0';
    return (int)strlen(lpClassName);
}

DWORD SetClassLongA(HWND hWnd, int nIndex, LONG dwNewLong)
{
    (void)hWnd;
    (void)nIndex;
    (void)dwNewLong;
    return 0;
}

/* ==========================================================================
 * Window Lifecycle & Tree
 * ========================================================================== */

HWND CreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName,
                     DWORD dwStyle, int X, int Y, int nWidth, int nHeight,
                     HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
    (void)hInstance;
    (void)lpParam;
    User_InternalInit();

    LogicalWindow *w = (LogicalWindow *)calloc(1, sizeof(LogicalWindow));
    if (!w) return NULL;

    w->style = dwStyle;
    w->ex_style = dwExStyle;
    if (lpClassName) {
        strncpy(w->class_name, lpClassName, sizeof(w->class_name) - 1);
    }
    if (lpWindowName) {
        strncpy(w->text, lpWindowName, sizeof(w->text) - 1);
    }

    LogicalWindowClass *cls = User_FindClass(lpClassName);
    w->wndproc = cls ? cls->wndproc : DefWindowProcA;

    int wx = (X != (int)0x80000000) ? X : 0;
    int wy = (Y != (int)0x80000000) ? Y : 0;
    int ww = (nWidth > 0 && nWidth != (int)0x80000000) ? nWidth : 640;
    int wh = (nHeight > 0 && nHeight != (int)0x80000000) ? nHeight : 480;

    w->rect.left = wx;
    w->rect.top = wy;
    w->rect.right = wx + ww;
    w->rect.bottom = wy + wh;

    w->client_rect.left = 0;
    w->client_rect.top = 0;
    w->client_rect.right = ww;
    w->client_rect.bottom = wh;

    w->parent = hWndParent;
    w->id = (int)(intptr_t)hMenu;
    w->is_visible = (dwStyle & WS_VISIBLE) ? true : false;
    w->is_enabled = !(dwStyle & WS_DISABLED);

    /* Allocate surface framebuffer for the window */
    w->surface_pitch = ww;
    w->surface_pixels = (uint8_t *)calloc(1, (size_t)ww * (size_t)wh);

    HWND hwnd = (HWND)Platform_AllocHandle(HANDLE_TYPE_HWND, w, WindowDestructor);
    w->hwnd = hwnd;

    /* Link child into parent's hierarchy */
    if (hWndParent) {
        LogicalWindow *parent = User_GetWindow(hWndParent);
        if (parent) {
            if (!parent->first_child) {
                parent->first_child = hwnd;
            } else {
                HWND sib = parent->first_child;
                LogicalWindow *lsib = User_GetWindow(sib);
                while (lsib && lsib->next_sibling) {
                    sib = lsib->next_sibling;
                    lsib = User_GetWindow(sib);
                }
                if (lsib) {
                    lsib->next_sibling = hwnd;
                    w->prev_sibling = sib;
                }
            }
        }
    }

    /* Initialize SDL display on the first top-level window creation */
    if (!hWndParent) {
        DisplayConfig cfg;
        cfg.window_width = ww;
        cfg.window_height = wh;
        cfg.scale_factor = 2;
        cfg.fullscreen = false;
        cfg.vsync = true;
        cfg.window_title = lpWindowName ? lpWindowName : "Magic: The Gathering (Shandalar 1997)";
        Shandalar_DisplayInit(&cfg);
        g_UserState.active_window = hwnd;
        g_UserState.focus_window = hwnd;
    }

    /* Send WM_CREATE message */
    SendMessageA(hwnd, WM_CREATE, 0, 0);

    return hwnd;
}

BOOL DestroyWindow(HWND hWnd)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return FALSE;

    /* Send WM_DESTROY */
    SendMessageA(hWnd, WM_DESTROY, 0, 0);

    /* Recursively destroy children */
    HWND child = w->first_child;
    while (child) {
        LogicalWindow *c = User_GetWindow(child);
        HWND next = c ? c->next_sibling : NULL;
        DestroyWindow(child);
        child = next;
    }

    /* Unlink from parent */
    if (w->parent) {
        LogicalWindow *parent = User_GetWindow(w->parent);
        if (parent) {
            if (parent->first_child == hWnd) {
                parent->first_child = w->next_sibling;
            }
        }
    }
    if (w->prev_sibling) {
        LogicalWindow *prev = User_GetWindow(w->prev_sibling);
        if (prev) prev->next_sibling = w->next_sibling;
    }
    if (w->next_sibling) {
        LogicalWindow *next = User_GetWindow(w->next_sibling);
        if (next) next->prev_sibling = w->prev_sibling;
    }

    if (g_UserState.active_window == hWnd) g_UserState.active_window = NULL;
    if (g_UserState.focus_window == hWnd) g_UserState.focus_window = NULL;
    if (g_UserState.capture_window == hWnd) g_UserState.capture_window = NULL;

    SendMessageA(hWnd, WM_NCDESTROY, 0, 0);
    return Platform_FreeHandle(hWnd, HANDLE_TYPE_HWND);
}

BOOL ShowWindow(HWND hWnd, int nCmdShow)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return FALSE;

    BOOL was_visible = w->is_visible;
    w->is_visible = (nCmdShow != SW_HIDE);

    SendMessageA(hWnd, WM_SHOWWINDOW, (WPARAM)w->is_visible, 0);
    if (w->is_visible) {
        SendMessageA(hWnd, WM_PAINT, 0, 0);
    }
    return was_visible;
}

BOOL UpdateWindow(HWND hWnd)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w || !w->is_visible) return FALSE;

    SendMessageA(hWnd, WM_PAINT, 0, 0);
    return TRUE;
}

BOOL BringWindowToTop(HWND hWnd)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return FALSE;
    g_UserState.active_window = hWnd;
    return TRUE;
}

HWND FindWindowA(LPCSTR lpClassName, LPCSTR lpWindowName)
{
    (void)lpClassName;
    (void)lpWindowName;
    /* Return active top-level window if matched, or NULL */
    return g_UserState.active_window;
}

HWND FindWindowExA(HWND hWndParent, HWND hWndChildAfter, LPCSTR lpszClass, LPCSTR lpszWindow)
{
    (void)hWndChildAfter;
    (void)lpszClass;
    (void)lpszWindow;
    if (hWndParent) {
        LogicalWindow *p = User_GetWindow(hWndParent);
        if (p) return p->first_child;
    }
    return NULL;
}

HWND GetDesktopWindow(void)
{
    return g_UserState.desktop_window;
}

HWND WindowFromPoint(POINT Point)
{
    HWND active = g_UserState.active_window;
    if (!active) return NULL;

    LogicalWindow *top = User_GetWindow(active);
    if (!top || !top->is_visible) return NULL;

    /* Search child hierarchy */
    HWND child = top->first_child;
    while (child) {
        LogicalWindow *cw = User_GetWindow(child);
        if (cw && cw->is_visible && PtInRect(&cw->rect, Point)) {
            return child;
        }
        child = cw ? cw->next_sibling : NULL;
    }

    return active;
}

/* ==========================================================================
 * Geometry & Coordinates
 * ========================================================================== */

BOOL GetClientRect(HWND hWnd, LPRECT lpRect)
{
    if (!lpRect) return FALSE;
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) {
        lpRect->left = 0;
        lpRect->top = 0;
        lpRect->right = 640;
        lpRect->bottom = 480;
        return TRUE;
    }
    *lpRect = w->client_rect;
    return TRUE;
}

BOOL GetWindowRect(HWND hWnd, LPRECT lpRect)
{
    if (!lpRect) return FALSE;
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) {
        lpRect->left = 0;
        lpRect->top = 0;
        lpRect->right = 640;
        lpRect->bottom = 480;
        return TRUE;
    }
    *lpRect = w->rect;
    return TRUE;
}

BOOL ClientToScreen(HWND hWnd, LPPOINT lpPoint)
{
    if (!lpPoint) return FALSE;
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return FALSE;

    lpPoint->x += w->rect.left;
    lpPoint->y += w->rect.top;
    return TRUE;
}

BOOL ScreenToClient(HWND hWnd, LPPOINT lpPoint)
{
    if (!lpPoint) return FALSE;
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return FALSE;

    lpPoint->x -= w->rect.left;
    lpPoint->y -= w->rect.top;
    return TRUE;
}

int MapWindowPoints(HWND hWndFrom, HWND hWndTo, LPPOINT lpPoints, UINT cPoints)
{
    if (!lpPoints || cPoints == 0) return 0;
    int dx = 0, dy = 0;

    if (hWndFrom) {
        LogicalWindow *wf = User_GetWindow(hWndFrom);
        if (wf) {
            dx += wf->rect.left;
            dy += wf->rect.top;
        }
    }
    if (hWndTo) {
        LogicalWindow *wt = User_GetWindow(hWndTo);
        if (wt) {
            dx -= wt->rect.left;
            dy -= wt->rect.top;
        }
    }

    for (UINT i = 0; i < cPoints; i++) {
        lpPoints[i].x += dx;
        lpPoints[i].y += dy;
    }
    return (dy << 16) | (dx & 0xffff);
}

BOOL MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return FALSE;

    w->rect.left = X;
    w->rect.top = Y;
    w->rect.right = X + nWidth;
    w->rect.bottom = Y + nHeight;

    w->client_rect.left = 0;
    w->client_rect.top = 0;
    w->client_rect.right = nWidth;
    w->client_rect.bottom = nHeight;

    SendMessageA(hWnd, WM_MOVE, 0, (LPARAM)(((Y & 0xffff) << 16) | (X & 0xffff)));
    SendMessageA(hWnd, WM_SIZE, 0, (LPARAM)(((nHeight & 0xffff) << 16) | (nWidth & 0xffff)));

    if (bRepaint && w->is_visible) {
        SendMessageA(hWnd, WM_PAINT, 0, 0);
    }
    return TRUE;
}

BOOL SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags)
{
    (void)hWndInsertAfter;
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return FALSE;

    if (!(uFlags & SWP_NOMOVE)) {
        int w_w = w->rect.right - w->rect.left;
        int w_h = w->rect.bottom - w->rect.top;
        w->rect.left = X;
        w->rect.top = Y;
        w->rect.right = X + w_w;
        w->rect.bottom = Y + w_h;
    }

    if (!(uFlags & SWP_NOSIZE)) {
        w->rect.right = w->rect.left + cx;
        w->rect.bottom = w->rect.top + cy;
        w->client_rect.right = cx;
        w->client_rect.bottom = cy;
    }

    if (uFlags & SWP_SHOWWINDOW) {
        w->is_visible = true;
    } else if (uFlags & SWP_HIDEWINDOW) {
        w->is_visible = false;
    }

    if (!(uFlags & SWP_NOREDRAW) && w->is_visible) {
        SendMessageA(hWnd, WM_PAINT, 0, 0);
    }
    return TRUE;
}

BOOL AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu)
{
    (void)dwStyle;
    (void)bMenu;
    /* In our 640x480 direct framebuffer model, client equals window rect */
    return (lpRect != NULL);
}

HWND GetParent(HWND hWnd)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    return w ? w->parent : NULL;
}

HWND SetParent(HWND hWndChild, HWND hWndNewParent)
{
    LogicalWindow *w = User_GetWindow(hWndChild);
    if (!w) return NULL;
    HWND old = w->parent;
    w->parent = hWndNewParent;
    return old;
}

HWND GetTopWindow(HWND hWnd)
{
    if (!hWnd) return g_UserState.active_window;
    LogicalWindow *w = User_GetWindow(hWnd);
    return w ? w->first_child : NULL;
}

HWND GetWindow(HWND hWnd, UINT uCmd)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return NULL;

    switch (uCmd) {
        case 0: /* GW_HWNDFIRST */
            return w->parent ? User_GetWindow(w->parent)->first_child : g_UserState.active_window;
        case 1: /* GW_HWNDLAST */
            return hWnd;
        case 2: /* GW_HWNDNEXT */
            return w->next_sibling;
        case 3: /* GW_HWNDPREV */
            return w->prev_sibling;
        case 4: /* GW_OWNER */
            return w->owner;
        case 5: /* GW_CHILD */
            return w->first_child;
        default:
            return NULL;
    }
}

BOOL EnumChildWindows(HWND hWndParent, WNDENUMPROC lpEnumFunc, LPARAM lParam)
{
    if (!lpEnumFunc) return FALSE;
    LogicalWindow *p = User_GetWindow(hWndParent);
    if (!p) return FALSE;

    HWND child = p->first_child;
    while (child) {
        LogicalWindow *cw = User_GetWindow(child);
        if (!lpEnumFunc(child, lParam)) return FALSE;
        child = cw ? cw->next_sibling : NULL;
    }
    return TRUE;
}

/* ==========================================================================
 * Window Properties & User Data
 * ========================================================================== */

BOOL IsWindowVisible(HWND hWnd)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    return w ? (w->is_visible ? TRUE : FALSE) : FALSE;
}

BOOL IsIconic(HWND hWnd)
{
    (void)hWnd;
    return FALSE;
}

BOOL EnableWindow(HWND hWnd, BOOL bEnable)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return FALSE;
    BOOL prev = w->is_enabled;
    w->is_enabled = bEnable ? true : false;
    SendMessageA(hWnd, WM_ENABLE, (WPARAM)bEnable, 0);
    return prev;
}

BOOL IsWindowEnabled(HWND hWnd)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    return w ? (w->is_enabled ? TRUE : FALSE) : TRUE;
}

LONG GetWindowLongA(HWND hWnd, int nIndex)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return 0;

    switch (nIndex) {
        case GWL_WNDPROC:
            return (LONG)(intptr_t)w->wndproc;
        case GWL_STYLE:
            return (LONG)w->style;
        case GWL_EXSTYLE:
            return (LONG)w->ex_style;
        case GWL_USERDATA:
            return (LONG)w->user_data;
        case GWL_ID:
            return (LONG)w->id;
        case GWL_HWNDPARENT:
            return (LONG)(intptr_t)w->parent;
        default:
            if (nIndex >= 0 && nIndex + (int)sizeof(LONG) <= (int)sizeof(w->extra_bytes)) {
                LONG val = 0;
                memcpy(&val, &w->extra_bytes[nIndex], sizeof(LONG));
                return val;
            }
            return 0;
    }
}

LONG SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return 0;

    LONG prev = 0;
    switch (nIndex) {
        case GWL_WNDPROC:
            prev = (LONG)(intptr_t)w->wndproc;
            w->wndproc = (WNDPROC)(intptr_t)dwNewLong;
            return prev;
        case GWL_STYLE:
            prev = (LONG)w->style;
            w->style = (DWORD)dwNewLong;
            return prev;
        case GWL_EXSTYLE:
            prev = (LONG)w->ex_style;
            w->ex_style = (DWORD)dwNewLong;
            return prev;
        case GWL_USERDATA:
            prev = (LONG)w->user_data;
            w->user_data = (LONG_PTR)dwNewLong;
            return prev;
        case GWL_ID:
            prev = (LONG)w->id;
            w->id = (int)dwNewLong;
            return prev;
        case GWL_HWNDPARENT:
            prev = (LONG)(intptr_t)w->parent;
            w->parent = (HWND)(intptr_t)dwNewLong;
            return prev;
        default:
            if (nIndex >= 0 && nIndex + (int)sizeof(LONG) <= (int)sizeof(w->extra_bytes)) {
                memcpy(&prev, &w->extra_bytes[nIndex], sizeof(LONG));
                memcpy(&w->extra_bytes[nIndex], &dwNewLong, sizeof(LONG));
                return prev;
            }
            return 0;
    }
}

WORD GetWindowWord(HWND hWnd, int nIndex)
{
    return (WORD)GetWindowLongA(hWnd, nIndex);
}

WORD SetWindowWord(HWND hWnd, int nIndex, WORD wNewWord)
{
    return (WORD)SetWindowLongA(hWnd, nIndex, (LONG)wNewWord);
}

int GetWindowTextA(HWND hWnd, LPSTR lpString, int nMaxCount)
{
    if (!lpString || nMaxCount <= 0) return 0;
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) {
        lpString[0] = '\0';
        return 0;
    }
    strncpy(lpString, w->text, nMaxCount - 1);
    lpString[nMaxCount - 1] = '\0';
    return (int)strlen(lpString);
}

BOOL SetWindowTextA(HWND hWnd, LPCSTR lpString)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return FALSE;
    if (lpString) {
        strncpy(w->text, lpString, sizeof(w->text) - 1);
    } else {
        w->text[0] = '\0';
    }
    SendMessageA(hWnd, WM_SETTEXT, 0, (LPARAM)(intptr_t)lpString);
    return TRUE;
}

DWORD GetWindowThreadProcessId(HWND hWnd, DWORD *lpdwProcessId)
{
    (void)hWnd;
    if (lpdwProcessId) *lpdwProcessId = 1;
    return 1;
}

/* ==========================================================================
 * Focus, Activation & Capture
 * ========================================================================== */

HWND GetFocus(void)
{
    return g_UserState.focus_window;
}

HWND SetFocus(HWND hWnd)
{
    HWND prev = g_UserState.focus_window;
    if (prev != hWnd) {
        if (prev) SendMessageA(prev, WM_KILLFOCUS, (WPARAM)(uintptr_t)hWnd, 0);
        g_UserState.focus_window = hWnd;
        if (hWnd) SendMessageA(hWnd, WM_SETFOCUS, (WPARAM)(uintptr_t)prev, 0);
    }
    return prev;
}

HWND GetActiveWindow(void)
{
    return g_UserState.active_window;
}

HWND SetActiveWindow(HWND hWnd)
{
    HWND prev = g_UserState.active_window;
    if (prev != hWnd) {
        if (prev) SendMessageA(prev, WM_ACTIVATE, 0, (LPARAM)(intptr_t)hWnd);
        g_UserState.active_window = hWnd;
        if (hWnd) SendMessageA(hWnd, WM_ACTIVATE, 1, (LPARAM)(intptr_t)prev);
    }
    return prev;
}

BOOL SetForegroundWindow(HWND hWnd)
{
    SetActiveWindow(hWnd);
    SetFocus(hWnd);
    return TRUE;
}

HWND GetCapture(void)
{
    return g_UserState.capture_window;
}

HWND SetCapture(HWND hWnd)
{
    HWND prev = g_UserState.capture_window;
    g_UserState.capture_window = hWnd;
    return prev;
}

BOOL ReleaseCapture(void)
{
    g_UserState.capture_window = NULL;
    return TRUE;
}

/* ==========================================================================
 * Scrollbars
 * ========================================================================== */

int GetScrollPos(HWND hWnd, int nBar)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return 0;
    return (nBar == SB_VERT) ? w->scroll_v_pos : w->scroll_h_pos;
}

int SetScrollPos(HWND hWnd, int nBar, int nPos, BOOL bRedraw)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return 0;

    int prev = 0;
    if (nBar == SB_VERT) {
        prev = w->scroll_v_pos;
        w->scroll_v_pos = nPos;
    } else {
        prev = w->scroll_h_pos;
        w->scroll_h_pos = nPos;
    }

    if (bRedraw && w->is_visible) {
        SendMessageA(hWnd, WM_PAINT, 0, 0);
    }
    return prev;
}

BOOL GetScrollRange(HWND hWnd, int nBar, LPINT lpMinPos, LPINT lpMaxPos)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return FALSE;

    if (nBar == SB_VERT) {
        if (lpMinPos) *lpMinPos = w->scroll_v_min;
        if (lpMaxPos) *lpMaxPos = w->scroll_v_max;
    } else {
        if (lpMinPos) *lpMinPos = w->scroll_h_min;
        if (lpMaxPos) *lpMaxPos = w->scroll_h_max;
    }
    return TRUE;
}

BOOL SetScrollRange(HWND hWnd, int nBar, int nMinPos, int nMaxPos, BOOL bRedraw)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return FALSE;

    if (nBar == SB_VERT) {
        w->scroll_v_min = nMinPos;
        w->scroll_v_max = nMaxPos;
    } else {
        w->scroll_h_min = nMinPos;
        w->scroll_h_max = nMaxPos;
    }

    if (bRedraw && w->is_visible) {
        SendMessageA(hWnd, WM_PAINT, 0, 0);
    }
    return TRUE;
}

BOOL ScrollWindow(HWND hWnd, int XAmount, int YAmount, const RECT *lpRect, const RECT *lpClipRect)
{
    (void)XAmount;
    (void)YAmount;
    (void)lpRect;
    (void)lpClipRect;
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w || !w->is_visible) return FALSE;

    SendMessageA(hWnd, WM_PAINT, 0, 0);
    return TRUE;
}

/* ==========================================================================
 * Dialogs & Controls
 * ========================================================================== */

int GetDlgCtrlID(HWND hWnd)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    return w ? w->id : 0;
}

HWND GetDlgItem(HWND hDlg, int nIDDlgItem)
{
    LogicalWindow *p = User_GetWindow(hDlg);
    if (!p) return NULL;

    HWND child = p->first_child;
    while (child) {
        LogicalWindow *cw = User_GetWindow(child);
        if (cw && cw->id == nIDDlgItem) return child;
        child = cw ? cw->next_sibling : NULL;
    }
    return NULL;
}

UINT GetDlgItemInt(HWND hDlg, int nIDDlgItem, BOOL *lpTranslated, BOOL bSigned)
{
    char buf[64];
    if (GetDlgItemTextA(hDlg, nIDDlgItem, buf, sizeof(buf)) == 0) {
        if (lpTranslated) *lpTranslated = FALSE;
        return 0;
    }

    if (lpTranslated) *lpTranslated = TRUE;
    if (bSigned) {
        return (UINT)atoi(buf);
    } else {
        return (UINT)strtoul(buf, NULL, 10);
    }
}

UINT GetDlgItemTextA(HWND hDlg, int nIDDlgItem, LPSTR lpString, int nMaxCount)
{
    HWND item = GetDlgItem(hDlg, nIDDlgItem);
    if (!item) {
        if (lpString && nMaxCount > 0) lpString[0] = '\0';
        return 0;
    }
    return (UINT)GetWindowTextA(item, lpString, nMaxCount);
}

BOOL SetDlgItemInt(HWND hDlg, int nIDDlgItem, UINT uValue, BOOL bSigned)
{
    char buf[64];
    if (bSigned) {
        snprintf(buf, sizeof(buf), "%d", (int)uValue);
    } else {
        snprintf(buf, sizeof(buf), "%u", uValue);
    }
    return SetDlgItemTextA(hDlg, nIDDlgItem, buf);
}

BOOL SetDlgItemTextA(HWND hDlg, int nIDDlgItem, LPCSTR lpString)
{
    HWND item = GetDlgItem(hDlg, nIDDlgItem);
    if (!item) return FALSE;
    return SetWindowTextA(item, lpString);
}

LRESULT SendDlgItemMessageA(HWND hDlg, int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    HWND item = GetDlgItem(hDlg, nIDDlgItem);
    if (!item) return 0;
    return SendMessageA(item, Msg, wParam, lParam);
}

BOOL CheckDlgButton(HWND hDlg, int nIDButton, UINT uCheck)
{
    HWND item = GetDlgItem(hDlg, nIDButton);
    if (!item) return FALSE;
    LogicalWindow *w = User_GetWindow(item);
    if (w) {
        w->check_state = (int)uCheck;
        SendMessageA(item, WM_PAINT, 0, 0);
        return TRUE;
    }
    return FALSE;
}

UINT IsDlgButtonChecked(HWND hDlg, int nIDButton)
{
    HWND item = GetDlgItem(hDlg, nIDButton);
    if (!item) return 0;
    LogicalWindow *w = User_GetWindow(item);
    return w ? (UINT)w->check_state : 0;
}

BOOL CheckRadioButton(HWND hDlg, int nIDFirstButton, int nIDLastButton, int nIDCheckButton)
{
    for (int id = nIDFirstButton; id <= nIDLastButton; id++) {
        CheckDlgButton(hDlg, id, (id == nIDCheckButton) ? BST_CHECKED : BST_UNCHECKED);
    }
    return TRUE;
}

INT_PTR DialogBoxParamA(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent,
                        DLGPROC lpDialogFunc, LPARAM dwInitParam)
{
    (void)hInstance;
    (void)lpTemplateName;

    /* Create modal dialog window */
    HWND dlg = CreateWindowExA(WS_EX_DLGMODALFRAME, "#32770", "Dialog",
                               WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU,
                               100, 100, 440, 280, hWndParent, NULL, hInstance, NULL);
    if (!dlg) return -1;

    LogicalWindow *w = User_GetWindow(dlg);
    if (w) {
        w->is_dialog = true;
        w->dlgproc = lpDialogFunc;
    }

    if (lpDialogFunc) {
        lpDialogFunc(dlg, WM_INITDIALOG, (WPARAM)(uintptr_t)dlg, dwInitParam);
    }

    /* Modal loop - runs until EndDialog is called */
    tagMSG msg;
    extern BOOL GetMessageA(tagMSG *lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
    extern BOOL TranslateMessage(const tagMSG *lpMsg);
    extern LRESULT DispatchMessageA(const tagMSG *lpMsg);

    while (User_GetWindow(dlg) && GetMessageA(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
        if (!User_GetWindow(dlg)) break;
    }

    INT_PTR res = w ? w->dialog_result : IDOK;
    return res;
}

BOOL EndDialog(HWND hDlg, INT_PTR nResult)
{
    LogicalWindow *w = User_GetWindow(hDlg);
    if (!w) return FALSE;
    w->dialog_result = nResult;
    return DestroyWindow(hDlg);
}

/* ==========================================================================
 * Menus & Accelerators
 * ========================================================================== */

HMENU CreatePopupMenu(void)
{
    User_InternalInit();
    LogicalMenu *m = (LogicalMenu *)calloc(1, sizeof(LogicalMenu));
    if (!m) return NULL;

    m->item_capacity = 16;
    m->items = (LogicalMenuItem *)calloc(m->item_capacity, sizeof(LogicalMenuItem));
    m->item_count = 0;

    HMENU hmenu = (HMENU)Platform_AllocHandle(HANDLE_TYPE_HMENU, m, MenuDestructor);
    m->hmenu = hmenu;
    return hmenu;
}

BOOL AppendMenuA(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem)
{
    LogicalMenu *m = (LogicalMenu *)Platform_ResolveHandle(hMenu, HANDLE_TYPE_HMENU);
    if (!m) return FALSE;

    if (m->item_count >= m->item_capacity) {
        size_t new_cap = m->item_capacity * 2;
        LogicalMenuItem *new_items = (LogicalMenuItem *)realloc(m->items, new_cap * sizeof(LogicalMenuItem));
        if (!new_items) return FALSE;
        m->items = new_items;
        m->item_capacity = new_cap;
    }

    LogicalMenuItem *item = &m->items[m->item_count++];
    memset(item, 0, sizeof(*item));
    item->id = (UINT)uIDNewItem;
    item->flags = uFlags;
    item->is_separator = (uFlags & MF_SEPARATOR) ? true : false;
    item->is_checked = (uFlags & MF_CHECKED) ? true : false;
    item->is_enabled = !(uFlags & (MF_GRAYED | MF_DISABLED));
    if (uFlags & MF_POPUP) {
        item->submenu = (HMENU)(uintptr_t)uIDNewItem;
    }
    if (lpNewItem) {
        strncpy(item->text, lpNewItem, sizeof(item->text) - 1);
    }
    return TRUE;
}

BOOL InsertMenuA(HMENU hMenu, UINT uPosition, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem)
{
    (void)uPosition;
    return AppendMenuA(hMenu, uFlags, uIDNewItem, lpNewItem);
}

BOOL ModifyMenuA(HMENU hMnu, UINT uPosition, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem)
{
    LogicalMenu *m = (LogicalMenu *)Platform_ResolveHandle(hMnu, HANDLE_TYPE_HMENU);
    if (!m) return FALSE;

    for (size_t i = 0; i < m->item_count; i++) {
        bool match = (uFlags & MF_BYPOSITION) ? (i == (size_t)uPosition) : (m->items[i].id == (UINT)uPosition);
        if (match) {
            m->items[i].id = (UINT)uIDNewItem;
            m->items[i].flags = uFlags;
            m->items[i].is_separator = (uFlags & MF_SEPARATOR) ? true : false;
            m->items[i].is_checked = (uFlags & MF_CHECKED) ? true : false;
            m->items[i].is_enabled = !(uFlags & (MF_GRAYED | MF_DISABLED));
            if (lpNewItem) {
                strncpy(m->items[i].text, lpNewItem, sizeof(m->items[i].text) - 1);
            }
            return TRUE;
        }
    }
    return FALSE;
}

BOOL DeleteMenu(HMENU hMenu, UINT uPosition, UINT uFlags)
{
    LogicalMenu *m = (LogicalMenu *)Platform_ResolveHandle(hMenu, HANDLE_TYPE_HMENU);
    if (!m) return FALSE;

    for (size_t i = 0; i < m->item_count; i++) {
        bool match = (uFlags & MF_BYPOSITION) ? (i == (size_t)uPosition) : (m->items[i].id == (UINT)uPosition);
        if (match) {
            for (size_t j = i; j + 1 < m->item_count; j++) {
                m->items[j] = m->items[j + 1];
            }
            m->item_count--;
            return TRUE;
        }
    }
    return FALSE;
}

BOOL RemoveMenu(HMENU hMenu, UINT uPosition, UINT uFlags)
{
    return DeleteMenu(hMenu, uPosition, uFlags);
}

BOOL DestroyMenu(HMENU hMenu)
{
    return Platform_FreeHandle(hMenu, HANDLE_TYPE_HMENU);
}

HMENU GetMenu(HWND hWnd)
{
    (void)hWnd;
    return NULL;
}

HMENU GetSubMenu(HMENU hMenu, int nPos)
{
    LogicalMenu *m = (LogicalMenu *)Platform_ResolveHandle(hMenu, HANDLE_TYPE_HMENU);
    if (!m || nPos < 0 || (size_t)nPos >= m->item_count) return NULL;
    return m->items[nPos].submenu;
}

int GetMenuItemCount(HMENU hMenu)
{
    LogicalMenu *m = (LogicalMenu *)Platform_ResolveHandle(hMenu, HANDLE_TYPE_HMENU);
    return m ? (int)m->item_count : 0;
}

DWORD CheckMenuItem(HMENU hMenu, UINT uIDCheckItem, UINT uCheck)
{
    LogicalMenu *m = (LogicalMenu *)Platform_ResolveHandle(hMenu, HANDLE_TYPE_HMENU);
    if (!m) return 0xFFFFFFFF;

    for (size_t i = 0; i < m->item_count; i++) {
        bool match = (uCheck & MF_BYPOSITION) ? (i == (size_t)uIDCheckItem) : (m->items[i].id == (UINT)uIDCheckItem);
        if (match) {
            DWORD prev = m->items[i].is_checked ? MF_CHECKED : MF_UNCHECKED;
            m->items[i].is_checked = (uCheck & MF_CHECKED) ? true : false;
            return prev;
        }
    }
    return 0xFFFFFFFF;
}

BOOL EnableMenuItem(HMENU hMenu, UINT uIDEnableItem, UINT uEnable)
{
    LogicalMenu *m = (LogicalMenu *)Platform_ResolveHandle(hMenu, HANDLE_TYPE_HMENU);
    if (!m) return FALSE;

    for (size_t i = 0; i < m->item_count; i++) {
        bool match = (uEnable & MF_BYPOSITION) ? (i == (size_t)uIDEnableItem) : (m->items[i].id == (UINT)uIDEnableItem);
        if (match) {
            m->items[i].is_enabled = !(uEnable & (MF_GRAYED | MF_DISABLED));
            return TRUE;
        }
    }
    return FALSE;
}

BOOL TrackPopupMenu(HMENU hMenu, UINT uFlags, int x, int y, int nReserved, HWND hWnd, const RECT *prcRect)
{
    (void)uFlags;
    (void)x;
    (void)y;
    (void)nReserved;
    (void)hWnd;
    (void)prcRect;
    LogicalMenu *m = (LogicalMenu *)Platform_ResolveHandle(hMenu, HANDLE_TYPE_HMENU);
    return (m != NULL);
}

HACCEL LoadAcceleratorsA(HINSTANCE hInstance, LPCSTR lpTableName)
{
    (void)hInstance;
    (void)lpTableName;
    User_InternalInit();
    LogicalAccelTable *a = (LogicalAccelTable *)calloc(1, sizeof(LogicalAccelTable));
    if (!a) return NULL;
    return (HACCEL)Platform_AllocHandle(HANDLE_TYPE_HACCEL, a, AccelDestructor);
}

int TranslateAcceleratorA(HWND hWnd, HACCEL hAccTable, LPMSG lpMsg)
{
    (void)hWnd;
    (void)hAccTable;
    (void)lpMsg;
    return 0;
}

/* ==========================================================================
 * Icons, Cursors & Input Queries
 * ========================================================================== */

HICON LoadIconA(HINSTANCE hInstance, LPCSTR lpIconName)
{
    (void)hInstance;
    (void)lpIconName;
    return (HICON)(uintptr_t)1;
}

BOOL DestroyIcon(HICON hIcon)
{
    (void)hIcon;
    return TRUE;
}

HCURSOR LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName)
{
    (void)hInstance;
    (void)lpCursorName;
    return (HCURSOR)(uintptr_t)1;
}

BOOL DestroyCursor(HCURSOR hCursor)
{
    (void)hCursor;
    return TRUE;
}

int ShowCursor(BOOL bShow)
{
    g_UserState.cursor_visible = bShow ? true : false;
    SDL_ShowCursor(bShow ? SDL_ENABLE : SDL_DISABLE);
    return bShow ? 0 : -1;
}

HCURSOR SetCursor(HCURSOR hCursor)
{
    HCURSOR prev = g_UserState.current_cursor;
    g_UserState.current_cursor = hCursor;
    return prev;
}

BOOL GetCursorPos(LPPOINT lpPoint)
{
    if (!lpPoint) return FALSE;
    int mx = 0, my = 0;
    SDL_GetMouseState(&mx, &my);
    lpPoint->x = mx;
    lpPoint->y = my;
    return TRUE;
}

BOOL SetCursorPos(int X, int Y)
{
    g_UserState.cursor_pos.x = X;
    g_UserState.cursor_pos.y = Y;
    return TRUE;
}

UINT GetDoubleClickTime(void)
{
    return 500; /* Standard 500ms Windows default */
}

SHORT GetAsyncKeyState(int vKey)
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (!state) return 0;

    SDL_Scancode sc = SDL_SCANCODE_UNKNOWN;
    if (vKey >= 'A' && vKey <= 'Z') sc = (SDL_Scancode)(SDL_SCANCODE_A + (vKey - 'A'));
    else if (vKey >= '0' && vKey <= '9') sc = (SDL_Scancode)(SDL_SCANCODE_0 + (vKey - '0'));
    else if (vKey == VK_SPACE) sc = SDL_SCANCODE_SPACE;
    else if (vKey == VK_RETURN) sc = SDL_SCANCODE_RETURN;
    else if (vKey == VK_ESCAPE) sc = SDL_SCANCODE_ESCAPE;
    else if (vKey == VK_SHIFT) sc = SDL_SCANCODE_LSHIFT;
    else if (vKey == VK_CONTROL) sc = SDL_SCANCODE_LCTRL;

    return (sc != SDL_SCANCODE_UNKNOWN && state[sc]) ? (SHORT)0x8000 : 0;
}

SHORT GetKeyState(int nVirtKey)
{
    return GetAsyncKeyState(nVirtKey);
}

/* ==========================================================================
 * System Metrics, Colors, Message Box & UI Utilities
 * ========================================================================== */

int GetSystemMetrics(int nIndex)
{
    switch (nIndex) {
        case SM_CXSCREEN:
        case SM_CXFULLSCREEN:
            return 640;
        case SM_CYSCREEN:
        case SM_CYFULLSCREEN:
            return 480;
        case SM_CXDOUBLECLK:
        case SM_CYDOUBLECLK:
            return 4;
        case SM_MOUSEPRESENT:
            return 1;
        case SM_CMOUSEBUTTONS:
            return 2;
        default:
            return 0;
    }
}

DWORD GetSysColor(int nIndex)
{
    switch (nIndex) {
        case COLOR_WINDOW:
            return RGB(255, 255, 255);
        case COLOR_WINDOWTEXT:
            return RGB(0, 0, 0);
        case COLOR_BTNFACE:
            return RGB(192, 192, 192);
        case COLOR_BTNSHADOW:
            return RGB(128, 128, 128);
        case COLOR_BTNHIGHLIGHT:
            return RGB(255, 255, 255);
        case COLOR_HIGHLIGHT:
            return RGB(0, 0, 128);
        case COLOR_HIGHLIGHTTEXT:
            return RGB(255, 255, 255);
        default:
            return RGB(0, 0, 0);
    }
}

int MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    (void)hWnd;
    Uint32 flags = 0;
    if (uType & MB_ICONERROR) flags |= SDL_MESSAGEBOX_ERROR;
    else if (uType & MB_ICONWARNING) flags |= SDL_MESSAGEBOX_WARNING;
    else flags |= SDL_MESSAGEBOX_INFORMATION;

    const char *title = lpCaption ? lpCaption : "Magic: Shandalar";
    const char *msg = lpText ? lpText : "";

    printf("[MessageBox: %s] %s\n", title, msg);
    SDL_ShowSimpleMessageBox(flags, title, msg, NULL);
    return IDOK;
}

BOOL MessageBeep(UINT uType)
{
    (void)uType;
    return TRUE;
}

BOOL LockWindowUpdate(HWND hWndLock)
{
    (void)hWndLock;
    return TRUE;
}

UINT_PTR SHAppBarMessage(DWORD dwMessage, PAPPBARDATA pData)
{
    (void)dwMessage;
    if (pData) {
        pData->rc.left = 0;
        pData->rc.top = 0;
        pData->rc.right = 640;
        pData->rc.bottom = 480;
    }
    return 1;
}

BOOL WinHelpA(HWND hWndMain, LPCSTR lpszHelp, UINT uCommand, DWORD_PTR dwData)
{
    (void)hWndMain;
    (void)lpszHelp;
    (void)uCommand;
    (void)dwData;
    printf("[WinHelp] Help requested: %s\n", lpszHelp ? lpszHelp : "(default)");
    return TRUE;
}

void Ordinal_17(void)
{
    /* InitCommonControls equivalent */
    User_InternalInit();
}

BOOL GetOpenFileNameA(LPOPENFILENAMEA lpofn)
{
    (void)lpofn;
    return FALSE; /* Return false for automated / headless fallback */
}

BOOL GetSaveFileNameA(LPOPENFILENAMEA lpofn)
{
    (void)lpofn;
    return FALSE;
}

/* ==========================================================================
 * Rectangle Primitives
 * ========================================================================== */

BOOL SetRect(LPRECT lprc, int xLeft, int yTop, int xRight, int yBottom)
{
    if (!lprc) return FALSE;
    lprc->left = xLeft;
    lprc->top = yTop;
    lprc->right = xRight;
    lprc->bottom = yBottom;
    return TRUE;
}

BOOL CopyRect(LPRECT lprcDst, const RECT *lprcSrc)
{
    if (!lprcDst || !lprcSrc) return FALSE;
    *lprcDst = *lprcSrc;
    return TRUE;
}

BOOL IntersectRect(LPRECT lprcDst, const RECT *lprcSrc1, const RECT *lprcSrc2)
{
    if (!lprcDst || !lprcSrc1 || !lprcSrc2) return FALSE;

    int left = (lprcSrc1->left > lprcSrc2->left) ? lprcSrc1->left : lprcSrc2->left;
    int top = (lprcSrc1->top > lprcSrc2->top) ? lprcSrc1->top : lprcSrc2->top;
    int right = (lprcSrc1->right < lprcSrc2->right) ? lprcSrc1->right : lprcSrc2->right;
    int bottom = (lprcSrc1->bottom < lprcSrc2->bottom) ? lprcSrc1->bottom : lprcSrc2->bottom;

    if (left < right && top < bottom) {
        lprcDst->left = left;
        lprcDst->top = top;
        lprcDst->right = right;
        lprcDst->bottom = bottom;
        return TRUE;
    }

    memset(lprcDst, 0, sizeof(RECT));
    return FALSE;
}

BOOL UnionRect(LPRECT lprcDst, const RECT *lprcSrc1, const RECT *lprcSrc2)
{
    if (!lprcDst || !lprcSrc1 || !lprcSrc2) return FALSE;

    if (IsRectEmpty(lprcSrc1)) {
        *lprcDst = *lprcSrc2;
        return !IsRectEmpty(lprcSrc2);
    }
    if (IsRectEmpty(lprcSrc2)) {
        *lprcDst = *lprcSrc1;
        return !IsRectEmpty(lprcSrc1);
    }

    lprcDst->left = (lprcSrc1->left < lprcSrc2->left) ? lprcSrc1->left : lprcSrc2->left;
    lprcDst->top = (lprcSrc1->top < lprcSrc2->top) ? lprcSrc1->top : lprcSrc2->top;
    lprcDst->right = (lprcSrc1->right > lprcSrc2->right) ? lprcSrc1->right : lprcSrc2->right;
    lprcDst->bottom = (lprcSrc1->bottom > lprcSrc2->bottom) ? lprcSrc1->bottom : lprcSrc2->bottom;
    return TRUE;
}

BOOL OffsetRect(LPRECT lprc, int dx, int dy)
{
    if (!lprc) return FALSE;
    lprc->left += dx;
    lprc->right += dx;
    lprc->top += dy;
    lprc->bottom += dy;
    return TRUE;
}

BOOL InflateRect(LPRECT lprc, int dx, int dy)
{
    if (!lprc) return FALSE;
    lprc->left -= dx;
    lprc->right += dx;
    lprc->top -= dy;
    lprc->bottom += dy;
    return TRUE;
}

BOOL IsRectEmpty(const RECT *lprc)
{
    if (!lprc) return TRUE;
    return (lprc->left >= lprc->right || lprc->top >= lprc->bottom);
}

BOOL PtInRect(const RECT *lprc, POINT pt)
{
    if (!lprc) return FALSE;
    return (pt.x >= lprc->left && pt.x < lprc->right &&
            pt.y >= lprc->top && pt.y < lprc->bottom);
}
