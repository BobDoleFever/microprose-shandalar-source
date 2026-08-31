/*
 * tests/test_win32_compat.c - Comprehensive Unit & Integration Test Suite for Win32 Compat Layer
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include "windows_types.h"
#include "shandalar/platform_handle.h"
#include "shandalar/win32_compat.h"
#include "shandalar/win32_internal.h"
#include "shandalar/api_manifest.h"

static int g_TestsRun = 0;
static int g_TestsPassed = 0;

#define TEST_ASSERT(cond, msg) do { \
    g_TestsRun++; \
    if (cond) { \
        g_TestsPassed++; \
    } else { \
        fprintf(stderr, "FAIL: %s (line %d): %s\n", __func__, __LINE__, msg); \
        assert(cond); \
    } \
} while(0)

/* ==========================================================================
 * 1. Handle Subsystem Tests
 * ========================================================================== */
static void Test_Handles(void)
{
    printf("[Test] Running Handle Subsystem tests...\n");

    Platform_HandleInit();

    int dummy1 = 42;
    int dummy2 = 84;

    HANDLE h1 = Platform_AllocHandle(HANDLE_TYPE_HWND, &dummy1, NULL);
    HANDLE h2 = Platform_AllocHandle(HANDLE_TYPE_HDC, &dummy2, NULL);

    TEST_ASSERT(h1 != NULL, "Alloc HWND handle");
    TEST_ASSERT(h2 != NULL, "Alloc HDC handle");
    TEST_ASSERT(h1 != h2, "Handles must be distinct");

    /* Ensure 32-bit ID safety */
    TEST_ASSERT((uintptr_t)h1 <= 0xFFFFFFFFU, "HWND must fit in 32-bit int");
    TEST_ASSERT((uintptr_t)h2 <= 0xFFFFFFFFU, "HDC must fit in 32-bit int");

    /* Type validation */
    TEST_ASSERT(Platform_ResolveHandle(h1, HANDLE_TYPE_HWND) == &dummy1, "Resolve matching HWND");
    TEST_ASSERT(Platform_ResolveHandle(h1, HANDLE_TYPE_HDC) == NULL, "Reject mismatched type HWND as HDC");
    TEST_ASSERT(Platform_ResolveHandle(h2, HANDLE_TYPE_HDC) == &dummy2, "Resolve matching HDC");
    TEST_ASSERT(Platform_ResolveHandle(h2, HANDLE_TYPE_HWND) == NULL, "Reject mismatched type HDC as HWND");

    /* Free handle */
    TEST_ASSERT(Platform_FreeHandle(h1, HANDLE_TYPE_HWND) == TRUE, "Free HWND handle");
    TEST_ASSERT(Platform_ResolveHandle(h1, HANDLE_TYPE_HWND) == NULL, "Resolved freed handle returns NULL");
    TEST_ASSERT(Platform_FreeHandle(h1, HANDLE_TYPE_HWND) == FALSE, "Double-free returns FALSE");

    Platform_FreeHandle(h2, HANDLE_TYPE_HDC);
}

/* ==========================================================================
 * 2. Windowing & Classes Tests
 * ========================================================================== */
static LRESULT CustomTestWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_USER + 100) {
        return (LRESULT)(wParam + lParam);
    }
    return DefWindowProcA(hwnd, msg, wParam, lParam);
}

static void Test_Windowing(void)
{
    printf("[Test] Running Windowing & Classes tests...\n");

    WNDCLASSA wc;
    memset(&wc, 0, sizeof(wc));
    wc.lpfnWndProc = CustomTestWndProc;
    wc.lpszClassName = "TestWindowClass";
    ATOM a = RegisterClassA(&wc);
    TEST_ASSERT(a != 0, "RegisterClassA success");

    char className[64];
    HWND topWin = CreateWindowExA(0, "TestWindowClass", "Main Test Window",
                                  WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                                  50, 60, 640, 480, NULL, NULL, NULL, NULL);
    TEST_ASSERT(topWin != NULL, "CreateWindowExA top-level window");
    TEST_ASSERT(IsWindowVisible(topWin), "Window is visible");

    GetClassNameA(topWin, className, sizeof(className));
    TEST_ASSERT(strcmp(className, "TestWindowClass") == 0, "GetClassNameA matches registered name");

    /* Test user data and window longs */
    SetWindowLongA(topWin, GWL_USERDATA, 0x12345678);
    TEST_ASSERT(GetWindowLongA(topWin, GWL_USERDATA) == 0x12345678, "Get/SetWindowLongA GWL_USERDATA");

    char titleBuf[128];
    GetWindowTextA(topWin, titleBuf, sizeof(titleBuf));
    TEST_ASSERT(strcmp(titleBuf, "Main Test Window") == 0, "GetWindowTextA matches title");

    SetWindowTextA(topWin, "Updated Title");
    GetWindowTextA(topWin, titleBuf, sizeof(titleBuf));
    TEST_ASSERT(strcmp(titleBuf, "Updated Title") == 0, "SetWindowTextA updates title");

    /* Child controls */
    HWND childBtn = CreateWindowExA(0, "BUTTON", "OK Button",
                                    WS_CHILD | WS_VISIBLE,
                                    10, 20, 100, 30, topWin, (HMENU)(intptr_t)101, NULL, NULL);
    TEST_ASSERT(childBtn != NULL, "CreateWindowExA child button");
    TEST_ASSERT(GetParent(childBtn) == topWin, "GetParent returns top-level window");
    TEST_ASSERT(GetDlgCtrlID(childBtn) == 101, "GetDlgCtrlID matches control ID");
    TEST_ASSERT(GetDlgItem(topWin, 101) == childBtn, "GetDlgItem finds child by ID");

    /* Test button check state */
    CheckDlgButton(topWin, 101, BST_CHECKED);
    TEST_ASSERT(IsDlgButtonChecked(topWin, 101) == BST_CHECKED, "CheckDlgButton / IsDlgButtonChecked");

    /* Test Geometry */
    RECT rcClient, rcWindow;
    GetClientRect(topWin, &rcClient);
    GetWindowRect(topWin, &rcWindow);
    TEST_ASSERT(rcClient.right - rcClient.left == 640, "Client width is 640");
    TEST_ASSERT(rcClient.bottom - rcClient.top == 480, "Client height is 480");

    POINT pt = {10, 20};
    ClientToScreen(topWin, &pt);
    TEST_ASSERT(pt.x == 60 && pt.y == 80, "ClientToScreen offset calculation");
    ScreenToClient(topWin, &pt);
    TEST_ASSERT(pt.x == 10 && pt.y == 20, "ScreenToClient inverse offset calculation");

    /* Menus */
    HMENU hmenu = CreatePopupMenu();
    TEST_ASSERT(hmenu != NULL, "CreatePopupMenu");
    AppendMenuA(hmenu, MF_STRING, 201, "Item 1");
    AppendMenuA(hmenu, MF_STRING, 202, "Item 2");
    TEST_ASSERT(GetMenuItemCount(hmenu) == 2, "GetMenuItemCount == 2");
    CheckMenuItem(hmenu, 201, MF_CHECKED);
    DestroyMenu(hmenu);

    DestroyWindow(topWin);
    TEST_ASSERT(User_GetWindow(topWin) == NULL, "Top-level window destroyed");
    TEST_ASSERT(User_GetWindow(childBtn) == NULL, "Child window recursively destroyed");
}

/* ==========================================================================
 * 3. Message Queue & Event Tests
 * ========================================================================== */
static void Test_MessageQueue(void)
{
    printf("[Test] Running Message Queue & Events tests...\n");

    HWND win = CreateWindowExA(0, "TestWindowClass", "Msg Window",
                               WS_POPUP, 0, 0, 320, 240, NULL, NULL, NULL, NULL);

    /* Test synchronous SendMessageA */
    LRESULT res = SendMessageA(win, WM_USER + 100, 30, 40);
    TEST_ASSERT(res == 70, "Synchronous SendMessageA dispatch");

    /* Test asynchronous PostMessageA FIFO */
    PostMessageA(win, WM_USER + 1, 10, 100);
    PostMessageA(win, WM_USER + 2, 20, 200);
    PostMessageA(win, WM_USER + 3, 30, 300);

    tagMSG msg;
    /* Peek with PM_NOREMOVE */
    BOOL hasMsg = PeekMessageA(&msg, win, 0, 0, PM_NOREMOVE);
    TEST_ASSERT(hasMsg == TRUE, "PeekMessageA PM_NOREMOVE found message");
    TEST_ASSERT(msg.message == WM_USER + 1, "First peeked message is WM_USER + 1");

    /* GetMessageA retrieves in exact FIFO order */
    TEST_ASSERT(GetMessageA(&msg, win, 0, 0) == TRUE && msg.message == WM_USER + 1, "FIFO msg 1");
    TEST_ASSERT(GetMessageA(&msg, win, 0, 0) == TRUE && msg.message == WM_USER + 2, "FIFO msg 2");
    TEST_ASSERT(GetMessageA(&msg, win, 0, 0) == TRUE && msg.message == WM_USER + 3, "FIFO msg 3");

    /* Test TranslateMessage WM_KEYDOWN -> WM_CHAR */
    tagMSG keyMsg;
    memset(&keyMsg, 0, sizeof(keyMsg));
    keyMsg.hwnd = win;
    keyMsg.message = WM_KEYDOWN;
    keyMsg.wParam = 'A';
    TranslateMessage(&keyMsg);

    TEST_ASSERT(PeekMessageA(&msg, win, 0, 0, PM_REMOVE) == TRUE, "TranslateMessage posted WM_CHAR");
    TEST_ASSERT(msg.message == WM_CHAR && msg.wParam == 'a', "Translated char is 'a'");

    /* Test Timers */
    UINT_PTR timerId = SetTimer(win, 55, 10, NULL);
    TEST_ASSERT(timerId == 55, "SetTimer returns timer ID");
    TEST_ASSERT(KillTimer(win, 55) == TRUE, "KillTimer success");

    /* Test Quit Message */
    PostQuitMessage(42);
    TEST_ASSERT(GetMessageA(&msg, win, 0, 0) == FALSE, "GetMessageA returns FALSE on WM_QUIT");
    TEST_ASSERT(msg.message == WM_QUIT && msg.wParam == 42, "WM_QUIT carries exit code 42");

    DestroyWindow(win);
}

/* ==========================================================================
 * 4. GDI & DIBSection Tests
 * ========================================================================== */
static void Test_GDI(void)
{
    printf("[Test] Running GDI & DIBSection tests...\n");

    HDC hdcScreen = GetDC(NULL);
    TEST_ASSERT(hdcScreen != NULL, "GetDC screen DC");

    HDC memDC = CreateCompatibleDC(hdcScreen);
    TEST_ASSERT(memDC != NULL, "CreateCompatibleDC");

    /* Create 8-bit DIBSection with 4-byte row alignment */
    struct {
        BITMAPINFOHEADER bmiHeader;
        RGBQUAD          bmiColors[256];
    } bmi;
    memset(&bmi, 0, sizeof(bmi));
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = 100;
    bmi.bmiHeader.biHeight = 100;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 8;
    bmi.bmiHeader.biCompression = BI_RGB;
    bmi.bmiHeader.biClrUsed = 256;

    for (int i = 0; i < 256; i++) {
        bmi.bmiColors[i].rgbRed = (BYTE)i;
        bmi.bmiColors[i].rgbGreen = (BYTE)i;
        bmi.bmiColors[i].rgbBlue = (BYTE)i;
    }

    void *bits = NULL;
    HBITMAP hDIB = CreateDIBSection(memDC, (const BITMAPINFO *)&bmi, DIB_RGB_COLORS, &bits, NULL, 0);
    TEST_ASSERT(hDIB != NULL, "CreateDIBSection returns valid handle");
    TEST_ASSERT(bits != NULL, "CreateDIBSection returns valid bit pointer");

    BITMAP bm;
    GetObjectA(hDIB, sizeof(bm), &bm);
    TEST_ASSERT(bm.bmWidth == 100, "Bitmap width is 100");
    TEST_ASSERT(bm.bmHeight == 100, "Bitmap height is 100");
    TEST_ASSERT(bm.bmWidthBytes == 100, "Bitmap row pitch with 4-byte alignment (100 is multiple of 4)");
    TEST_ASSERT(bm.bmBitsPixel == 8, "Bitmap bpp is 8");

    /* Select DIB into memory DC */
    HBITMAP oldBmp = (HBITMAP)SelectObject(memDC, hDIB);
    TEST_ASSERT(oldBmp != NULL, "SelectObject DIBSection into Memory DC");

    /* Test Drawing Primitives & ROPs */
    HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
    RECT rc = {10, 10, 50, 50};
    FillRect(memDC, &rc, redBrush);

    /* Verify pixel inside rect was filled */
    COLORREF px = GetPixel(memDC, 20, 20);
    TEST_ASSERT(px != 0, "GetPixel inside filled rect");

    /* Test BitBlt SRCCOPY to another DC */
    HDC memDC2 = CreateCompatibleDC(hdcScreen);
    void *bits2 = NULL;
    HBITMAP hDIB2 = CreateDIBSection(memDC2, (const BITMAPINFO *)&bmi, DIB_RGB_COLORS, &bits2, NULL, 0);
    SelectObject(memDC2, hDIB2);

    BOOL bltRes = BitBlt(memDC2, 0, 0, 100, 100, memDC, 0, 0, SRCCOPY);
    TEST_ASSERT(bltRes == TRUE, "BitBlt SRCCOPY");

    COLORREF px2 = GetPixel(memDC2, 20, 20);
    TEST_ASSERT(px2 == px, "Pixel copied correctly via BitBlt");

    /* Stock objects */
    HGDIOBJ stockBrush = GetStockObject(WHITE_BRUSH);
    TEST_ASSERT(stockBrush != NULL, "GetStockObject WHITE_BRUSH");
    TEST_ASSERT(DeleteObject(stockBrush) == TRUE, "DeleteObject on stock object does not fail");

    DeleteObject(redBrush);
    DeleteObject(hDIB);
    DeleteObject(hDIB2);
    DeleteDC(memDC);
    DeleteDC(memDC2);
    ReleaseDC(NULL, hdcScreen);
}

/* ==========================================================================
 * 5. Kernel, Files & Memory Tests
 * ========================================================================== */
static DWORD WorkerThreadFunc(void *param)
{
    int val = (int)(intptr_t)param;
    return (DWORD)(val * 2);
}

static void Test_Kernel(void)
{
    printf("[Test] Running Kernel, Files, Threads & Memory tests...\n");

    /* File I/O */
    const char *testFile = "test_temp_file.bin";
    HANDLE hFile = CreateFileA(testFile, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
    TEST_ASSERT(hFile != INVALID_HANDLE_VALUE, "CreateFileA write mode");

    const char testData[] = "Magic: The Gathering 1997 Shandalar Test";
    DWORD written = 0;
    WriteFile(hFile, testData, (DWORD)strlen(testData), &written, NULL);
    TEST_ASSERT(written == strlen(testData), "WriteFile wrote all bytes");

    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
    char readBuf[128];
    memset(readBuf, 0, sizeof(readBuf));
    DWORD readBytes = 0;
    ReadFile(hFile, readBuf, sizeof(readBuf) - 1, &readBytes, NULL);
    TEST_ASSERT(readBytes == written, "ReadFile read exact byte count");
    TEST_ASSERT(strcmp(readBuf, testData) == 0, "ReadFile read correct string content");

    DWORD sz = GetFileSize(hFile, NULL);
    TEST_ASSERT(sz == written, "GetFileSize matches written size");

    CloseHandle(hFile);
    DeleteFileA(testFile);

    /* Critical Section recursion */
    CRITICAL_SECTION cs;
    InitializeCriticalSection(&cs);
    EnterCriticalSection(&cs);
    EnterCriticalSection(&cs); /* Recursive lock */
    LeaveCriticalSection(&cs);
    LeaveCriticalSection(&cs);
    DeleteCriticalSection(&cs);

    /* Thread creation & wait */
    DWORD threadId = 0;
    HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)WorkerThreadFunc, (LPVOID)(intptr_t)21, 0, &threadId);
    TEST_ASSERT(hThread != NULL, "CreateThread");
    TEST_ASSERT(threadId > 0, "Valid thread ID assigned");

    WaitForSingleObject(hThread, 5000);
    DWORD exitCode = 0;
    GetExitCodeThread(hThread, &exitCode);
    TEST_ASSERT(exitCode == 42, "Worker thread returned correct exit code");
    CloseHandle(hThread);

    /* Global Memory */
    HGLOBAL hMem = GlobalAlloc(GMEM_ZEROINIT, 256);
    TEST_ASSERT(hMem != NULL, "GlobalAlloc");
    void *ptr = GlobalLock(hMem);
    TEST_ASSERT(ptr != NULL, "GlobalLock returns memory pointer");
    GlobalUnlock(hMem);
    GlobalFree(hMem);

    /* Atomics */
    LONG counter = 10;
    TEST_ASSERT(InterlockedIncrement(&counter) == 11, "InterlockedIncrement");
    TEST_ASSERT(InterlockedDecrement(&counter) == 10, "InterlockedDecrement");

    /* Strings & Formatting */
    char fmtBuf[64];
    wsprintfA(fmtBuf, "Score: %d, Name: %s", 100, "Player");
    TEST_ASSERT(strcmp(fmtBuf, "Score: 100, Name: Player") == 0, "wsprintfA formatting");
}

/* ==========================================================================
 * 6. Config & Multimedia Tests
 * ========================================================================== */
static void Test_ConfigAndMultimedia(void)
{
    printf("[Test] Running Config & Multimedia tests...\n");

    /* Registry Emulation */
    HKEY hk = NULL;
    LONG r = RegCreateKeyExA(HKEY_CURRENT_USER, "Software\\MicroProse\\Magic", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hk, NULL);
    TEST_ASSERT(r == ERROR_SUCCESS, "RegCreateKeyExA");

    DWORD val = 1234;
    RegSetValueExA(hk, "TestSetting", 0, REG_DWORD, (const BYTE *)&val, sizeof(val));

    DWORD readVal = 0;
    DWORD readSz = sizeof(readVal);
    DWORD type = 0;
    LONG r2 = RegQueryValueExA(hk, "TestSetting", NULL, &type, (LPBYTE)&readVal, &readSz);
    TEST_ASSERT(r2 == ERROR_SUCCESS && readVal == 1234, "RegSetValueExA / RegQueryValueExA match");
    RegCloseKey(hk);

    /* WinMM Timers */
    DWORD t1 = timeGetTime();
    TEST_ASSERT(t1 > 0, "timeGetTime returns positive monotonic tick");
    UINT mmTimer = timeSetEvent(10, 0, NULL, 0, TIME_ONESHOT);
    TEST_ASSERT(mmTimer > 0, "timeSetEvent returns valid timer ID");
    TEST_ASSERT(timeKillEvent(mmTimer) == 0, "timeKillEvent succeeds");

    /* AVI / MMIO */
    AVIFileInit();
    AVIFileExit();
    TEST_ASSERT(AVIStreamSampleToTime(NULL, 15) == 15 * 66, "AVIStreamSampleToTime calculation");
}

/* ==========================================================================
 * 7. Manifest Integrity Test
 * ========================================================================== */
static void Test_ApiManifest(void)
{
    printf("[Test] Running API Manifest Integrity test...\n");

    size_t count = 0;
    const ApiEntry *manifest = Platform_GetApiManifest(&count);
    TEST_ASSERT(count == 358, "API Manifest must contain exactly 358 Win32 APIs");
    TEST_ASSERT(manifest != NULL, "Manifest pointer valid");

    /* Check sample APIs across all subsystems */
    TEST_ASSERT(Platform_FindApiEntry("CreateWindowExA") != NULL, "CreateWindowExA in manifest");
    TEST_ASSERT(Platform_FindApiEntry("BitBlt") != NULL, "BitBlt in manifest");
    TEST_ASSERT(Platform_FindApiEntry("CreateFileA") != NULL, "CreateFileA in manifest");
    TEST_ASSERT(Platform_FindApiEntry("RegOpenKeyExA") != NULL, "RegOpenKeyExA in manifest");
    TEST_ASSERT(Platform_FindApiEntry("timeSetEvent") != NULL, "timeSetEvent in manifest");
    TEST_ASSERT(Platform_FindApiEntry("AVIFileOpenA") != NULL, "AVIFileOpenA in manifest");
}

/* ==========================================================================
 * Main Test Runner
 * ========================================================================== */
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

    printf("=========================================================\n");
    printf(" Shandalar Win32 API Compatibility Layer Test Suite\n");
    printf("=========================================================\n");

    Platform_InitWin32Subsystems();

    printf("1. Running Test_Handles...\n");
    Test_Handles();
    printf("2. Running Test_Windowing...\n");
    Test_Windowing();
    printf("3. Running Test_MessageQueue...\n");
    Test_MessageQueue();
    printf("4. Running Test_GDI...\n");
    Test_GDI();
    printf("5. Running Test_Kernel...\n");
    Test_Kernel();
    printf("6. Running Test_ConfigAndMultimedia...\n");
    Test_ConfigAndMultimedia();
    printf("7. Running Test_ApiManifest...\n");
    Test_ApiManifest();

    Platform_ShutdownWin32Subsystems();
    SDL_Quit();

    printf("=========================================================\n");
    printf(" Test Results: %d / %d tests passed successfully!\n", g_TestsPassed, g_TestsRun);
    printf("=========================================================\n");

    return (g_TestsPassed == g_TestsRun) ? 0 : 1;
}
