/*
 * src/platform/win32_kernel.c - Win32 Kernel Subsystem (Files, Mappings, Memory, Threads, Modules, Strings)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <wchar.h>

#include <SDL.h>

#include "windows_types.h"
#include "shandalar/platform_handle.h"
#include "shandalar/win32_internal.h"
#include "shandalar/win32_compat.h"

/* Thread-local error code */
static __thread DWORD g_LastError = ERROR_SUCCESS;

/* Destructors */
static void FileDestructor(void *ptr)
{
    Win32File *f = (Win32File *)ptr;
    if (!f) return;
    if (f->fp) {
        fclose(f->fp);
        f->fp = NULL;
    }
    free(f);
}

static void MappingDestructor(void *ptr)
{
    Win32Mapping *m = (Win32Mapping *)ptr;
    if (!m) return;
    if (m->mapped_data) {
        free(m->mapped_data);
        m->mapped_data = NULL;
    }
    free(m);
}

static void ThreadDestructor(void *ptr)
{
    Win32Thread *t = (Win32Thread *)ptr;
    if (!t) return;
    if (t->sdl_thread && !t->is_finished) {
        SDL_WaitThread(t->sdl_thread, NULL);
    }
    free(t);
}

static void GlobalMemDestructor(void *ptr)
{
    if (ptr) free(ptr);
}

void Kernel_InternalInit(void)
{
    Platform_HandleInit();
}

void Kernel_InternalShutdown(void)
{
}

/* ==========================================================================
 * Error Handling
 * ========================================================================== */

DWORD GetLastError(void)
{
    return g_LastError;
}

void SetLastError(DWORD dwErrCode)
{
    g_LastError = dwErrCode;
}

/* ==========================================================================
 * File Operations
 * ========================================================================== */

HANDLE CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
                   LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition,
                   DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
    (void)lpSecurityAttributes;
    (void)dwFlagsAndAttributes;
    (void)hTemplateFile;

    if (!lpFileName) {
        SetLastError(ERROR_INVALID_PARAMETER);
        return INVALID_HANDLE_VALUE;
    }

    const char *resolved_path = Platform_ResolveAssetPath(lpFileName);

    const char *mode = "rb";
    if ((dwDesiredAccess & GENERIC_READ) && (dwDesiredAccess & GENERIC_WRITE)) {
        if (dwCreationDisposition == CREATE_ALWAYS || dwCreationDisposition == TRUNCATE_EXISTING) mode = "wb+";
        else if (dwCreationDisposition == OPEN_ALWAYS) mode = "ab+";
        else mode = "rb+";
    } else if (dwDesiredAccess & GENERIC_WRITE) {
        if (dwCreationDisposition == CREATE_ALWAYS || dwCreationDisposition == TRUNCATE_EXISTING) mode = "wb";
        else mode = "ab";
    } else {
        mode = "rb";
    }

    FILE *fp = fopen(resolved_path, mode);
    if (!fp) {
        if (dwCreationDisposition == OPEN_ALWAYS || dwCreationDisposition == CREATE_ALWAYS) {
            fp = fopen(resolved_path, "wb+");
        }
    }

    if (!fp) {
        SetLastError(ERROR_FILE_NOT_FOUND);
        return INVALID_HANDLE_VALUE;
    }

    Win32File *wf = (Win32File *)calloc(1, sizeof(Win32File));
    if (!wf) {
        fclose(fp);
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        return INVALID_HANDLE_VALUE;
    }

    wf->fp = fp;
    wf->fd = fileno(fp);
    wf->access = dwDesiredAccess;
    wf->share = dwShareMode;
    wf->disposition = dwCreationDisposition;
    strncpy(wf->path, resolved_path, sizeof(wf->path) - 1);

    HANDLE h = Platform_AllocHandle(HANDLE_TYPE_FILE, wf, FileDestructor);
    wf->hfile = h;
    SetLastError(ERROR_SUCCESS);
    return h;
}

BOOL ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead,
              LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped)
{
    (void)lpOverlapped;
    Win32File *wf = (Win32File *)Platform_ResolveHandle(hFile, HANDLE_TYPE_FILE);
    if (!wf || !wf->fp || !lpBuffer) {
        SetLastError(ERROR_INVALID_HANDLE);
        if (lpNumberOfBytesRead) *lpNumberOfBytesRead = 0;
        return FALSE;
    }

    size_t read_bytes = fread(lpBuffer, 1, nNumberOfBytesToRead, wf->fp);
    if (lpNumberOfBytesRead) *lpNumberOfBytesRead = (DWORD)read_bytes;
    SetLastError(ERROR_SUCCESS);
    return TRUE;
}

BOOL WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite,
               LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped)
{
    (void)lpOverlapped;
    Win32File *wf = (Win32File *)Platform_ResolveHandle(hFile, HANDLE_TYPE_FILE);
    if (!wf || !wf->fp || !lpBuffer) {
        SetLastError(ERROR_INVALID_HANDLE);
        if (lpNumberOfBytesWritten) *lpNumberOfBytesWritten = 0;
        return FALSE;
    }

    size_t written = fwrite(lpBuffer, 1, nNumberOfBytesToWrite, wf->fp);
    if (lpNumberOfBytesWritten) *lpNumberOfBytesWritten = (DWORD)written;
    SetLastError(ERROR_SUCCESS);
    return TRUE;
}

DWORD SetFilePointer(HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod)
{
    (void)lpDistanceToMoveHigh;
    Win32File *wf = (Win32File *)Platform_ResolveHandle(hFile, HANDLE_TYPE_FILE);
    if (!wf || !wf->fp) {
        SetLastError(ERROR_INVALID_HANDLE);
        return INVALID_SET_FILE_POINTER;
    }

    int origin = SEEK_SET;
    if (dwMoveMethod == FILE_CURRENT) origin = SEEK_CUR;
    else if (dwMoveMethod == FILE_END) origin = SEEK_END;

    if (fseek(wf->fp, lDistanceToMove, origin) != 0) {
        SetLastError(ERROR_INVALID_PARAMETER);
        return INVALID_SET_FILE_POINTER;
    }

    long pos = ftell(wf->fp);
    SetLastError(ERROR_SUCCESS);
    return (DWORD)pos;
}

BOOL SetEndOfFile(HANDLE hFile)
{
    Win32File *wf = (Win32File *)Platform_ResolveHandle(hFile, HANDLE_TYPE_FILE);
    if (!wf || !wf->fp) {
        SetLastError(ERROR_INVALID_HANDLE);
        return FALSE;
    }
    long pos = ftell(wf->fp);
    fflush(wf->fp);
    if (ftruncate(wf->fd, pos) != 0) {
        SetLastError(ERROR_ACCESS_DENIED);
        return FALSE;
    }
    return TRUE;
}

BOOL FlushFileBuffers(HANDLE hFile)
{
    Win32File *wf = (Win32File *)Platform_ResolveHandle(hFile, HANDLE_TYPE_FILE);
    if (!wf || !wf->fp) return FALSE;
    return fflush(wf->fp) == 0;
}

DWORD GetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh)
{
    if (lpFileSizeHigh) *lpFileSizeHigh = 0;
    Win32File *wf = (Win32File *)Platform_ResolveHandle(hFile, HANDLE_TYPE_FILE);
    if (!wf || !wf->fp) {
        SetLastError(ERROR_INVALID_HANDLE);
        return INVALID_FILE_SIZE;
    }

    long cur = ftell(wf->fp);
    fseek(wf->fp, 0, SEEK_END);
    long sz = ftell(wf->fp);
    fseek(wf->fp, cur, SEEK_SET);

    SetLastError(ERROR_SUCCESS);
    return (DWORD)sz;
}

DWORD GetFileType(HANDLE hFile)
{
    (void)hFile;
    return 1; /* FILE_TYPE_DISK */
}

BOOL CloseHandle(HANDLE hObject)
{
    if (!hObject || hObject == INVALID_HANDLE_VALUE) return FALSE;
    HandleType t = Platform_GetHandleType(hObject);
    if (t == HANDLE_TYPE_NONE) return FALSE;
    return Platform_FreeHandle(hObject, t);
}

BOOL CopyFileA(LPCSTR lpExistingFileName, LPCSTR lpNewFileName, BOOL bFailIfExists)
{
    if (!lpExistingFileName || !lpNewFileName) return FALSE;

    const char *src_path = Platform_ResolveAssetPath(lpExistingFileName);
    const char *dst_path = Platform_ResolveAssetPath(lpNewFileName);

    if (bFailIfExists) {
        FILE *check = fopen(dst_path, "rb");
        if (check) {
            fclose(check);
            SetLastError(ERROR_ACCESS_DENIED);
            return FALSE;
        }
    }

    FILE *src = fopen(src_path, "rb");
    if (!src) {
        SetLastError(ERROR_FILE_NOT_FOUND);
        return FALSE;
    }

    FILE *dst = fopen(dst_path, "wb");
    if (!dst) {
        fclose(src);
        SetLastError(ERROR_ACCESS_DENIED);
        return FALSE;
    }

    char buf[4096];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), src)) > 0) {
        fwrite(buf, 1, n, dst);
    }

    fclose(src);
    fclose(dst);
    SetLastError(ERROR_SUCCESS);
    return TRUE;
}

BOOL DeleteFileA(LPCSTR lpFileName)
{
    if (!lpFileName) return FALSE;
    const char *path = Platform_ResolveAssetPath(lpFileName);
    return remove(path) == 0;
}

BOOL CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
    (void)lpSecurityAttributes;
    if (!lpPathName) return FALSE;
    const char *path = Platform_ResolveAssetPath(lpPathName);
    return mkdir(path, 0755) == 0;
}

DWORD GetCurrentDirectoryA(DWORD nBufferLength, LPSTR lpBuffer)
{
    if (!lpBuffer || nBufferLength == 0) return 0;
    if (!getcwd(lpBuffer, nBufferLength)) return 0;
    return (DWORD)strlen(lpBuffer);
}

BOOL SetCurrentDirectoryA(LPCSTR lpPathName)
{
    if (!lpPathName) return FALSE;
    const char *path = Platform_ResolveAssetPath(lpPathName);
    return chdir(path) == 0;
}

UINT GetDriveTypeA(LPCSTR lpRootPathName)
{
    (void)lpRootPathName;
    return DRIVE_FIXED;
}

BOOL DeviceIoControl(HANDLE hDevice, DWORD dwIoControlCode, LPVOID lpInBuffer, DWORD nInBufferSize,
                     LPVOID lpOutBuffer, DWORD nOutBufferSize, LPDWORD lpBytesReturned, LPOVERLAPPED lpOverlapped)
{
    (void)hDevice;
    (void)dwIoControlCode;
    (void)lpInBuffer;
    (void)nInBufferSize;
    (void)lpOutBuffer;
    (void)nOutBufferSize;
    (void)lpOverlapped;
    if (lpBytesReturned) *lpBytesReturned = 0;
    return TRUE;
}

HFILE _lopen(LPCSTR lpPathName, int iReadWrite)
{
    DWORD access = GENERIC_READ;
    if (iReadWrite == 1) access = GENERIC_WRITE;
    else if (iReadWrite == 2) access = GENERIC_READ | GENERIC_WRITE;
    return (HFILE)(intptr_t)CreateFileA(lpPathName, access, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
}

HFILE _lclose(HFILE hFile)
{
    CloseHandle((HANDLE)(intptr_t)hFile);
    return 0;
}

UINT SetHandleCount(UINT uNumber)
{
    return uNumber;
}

BOOL SetStdHandle(DWORD nStdHandle, HANDLE hHandle)
{
    (void)nStdHandle;
    (void)hHandle;
    return TRUE;
}

HANDLE GetStdHandle(DWORD nStdHandle)
{
    (void)nStdHandle;
    return (HANDLE)(intptr_t)1;
}

/* ==========================================================================
 * Memory Mappings
 * ========================================================================== */

HANDLE CreateFileMappingA(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
                          DWORD flProtect, DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow,
                          LPCSTR lpName)
{
    (void)lpFileMappingAttributes;
    (void)lpName;

    Win32Mapping *m = (Win32Mapping *)calloc(1, sizeof(Win32Mapping));
    if (!m) return NULL;

    m->hfile = hFile;
    m->protect = flProtect;
    m->max_size_low = dwMaximumSizeLow;
    m->max_size_high = dwMaximumSizeHigh;

    size_t sz = 0;
    if (hFile && hFile != INVALID_HANDLE_VALUE) {
        sz = GetFileSize(hFile, NULL);
    }
    if (dwMaximumSizeLow > sz) sz = dwMaximumSizeLow;
    m->size = sz;

    HANDLE h = Platform_AllocHandle(HANDLE_TYPE_MAPPING, m, MappingDestructor);
    m->hmap = h;
    return h;
}

LPVOID MapViewOfFile(HANDLE hFileMappingObject, DWORD dwDesiredAccess,
                     DWORD dwFileOffsetHigh, DWORD dwFileOffsetLow,
                     SIZE_T dwNumberOfBytesToMap)
{
    (void)dwDesiredAccess;
    (void)dwFileOffsetHigh;

    Win32Mapping *m = (Win32Mapping *)Platform_ResolveHandle(hFileMappingObject, HANDLE_TYPE_MAPPING);
    if (!m) return NULL;

    size_t sz = dwNumberOfBytesToMap ? dwNumberOfBytesToMap : m->size;
    if (sz == 0) sz = 4096;

    void *mem = calloc(1, sz);
    if (!mem) return NULL;

    if (m->hfile && m->hfile != INVALID_HANDLE_VALUE) {
        SetFilePointer(m->hfile, (LONG)dwFileOffsetLow, NULL, FILE_BEGIN);
        DWORD read_bytes = 0;
        ReadFile(m->hfile, mem, (DWORD)sz, &read_bytes, NULL);
    }

    m->mapped_data = mem;
    return mem;
}

BOOL UnmapViewOfFile(LPCVOID lpBaseAddress)
{
    if (lpBaseAddress) {
        free((void *)lpBaseAddress);
        return TRUE;
    }
    return FALSE;
}

/* ==========================================================================
 * Resources
 * ========================================================================== */

HRSRC FindResourceA(HMODULE hModule, LPCSTR lpName, LPCSTR lpType)
{
    (void)hModule;
    (void)lpName;
    (void)lpType;
    return (HRSRC)(uintptr_t)1;
}

HGLOBAL LoadResource(HMODULE hModule, HRSRC hResInfo)
{
    (void)hModule;
    (void)hResInfo;
    return (HGLOBAL)(uintptr_t)1;
}

LPVOID LockResource(HGLOBAL hResData)
{
    (void)hResData;
    static uint8_t s_DummyRes[256] = {0};
    return s_DummyRes;
}

/* ==========================================================================
 * Global, Local & Virtual Memory
 * ========================================================================== */

HGLOBAL GlobalAlloc(UINT uFlags, SIZE_T dwBytes)
{
    void *mem = NULL;
    if (uFlags & GMEM_ZEROINIT) {
        mem = calloc(1, dwBytes ? dwBytes : 1);
    } else {
        mem = malloc(dwBytes ? dwBytes : 1);
    }

    if (!mem) return NULL;
    return (HGLOBAL)Platform_AllocHandle(HANDLE_TYPE_GLOBAL_MEM, mem, GlobalMemDestructor);
}

HGLOBAL GlobalFree(HGLOBAL hMem)
{
    Platform_FreeHandle(hMem, HANDLE_TYPE_GLOBAL_MEM);
    return NULL;
}

LPVOID GlobalLock(HGLOBAL hMem)
{
    return Platform_ResolveHandle(hMem, HANDLE_TYPE_GLOBAL_MEM);
}

BOOL GlobalUnlock(HGLOBAL hMem)
{
    (void)hMem;
    return TRUE;
}

HGLOBAL GlobalHandle(LPCVOID pMem)
{
    (void)pMem;
    return NULL;
}

HLOCAL LocalFree(HLOCAL hMem)
{
    return (HLOCAL)GlobalFree((HGLOBAL)hMem);
}

LPVOID VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect)
{
    (void)lpAddress;
    (void)flAllocationType;
    (void)flProtect;
    return calloc(1, dwSize);
}

BOOL VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType)
{
    (void)dwSize;
    (void)dwFreeType;
    if (lpAddress) free(lpAddress);
    return TRUE;
}

LPVOID HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes)
{
    (void)hHeap;
    if (dwFlags & 0x00000008) return calloc(1, dwBytes); /* HEAP_ZERO_MEMORY */
    return malloc(dwBytes);
}

LPVOID HeapReAlloc(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes)
{
    (void)hHeap;
    (void)dwFlags;
    return realloc(lpMem, dwBytes);
}

BOOL HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem)
{
    (void)hHeap;
    (void)dwFlags;
    if (lpMem) free(lpMem);
    return TRUE;
}

HANDLE HeapCreate(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize)
{
    (void)flOptions;
    (void)dwInitialSize;
    (void)dwMaximumSize;
    return (HANDLE)(intptr_t)1;
}

BOOL HeapDestroy(HANDLE hHeap)
{
    (void)hHeap;
    return TRUE;
}

BOOL HeapValidate(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem)
{
    (void)hHeap;
    (void)dwFlags;
    (void)lpMem;
    return TRUE;
}

BOOL IsBadReadPtr(const void *lp, UINT_PTR ucb)
{
    (void)ucb;
    return (lp == NULL);
}

BOOL IsBadWritePtr(LPVOID lp, UINT_PTR ucb)
{
    (void)ucb;
    return (lp == NULL);
}

/* ==========================================================================
 * Synchronization & Threads
 * ========================================================================== */

void InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
    if (!lpCriticalSection) return;
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_t *mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    if (mutex) {
        pthread_mutex_init(mutex, &attr);
        lpCriticalSection->DebugInfo = mutex;
    }
    pthread_mutexattr_destroy(&attr);
}

void DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
    if (!lpCriticalSection || !lpCriticalSection->DebugInfo) return;
    pthread_mutex_t *mutex = (pthread_mutex_t *)lpCriticalSection->DebugInfo;
    pthread_mutex_destroy(mutex);
    free(mutex);
    lpCriticalSection->DebugInfo = NULL;
}

void EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
    if (!lpCriticalSection || !lpCriticalSection->DebugInfo) return;
    pthread_mutex_t *mutex = (pthread_mutex_t *)lpCriticalSection->DebugInfo;
    pthread_mutex_lock(mutex);
}

void LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
    if (!lpCriticalSection || !lpCriticalSection->DebugInfo) return;
    pthread_mutex_t *mutex = (pthread_mutex_t *)lpCriticalSection->DebugInfo;
    pthread_mutex_unlock(mutex);
}

static int ThreadRunner(void *param)
{
    Win32Thread *t = (Win32Thread *)param;
    if (!t || !t->start_addr) return 0;

    DWORD (*func)(void *) = (DWORD (*)(void *))t->start_addr;
    t->exit_code = func(t->param);
    t->is_finished = true;
    return (int)t->exit_code;
}

HANDLE CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize,
                    LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter,
                    DWORD dwCreationFlags, LPDWORD lpThreadId)
{
    (void)lpThreadAttributes;
    (void)dwStackSize;
    (void)dwCreationFlags;

    Win32Thread *t = (Win32Thread *)calloc(1, sizeof(Win32Thread));
    if (!t) return NULL;

    static DWORD s_ThreadIdGen = 100;
    t->thread_id = ++s_ThreadIdGen;
    t->start_addr = (void *)lpStartAddress;
    t->param = lpParameter;
    t->is_finished = false;

    if (lpThreadId) *lpThreadId = t->thread_id;

    HANDLE h = Platform_AllocHandle(HANDLE_TYPE_THREAD, t, ThreadDestructor);
    t->hthread = h;

    t->sdl_thread = SDL_CreateThread(ThreadRunner, "Win32Worker", t);
    return h;
}

void ExitThread(DWORD dwExitCode)
{
    pthread_exit((void *)(intptr_t)dwExitCode);
}

BOOL GetExitCodeThread(HANDLE hThread, LPDWORD lpExitCode)
{
    Win32Thread *t = (Win32Thread *)Platform_ResolveHandle(hThread, HANDLE_TYPE_THREAD);
    if (!t) return FALSE;
    if (lpExitCode) *lpExitCode = t->exit_code;
    return TRUE;
}

DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds)
{
    Win32Thread *t = (Win32Thread *)Platform_ResolveHandle(hHandle, HANDLE_TYPE_THREAD);
    if (t && t->sdl_thread) {
        if (dwMilliseconds == 0) {
            return t->is_finished ? 0 : 0x00000102L; /* WAIT_TIMEOUT */
        }
        SDL_WaitThread(t->sdl_thread, NULL);
        t->sdl_thread = NULL;
        return 0; /* WAIT_OBJECT_0 */
    }
    return 0;
}

HANDLE GetCurrentProcess(void)
{
    return (HANDLE)(intptr_t)1;
}

HANDLE GetCurrentThread(void)
{
    return (HANDLE)(intptr_t)1;
}

BOOL DuplicateHandle(HANDLE hSourceProcessHandle, HANDLE hSourceHandle,
                     HANDLE hTargetProcessHandle, LPHANDLE lpTargetHandle,
                     DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwOptions)
{
    (void)hSourceProcessHandle;
    (void)hTargetProcessHandle;
    (void)dwDesiredAccess;
    (void)bInheritHandle;
    (void)dwOptions;
    if (lpTargetHandle) *lpTargetHandle = hSourceHandle;
    return TRUE;
}

BOOL TerminateProcess(HANDLE hProcess, UINT uExitCode)
{
    (void)hProcess;
    exit((int)uExitCode);
}

void ExitProcess(UINT uExitCode)
{
    exit((int)uExitCode);
}

int GetThreadPriority(HANDLE hThread)
{
    (void)hThread;
    return 0; /* THREAD_PRIORITY_NORMAL */
}

BOOL SetThreadPriority(HANDLE hThread, int nPriority)
{
    (void)hThread;
    (void)nPriority;
    return TRUE;
}

DWORD GetPriorityClass(HANDLE hProcess)
{
    (void)hProcess;
    return 0x00000020; /* NORMAL_PRIORITY_CLASS */
}

BOOL SetPriorityClass(HANDLE hProcess, DWORD dwPriorityClass)
{
    (void)hProcess;
    (void)dwPriorityClass;
    return TRUE;
}

LONG InterlockedIncrement(LONG volatile *lpAddend)
{
    return __sync_add_and_fetch(lpAddend, 1);
}

LONG InterlockedDecrement(LONG volatile *lpAddend)
{
    return __sync_sub_and_fetch(lpAddend, 1);
}

void Sleep(DWORD dwMilliseconds)
{
    SDL_Delay(dwMilliseconds);
}

/* ==========================================================================
 * Clocks & System Time
 * ========================================================================== */

DWORD GetTickCount(void)
{
    return (DWORD)SDL_GetTicks();
}

void GetLocalTime(LPSYSTEMTIME lpSystemTime)
{
    if (!lpSystemTime) return;
    time_t rawtime;
    time(&rawtime);
    struct tm *t = localtime(&rawtime);

    lpSystemTime->wYear = (WORD)(t->tm_year + 1900);
    lpSystemTime->wMonth = (WORD)(t->tm_mon + 1);
    lpSystemTime->wDayOfWeek = (WORD)t->tm_wday;
    lpSystemTime->wDay = (WORD)t->tm_mday;
    lpSystemTime->wHour = (WORD)t->tm_hour;
    lpSystemTime->wMinute = (WORD)t->tm_min;
    lpSystemTime->wSecond = (WORD)t->tm_sec;
    lpSystemTime->wMilliseconds = (WORD)(SDL_GetTicks() % 1000);
}

void GetSystemTime(LPSYSTEMTIME lpSystemTime)
{
    if (!lpSystemTime) return;
    time_t rawtime;
    time(&rawtime);
    struct tm *t = gmtime(&rawtime);

    lpSystemTime->wYear = (WORD)(t->tm_year + 1900);
    lpSystemTime->wMonth = (WORD)(t->tm_mon + 1);
    lpSystemTime->wDayOfWeek = (WORD)t->tm_wday;
    lpSystemTime->wDay = (WORD)t->tm_mday;
    lpSystemTime->wHour = (WORD)t->tm_hour;
    lpSystemTime->wMinute = (WORD)t->tm_min;
    lpSystemTime->wSecond = (WORD)t->tm_sec;
    lpSystemTime->wMilliseconds = (WORD)(SDL_GetTicks() % 1000);
}

DWORD GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation)
{
    if (lpTimeZoneInformation) {
        memset(lpTimeZoneInformation, 0, sizeof(*lpTimeZoneInformation));
    }
    return 0; /* TIME_ZONE_ID_UNKNOWN */
}

int GetDateFormatA(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpDate,
                   LPCSTR lpFormat, LPSTR lpDateStr, int cchDate)
{
    (void)Locale;
    (void)dwFlags;
    (void)lpFormat;
    if (!lpDateStr || cchDate <= 0) return 0;

    SYSTEMTIME st;
    if (!lpDate) GetLocalTime(&st);
    else st = *lpDate;

    snprintf(lpDateStr, cchDate, "%02d/%02d/%04d", st.wMonth, st.wDay, st.wYear);
    return (int)strlen(lpDateStr);
}

/* ==========================================================================
 * Dynamic Module & DLL Management
 * ========================================================================== */

HMODULE GetModuleHandleA(LPCSTR lpModuleName)
{
    (void)lpModuleName;
    return (HMODULE)(intptr_t)1;
}

DWORD GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize)
{
    (void)hModule;
    if (!lpFilename || nSize == 0) return 0;
    strncpy(lpFilename, "MAGIC.EXE", nSize - 1);
    lpFilename[nSize - 1] = '\0';
    return (DWORD)strlen(lpFilename);
}

HMODULE LoadLibraryA(LPCSTR lpLibFileName)
{
    (void)lpLibFileName;
    return (HMODULE)(intptr_t)1;
}

BOOL FreeLibrary(HMODULE hLibModule)
{
    (void)hLibModule;
    return TRUE;
}

FARPROC GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
    (void)hModule;
    if (!lpProcName) return NULL;
    return NULL;
}

BOOL DisableThreadLibraryCalls(HMODULE hLibModule)
{
    (void)hLibModule;
    return TRUE;
}

/* ==========================================================================
 * Environment & Command Line
 * ========================================================================== */

LPSTR GetCommandLineA(void)
{
    static char s_CmdLine[] = "MAGIC.EXE /MTGshell /6";
    return s_CmdLine;
}

void GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo)
{
    if (!lpStartupInfo) return;
    memset(lpStartupInfo, 0, sizeof(*lpStartupInfo));
    lpStartupInfo->cb = sizeof(*lpStartupInfo);
    lpStartupInfo->dwFlags = 1; /* STARTF_USESHOWWINDOW */
    lpStartupInfo->wShowWindow = SW_SHOWNORMAL;
}

LPVOID GetEnvironmentStrings(void)
{
    static char s_Env[] = "PATH=.\0";
    return s_Env;
}

LPWSTR GetEnvironmentStringsW(void)
{
    static wchar_t s_EnvW[] = L"PATH=.\0";
    return s_EnvW;
}

BOOL FreeEnvironmentStringsA(LPSTR lpszEnvironmentBlock)
{
    (void)lpszEnvironmentBlock;
    return TRUE;
}

BOOL FreeEnvironmentStringsW(LPWSTR lpszEnvironmentBlock)
{
    (void)lpszEnvironmentBlock;
    return TRUE;
}

BOOL SetEnvironmentVariableA(LPCSTR lpName, LPCSTR lpValue)
{
    if (!lpName) return FALSE;
    if (lpValue) setenv(lpName, lpValue, 1);
    else unsetenv(lpName);
    return TRUE;
}

DWORD GetVersion(void)
{
    /* Windows 95 version: Major=4, Minor=0, Build=950 */
    return (DWORD)(4 | (0 << 8) | (0x80000000));
}

UINT GetACP(void)
{
    return 1252; /* ANSI Latin 1 (Windows 95 default) */
}

UINT GetOEMCP(void)
{
    return 437; /* OEM US */
}

BOOL GetCPInfo(UINT CodePage, LPCPINFO lpCPInfo)
{
    (void)CodePage;
    if (!lpCPInfo) return FALSE;
    lpCPInfo->MaxCharSize = 1;
    lpCPInfo->DefaultChar[0] = '?';
    lpCPInfo->DefaultChar[1] = 0;
    memset(lpCPInfo->LeadByte, 0, sizeof(lpCPInfo->LeadByte));
    return TRUE;
}

BOOL GetStringTypeA(LCID Locale, DWORD dwInfoType, LPCSTR lpSrcStr, int cchSrc, LPWORD lpCharType)
{
    (void)Locale;
    (void)dwInfoType;
    if (!lpSrcStr || !lpCharType) return FALSE;
    int len = (cchSrc >= 0) ? cchSrc : (int)strlen(lpSrcStr);
    for (int i = 0; i < len; i++) {
        lpCharType[i] = 0x0001; /* C1_UPPER / C1_LOWER placeholder */
    }
    return TRUE;
}

BOOL GetStringTypeW(DWORD dwInfoType, LPCWSTR lpSrcStr, int cchSrc, LPWORD lpCharType)
{
    (void)dwInfoType;
    if (!lpSrcStr || !lpCharType) return FALSE;
    int len = (cchSrc >= 0) ? cchSrc : (int)wcslen(lpSrcStr);
    for (int i = 0; i < len; i++) {
        lpCharType[i] = 0x0001;
    }
    return TRUE;
}

int LCMapStringA(LCID Locale, DWORD dwMapFlags, LPCSTR lpSrcStr, int cchSrc, LPSTR lpDestStr, int cchDest)
{
    (void)Locale;
    (void)dwMapFlags;
    if (!lpSrcStr) return 0;
    int len = (cchSrc >= 0) ? cchSrc : (int)strlen(lpSrcStr);
    if (!lpDestStr || cchDest <= 0) return len;

    int copy_len = (len < cchDest) ? len : cchDest - 1;
    memcpy(lpDestStr, lpSrcStr, copy_len);
    lpDestStr[copy_len] = '\0';
    return copy_len;
}

int LCMapStringW(LCID Locale, DWORD dwMapFlags, LPCWSTR lpSrcStr, int cchSrc, LPWSTR lpDestStr, int cchDest)
{
    (void)Locale;
    (void)dwMapFlags;
    if (!lpSrcStr) return 0;
    int len = (cchSrc >= 0) ? cchSrc : (int)wcslen(lpSrcStr);
    if (!lpDestStr || cchDest <= 0) return len;

    int copy_len = (len < cchDest) ? len : cchDest - 1;
    wmemcpy(lpDestStr, lpSrcStr, copy_len);
    lpDestStr[copy_len] = L'\0';
    return copy_len;
}

int CompareStringA(LCID Locale, DWORD dwCmpFlags, LPCSTR lpString1, int cchCount1, LPCSTR lpString2, int cchCount2)
{
    (void)Locale;
    (void)dwCmpFlags;
    if (!lpString1 || !lpString2) return 0;
    int res = (cchCount1 >= 0 && cchCount2 >= 0) ?
              strncmp(lpString1, lpString2, (size_t)(cchCount1 < cchCount2 ? cchCount1 : cchCount2)) :
              strcmp(lpString1, lpString2);
    if (res < 0) return 1; /* CSTR_LESS_THAN */
    if (res > 0) return 3; /* CSTR_GREATER_THAN */
    return 2;              /* CSTR_EQUAL */
}

int CompareStringW(LCID Locale, DWORD dwCmpFlags, LPCWSTR lpString1, int cchCount1, LPCWSTR lpString2, int cchCount2)
{
    (void)Locale;
    (void)dwCmpFlags;
    if (!lpString1 || !lpString2) return 0;
    int res = wcscmp(lpString1, lpString2);
    if (res < 0) return 1;
    if (res > 0) return 3;
    return 2;
}

int MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cbMultiByte,
                        LPWSTR lpWideCharStr, int cchWideChar)
{
    (void)CodePage;
    (void)dwFlags;
    if (!lpMultiByteStr) return 0;
    int src_len = (cbMultiByte >= 0) ? cbMultiByte : (int)strlen(lpMultiByteStr);
    if (!lpWideCharStr || cchWideChar <= 0) return src_len;

    int copy_len = (src_len < cchWideChar) ? src_len : cchWideChar;
    for (int i = 0; i < copy_len; i++) {
        lpWideCharStr[i] = (wchar_t)(unsigned char)lpMultiByteStr[i];
    }
    return copy_len;
}

int WideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar,
                        LPSTR lpMultiByteStr, int cbMultiByte, LPCSTR lpDefaultChar, LPBOOL lpUsedDefaultChar)
{
    (void)CodePage;
    (void)dwFlags;
    (void)lpDefaultChar;
    if (lpUsedDefaultChar) *lpUsedDefaultChar = FALSE;
    if (!lpWideCharStr) return 0;

    int src_len = (cchWideChar >= 0) ? cchWideChar : (int)wcslen(lpWideCharStr);
    if (!lpMultiByteStr || cbMultiByte <= 0) return src_len;

    int copy_len = (src_len < cbMultiByte) ? src_len : cbMultiByte;
    for (int i = 0; i < copy_len; i++) {
        lpMultiByteStr[i] = (char)lpWideCharStr[i];
    }
    return copy_len;
}

/* ==========================================================================
 * String & Formatting Routines
 * ========================================================================== */

LPSTR lstrcpyA(LPSTR lpString1, LPCSTR lpString2)
{
    if (!lpString1 || !lpString2) return lpString1;
    return strcpy(lpString1, lpString2);
}

LPSTR lstrcatA(LPSTR lpString1, LPCSTR lpString2)
{
    if (!lpString1 || !lpString2) return lpString1;
    return strcat(lpString1, lpString2);
}

int lstrlenA(LPCSTR lpString)
{
    if (!lpString) return 0;
    return (int)strlen(lpString);
}

int wsprintfA(LPSTR lpOut, LPCSTR lpFmt, ...)
{
    if (!lpOut || !lpFmt) return 0;
    va_list args;
    va_start(args, lpFmt);
    int res = vsprintf(lpOut, lpFmt, args);
    va_end(args);
    return res;
}

int wvsprintfA(LPSTR lpOut, LPCSTR lpFmt, va_list arglist)
{
    if (!lpOut || !lpFmt) return 0;
    return vsprintf(lpOut, lpFmt, arglist);
}

DWORD FormatMessageA(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId,
                     DWORD dwLanguageId, LPSTR lpBuffer, DWORD nSize, va_list *Arguments)
{
    (void)dwFlags;
    (void)lpSource;
    (void)dwMessageId;
    (void)dwLanguageId;
    (void)Arguments;
    if (!lpBuffer || nSize == 0) return 0;
    snprintf(lpBuffer, nSize, "Error 0x%08X", (unsigned int)dwMessageId);
    return (DWORD)strlen(lpBuffer);
}

void OutputDebugStringA(LPCSTR lpOutputString)
{
    if (lpOutputString) {
        fprintf(stderr, "[Win32 Debug] %s", lpOutputString);
    }
}

/* ==========================================================================
 * Misc / CRT Exception & Signals
 * ========================================================================== */

void DebugBreak(void)
{
}

LONG UnhandledExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
    (void)ExceptionInfo;
    return 1; /* EXCEPTION_EXECUTE_HANDLER */
}

BOOL SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine, BOOL Add)
{
    (void)HandlerRoutine;
    (void)Add;
    return TRUE;
}

void RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
    (void)TargetFrame;
    (void)TargetIp;
    (void)ExceptionRecord;
    (void)ReturnValue;
}
