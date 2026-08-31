/*
 * src/platform/win32_multimedia.c - Win32 Multimedia Subsystem (WinMM, Timers, MMIO, DirectSound, AVI)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>

#include <SDL.h>

#include "windows_types.h"
#include "shandalar/platform_handle.h"
#include "shandalar/win32_internal.h"
#include "shandalar/win32_compat.h"

#define MAX_MM_TIMERS 32

typedef struct MmioFile {
    HMMIO    hmmio;
    FILE    *fp;
    DWORD    flags;
} MmioFile;

typedef struct WinMmTimer {
    UINT         id;
    UINT         delay;
    UINT         resolution;
    TIMECALLBACK callback;
    DWORD_PTR    user_data;
    UINT         event_type;
    uint32_t     last_tick;
    bool         is_active;
} WinMmTimer;

static struct {
    WinMmTimer      timers[MAX_MM_TIMERS];
    size_t          timer_count;
    pthread_mutex_t lock;
    bool            is_initialized;
} g_MmState = {0};

static void MmioDestructor(void *ptr)
{
    MmioFile *m = (MmioFile *)ptr;
    if (!m) return;
    if (m->fp) {
        fclose(m->fp);
        m->fp = NULL;
    }
    free(m);
}

void Multimedia_InternalInit(void)
{
    if (g_MmState.is_initialized) return;

    pthread_mutex_init(&g_MmState.lock, NULL);
    pthread_mutex_lock(&g_MmState.lock);

    g_MmState.timer_count = 0;
    g_MmState.is_initialized = true;

    pthread_mutex_unlock(&g_MmState.lock);
}

void Multimedia_InternalShutdown(void)
{
    if (!g_MmState.is_initialized) return;
    pthread_mutex_destroy(&g_MmState.lock);
    g_MmState.is_initialized = false;
}

/* ==========================================================================
 * WinMM Clocks & Timers
 * ========================================================================== */

DWORD timeGetTime(void)
{
    return (DWORD)SDL_GetTicks();
}

MMRESULT timeGetDevCaps(LPTIMECAPS ptc, UINT cbtc)
{
    (void)cbtc;
    if (!ptc) return 1; /* TIMERR_NOCANDO */
    ptc->wPeriodMin = 1;
    ptc->wPeriodMax = 1000;
    return 0; /* TIMERR_NOERROR */
}

MMRESULT timeBeginPeriod(UINT uPeriod)
{
    (void)uPeriod;
    return 0; /* TIMERR_NOERROR */
}

MMRESULT timeEndPeriod(UINT uPeriod)
{
    (void)uPeriod;
    return 0; /* TIMERR_NOERROR */
}

MMRESULT timeSetEvent(UINT uDelay, UINT uResolution, LPTIMECALLBACK lpTimeProc, DWORD_PTR dwUser, UINT fuEvent)
{
    Multimedia_InternalInit();
    pthread_mutex_lock(&g_MmState.lock);

    if (g_MmState.timer_count >= MAX_MM_TIMERS) {
        pthread_mutex_unlock(&g_MmState.lock);
        return 0;
    }

    size_t idx = g_MmState.timer_count++;
    WinMmTimer *t = &g_MmState.timers[idx];
    t->id = (UINT)(idx + 1);
    t->delay = uDelay ? uDelay : 10;
    t->resolution = uResolution;
    t->callback = lpTimeProc;
    t->user_data = dwUser;
    t->event_type = fuEvent;
    t->last_tick = SDL_GetTicks();
    t->is_active = true;

    UINT timer_id = t->id;
    pthread_mutex_unlock(&g_MmState.lock);
    return timer_id;
}

MMRESULT timeKillEvent(UINT uTimerID)
{
    if (!g_MmState.is_initialized || uTimerID == 0) return 1;

    pthread_mutex_lock(&g_MmState.lock);
    for (size_t i = 0; i < g_MmState.timer_count; i++) {
        if (g_MmState.timers[i].id == uTimerID) {
            g_MmState.timers[i].is_active = false;
            pthread_mutex_unlock(&g_MmState.lock);
            return 0; /* TIMERR_NOERROR */
        }
    }
    pthread_mutex_unlock(&g_MmState.lock);
    return 1;
}

/* ==========================================================================
 * MMIO / WAV RIFF Support
 * ========================================================================== */

HMMIO mmioOpenA(LPSTR szFilename, LPMMIOINFO lpmmioinfo, DWORD dwOpenFlags)
{
    (void)lpmmioinfo;
    if (!szFilename) return NULL;

    const char *resolved = Platform_ResolveAssetPath(szFilename);
    const char *mode = (dwOpenFlags & MMIO_WRITE) ? "wb" : ((dwOpenFlags & MMIO_READWRITE) ? "rb+" : "rb");

    FILE *fp = fopen(resolved, mode);
    if (!fp) return NULL;

    MmioFile *m = (MmioFile *)calloc(1, sizeof(MmioFile));
    if (!m) {
        fclose(fp);
        return NULL;
    }

    m->fp = fp;
    m->flags = dwOpenFlags;

    HMMIO hmmio = (HMMIO)Platform_AllocHandle(HANDLE_TYPE_MMIO, m, MmioDestructor);
    m->hmmio = hmmio;
    return hmmio;
}

MMRESULT mmioClose(HMMIO hmmio, UINT uFlags)
{
    (void)uFlags;
    return Platform_FreeHandle(hmmio, HANDLE_TYPE_MMIO) ? 0 : 1;
}

LONG mmioRead(HMMIO hmmio, HPSTR pch, LONG cch)
{
    MmioFile *m = (MmioFile *)Platform_ResolveHandle(hmmio, HANDLE_TYPE_MMIO);
    if (!m || !m->fp || !pch || cch <= 0) return -1;
    return (LONG)fread(pch, 1, (size_t)cch, m->fp);
}

LONG mmioSeek(HMMIO hmmio, LONG lOffset, int iOrigin)
{
    MmioFile *m = (MmioFile *)Platform_ResolveHandle(hmmio, HANDLE_TYPE_MMIO);
    if (!m || !m->fp) return -1;

    int origin = SEEK_SET;
    if (iOrigin == 1) origin = SEEK_CUR;
    else if (iOrigin == 2) origin = SEEK_END;

    if (fseek(m->fp, lOffset, origin) != 0) return -1;
    return (LONG)ftell(m->fp);
}

MMRESULT mmioDescend(HMMIO hmmio, LPMMCKINFO lpck, const MMCKINFO *lpckParent, UINT uFlags)
{
    (void)lpckParent;
    (void)uFlags;
    MmioFile *m = (MmioFile *)Platform_ResolveHandle(hmmio, HANDLE_TYPE_MMIO);
    if (!m || !m->fp || !lpck) return 1;

    lpck->dwDataOffset = (DWORD)ftell(m->fp);
    if (fread(&lpck->ckid, 4, 1, m->fp) != 1) return 1;
    if (fread(&lpck->cksize, 4, 1, m->fp) != 1) return 1;
    if (lpck->ckid == mmioFOURCC('R','I','F','F') || lpck->ckid == mmioFOURCC('L','I','S','T')) {
        fread(&lpck->fccType, 4, 1, m->fp);
    }
    return 0;
}

MMRESULT mmioAscend(HMMIO hmmio, LPMMCKINFO lpck, UINT uFlags)
{
    (void)uFlags;
    MmioFile *m = (MmioFile *)Platform_ResolveHandle(hmmio, HANDLE_TYPE_MMIO);
    if (!m || !m->fp || !lpck) return 1;

    long target = lpck->dwDataOffset + 8 + lpck->cksize;
    if (lpck->cksize & 1) target++;
    fseek(m->fp, target, SEEK_SET);
    return 0;
}

MMRESULT mmioAdvance(HMMIO hmmio, LPMMIOINFO lpmmioinfo, UINT uFlags)
{
    (void)hmmio;
    (void)lpmmioinfo;
    (void)uFlags;
    return 0;
}

MMRESULT mmioSetInfo(HMMIO hmmio, LPCMMIOINFO lpmmioinfo, UINT uFlags)
{
    (void)hmmio;
    (void)lpmmioinfo;
    (void)uFlags;
    return 0;
}

MMRESULT mmioGetInfo(HMMIO hmmio, LPMMIOINFO lpmmioinfo, UINT uFlags)
{
    (void)hmmio;
    (void)lpmmioinfo;
    (void)uFlags;
    return 0;
}

MMRESULT waveOutWrite(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh)
{
    (void)hwo;
    (void)pwh;
    (void)cbwh;
    return 0;
}

/* ==========================================================================
 * DirectSound Stub
 * ========================================================================== */

int DirectSoundCreate(void *lpGuid, void **ppDS, void *pUnkOuter)
{
    (void)lpGuid;
    (void)pUnkOuter;
    if (ppDS) *ppDS = (void *)(uintptr_t)1;
    return 0; /* DS_OK */
}

/* ==========================================================================
 * AVIFile / Video for Windows Adapter & Fallbacks
 * ========================================================================== */

void AVIFileInit(void)
{
}

void AVIFileExit(void)
{
}

HRESULT AVIFileOpenA(PAVIFILE *ppfile, LPCSTR szFile, UINT uMode, LPCLSID lpHandler)
{
    (void)szFile;
    (void)uMode;
    (void)lpHandler;
    if (ppfile) *ppfile = (PAVIFILE)(uintptr_t)1;
    return 0;
}

ULONG AVIFileRelease(PAVIFILE pfile)
{
    (void)pfile;
    return 0;
}

HRESULT AVIFileGetStream(PAVIFILE pfile, PAVISTREAM *ppavi, DWORD fccType, LONG lParam)
{
    (void)pfile;
    (void)fccType;
    (void)lParam;
    if (ppavi) *ppavi = (PAVISTREAM)(uintptr_t)1;
    return 0;
}

ULONG AVIStreamRelease(PAVISTREAM pavi)
{
    (void)pavi;
    return 0;
}

HRESULT AVIStreamInfoA(PAVISTREAM pavi, LPAVISTREAMINFOA psi, LONG lSize)
{
    (void)pavi;
    (void)lSize;
    if (psi) {
        memset(psi, 0, sizeof(*psi));
        psi->dwScale = 1;
        psi->dwRate = 15;
        psi->dwLength = 100;
        psi->rcFrame.right = 320;
        psi->rcFrame.bottom = 240;
    }
    return 0;
}

HRESULT AVIStreamReadFormat(PAVISTREAM pavi, LONG lPos, LPVOID lpFormat, LONG *lpcbFormat)
{
    (void)pavi;
    (void)lPos;
    (void)lpFormat;
    if (lpcbFormat) *lpcbFormat = sizeof(BITMAPINFOHEADER);
    return 0;
}

HRESULT AVIStreamRead(PAVISTREAM pavi, LONG lStart, LONG lSamples, LPVOID lpBuffer,
                      LONG cbBuffer, LONG *plBytes, LONG *plSamples)
{
    (void)pavi;
    (void)lStart;
    (void)lSamples;
    (void)lpBuffer;
    (void)cbBuffer;
    if (plBytes) *plBytes = 0;
    if (plSamples) *plSamples = 0;
    return 0;
}

LONG AVIStreamSampleToTime(PAVISTREAM pavi, LONG lSample)
{
    (void)pavi;
    return lSample * 66; /* ~15 fps -> 66ms per frame */
}

LONG AVIStreamTimeToSample(PAVISTREAM pavi, LONG lTime)
{
    (void)pavi;
    return lTime / 66;
}

HDRAWDIB DrawDibOpen(void)
{
    return (HDRAWDIB)(uintptr_t)1;
}

BOOL DrawDibClose(HDRAWDIB hdd)
{
    (void)hdd;
    return TRUE;
}

BOOL DrawDibBegin(HDRAWDIB hdd, HDC hdc, int dxDest, int dyDest,
                  LPBITMAPINFOHEADER lpbi, int dxSrc, int dySrc, UINT wFlags)
{
    (void)hdd;
    (void)hdc;
    (void)dxDest;
    (void)dyDest;
    (void)lpbi;
    (void)dxSrc;
    (void)dySrc;
    (void)wFlags;
    return TRUE;
}

BOOL DrawDibEnd(HDRAWDIB hdd)
{
    (void)hdd;
    return TRUE;
}

BOOL DrawDibStart(HDRAWDIB hdd, DWORD rate)
{
    (void)hdd;
    (void)rate;
    return TRUE;
}

BOOL DrawDibStop(HDRAWDIB hdd)
{
    (void)hdd;
    return TRUE;
}

BOOL DrawDibDraw(HDRAWDIB hdd, HDC hdc, int xDst, int yDst, int dxDst, int dyDst,
                 LPBITMAPINFOHEADER lpbi, LPVOID lpBits, int xSrc, int ySrc,
                 int dxSrc, int dySrc, UINT wFlags)
{
    (void)hdd;
    (void)wFlags;
    if (lpbi && lpBits) {
        SetDIBitsToDevice(hdc, xDst, yDst, (DWORD)dxDst, (DWORD)dyDst, xSrc, ySrc, 0, (UINT)dySrc, lpBits, (const BITMAPINFO *)lpbi, DIB_RGB_COLORS);
    }
    return TRUE;
}

HIC ICLocate(DWORD fccType, DWORD fccHandler, LPBITMAPINFOHEADER lpbiIn, LPBITMAPINFOHEADER lpbiOut, WORD wFlags)
{
    (void)fccType;
    (void)fccHandler;
    (void)lpbiIn;
    (void)lpbiOut;
    (void)wFlags;
    return (HIC)(uintptr_t)1;
}

LRESULT ICClose(HIC hic)
{
    (void)hic;
    return 0;
}

LRESULT ICSendMessage(HIC hic, UINT msg, DWORD_PTR dw1, DWORD_PTR dw2)
{
    (void)hic;
    (void)msg;
    (void)dw1;
    (void)dw2;
    return 0;
}

DWORD ICDrawBegin(HIC hic, DWORD dwFlags, HPALETTE hpal, HWND hwnd, HDC hdc,
                  int xDst, int yDst, int dxDst, int dyDst,
                  LPBITMAPINFOHEADER lpbi, int xSrc, int ySrc, int dxSrc, int dySrc,
                  DWORD dwRate, DWORD dwScale)
{
    (void)hic;
    (void)dwFlags;
    (void)hpal;
    (void)hwnd;
    (void)hdc;
    (void)xDst;
    (void)yDst;
    (void)dxDst;
    (void)dyDst;
    (void)lpbi;
    (void)xSrc;
    (void)ySrc;
    (void)dxSrc;
    (void)dySrc;
    (void)dwRate;
    (void)dwScale;
    return 0;
}

HWND MCIWndCreateA(HWND hwndParent, HINSTANCE hInstance, DWORD dwStyle, LPCSTR szFile)
{
    (void)hInstance;
    (void)dwStyle;
    (void)szFile;
    return CreateWindowExA(0, "STATIC", "MCIWnd", WS_CHILD, 0, 0, 320, 240, hwndParent, NULL, hInstance, NULL);
}
