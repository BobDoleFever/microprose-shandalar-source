/*
 * shandalar/graphics.h - 2D Graphics, PCX, PIC, Sprites, and Palettes
 */
#ifndef SHANDALAR_GRAPHICS_H
#define SHANDALAR_GRAPHICS_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Image & Resource Loaders */
int  Pic_Load(const char* filename, void** out_buffer);
int  Pcx_Decode(const char* filename, void* dst_surface);
void Sprite_Draw(void* sprite, int x, int y, int flags);

/* Standard Win32 GDI Prototypes */
HPALETTE SelectPalette(HDC hdc, HPALETTE hpal, BOOL bForceBkgd);
UINT     RealizePalette(HDC hdc);
UINT     SetDIBColorTable(HDC hdc, UINT iStart, UINT cEntries, const RGBQUAD *prgbq);
int      SetStretchBltMode(HDC hdc, int mode);
BOOL     GdiFlush(void);
BOOL     UnrealizeObject(HGDIOBJ hgdiobj);
BOOL     FreeLibrary(HMODULE hLibModule);
BOOL     BitBlt(HDC hdcDest, int nXDest, int nYDest, int nWidth, int nHeight, HDC hdcSrc, int nXSrc, int nYSrc, DWORD dwRop);
int      SetDIBitsToDevice(HDC hdc, int xDest, int yDest, DWORD w, DWORD h, int xSrc, int ySrc, UINT uStartScan, UINT cScanLines, const void *lpvBits, const BITMAPINFO *lpbmi, UINT fuColorUse);
BOOL     InvalidateRect(HWND hWnd, const RECT *lpRect, BOOL bErase);
BOOL     EnumChildWindows(HWND hWndParent, WNDENUMPROC lpEnumFunc, LPARAM lParam);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_GRAPHICS_H */
