/*
 * shandalar/win32_compat.h - Master Win32 & WinMM Compatibility Layer Header
 */
#ifndef SHANDALAR_WIN32_COMPAT_H
#define SHANDALAR_WIN32_COMPAT_H

#include "windows_types.h"
#include "platform_handle.h"
#include "api_manifest.h"
#include "display_shim.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Global Program Arguments Pointer for __p___argv */
char*** __p___argv(void);
void SetProgramArgv(char **argv);

/* Subsystem Lifecycle */
void Platform_InitWin32Subsystems(void);
void Platform_ShutdownWin32Subsystems(void);

/* Windowing & Classes */
HWND    FindWindowA(LPCSTR lpClassName, LPCSTR lpWindowName);
HWND    FindWindowExA(HWND hWndParent, HWND hWndChildAfter, LPCSTR lpszClass, LPCSTR lpszWindow);
ATOM    RegisterClassA(const WNDCLASSA *lpWndClass);
BOOL    UnregisterClassA(LPCSTR lpClassName, HINSTANCE hInstance);
int     GetClassNameA(HWND hWnd, LPSTR lpClassName, int nMaxCount);
DWORD   SetClassLongA(HWND hWnd, int nIndex, LONG dwNewLong);
HWND    CreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName,
                        DWORD dwStyle, int X, int Y, int nWidth, int nHeight,
                        HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
BOOL    DestroyWindow(HWND hWnd);
BOOL    ShowWindow(HWND hWnd, int nCmdShow);
BOOL    UpdateWindow(HWND hWnd);
BOOL    BringWindowToTop(HWND hWnd);
HWND    GetDesktopWindow(void);
HWND    WindowFromPoint(POINT Point);

/* Geometry & Hierarchy */
BOOL    GetClientRect(HWND hWnd, LPRECT lpRect);
BOOL    GetWindowRect(HWND hWnd, LPRECT lpRect);
BOOL    ClientToScreen(HWND hWnd, LPPOINT lpPoint);
BOOL    ScreenToClient(HWND hWnd, LPPOINT lpPoint);
int     MapWindowPoints(HWND hWndFrom, HWND hWndTo, LPPOINT lpPoints, UINT cPoints);
BOOL    MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint);
BOOL    SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);
BOOL    AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu);
HWND    GetParent(HWND hWnd);
HWND    SetParent(HWND hWndChild, HWND hWndNewParent);
HWND    GetTopWindow(HWND hWnd);
HWND    GetWindow(HWND hWnd, UINT uCmd);
BOOL    EnumChildWindows(HWND hWndParent, WNDENUMPROC lpEnumFunc, LPARAM lParam);

/* Window State & Longs */
BOOL    IsWindowVisible(HWND hWnd);
BOOL    IsIconic(HWND hWnd);
BOOL    EnableWindow(HWND hWnd, BOOL bEnable);
BOOL    IsWindowEnabled(HWND hWnd);
LONG    GetWindowLongA(HWND hWnd, int nIndex);
LONG    SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong);
WORD    GetWindowWord(HWND hWnd, int nIndex);
WORD    SetWindowWord(HWND hWnd, int nIndex, WORD wNewWord);
int     GetWindowTextA(HWND hWnd, LPSTR lpString, int nMaxCount);
BOOL    SetWindowTextA(HWND hWnd, LPCSTR lpString);
DWORD   GetWindowThreadProcessId(HWND hWnd, DWORD *lpdwProcessId);

/* Focus, Activation & Capture */
HWND    GetFocus(void);
HWND    SetFocus(HWND hWnd);
HWND    GetActiveWindow(void);
HWND    SetActiveWindow(HWND hWnd);
BOOL    SetForegroundWindow(HWND hWnd);
HWND    GetCapture(void);
HWND    SetCapture(HWND hWnd);
BOOL    ReleaseCapture(void);

/* Scrollbars */
int     GetScrollPos(HWND hWnd, int nBar);
int     SetScrollPos(HWND hWnd, int nBar, int nPos, BOOL bRedraw);
BOOL    GetScrollRange(HWND hWnd, int nBar, LPINT lpMinPos, LPINT lpMaxPos);
BOOL    SetScrollRange(HWND hWnd, int nBar, int nMinPos, int nMaxPos, BOOL bRedraw);
BOOL    ScrollWindow(HWND hWnd, int XAmount, int YAmount, const RECT *lpRect, const RECT *lpClipRect);

/* Dialogs & Controls */
int     GetDlgCtrlID(HWND hWnd);
HWND    GetDlgItem(HWND hDlg, int nIDDlgItem);
UINT    GetDlgItemInt(HWND hDlg, int nIDDlgItem, BOOL *lpTranslated, BOOL bSigned);
UINT    GetDlgItemTextA(HWND hDlg, int nIDDlgItem, LPSTR lpString, int nMaxCount);
BOOL    SetDlgItemInt(HWND hDlg, int nIDDlgItem, UINT uValue, BOOL bSigned);
BOOL    SetDlgItemTextA(HWND hDlg, int nIDDlgItem, LPCSTR lpString);
LRESULT SendDlgItemMessageA(HWND hDlg, int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL    CheckDlgButton(HWND hDlg, int nIDButton, UINT uCheck);
UINT    IsDlgButtonChecked(HWND hDlg, int nIDButton);
BOOL    CheckRadioButton(HWND hDlg, int nIDFirstButton, int nIDLastButton, int nIDCheckButton);
INT_PTR DialogBoxParamA(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent,
                        DLGPROC lpDialogFunc, LPARAM dwInitParam);
BOOL    EndDialog(HWND hDlg, INT_PTR nResult);

/* Menus & Accelerators */
HMENU   CreatePopupMenu(void);
BOOL    AppendMenuA(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem);
BOOL    InsertMenuA(HMENU hMenu, UINT uPosition, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem);
BOOL    ModifyMenuA(HMENU hMnu, UINT uPosition, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem);
BOOL    DeleteMenu(HMENU hMenu, UINT uPosition, UINT uFlags);
BOOL    RemoveMenu(HMENU hMenu, UINT uPosition, UINT uFlags);
BOOL    DestroyMenu(HMENU hMenu);
HMENU   GetMenu(HWND hWnd);
HMENU   GetSubMenu(HMENU hMenu, int nPos);
int     GetMenuItemCount(HMENU hMenu);
DWORD   CheckMenuItem(HMENU hMenu, UINT uIDCheckItem, UINT uCheck);
BOOL    EnableMenuItem(HMENU hMenu, UINT uIDEnableItem, UINT uEnable);
BOOL    TrackPopupMenu(HMENU hMenu, UINT uFlags, int x, int y, int nReserved, HWND hWnd, const RECT *prcRect);
HACCEL  LoadAcceleratorsA(HINSTANCE hInstance, LPCSTR lpTableName);
int     TranslateAcceleratorA(HWND hWnd, HACCEL hAccTable, LPMSG lpMsg);

/* Icons, Cursors & Input */
HICON   LoadIconA(HINSTANCE hInstance, LPCSTR lpIconName);
BOOL    DestroyIcon(HICON hIcon);
HCURSOR LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName);
BOOL    DestroyCursor(HCURSOR hCursor);
int     ShowCursor(BOOL bShow);
HCURSOR SetCursor(HCURSOR hCursor);
BOOL    GetCursorPos(LPPOINT lpPoint);
BOOL    SetCursorPos(int X, int Y);
UINT    GetDoubleClickTime(void);
SHORT   GetAsyncKeyState(int vKey);
SHORT   GetKeyState(int nVirtKey);

/* UI Utilities & System Metrics */
int     GetSystemMetrics(int nIndex);
DWORD   GetSysColor(int nIndex);
int     MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
BOOL    MessageBeep(UINT uType);
BOOL    LockWindowUpdate(HWND hWndLock);
UINT_PTR SHAppBarMessage(DWORD dwMessage, PAPPBARDATA pData);
BOOL    WinHelpA(HWND hWndMain, LPCSTR lpszHelp, UINT uCommand, DWORD_PTR dwData);
void    Ordinal_17(void);
BOOL    GetOpenFileNameA(LPOPENFILENAMEA lpofn);
BOOL    GetSaveFileNameA(LPOPENFILENAMEA lpofn);

/* Rectangles */
BOOL    SetRect(LPRECT lprc, int xLeft, int yTop, int xRight, int yBottom);
BOOL    CopyRect(LPRECT lprcDst, const RECT *lprcSrc);
BOOL    IntersectRect(LPRECT lprcDst, const RECT *lprcSrc1, const RECT *lprcSrc2);
BOOL    UnionRect(LPRECT lprcDst, const RECT *lprcSrc1, const RECT *lprcSrc2);
BOOL    OffsetRect(LPRECT lprc, int dx, int dy);
BOOL    InflateRect(LPRECT lprc, int dx, int dy);
BOOL    IsRectEmpty(const RECT *lprc);
BOOL    PtInRect(const RECT *lprc, POINT pt);

/* Messages */
BOOL    PostMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
void    PostQuitMessage(int nExitCode);
LRESULT SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT CallWindowProcA(WNDPROC lpPrevWndFunc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL    GetMessageA(tagMSG *lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
BOOL    PeekMessageA(tagMSG *lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
BOOL    TranslateMessage(const tagMSG *lpMsg);
LRESULT DispatchMessageA(const tagMSG *lpMsg);
DWORD   GetMessageTime(void);
UINT_PTR SetTimer(HWND hWnd, UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc);
BOOL    KillTimer(HWND hWnd, UINT_PTR uIDEvent);

/* GDI Device Contexts */
HDC     GetDC(HWND hWnd);
HDC     GetWindowDC(HWND hWnd);
int     ReleaseDC(HWND hWnd, HDC hDC);
HDC     CreateDCA(LPCSTR lpszDriver, LPCSTR lpszDevice, LPCSTR lpszOutput, const void *lpInitData);
HDC     CreateCompatibleDC(HDC hdc);
BOOL    DeleteDC(HDC hdc);
int     SaveDC(HDC hdc);
BOOL    RestoreDC(HDC hdc, int nSavedDC);
int     GetDeviceCaps(HDC hdc, int nIndex);

/* GDI Stock Objects & Selection */
HGDIOBJ GetStockObject(int fnObject);
HGDIOBJ SelectObject(HDC hdc, HGDIOBJ h);
BOOL    DeleteObject(HGDIOBJ hObject);
BOOL    UnrealizeObject(HGDIOBJ hObject);
int     GetObjectA(HANDLE hgdiobj, int cbBuffer, void *lpvObject);

/* GDI Bitmaps & DIBs */
HBITMAP CreateBitmap(int nWidth, int nHeight, UINT nPlanes, UINT nBitCount, const void *lpBits);
HBITMAP CreateCompatibleBitmap(HDC hdc, int cx, int cy);
HBITMAP CreateDIBSection(HDC hdc, const BITMAPINFO *pbmi, UINT usage,
                         void **ppvBits, HANDLE hSection, DWORD offset);
BOOL    SetBitmapDimensionEx(HBITMAP hbm, int w, int h, LPSIZE lpsz);

/* GDI Palettes */
HPALETTE CreatePalette(const LOGPALETTE *plpal);
HPALETTE SelectPalette(HDC hdc, HPALETTE hPal, BOOL bForceBkgd);
UINT    RealizePalette(HDC hdc);
BOOL    AnimatePalette(HPALETTE hPal, UINT iStartIndex, UINT cEntries, const PALETTEENTRY *ppe);
UINT    GetPaletteEntries(HPALETTE hpal, UINT iStartIndex, UINT nEntries, LPPALETTEENTRY lppe);
UINT    SetPaletteEntries(HPALETTE hpal, UINT iStartIndex, UINT nEntries, const PALETTEENTRY *lppe);
UINT    GetNearestPaletteIndex(HPALETTE hpal, COLORREF cr);
UINT    SetSystemPaletteUse(HDC hdc, UINT uUsage);

/* GDI Pens, Brushes, Fonts, Regions */
HPEN    CreatePen(int iStyle, int cWidth, COLORREF color);
HPEN    CreatePenIndirect(const LOGPEN *plpen);
HBRUSH  CreateSolidBrush(COLORREF color);
HBRUSH  CreateBrushIndirect(const LOGBRUSH *plbrush);
HBRUSH  CreateHatchBrush(int iHatch, COLORREF color);
HFONT   CreateFontA(int cHeight, int cWidth, int cEscapement, int cOrientation,
                    int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut,
                    DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision,
                    DWORD iQuality, DWORD iPitchAndFamily, LPCSTR pszFaceName);
HFONT   CreateFontIndirectA(const LOGFONTA *lplf);
int     AddFontResourceA(LPCSTR lpFileName);
BOOL    RemoveFontResourceA(LPCSTR lpFileName);
HRGN    CreateRectRgn(int x1, int y1, int x2, int y2);
HRGN    CreateRectRgnIndirect(const RECT *lprc);
HRGN    CreatePolygonRgn(const POINT *pptl, int cPoint, int iMode);
BOOL    SetRectRgn(HRGN hrgn, int left, int top, int right, int bottom);
int     SelectClipRgn(HDC hdc, HRGN hrgn);
int     IntersectClipRect(HDC hdc, int left, int top, int right, int bottom);

/* GDI Settings & Coordinates */
int     SetROP2(HDC hdc, int rop2);
int     SetBkMode(HDC hdc, int mode);
COLORREF SetBkColor(HDC hdc, COLORREF color);
COLORREF SetTextColor(HDC hdc, COLORREF color);
UINT    SetTextAlign(HDC hdc, UINT align);
UINT    GetTextAlign(HDC hdc);
int     SetMapMode(HDC hdc, int iMode);
BOOL    SetViewportOrgEx(HDC hdc, int x, int y, LPPOINT lppt);
BOOL    OffsetViewportOrgEx(HDC hdc, int dx, int dy, LPPOINT lppt);
BOOL    SetViewportExtEx(HDC hdc, int x, int y, LPSIZE lpsz);
BOOL    SetWindowOrgEx(HDC hdc, int x, int y, LPPOINT lppt);
BOOL    SetWindowExtEx(HDC hdc, int x, int y, LPSIZE lpsz);
BOOL    LPtoDP(HDC hdc, LPPOINT lppt, int c);
BOOL    DPtoLP(HDC hdc, LPPOINT lppt, int c);

/* GDI Primitives */
BOOL    MoveToEx(HDC hdc, int x, int y, LPPOINT lppt);
BOOL    LineTo(HDC hdc, int x, int y);
BOOL    Rectangle(HDC hdc, int left, int top, int right, int bottom);
BOOL    RoundRect(HDC hdc, int left, int top, int right, int bottom, int width, int height);
BOOL    Ellipse(HDC hdc, int left, int top, int right, int bottom);
int     FillRect(HDC hdc, const RECT *lprc, HBRUSH hbr);
int     FrameRect(HDC hdc, const RECT *lprc, HBRUSH hbr);
BOOL    DrawFocusRect(HDC hdc, const RECT *lprc);
COLORREF GetPixel(HDC hdc, int x, int y);
COLORREF SetPixel(HDC hdc, int x, int y, COLORREF color);
BOOL    SetPixelV(HDC hdc, int x, int y, COLORREF color);

/* GDI Blits & DIBs */
int     SetStretchBltMode(HDC hdc, int mode);
BOOL    BitBlt(HDC hdcDst, int xDst, int yDst, int cx, int cy,
               HDC hdcSrc, int xSrc, int ySrc, DWORD rop);
BOOL    StretchBlt(HDC hdcDst, int xDst, int yDst, int cxDst, int cyDst,
                   HDC hdcSrc, int xSrc, int ySrc, int cxSrc, int cySrc, DWORD rop);
int     SetDIBitsToDevice(HDC hdc, int xDest, int yDest, DWORD w, DWORD h,
                          int xSrc, int ySrc, UINT StartScan, UINT cScanLines,
                          const void *lpvBits, const BITMAPINFO *lpbmi, UINT ColorUse);
int     SetDIBits(HDC hdc, HBITMAP hbm, UINT start, UINT cLines,
                  const void *lpBits, const BITMAPINFO *lpbmi, UINT ColorUse);
UINT    SetDIBColorTable(HDC hdc, UINT iStart, UINT cEntries, const RGBQUAD *prgbq);

/* GDI Paint & Presentation */
HDC     BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint);
BOOL    EndPaint(HWND hWnd, const PAINTSTRUCT *lpPaint);
BOOL    InvalidateRect(HWND hWnd, const RECT *lpRect, BOOL bErase);
BOOL    GdiFlush(void);
DWORD   GdiGetBatchLimit(void);
DWORD   GdiSetBatchLimit(DWORD dw);

/* GDI Text */
BOOL    TextOutA(HDC hdc, int x, int y, LPCSTR lpString, int c);
int     DrawTextA(HDC hdc, LPCSTR lpchText, int cchText, LPRECT lprc, UINT format);
BOOL    GetTextExtentPointA(HDC hdc, LPCSTR lpString, int cbString, LPSIZE lpSize);
BOOL    GetTextExtentPoint32A(HDC hdc, LPCSTR lpString, int cbString, LPSIZE lpSize);
BOOL    GetTextMetricsA(HDC hdc, LPTEXTMETRICA lptm);
BOOL    GetCharWidthA(HDC hdc, UINT iFirstChar, UINT iLastChar, LPINT lpBuffer);
BOOL    GetCharABCWidthsA(HDC hdc, UINT uFirstChar, UINT uLastChar, LPABC lpabc);

/* Kernel Files */
HANDLE  CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
                    LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition,
                    DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
BOOL    ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead,
                 LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);
BOOL    WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite,
                  LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
DWORD   SetFilePointer(HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod);
BOOL    SetEndOfFile(HANDLE hFile);
BOOL    FlushFileBuffers(HANDLE hFile);
DWORD   GetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh);
DWORD   GetFileType(HANDLE hFile);
BOOL    CloseHandle(HANDLE hObject);
BOOL    CopyFileA(LPCSTR lpExistingFileName, LPCSTR lpNewFileName, BOOL bFailIfExists);
BOOL    DeleteFileA(LPCSTR lpFileName);
BOOL    CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
DWORD   GetCurrentDirectoryA(DWORD nBufferLength, LPSTR lpBuffer);
BOOL    SetCurrentDirectoryA(LPCSTR lpPathName);
UINT    GetDriveTypeA(LPCSTR lpRootPathName);
BOOL    DeviceIoControl(HANDLE hDevice, DWORD dwIoControlCode, LPVOID lpInBuffer, DWORD nInBufferSize,
                        LPVOID lpOutBuffer, DWORD nOutBufferSize, LPDWORD lpBytesReturned, LPOVERLAPPED lpOverlapped);
HFILE   _lopen(LPCSTR lpPathName, int iReadWrite);
HFILE   _lclose(HFILE hFile);
UINT    SetHandleCount(UINT uNumber);
BOOL    SetStdHandle(DWORD nStdHandle, HANDLE hHandle);
HANDLE  GetStdHandle(DWORD nStdHandle);

/* Kernel Mappings & Resources */
HANDLE  CreateFileMappingA(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
                           DWORD flProtect, DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow,
                           LPCSTR lpName);
LPVOID  MapViewOfFile(HANDLE hFileMappingObject, DWORD dwDesiredAccess,
                      DWORD dwFileOffsetHigh, DWORD dwFileOffsetLow,
                      SIZE_T dwNumberOfBytesToMap);
BOOL    UnmapViewOfFile(LPCVOID lpBaseAddress);
HRSRC   FindResourceA(HMODULE hModule, LPCSTR lpName, LPCSTR lpType);
HGLOBAL LoadResource(HMODULE hModule, HRSRC hResInfo);
LPVOID  LockResource(HGLOBAL hResData);

/* Kernel Memory */
HGLOBAL GlobalAlloc(UINT uFlags, SIZE_T dwBytes);
HGLOBAL GlobalFree(HGLOBAL hMem);
LPVOID  GlobalLock(HGLOBAL hMem);
BOOL    GlobalUnlock(HGLOBAL hMem);
HGLOBAL GlobalHandle(LPCVOID pMem);
HLOCAL  LocalFree(HLOCAL hMem);
LPVOID  VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
BOOL    VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
LPVOID  HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
LPVOID  HeapReAlloc(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes);
BOOL    HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
HANDLE  HeapCreate(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize);
BOOL    HeapDestroy(HANDLE hHeap);
BOOL    HeapValidate(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem);
BOOL    IsBadReadPtr(const void *lp, UINT_PTR ucb);
BOOL    IsBadWritePtr(LPVOID lp, UINT_PTR ucb);

/* Kernel Sync & Threads */
void    InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
void    DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
void    EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
void    LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
HANDLE  CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize,
                     LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter,
                     DWORD dwCreationFlags, LPDWORD lpThreadId);
void    ExitThread(DWORD dwExitCode);
BOOL    GetExitCodeThread(HANDLE hThread, LPDWORD lpExitCode);
DWORD   WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
HANDLE  GetCurrentProcess(void);
HANDLE  GetCurrentThread(void);
BOOL    DuplicateHandle(HANDLE hSourceProcessHandle, HANDLE hSourceHandle,
                        HANDLE hTargetProcessHandle, LPHANDLE lpTargetHandle,
                        DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwOptions);
BOOL    TerminateProcess(HANDLE hProcess, UINT uExitCode);
void    ExitProcess(UINT uExitCode);
int     GetThreadPriority(HANDLE hThread);
BOOL    SetThreadPriority(HANDLE hThread, int nPriority);
DWORD   GetPriorityClass(HANDLE hProcess);
BOOL    SetPriorityClass(HANDLE hProcess, DWORD dwPriorityClass);
LONG    InterlockedIncrement(LONG volatile *lpAddend);
LONG    InterlockedDecrement(LONG volatile *lpAddend);
void    Sleep(DWORD dwMilliseconds);

/* Kernel Clocks & Modules */
DWORD   GetTickCount(void);
void    GetLocalTime(LPSYSTEMTIME lpSystemTime);
void    GetSystemTime(LPSYSTEMTIME lpSystemTime);
DWORD   GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation);
int     GetDateFormatA(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpDate,
                       LPCSTR lpFormat, LPSTR lpDateStr, int cchDate);
HMODULE GetModuleHandleA(LPCSTR lpModuleName);
DWORD   GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
HMODULE LoadLibraryA(LPCSTR lpLibFileName);
BOOL    FreeLibrary(HMODULE hLibModule);
FARPROC GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
BOOL    DisableThreadLibraryCalls(HMODULE hLibModule);

/* Kernel Environment & Strings */
LPSTR   GetCommandLineA(void);
void    GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
LPVOID  GetEnvironmentStrings(void);
LPWSTR  GetEnvironmentStringsW(void);
BOOL    FreeEnvironmentStringsA(LPSTR lpszEnvironmentBlock);
BOOL    FreeEnvironmentStringsW(LPWSTR lpszEnvironmentBlock);
BOOL    SetEnvironmentVariableA(LPCSTR lpName, LPCSTR lpValue);
DWORD   GetVersion(void);
UINT    GetACP(void);
UINT    GetOEMCP(void);
BOOL    GetCPInfo(UINT CodePage, LPCPINFO lpCPInfo);
BOOL    GetStringTypeA(LCID Locale, DWORD dwInfoType, LPCSTR lpSrcStr, int cchSrc, LPWORD lpCharType);
BOOL    GetStringTypeW(DWORD dwInfoType, LPCWSTR lpSrcStr, int cchSrc, LPWORD lpCharType);
int     LCMapStringA(LCID Locale, DWORD dwMapFlags, LPCSTR lpSrcStr, int cchSrc, LPSTR lpDestStr, int cchDest);
int     LCMapStringW(LCID Locale, DWORD dwMapFlags, LPCWSTR lpSrcStr, int cchSrc, LPWSTR lpDestStr, int cchDest);
int     CompareStringA(LCID Locale, DWORD dwCmpFlags, LPCSTR lpString1, int cchCount1, LPCSTR lpString2, int cchCount2);
int     CompareStringW(LCID Locale, DWORD dwCmpFlags, LPCWSTR lpString1, int cchCount1, LPCWSTR lpString2, int cchCount2);
int     MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cbMultiByte,
                            LPWSTR lpWideCharStr, int cchWideChar);
int     WideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar,
                            LPSTR lpMultiByteStr, int cbMultiByte, LPCSTR lpDefaultChar, LPBOOL lpUsedDefaultChar);
LPSTR   lstrcpyA(LPSTR lpString1, LPCSTR lpString2);
LPSTR   lstrcatA(LPSTR lpString1, LPCSTR lpString2);
int     lstrlenA(LPCSTR lpString);
int     wsprintfA(LPSTR lpOut, LPCSTR lpFmt, ...);
int     wvsprintfA(LPSTR lpOut, LPCSTR lpFmt, va_list arglist);
DWORD   FormatMessageA(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId,
                       DWORD dwLanguageId, LPSTR lpBuffer, DWORD nSize, va_list *Arguments);
void    OutputDebugStringA(LPCSTR lpOutputString);

/* Kernel Error & Exceptions */
DWORD   GetLastError(void);
void    SetLastError(DWORD dwErrCode);
void    DebugBreak(void);
LONG    UnhandledExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo);
BOOL    SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine, BOOL Add);
void    RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue);

/* Config: INI & Registry */
UINT    GetPrivateProfileIntA(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName);
DWORD   GetPrivateProfileStringA(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault,
                                LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName);
LONG    RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
LONG    RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass,
                        DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
                        PHKEY phkResult, LPDWORD lpdwDisposition);
LONG    RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved,
                         LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LONG    RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType,
                       const BYTE *lpData, DWORD cbData);
LONG    RegCloseKey(HKEY hKey);
LONG    RegFlushKey(HKEY hKey);

/* Multimedia: WinMM, MMIO, DirectSound, AVI */
DWORD   timeGetTime(void);
MMRESULT timeGetDevCaps(LPTIMECAPS ptc, UINT cbtc);
MMRESULT timeBeginPeriod(UINT uPeriod);
MMRESULT timeEndPeriod(UINT uPeriod);
MMRESULT timeSetEvent(UINT uDelay, UINT uResolution, LPTIMECALLBACK lpTimeProc, DWORD_PTR dwUser, UINT fuEvent);
MMRESULT timeKillEvent(UINT uTimerID);
HMMIO   mmioOpenA(LPSTR szFilename, LPMMIOINFO lpmmioinfo, DWORD dwOpenFlags);
MMRESULT mmioClose(HMMIO hmmio, UINT uFlags);
LONG    mmioRead(HMMIO hmmio, HPSTR pch, LONG cch);
LONG    mmioSeek(HMMIO hmmio, LONG lOffset, int iOrigin);
MMRESULT mmioDescend(HMMIO hmmio, LPMMCKINFO lpck, const MMCKINFO *lpckParent, UINT uFlags);
MMRESULT mmioAscend(HMMIO hmmio, LPMMCKINFO lpck, UINT uFlags);
MMRESULT mmioAdvance(HMMIO hmmio, LPMMIOINFO lpmmioinfo, UINT uFlags);
MMRESULT mmioSetInfo(HMMIO hmmio, LPCMMIOINFO lpmmioinfo, UINT uFlags);
MMRESULT mmioGetInfo(HMMIO hmmio, LPMMIOINFO lpmmioinfo, UINT uFlags);
MMRESULT waveOutWrite(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
int     DirectSoundCreate(void *lpGuid, void **ppDS, void *pUnkOuter);
void    AVIFileInit(void);
void    AVIFileExit(void);
HRESULT AVIFileOpenA(PAVIFILE *ppfile, LPCSTR szFile, UINT uMode, LPCLSID lpHandler);
ULONG   AVIFileRelease(PAVIFILE pfile);
HRESULT AVIFileGetStream(PAVIFILE pfile, PAVISTREAM *ppavi, DWORD fccType, LONG lParam);
ULONG   AVIStreamRelease(PAVISTREAM pavi);
HRESULT AVIStreamInfoA(PAVISTREAM pavi, LPAVISTREAMINFOA psi, LONG lSize);
HRESULT AVIStreamReadFormat(PAVISTREAM pavi, LONG lPos, LPVOID lpFormat, LONG *lpcbFormat);
HRESULT AVIStreamRead(PAVISTREAM pavi, LONG lStart, LONG lSamples, LPVOID lpBuffer,
                      LONG cbBuffer, LONG *plBytes, LONG *plSamples);
LONG    AVIStreamSampleToTime(PAVISTREAM pavi, LONG lSample);
LONG    AVIStreamTimeToSample(PAVISTREAM pavi, LONG lTime);
HDRAWDIB DrawDibOpen(void);
BOOL    DrawDibClose(HDRAWDIB hdd);
BOOL    DrawDibBegin(HDRAWDIB hdd, HDC hdc, int dxDest, int dyDest,
                     LPBITMAPINFOHEADER lpbi, int dxSrc, int dySrc, UINT wFlags);
BOOL    DrawDibEnd(HDRAWDIB hdd);
BOOL    DrawDibStart(HDRAWDIB hdd, DWORD rate);
BOOL    DrawDibStop(HDRAWDIB hdd);
BOOL    DrawDibDraw(HDRAWDIB hdd, HDC hdc, int xDst, int yDst, int dxDst, int dyDst,
                    LPBITMAPINFOHEADER lpbi, LPVOID lpBits, int xSrc, int ySrc,
                    int dxSrc, int dySrc, UINT wFlags);
HIC     ICLocate(DWORD fccType, DWORD fccHandler, LPBITMAPINFOHEADER lpbiIn, LPBITMAPINFOHEADER lpbiOut, WORD wFlags);
LRESULT ICClose(HIC hic);
LRESULT ICSendMessage(HIC hic, UINT msg, DWORD_PTR dw1, DWORD_PTR dw2);
DWORD   ICDrawBegin(HIC hic, DWORD dwFlags, HPALETTE hpal, HWND hwnd, HDC hdc,
                    int xDst, int yDst, int dxDst, int dyDst,
                    LPBITMAPINFOHEADER lpbi, int xSrc, int ySrc, int dxSrc, int dySrc,
                    DWORD dwRate, DWORD dwScale);
HWND    MCIWndCreateA(HWND hwndParent, HINSTANCE hInstance, DWORD dwStyle, LPCSTR szFile);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_WIN32_COMPAT_H */
