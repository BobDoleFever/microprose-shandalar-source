/*
 * src/platform/win32_compat.c - Win32 API Emulation via SDL2 Backend
 * Translates legacy Windows 95 API calls into modern SDL2 calls.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#include <SDL.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/display_shim.h"

/* Active Registered Window Class */
static WNDPROC g_ActiveWndProc = NULL;
static bool    g_QuitPosted = false;
static int     g_QuitCode = 0;

/* Global Program Arguments Pointer for __p___argv */
static char **g_ProgramArgv = NULL;

char*** __p___argv(void)
{
    return &g_ProgramArgv;
}

void SetProgramArgv(char **argv)
{
    g_ProgramArgv = argv;
}

/* ==========================================================================
 * Win32 Windowing & Messaging Shims
 * ========================================================================== */

HWND FindWindowA(LPCSTR lpClassName, LPCSTR lpWindowName)
{
    (void)lpClassName;
    (void)lpWindowName;
    return NULL; /* Indicate no previous instance is running */
}

HWND FindWindowExA(HWND hWndParent, HWND hWndChildAfter, LPCSTR lpszClass, LPCSTR lpszWindow)
{
    (void)hWndParent;
    (void)hWndChildAfter;
    (void)lpszClass;
    (void)lpszWindow;
    return NULL;
}

ATOM RegisterClassA(const WNDCLASSA *lpWndClass)
{
    if (!lpWndClass) return 0;
    g_ActiveWndProc = lpWndClass->lpfnWndProc;
    return 1;
}

HWND CreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName,
                     DWORD dwStyle, int X, int Y, int nWidth, int nHeight,
                     HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
    (void)dwExStyle;
    (void)lpClassName;
    (void)dwStyle;
    (void)X;
    (void)Y;
    (void)hWndParent;
    (void)hMenu;
    (void)hInstance;
    (void)lpParam;

    DisplayConfig cfg;
    cfg.window_width = (nWidth > 0) ? nWidth : 640;
    cfg.window_height = (nHeight > 0) ? nHeight : 480;
    cfg.scale_factor = 2;
    cfg.fullscreen = false;
    cfg.vsync = true;
    cfg.window_title = lpWindowName ? lpWindowName : "Magic: Shandalar (1997)";

    Shandalar_DisplayInit(&cfg);
    return (HWND)(uintptr_t)1;
}

BOOL ShowWindow(HWND hWnd, int nCmdShow)
{
    (void)hWnd;
    (void)nCmdShow;
    return 1;
}

BOOL UpdateWindow(HWND hWnd)
{
    (void)hWnd;
    return 1;
}

BOOL BringWindowToTop(HWND hWnd)
{
    (void)hWnd;
    return 1;
}

HDC GetDC(HWND hWnd)
{
    (void)hWnd;
    return (HDC)(uintptr_t)1;
}

int ReleaseDC(HWND hWnd, HDC hDC)
{
    (void)hWnd;
    (void)hDC;
    return 1;
}

int GetDeviceCaps(HDC hdc, int nIndex)
{
    (void)hdc;
    if (nIndex == 8) { /* HORZRES / VERTRES */
        return 640;
    }
    return 640;
}

HGDIOBJ GetStockObject(int fnObject)
{
    (void)fnObject;
    return (HGDIOBJ)(uintptr_t)1;
}

HICON LoadIconA(HINSTANCE hInstance, LPCSTR lpIconName)
{
    (void)hInstance;
    (void)lpIconName;
    return (HICON)(uintptr_t)1;
}

HCURSOR LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName)
{
    (void)hInstance;
    (void)lpCursorName;
    return (HCURSOR)(uintptr_t)1;
}

int MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    (void)hWnd;
    (void)uType;
    printf("[MessageBox: %s] %s\n", lpCaption ? lpCaption : "Alert", lpText ? lpText : "");
    return 1;
}

UINT SetSystemPaletteUse(HDC hdc, UINT uUsage)
{
    (void)hdc;
    (void)uUsage;
    return 1;
}

DWORD GetTickCount(void)
{
    return (DWORD)SDL_GetTicks();
}

HANDLE GetCurrentProcess(void)
{
    return (HANDLE)(uintptr_t)1;
}

HANDLE GetCurrentThread(void)
{
    return (HANDLE)(uintptr_t)1;
}

BOOL DuplicateHandle(HANDLE hSourceProcessHandle, HANDLE hSourceHandle,
                     HANDLE hTargetProcessHandle, HANDLE *lpTargetHandle,
                     DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwOptions)
{
    (void)hSourceProcessHandle;
    (void)hSourceHandle;
    (void)hTargetProcessHandle;
    (void)dwDesiredAccess;
    (void)bInheritHandle;
    (void)dwOptions;
    if (lpTargetHandle) *lpTargetHandle = (HANDLE)(uintptr_t)1;
    return 1;
}

void InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
    (void)lpCriticalSection;
}

void DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
    (void)lpCriticalSection;
}

HANDLE CreateThread(void *lpThreadAttributes, size_t dwStackSize,
                    void *lpStartAddress, void *lpParameter,
                    DWORD dwCreationFlags, DWORD *lpThreadId)
{
    (void)lpThreadAttributes;
    (void)dwStackSize;
    (void)lpStartAddress;
    (void)lpParameter;
    (void)dwCreationFlags;
    if (lpThreadId) *lpThreadId = 1;
    return (HANDLE)(uintptr_t)1;
}

UINT timeBeginPeriod(UINT uPeriod)
{
    (void)uPeriod;
    return 0;
}

UINT timeEndPeriod(UINT uPeriod)
{
    (void)uPeriod;
    return 0;
}

UINT timeSetEvent(UINT uDelay, UINT uResolution, void *lpTimeProc, DWORD_PTR dwUser, UINT fuEvent)
{
    (void)uDelay;
    (void)uResolution;
    (void)lpTimeProc;
    (void)dwUser;
    (void)fuEvent;
    return 1;
}

BOOL PostMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    if (g_ActiveWndProc) {
        g_ActiveWndProc(hWnd, Msg, wParam, lParam);
    }
    return 1;
}

void PostQuitMessage(int nExitCode)
{
    g_QuitPosted = true;
    g_QuitCode = nExitCode;
}

LRESULT DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    (void)hWnd;
    (void)Msg;
    (void)wParam;
    (void)lParam;
    return 0;
}

/* ==========================================================================
 * Main Message Loop Pump (Translates SDL2 events to Win32 tagMSG)
 * ========================================================================== */

BOOL GetMessageA(tagMSG *lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
    (void)hWnd;
    (void)wMsgFilterMin;
    (void)wMsgFilterMax;

    if (g_QuitPosted) {
        if (lpMsg) {
            lpMsg->message = 0x12; /* WM_QUIT */
            lpMsg->wParam = g_QuitCode;
        }
        return FALSE;
    }

    SDL_Event event;
    /* Wait for next event or tick presentation */
    while (SDL_PollEvent(&event)) {
        if (!lpMsg) continue;
        lpMsg->hwnd = (HWND)(uintptr_t)1;
        lpMsg->time = (DWORD)SDL_GetTicks();

        switch (event.type) {
            case SDL_QUIT:
                g_QuitPosted = true;
                lpMsg->message = 0x12; /* WM_QUIT */
                lpMsg->wParam = 0;
                return FALSE;

            case SDL_MOUSEMOTION: {
                int mx = event.motion.x;
                int my = event.motion.y;
                if (mx < 0) mx = 0; else if (mx >= 640) mx = 639;
                if (my < 0) my = 0; else if (my >= 480) my = 479;
                lpMsg->message = 0x200; /* WM_MOUSEMOVE */
                lpMsg->wParam = 0;
                lpMsg->lParam = ((my & 0xffff) << 16) | (mx & 0xffff);
                return TRUE;
            }

            case SDL_MOUSEBUTTONDOWN: {
                int bx = event.button.x;
                int by = event.button.y;
                if (bx < 0) bx = 0; else if (bx >= 640) bx = 639;
                if (by < 0) by = 0; else if (by >= 480) by = 479;
                if (event.button.button == SDL_BUTTON_LEFT) {
                    lpMsg->message = 0x201; /* WM_LBUTTONDOWN */
                } else {
                    lpMsg->message = 0x204; /* WM_RBUTTONDOWN */
                }
                lpMsg->wParam = 1;
                lpMsg->lParam = ((by & 0xffff) << 16) | (bx & 0xffff);
                return TRUE;
            }

            case SDL_MOUSEBUTTONUP: {
                int bx = event.button.x;
                int by = event.button.y;
                if (bx < 0) bx = 0; else if (bx >= 640) bx = 639;
                if (by < 0) by = 0; else if (by >= 480) by = 479;
                if (event.button.button == SDL_BUTTON_LEFT) {
                    lpMsg->message = 0x202; /* WM_LBUTTONUP */
                } else {
                    lpMsg->message = 0x205; /* WM_RBUTTONUP */
                }
                lpMsg->wParam = 0;
                lpMsg->lParam = ((by & 0xffff) << 16) | (bx & 0xffff);
                return TRUE;
            }

            case SDL_KEYDOWN:
                lpMsg->message = 0x100; /* WM_KEYDOWN */
                lpMsg->wParam = (WPARAM)event.key.keysym.sym;
                lpMsg->lParam = 0;
                return TRUE;

            default:
                break;
        }
    }

    /* Periodic paint message for smooth rendering */
    if (lpMsg) {
        lpMsg->hwnd = (HWND)(uintptr_t)1;
        lpMsg->message = 0x0F; /* WM_PAINT */
        lpMsg->wParam = 0;
        lpMsg->lParam = 0;
    }
    SDL_Delay(16); /* ~60 FPS pump */
    return TRUE;
}

BOOL PeekMessageA(tagMSG *lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg)
{
    (void)wRemoveMsg;
    return GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
}

BOOL TranslateMessage(const tagMSG *lpMsg)
{
    (void)lpMsg;
    return 1;
}

LRESULT DispatchMessageA(const tagMSG *lpMsg)
{
    if (!lpMsg) return 0;
    if (g_ActiveWndProc) {
        return g_ActiveWndProc(lpMsg->hwnd, lpMsg->message, lpMsg->wParam, lpMsg->lParam);
    }
    return 0;
}
