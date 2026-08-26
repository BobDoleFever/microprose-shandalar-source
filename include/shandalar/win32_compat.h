/*
 * shandalar/win32_compat.h - Win32 API Emulation & Compatibility Layer (SDL2 Backend)
 * Comments follow Simplified Technical English (ASD-STE100) rules.
 */
#ifndef SHANDALAR_WIN32_COMPAT_H
#define SHANDALAR_WIN32_COMPAT_H

#include "types.h"
#include "sprite.h"
#include "display_shim.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct _CRITICAL_SECTION {
    void *DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
} CRITICAL_SECTION, *LPCRITICAL_SECTION;

/*
 * Win32 Emulation API Functions
 */
HWND    FindWindowA(LPCSTR lpClassName, LPCSTR lpWindowName);
HWND    FindWindowExA(HWND hWndParent, HWND hWndChildAfter, LPCSTR lpszClass, LPCSTR lpszWindow);
ATOM    RegisterClassA(const WNDCLASSA *lpWndClass);
HWND    CreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName,
                        DWORD dwStyle, int X, int Y, int nWidth, int nHeight,
                        HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
BOOL    ShowWindow(HWND hWnd, int nCmdShow);
BOOL    UpdateWindow(HWND hWnd);
BOOL    BringWindowToTop(HWND hWnd);
HDC     GetDC(HWND hWnd);
int     ReleaseDC(HWND hWnd, HDC hDC);
int     GetDeviceCaps(HDC hdc, int nIndex);
HGDIOBJ GetStockObject(int fnObject);
HICON   LoadIconA(HINSTANCE hInstance, LPCSTR lpIconName);
HCURSOR LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName);
int     MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
UINT    SetSystemPaletteUse(HDC hdc, UINT uUsage);
DWORD   GetTickCount(void);
HANDLE  GetCurrentProcess(void);
HANDLE  GetCurrentThread(void);
BOOL    DuplicateHandle(HANDLE hSourceProcessHandle, HANDLE hSourceHandle,
                        HANDLE hTargetProcessHandle, HANDLE *lpTargetHandle,
                        DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwOptions);
void    InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
void    DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
HANDLE  CreateThread(void *lpThreadAttributes, size_t dwStackSize,
                     void *lpStartAddress, void *lpParameter,
                     DWORD dwCreationFlags, DWORD *lpThreadId);
UINT    timeBeginPeriod(UINT uPeriod);
UINT    timeEndPeriod(UINT uPeriod);
UINT    timeSetEvent(UINT uDelay, UINT uResolution, void *lpTimeProc, DWORD_PTR dwUser, UINT fuEvent);
BOOL    PostMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
void    PostQuitMessage(int nExitCode);
LRESULT DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL    GetMessageA(tagMSG *lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
BOOL    PeekMessageA(tagMSG *lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
BOOL    TranslateMessage(const tagMSG *lpMsg);
LRESULT DispatchMessageA(const tagMSG *lpMsg);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_WIN32_COMPAT_H */
