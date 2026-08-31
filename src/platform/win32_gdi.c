/*
 * src/platform/win32_gdi.c - Win32 GDI Subsystem (DCs, DIBs, Palettes, Blits, ROPs, Primitives)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#include "windows_types.h"
#include "shandalar/platform_handle.h"
#include "shandalar/win32_internal.h"
#include "shandalar/win32_compat.h"
#include "shandalar/display_shim.h"

/* Stock object handles */
static struct {
    HBRUSH    white_brush;
    HBRUSH    ltgray_brush;
    HBRUSH    gray_brush;
    HBRUSH    dkgray_brush;
    HBRUSH    black_brush;
    HBRUSH    null_brush;
    HPEN      white_pen;
    HPEN      black_pen;
    HPEN      null_pen;
    HFONT     system_font;
    HPALETTE  default_palette;
    HBITMAP   stock_bitmap;
    bool      is_initialized;
} g_StockGdi = {0};

/* Destructors */
static void DCDestructor(void *ptr)
{
    GdiDC *dc = (GdiDC *)ptr;
    if (!dc) return;
    /* Free saved DC chain if any */
    GdiDC *cur = dc->saved_state;
    while (cur) {
        GdiDC *next = cur->saved_state;
        free(cur);
        cur = next;
    }
    free(dc);
}

static void BitmapDestructor(void *ptr)
{
    GdiBitmap *bmp = (GdiBitmap *)ptr;
    if (!bmp) return;
    if (bmp->owns_bits && bmp->bits) {
        free(bmp->bits);
        bmp->bits = NULL;
    }
    free(bmp);
}

static void PaletteDestructor(void *ptr)
{
    GdiPalette *pal = (GdiPalette *)ptr;
    if (pal) free(pal);
}

static void PenDestructor(void *ptr)
{
    GdiPen *p = (GdiPen *)ptr;
    if (p) free(p);
}

static void BrushDestructor(void *ptr)
{
    GdiBrush *b = (GdiBrush *)ptr;
    if (b) free(b);
}

static void FontDestructor(void *ptr)
{
    GdiFont *f = (GdiFont *)ptr;
    if (f) free(f);
}

static void RegionDestructor(void *ptr)
{
    GdiRegion *r = (GdiRegion *)ptr;
    if (r) free(r);
}

void Gdi_InternalInit(void)
{
    if (g_StockGdi.is_initialized) return;
    g_StockGdi.is_initialized = true;

    Platform_HandleInit();

    /* Create stock brushes */
    g_StockGdi.white_brush = CreateSolidBrush(RGB(255, 255, 255));
    g_StockGdi.ltgray_brush = CreateSolidBrush(RGB(192, 192, 192));
    g_StockGdi.gray_brush = CreateSolidBrush(RGB(128, 128, 128));
    g_StockGdi.dkgray_brush = CreateSolidBrush(RGB(64, 64, 64));
    g_StockGdi.black_brush = CreateSolidBrush(RGB(0, 0, 0));

    LOGBRUSH lb_null = {BS_NULL, 0, 0};
    g_StockGdi.null_brush = CreateBrushIndirect(&lb_null);

    /* Create stock pens */
    g_StockGdi.white_pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    g_StockGdi.black_pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    g_StockGdi.null_pen = CreatePen(PS_NULL, 1, 0);

    /* Create stock font */
    LOGFONTA lf;
    memset(&lf, 0, sizeof(lf));
    lf.lfHeight = 12;
    strncpy(lf.lfFaceName, "System", sizeof(lf.lfFaceName) - 1);
    g_StockGdi.system_font = CreateFontIndirectA(&lf);

    /* Create default palette */
    struct {
        WORD palVersion;
        WORD palNumEntries;
        PALETTEENTRY entries[256];
    } def_pal;
    def_pal.palVersion = 0x300;
    def_pal.palNumEntries = 256;
    for (int i = 0; i < 256; i++) {
        def_pal.entries[i].peRed = (BYTE)i;
        def_pal.entries[i].peGreen = (BYTE)i;
        def_pal.entries[i].peBlue = (BYTE)i;
        def_pal.entries[i].peFlags = 0;
    }
    g_StockGdi.default_palette = CreatePalette((const LOGPALETTE *)&def_pal);
    g_StockGdi.stock_bitmap = CreateBitmap(1, 1, 1, 1, NULL);

    /* Mark all stock objects as permanent */
    Platform_SetHandleStock(g_StockGdi.white_brush, TRUE);
    Platform_SetHandleStock(g_StockGdi.ltgray_brush, TRUE);
    Platform_SetHandleStock(g_StockGdi.gray_brush, TRUE);
    Platform_SetHandleStock(g_StockGdi.dkgray_brush, TRUE);
    Platform_SetHandleStock(g_StockGdi.black_brush, TRUE);
    Platform_SetHandleStock(g_StockGdi.null_brush, TRUE);
    Platform_SetHandleStock(g_StockGdi.white_pen, TRUE);
    Platform_SetHandleStock(g_StockGdi.black_pen, TRUE);
    Platform_SetHandleStock(g_StockGdi.null_pen, TRUE);
    Platform_SetHandleStock(g_StockGdi.system_font, TRUE);
    Platform_SetHandleStock(g_StockGdi.default_palette, TRUE);
    Platform_SetHandleStock(g_StockGdi.stock_bitmap, TRUE);

    g_StockGdi.is_initialized = true;
}

void Gdi_InternalShutdown(void)
{
    g_StockGdi.is_initialized = false;
}

GdiDC* Gdi_GetDC(HDC hdc)
{
    return (GdiDC *)Platform_ResolveHandle(hdc, HANDLE_TYPE_HDC);
}

/* ==========================================================================
 * Device Context Management
 * ========================================================================== */

HDC GetDC(HWND hWnd)
{
    Gdi_InternalInit();
    LogicalWindow *w = User_GetWindow(hWnd);

    GdiDC *dc = (GdiDC *)calloc(1, sizeof(GdiDC));
    if (!dc) return NULL;

    dc->is_memory_dc = false;
    dc->hwnd = hWnd;
    dc->width = w ? (w->client_rect.right - w->client_rect.left) : 640;
    dc->height = w ? (w->client_rect.bottom - w->client_rect.top) : 480;
    if (dc->width <= 0) dc->width = 640;
    if (dc->height <= 0) dc->height = 480;

    dc->pixels = w ? w->surface_pixels : NULL;
    dc->pitch = w ? w->surface_pitch : dc->width;

    dc->selected_brush = g_StockGdi.white_brush;
    dc->selected_pen = g_StockGdi.black_pen;
    dc->selected_font = g_StockGdi.system_font;
    dc->selected_palette = g_StockGdi.default_palette;

    dc->clip_rect.left = 0;
    dc->clip_rect.top = 0;
    dc->clip_rect.right = dc->width;
    dc->clip_rect.bottom = dc->height;

    dc->bk_mode = OPAQUE;
    dc->bk_color = RGB(255, 255, 255);
    dc->text_color = RGB(0, 0, 0);
    dc->rop2 = R2_COPYPEN;
    dc->map_mode = MM_TEXT;

    HDC hdc = (HDC)Platform_AllocHandle(HANDLE_TYPE_HDC, dc, DCDestructor);
    dc->hdc = hdc;
    return hdc;
}

HDC GetWindowDC(HWND hWnd)
{
    return GetDC(hWnd);
}

int ReleaseDC(HWND hWnd, HDC hDC)
{
    (void)hWnd;
    return Platform_FreeHandle(hDC, HANDLE_TYPE_HDC) ? 1 : 0;
}

HDC CreateDCA(LPCSTR lpszDriver, LPCSTR lpszDevice, LPCSTR lpszOutput, const void *lpInitData)
{
    (void)lpszDriver;
    (void)lpszDevice;
    (void)lpszOutput;
    (void)lpInitData;
    return GetDC(NULL);
}

HDC CreateCompatibleDC(HDC hdc)
{
    Gdi_InternalInit();
    GdiDC *src = Gdi_GetDC(hdc);

    GdiDC *dc = (GdiDC *)calloc(1, sizeof(GdiDC));
    if (!dc) return NULL;

    dc->is_memory_dc = true;
    dc->hwnd = NULL;
    dc->width = src ? src->width : 640;
    dc->height = src ? src->height : 480;
    dc->pitch = dc->width;
    dc->pixels = NULL; /* No surface until a bitmap is selected */

    dc->selected_brush = g_StockGdi.white_brush;
    dc->selected_pen = g_StockGdi.black_pen;
    dc->selected_font = g_StockGdi.system_font;
    dc->selected_palette = src ? src->selected_palette : g_StockGdi.default_palette;
    dc->selected_bitmap = g_StockGdi.stock_bitmap;

    dc->clip_rect.left = 0;
    dc->clip_rect.top = 0;
    dc->clip_rect.right = dc->width;
    dc->clip_rect.bottom = dc->height;

    dc->bk_mode = OPAQUE;
    dc->bk_color = RGB(255, 255, 255);
    dc->text_color = RGB(0, 0, 0);
    dc->rop2 = R2_COPYPEN;
    dc->map_mode = MM_TEXT;

    HDC new_hdc = (HDC)Platform_AllocHandle(HANDLE_TYPE_HDC, dc, DCDestructor);
    dc->hdc = new_hdc;
    return new_hdc;
}

BOOL DeleteDC(HDC hdc)
{
    return Platform_FreeHandle(hdc, HANDLE_TYPE_HDC);
}

int SaveDC(HDC hdc)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return 0;

    GdiDC *copy = (GdiDC *)malloc(sizeof(GdiDC));
    if (!copy) return 0;

    *copy = *dc;
    copy->saved_state = dc->saved_state;
    dc->saved_state = copy;
    return 1;
}

BOOL RestoreDC(HDC hdc, int nSavedDC)
{
    (void)nSavedDC;
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc || !dc->saved_state) return FALSE;

    GdiDC *saved = dc->saved_state;
    dc->selected_bitmap = saved->selected_bitmap;
    dc->selected_brush = saved->selected_brush;
    dc->selected_pen = saved->selected_pen;
    dc->selected_font = saved->selected_font;
    dc->selected_palette = saved->selected_palette;
    dc->clip_rect = saved->clip_rect;
    dc->bk_mode = saved->bk_mode;
    dc->bk_color = saved->bk_color;
    dc->text_color = saved->text_color;
    dc->text_align = saved->text_align;
    dc->rop2 = saved->rop2;
    dc->map_mode = saved->map_mode;
    dc->view_org = saved->view_org;
    dc->win_org = saved->win_org;
    dc->current_pos = saved->current_pos;

    dc->saved_state = saved->saved_state;
    free(saved);
    return TRUE;
}

/* ==========================================================================
 * Stock Objects & Object Selection
 * ========================================================================== */

HGDIOBJ GetStockObject(int fnObject)
{
    Gdi_InternalInit();
    switch (fnObject) {
        case WHITE_BRUSH:         return (HGDIOBJ)g_StockGdi.white_brush;
        case LTGRAY_BRUSH:        return (HGDIOBJ)g_StockGdi.ltgray_brush;
        case GRAY_BRUSH:          return (HGDIOBJ)g_StockGdi.gray_brush;
        case DKGRAY_BRUSH:        return (HGDIOBJ)g_StockGdi.dkgray_brush;
        case BLACK_BRUSH:         return (HGDIOBJ)g_StockGdi.black_brush;
        case NULL_BRUSH:          return (HGDIOBJ)g_StockGdi.null_brush;
        case WHITE_PEN:           return (HGDIOBJ)g_StockGdi.white_pen;
        case BLACK_PEN:           return (HGDIOBJ)g_StockGdi.black_pen;
        case NULL_PEN:            return (HGDIOBJ)g_StockGdi.null_pen;
        case OEM_FIXED_FONT:
        case ANSI_FIXED_FONT:
        case ANSI_VAR_FONT:
        case SYSTEM_FONT:
        case DEVICE_DEFAULT_FONT:
        case SYSTEM_FIXED_FONT:
        case DEFAULT_GUI_FONT:    return (HGDIOBJ)g_StockGdi.system_font;
        case DEFAULT_PALETTE:     return (HGDIOBJ)g_StockGdi.default_palette;
        default:                  return (HGDIOBJ)g_StockGdi.null_brush;
    }
}

HGDIOBJ SelectObject(HDC hdc, HGDIOBJ h)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc || !h) return NULL;

    HandleType t = Platform_GetHandleType(h);
    switch (t) {
        case HANDLE_TYPE_HBITMAP: {
            GdiBitmap *bmp = (GdiBitmap *)Platform_ResolveHandle(h, HANDLE_TYPE_HBITMAP);
            if (!bmp) return NULL;
            HGDIOBJ prev = (HGDIOBJ)dc->selected_bitmap;
            if (!prev) prev = (HGDIOBJ)g_StockGdi.stock_bitmap;
            dc->selected_bitmap = (HBITMAP)h;
            if (dc->is_memory_dc) {
                dc->pixels = bmp->bits;
                dc->width = bmp->width;
                dc->height = bmp->height;
                dc->pitch = bmp->pitch;
                dc->clip_rect.left = 0;
                dc->clip_rect.top = 0;
                dc->clip_rect.right = bmp->width;
                dc->clip_rect.bottom = bmp->height;
            }
            return prev;
        }
        case HANDLE_TYPE_HBRUSH: {
            HGDIOBJ prev = (HGDIOBJ)dc->selected_brush;
            dc->selected_brush = (HBRUSH)h;
            return prev;
        }
        case HANDLE_TYPE_HPEN: {
            HGDIOBJ prev = (HGDIOBJ)dc->selected_pen;
            dc->selected_pen = (HPEN)h;
            return prev;
        }
        case HANDLE_TYPE_HFONT: {
            HGDIOBJ prev = (HGDIOBJ)dc->selected_font;
            dc->selected_font = (HFONT)h;
            return prev;
        }
        case HANDLE_TYPE_HRGN: {
            GdiRegion *r = (GdiRegion *)Platform_ResolveHandle(h, HANDLE_TYPE_HRGN);
            if (r) dc->clip_rect = r->rect;
            HGDIOBJ prev = (HGDIOBJ)dc->selected_region;
            dc->selected_region = (HRGN)h;
            return prev;
        }
        default:
            return NULL;
    }
}

BOOL DeleteObject(HGDIOBJ hObject)
{
    if (!hObject) return FALSE;
    if (Platform_IsHandleStock(hObject)) return TRUE; /* Stock objects are immortal */
    return Platform_FreeHandle(hObject, HANDLE_TYPE_ANY_GDI);
}

BOOL UnrealizeObject(HGDIOBJ hObject)
{
    (void)hObject;
    return TRUE;
}

int GetObjectA(HANDLE hgdiobj, int cbBuffer, void *lpvObject)
{
    if (!hgdiobj || !lpvObject || cbBuffer <= 0) return 0;
    HandleType t = Platform_GetHandleType(hgdiobj);

    if (t == HANDLE_TYPE_HBITMAP) {
        GdiBitmap *bmp = (GdiBitmap *)Platform_ResolveHandle(hgdiobj, HANDLE_TYPE_HBITMAP);
        if (!bmp) return 0;
        if ((size_t)cbBuffer >= sizeof(BITMAP)) {
            BITMAP *bm = (BITMAP *)lpvObject;
            bm->bmType = 0;
            bm->bmWidth = bmp->width;
            bm->bmHeight = bmp->height;
            bm->bmWidthBytes = bmp->pitch;
            bm->bmPlanes = 1;
            bm->bmBitsPixel = (WORD)bmp->bpp;
            bm->bmBits = bmp->bits;
            return sizeof(BITMAP);
        }
    } else if (t == HANDLE_TYPE_HFONT) {
        GdiFont *f = (GdiFont *)Platform_ResolveHandle(hgdiobj, HANDLE_TYPE_HFONT);
        if (!f) return 0;
        if ((size_t)cbBuffer >= sizeof(LOGFONTA)) {
            memcpy(lpvObject, &f->logfont, sizeof(LOGFONTA));
            return sizeof(LOGFONTA);
        }
    } else if (t == HANDLE_TYPE_HPEN) {
        GdiPen *p = (GdiPen *)Platform_ResolveHandle(hgdiobj, HANDLE_TYPE_HPEN);
        if (!p) return 0;
        if ((size_t)cbBuffer >= sizeof(LOGPEN)) {
            LOGPEN *lp = (LOGPEN *)lpvObject;
            lp->lopnStyle = p->style;
            lp->lopnWidth.x = p->width;
            lp->lopnWidth.y = 0;
            lp->lopnColor = p->color;
            return sizeof(LOGPEN);
        }
    } else if (t == HANDLE_TYPE_HBRUSH) {
        GdiBrush *b = (GdiBrush *)Platform_ResolveHandle(hgdiobj, HANDLE_TYPE_HBRUSH);
        if (!b) return 0;
        if ((size_t)cbBuffer >= sizeof(LOGBRUSH)) {
            LOGBRUSH *lb = (LOGBRUSH *)lpvObject;
            lb->lbStyle = b->style;
            lb->lbColor = b->color;
            lb->lbHatch = b->hatch;
            return sizeof(LOGBRUSH);
        }
    }

    return 0;
}

/* ==========================================================================
 * Bitmaps & DIBSections
 * ========================================================================== */

HBITMAP CreateBitmap(int nWidth, int nHeight, UINT nPlanes, UINT nBitCount, const void *lpBits)
{
    (void)nPlanes;
    Gdi_InternalInit();
    if (nWidth <= 0 || nHeight <= 0) return NULL;

    GdiBitmap *bmp = (GdiBitmap *)calloc(1, sizeof(GdiBitmap));
    if (!bmp) return NULL;

    int bpp = (nBitCount > 0) ? (int)nBitCount : 8;
    int pitch = ((nWidth * bpp + 31) / 32) * 4;

    bmp->width = nWidth;
    bmp->height = nHeight;
    bmp->bpp = bpp;
    bmp->pitch = pitch;
    bmp->is_dib = false;
    bmp->is_top_down = true;
    bmp->owns_bits = true;
    bmp->bits = (uint8_t *)calloc(1, (size_t)pitch * (size_t)nHeight);

    if (lpBits && bmp->bits) {
        memcpy(bmp->bits, lpBits, (size_t)pitch * (size_t)nHeight);
    }

    HBITMAP hbmp = (HBITMAP)Platform_AllocHandle(HANDLE_TYPE_HBITMAP, bmp, BitmapDestructor);
    bmp->hbmp = hbmp;
    return hbmp;
}

HBITMAP CreateCompatibleBitmap(HDC hdc, int cx, int cy)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    int bpp = 8;
    if (dc && dc->selected_bitmap) {
        GdiBitmap *sel = (GdiBitmap *)Platform_ResolveHandle(dc->selected_bitmap, HANDLE_TYPE_HBITMAP);
        if (sel) bpp = sel->bpp;
    }
    return CreateBitmap(cx, cy, 1, bpp, NULL);
}

HBITMAP CreateDIBSection(HDC hdc, const BITMAPINFO *pbmi, UINT usage,
                         void **ppvBits, HANDLE hSection, DWORD offset)
{
    (void)hdc;
    (void)usage;
    (void)hSection;
    (void)offset;
    Gdi_InternalInit();

    if (!pbmi || !ppvBits) return NULL;

    int width = pbmi->bmiHeader.biWidth;
    int height = pbmi->bmiHeader.biHeight;
    bool top_down = false;
    if (height < 0) {
        top_down = true;
        height = -height;
    }
    if (width <= 0 || height <= 0) return NULL;

    int bpp = pbmi->bmiHeader.biBitCount ? pbmi->bmiHeader.biBitCount : 8;
    int pitch = ((width * bpp + 31) / 32) * 4; /* Win32 4-byte row alignment */

    GdiBitmap *bmp = (GdiBitmap *)calloc(1, sizeof(GdiBitmap));
    if (!bmp) return NULL;

    bmp->width = width;
    bmp->height = height;
    bmp->bpp = bpp;
    bmp->pitch = pitch;
    bmp->is_dib = true;
    bmp->is_top_down = top_down;
    bmp->header = pbmi->bmiHeader;
    bmp->owns_bits = true;

    /* Copy palette colors if present */
    UINT colors = pbmi->bmiHeader.biClrUsed;
    if (colors == 0 && bpp <= 8) colors = 1 << bpp;
    if (colors > 256) colors = 256;
    bmp->color_count = colors;
    for (UINT i = 0; i < colors; i++) {
        bmp->colors[i] = pbmi->bmiColors[i];
    }

    bmp->bits = (uint8_t *)calloc(1, (size_t)pitch * (size_t)height);
    if (!bmp->bits) {
        free(bmp);
        return NULL;
    }

    *ppvBits = bmp->bits;

    HBITMAP hbmp = (HBITMAP)Platform_AllocHandle(HANDLE_TYPE_HBITMAP, bmp, BitmapDestructor);
    bmp->hbmp = hbmp;
    return hbmp;
}

BOOL SetBitmapDimensionEx(HBITMAP hbm, int w, int h, LPSIZE lpsz)
{
    (void)hbm;
    if (lpsz) {
        lpsz->cx = w;
        lpsz->cy = h;
    }
    return TRUE;
}

/* ==========================================================================
 * Palettes
 * ========================================================================== */

HPALETTE CreatePalette(const LOGPALETTE *plpal)
{
    Gdi_InternalInit();
    if (!plpal) return NULL;

    GdiPalette *pal = (GdiPalette *)calloc(1, sizeof(GdiPalette));
    if (!pal) return NULL;

    pal->count = plpal->palNumEntries;
    if (pal->count > 256) pal->count = 256;

    for (UINT i = 0; i < pal->count; i++) {
        pal->entries[i] = plpal->palPalEntry[i];
    }

    HPALETTE hpal = (HPALETTE)Platform_AllocHandle(HANDLE_TYPE_HPALETTE, pal, PaletteDestructor);
    pal->hpal = hpal;
    return hpal;
}

HPALETTE SelectPalette(HDC hdc, HPALETTE hPal, BOOL bForceBkgd)
{
    (void)bForceBkgd;
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc || !hPal) return NULL;

    HPALETTE prev = dc->selected_palette;
    dc->selected_palette = hPal;
    return prev;
}

UINT RealizePalette(HDC hdc)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc || !dc->selected_palette) return 0;

    GdiPalette *pal = (GdiPalette *)Platform_ResolveHandle(dc->selected_palette, HANDLE_TYPE_HPALETTE);
    if (!pal) return 0;

    uint32_t lut[256];
    for (UINT i = 0; i < pal->count && i < 256; i++) {
        lut[i] = ((uint32_t)pal->entries[i].peRed << 16) |
                 ((uint32_t)pal->entries[i].peGreen << 8) |
                 ((uint32_t)pal->entries[i].peBlue);
    }
    Shandalar_SetPalette(lut);
    return pal->count;
}

BOOL AnimatePalette(HPALETTE hPal, UINT iStartIndex, UINT cEntries, const PALETTEENTRY *ppe)
{
    GdiPalette *pal = (GdiPalette *)Platform_ResolveHandle(hPal, HANDLE_TYPE_HPALETTE);
    if (!pal || !ppe) return FALSE;

    for (UINT i = 0; i < cEntries && (iStartIndex + i) < 256; i++) {
        pal->entries[iStartIndex + i] = ppe[i];
        Shandalar_SetPaletteEntry((uint8_t)(iStartIndex + i), ppe[i].peRed, ppe[i].peGreen, ppe[i].peBlue);
    }
    return TRUE;
}

UINT GetPaletteEntries(HPALETTE hpal, UINT iStartIndex, UINT nEntries, LPPALETTEENTRY lppe)
{
    GdiPalette *pal = (GdiPalette *)Platform_ResolveHandle(hpal, HANDLE_TYPE_HPALETTE);
    if (!pal || !lppe) return 0;

    UINT copied = 0;
    for (UINT i = 0; i < nEntries && (iStartIndex + i) < pal->count; i++) {
        lppe[i] = pal->entries[iStartIndex + i];
        copied++;
    }
    return copied;
}

UINT SetPaletteEntries(HPALETTE hpal, UINT iStartIndex, UINT nEntries, const PALETTEENTRY *lppe)
{
    GdiPalette *pal = (GdiPalette *)Platform_ResolveHandle(hpal, HANDLE_TYPE_HPALETTE);
    if (!pal || !lppe) return 0;

    UINT set_count = 0;
    for (UINT i = 0; i < nEntries && (iStartIndex + i) < 256; i++) {
        pal->entries[iStartIndex + i] = lppe[i];
        set_count++;
    }
    if (iStartIndex + set_count > pal->count) {
        pal->count = iStartIndex + set_count;
    }
    return set_count;
}

UINT GetNearestPaletteIndex(HPALETTE hpal, COLORREF cr)
{
    GdiPalette *pal = (GdiPalette *)Platform_ResolveHandle(hpal, HANDLE_TYPE_HPALETTE);
    if (!pal || pal->count == 0) return 0;

    int r = GetRValue(cr);
    int g = GetGValue(cr);
    int b = GetBValue(cr);

    int best_idx = 0;
    int best_dist = 0x7FFFFFFF;

    for (UINT i = 0; i < pal->count; i++) {
        int dr = r - pal->entries[i].peRed;
        int dg = g - pal->entries[i].peGreen;
        int db = b - pal->entries[i].peBlue;
        int dist = dr * dr + dg * dg + db * db;
        if (dist < best_dist) {
            best_dist = dist;
            best_idx = (int)i;
        }
    }
    return (UINT)best_idx;
}

UINT SetSystemPaletteUse(HDC hdc, UINT uUsage)
{
    (void)hdc;
    (void)uUsage;
    return 1;
}

/* ==========================================================================
 * Pens, Brushes, Fonts & Regions
 * ========================================================================== */

HPEN CreatePen(int iStyle, int cWidth, COLORREF color)
{
    Gdi_InternalInit();
    GdiPen *p = (GdiPen *)calloc(1, sizeof(GdiPen));
    if (!p) return NULL;

    p->style = (UINT)iStyle;
    p->width = (cWidth > 0) ? cWidth : 1;
    p->color = color;

    HPEN hpen = (HPEN)Platform_AllocHandle(HANDLE_TYPE_HPEN, p, PenDestructor);
    p->hpen = hpen;
    return hpen;
}

HPEN CreatePenIndirect(const LOGPEN *plpen)
{
    if (!plpen) return NULL;
    return CreatePen(plpen->lopnStyle, plpen->lopnWidth.x, plpen->lopnColor);
}

HBRUSH CreateSolidBrush(COLORREF color)
{
    Gdi_InternalInit();
    GdiBrush *b = (GdiBrush *)calloc(1, sizeof(GdiBrush));
    if (!b) return NULL;

    b->style = BS_SOLID;
    b->color = color;

    HBRUSH hbrush = (HBRUSH)Platform_AllocHandle(HANDLE_TYPE_HBRUSH, b, BrushDestructor);
    b->hbrush = hbrush;
    return hbrush;
}

HBRUSH CreateBrushIndirect(const LOGBRUSH *plbrush)
{
    Gdi_InternalInit();
    if (!plbrush) return NULL;

    GdiBrush *b = (GdiBrush *)calloc(1, sizeof(GdiBrush));
    if (!b) return NULL;

    b->style = plbrush->lbStyle;
    b->color = plbrush->lbColor;
    b->hatch = plbrush->lbHatch;

    HBRUSH hbrush = (HBRUSH)Platform_AllocHandle(HANDLE_TYPE_HBRUSH, b, BrushDestructor);
    b->hbrush = hbrush;
    return hbrush;
}

HBRUSH CreateHatchBrush(int iHatch, COLORREF color)
{
    LOGBRUSH lb;
    lb.lbStyle = BS_HATCHED;
    lb.lbColor = color;
    lb.lbHatch = (ULONG_PTR)iHatch;
    return CreateBrushIndirect(&lb);
}

HFONT CreateFontA(int cHeight, int cWidth, int cEscapement, int cOrientation,
                  int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut,
                  DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision,
                  DWORD iQuality, DWORD iPitchAndFamily, LPCSTR pszFaceName)
{
    LOGFONTA lf;
    memset(&lf, 0, sizeof(lf));
    lf.lfHeight = cHeight;
    lf.lfWidth = cWidth;
    lf.lfEscapement = cEscapement;
    lf.lfOrientation = cOrientation;
    lf.lfWeight = cWeight;
    lf.lfItalic = (BYTE)bItalic;
    lf.lfUnderline = (BYTE)bUnderline;
    lf.lfStrikeOut = (BYTE)bStrikeOut;
    lf.lfCharSet = (BYTE)iCharSet;
    lf.lfOutPrecision = (BYTE)iOutPrecision;
    lf.lfClipPrecision = (BYTE)iClipPrecision;
    lf.lfQuality = (BYTE)iQuality;
    lf.lfPitchAndFamily = (BYTE)iPitchAndFamily;
    if (pszFaceName) {
        strncpy(lf.lfFaceName, pszFaceName, sizeof(lf.lfFaceName) - 1);
    }
    return CreateFontIndirectA(&lf);
}

HFONT CreateFontIndirectA(const LOGFONTA *lplf)
{
    Gdi_InternalInit();
    if (!lplf) return NULL;

    GdiFont *f = (GdiFont *)calloc(1, sizeof(GdiFont));
    if (!f) return NULL;

    f->logfont = *lplf;

    HFONT hfont = (HFONT)Platform_AllocHandle(HANDLE_TYPE_HFONT, f, FontDestructor);
    f->hfont = hfont;
    return hfont;
}

int AddFontResourceA(LPCSTR lpFileName)
{
    (void)lpFileName;
    return 1;
}

BOOL RemoveFontResourceA(LPCSTR lpFileName)
{
    (void)lpFileName;
    return TRUE;
}

HRGN CreateRectRgn(int x1, int y1, int x2, int y2)
{
    Gdi_InternalInit();
    GdiRegion *r = (GdiRegion *)calloc(1, sizeof(GdiRegion));
    if (!r) return NULL;

    r->rect.left = (x1 < x2) ? x1 : x2;
    r->rect.top = (y1 < y2) ? y1 : y2;
    r->rect.right = (x1 > x2) ? x1 : x2;
    r->rect.bottom = (y1 > y2) ? y1 : y2;
    r->is_null = false;

    HRGN hrgn = (HRGN)Platform_AllocHandle(HANDLE_TYPE_HRGN, r, RegionDestructor);
    r->hrgn = hrgn;
    return hrgn;
}

HRGN CreateRectRgnIndirect(const RECT *lprc)
{
    if (!lprc) return NULL;
    return CreateRectRgn(lprc->left, lprc->top, lprc->right, lprc->bottom);
}

HRGN CreatePolygonRgn(const POINT *pptl, int cPoint, int iMode)
{
    (void)iMode;
    if (!pptl || cPoint <= 0) return NULL;

    int min_x = pptl[0].x, max_x = pptl[0].x;
    int min_y = pptl[0].y, max_y = pptl[0].y;

    for (int i = 1; i < cPoint; i++) {
        if (pptl[i].x < min_x) min_x = pptl[i].x;
        if (pptl[i].x > max_x) max_x = pptl[i].x;
        if (pptl[i].y < min_y) min_y = pptl[i].y;
        if (pptl[i].y > max_y) max_y = pptl[i].y;
    }
    return CreateRectRgn(min_x, min_y, max_x, max_y);
}

BOOL SetRectRgn(HRGN hrgn, int left, int top, int right, int bottom)
{
    GdiRegion *r = (GdiRegion *)Platform_ResolveHandle(hrgn, HANDLE_TYPE_HRGN);
    if (!r) return FALSE;

    r->rect.left = left;
    r->rect.top = top;
    r->rect.right = right;
    r->rect.bottom = bottom;
    r->is_null = false;
    return TRUE;
}

int SelectClipRgn(HDC hdc, HRGN hrgn)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return 0;

    if (!hrgn) {
        dc->clip_rect.left = 0;
        dc->clip_rect.top = 0;
        dc->clip_rect.right = dc->width;
        dc->clip_rect.bottom = dc->height;
        return 1;
    }

    GdiRegion *r = (GdiRegion *)Platform_ResolveHandle(hrgn, HANDLE_TYPE_HRGN);
    if (r) {
        dc->clip_rect = r->rect;
        return 1;
    }
    return 0;
}

int IntersectClipRect(HDC hdc, int left, int top, int right, int bottom)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return 0;

    RECT r2 = {left, top, right, bottom};
    RECT out;
    if (IntersectRect(&out, &dc->clip_rect, &r2)) {
        dc->clip_rect = out;
        return 1;
    }
    return 0;
}

/* ==========================================================================
 * DC Settings & Coordinates
 * ========================================================================== */

int SetROP2(HDC hdc, int rop2)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return 0;
    int prev = dc->rop2;
    dc->rop2 = rop2;
    return prev;
}

int SetBkMode(HDC hdc, int mode)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return 0;
    int prev = dc->bk_mode;
    dc->bk_mode = mode;
    return prev;
}

COLORREF SetBkColor(HDC hdc, COLORREF color)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return 0;
    COLORREF prev = dc->bk_color;
    dc->bk_color = color;
    return prev;
}

COLORREF SetTextColor(HDC hdc, COLORREF color)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return 0;
    COLORREF prev = dc->text_color;
    dc->text_color = color;
    return prev;
}

UINT SetTextAlign(HDC hdc, UINT align)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return 0;
    UINT prev = dc->text_align;
    dc->text_align = align;
    return prev;
}

UINT GetTextAlign(HDC hdc)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    return dc ? dc->text_align : 0;
}

int SetMapMode(HDC hdc, int iMode)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return 0;
    int prev = dc->map_mode;
    dc->map_mode = iMode;
    return prev;
}

BOOL SetViewportOrgEx(HDC hdc, int x, int y, LPPOINT lppt)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return FALSE;
    if (lppt) *lppt = dc->view_org;
    dc->view_org.x = x;
    dc->view_org.y = y;
    return TRUE;
}

BOOL OffsetViewportOrgEx(HDC hdc, int dx, int dy, LPPOINT lppt)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return FALSE;
    if (lppt) *lppt = dc->view_org;
    dc->view_org.x += dx;
    dc->view_org.y += dy;
    return TRUE;
}

BOOL SetViewportExtEx(HDC hdc, int x, int y, LPSIZE lpsz)
{
    (void)hdc;
    (void)x;
    (void)y;
    if (lpsz) {
        lpsz->cx = 640;
        lpsz->cy = 480;
    }
    return TRUE;
}

BOOL SetWindowOrgEx(HDC hdc, int x, int y, LPPOINT lppt)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return FALSE;
    if (lppt) *lppt = dc->win_org;
    dc->win_org.x = x;
    dc->win_org.y = y;
    return TRUE;
}

BOOL SetWindowExtEx(HDC hdc, int x, int y, LPSIZE lpsz)
{
    (void)hdc;
    (void)x;
    (void)y;
    if (lpsz) {
        lpsz->cx = 640;
        lpsz->cy = 480;
    }
    return TRUE;
}

BOOL LPtoDP(HDC hdc, LPPOINT lppt, int c)
{
    (void)hdc;
    (void)lppt;
    (void)c;
    return TRUE;
}

BOOL DPtoLP(HDC hdc, LPPOINT lppt, int c)
{
    (void)hdc;
    (void)lppt;
    (void)c;
    return TRUE;
}

/* ==========================================================================
 * Drawing Primitives
 * ========================================================================== */

BOOL MoveToEx(HDC hdc, int x, int y, LPPOINT lppt)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return FALSE;
    if (lppt) *lppt = dc->current_pos;
    dc->current_pos.x = x;
    dc->current_pos.y = y;
    return TRUE;
}

BOOL LineTo(HDC hdc, int x, int y)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc || !dc->pixels) return FALSE;

    int x0 = dc->current_pos.x;
    int y0 = dc->current_pos.y;
    dc->current_pos.x = x;
    dc->current_pos.y = y;

    /* Bresenham's line algorithm */
    int dx = abs(x - x0);
    int dy = abs(y - y0);
    int sx = (x0 < x) ? 1 : -1;
    int sy = (y0 < y) ? 1 : -1;
    int err = dx - dy;

    uint8_t color_val = 0; /* Default black */
    GdiPen *p = (GdiPen *)Platform_ResolveHandle(dc->selected_pen, HANDLE_TYPE_HPEN);
    if (p) {
        if (p->style == PS_NULL) return TRUE;
        color_val = (uint8_t)GetNearestPaletteIndex(dc->selected_palette, p->color);
    }

    int w = dc->width;
    int h = dc->height;
    int pitch = dc->pitch;

    while (1) {
        if (x0 >= dc->clip_rect.left && x0 < dc->clip_rect.right &&
            y0 >= dc->clip_rect.top  && y0 < dc->clip_rect.bottom &&
            x0 >= 0 && x0 < w && y0 >= 0 && y0 < h) {
            dc->pixels[y0 * pitch + x0] = color_val;
        }

        if (x0 == x && y0 == y) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
    return TRUE;
}

BOOL Rectangle(HDC hdc, int left, int top, int right, int bottom)
{
    RECT rc = {left, top, right, bottom};
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return FALSE;

    FillRect(hdc, &rc, dc->selected_brush);
    FrameRect(hdc, &rc, dc->selected_brush);
    return TRUE;
}

BOOL RoundRect(HDC hdc, int left, int top, int right, int bottom, int width, int height)
{
    (void)width;
    (void)height;
    return Rectangle(hdc, left, top, right, bottom);
}

BOOL Ellipse(HDC hdc, int left, int top, int right, int bottom)
{
    return Rectangle(hdc, left, top, right, bottom);
}

int FillRect(HDC hdc, const RECT *lprc, HBRUSH hbr)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc || !dc->pixels || !lprc) return 0;

    GdiBrush *b = (GdiBrush *)Platform_ResolveHandle(hbr, HANDLE_TYPE_HBRUSH);
    if (!b || b->style == BS_NULL) return 1;

    uint8_t color_val = (uint8_t)GetNearestPaletteIndex(dc->selected_palette, b->color);

    int x0 = (lprc->left > dc->clip_rect.left) ? lprc->left : dc->clip_rect.left;
    int y0 = (lprc->top > dc->clip_rect.top) ? lprc->top : dc->clip_rect.top;
    int x1 = (lprc->right < dc->clip_rect.right) ? lprc->right : dc->clip_rect.right;
    int y1 = (lprc->bottom < dc->clip_rect.bottom) ? lprc->bottom : dc->clip_rect.bottom;

    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 > dc->width) x1 = dc->width;
    if (y1 > dc->height) y1 = dc->height;

    for (int y = y0; y < y1; y++) {
        uint8_t *row = dc->pixels + (y * dc->pitch);
        memset(row + x0, color_val, (size_t)(x1 - x0));
    }
    return 1;
}

int FrameRect(HDC hdc, const RECT *lprc, HBRUSH hbr)
{
    if (!lprc) return 0;
    RECT top = {lprc->left, lprc->top, lprc->right, lprc->top + 1};
    RECT bottom = {lprc->left, lprc->bottom - 1, lprc->right, lprc->bottom};
    RECT left = {lprc->left, lprc->top, lprc->left + 1, lprc->bottom};
    RECT right = {lprc->right - 1, lprc->top, lprc->right, lprc->bottom};

    FillRect(hdc, &top, hbr);
    FillRect(hdc, &bottom, hbr);
    FillRect(hdc, &left, hbr);
    FillRect(hdc, &right, hbr);
    return 1;
}

BOOL DrawFocusRect(HDC hdc, const RECT *lprc)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc) return FALSE;
    FrameRect(hdc, lprc, g_StockGdi.black_brush);
    return TRUE;
}

COLORREF GetPixel(HDC hdc, int x, int y)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc || !dc->pixels || x < 0 || x >= dc->width || y < 0 || y >= dc->height) {
        return 0;
    }
    uint8_t idx = dc->pixels[y * dc->pitch + x];
    GdiPalette *pal = (GdiPalette *)Platform_ResolveHandle(dc->selected_palette, HANDLE_TYPE_HPALETTE);
    if (pal && idx < pal->count) {
        return RGB(pal->entries[idx].peRed, pal->entries[idx].peGreen, pal->entries[idx].peBlue);
    }
    return RGB(idx, idx, idx);
}

COLORREF SetPixel(HDC hdc, int x, int y, COLORREF color)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc || !dc->pixels) return 0;

    if (x >= dc->clip_rect.left && x < dc->clip_rect.right &&
        y >= dc->clip_rect.top  && y < dc->clip_rect.bottom &&
        x >= 0 && x < dc->width && y >= 0 && y < dc->height) {
        uint8_t idx = (uint8_t)GetNearestPaletteIndex(dc->selected_palette, color);
        dc->pixels[y * dc->pitch + x] = idx;
        return color;
    }
    return 0;
}

BOOL SetPixelV(HDC hdc, int x, int y, COLORREF color)
{
    return (SetPixel(hdc, x, y, color) != 0);
}

/* ==========================================================================
 * Blits & DIB Transfers
 * ========================================================================== */

int SetStretchBltMode(HDC hdc, int mode)
{
    (void)hdc;
    (void)mode;
    return 1;
}

BOOL BitBlt(HDC hdcDst, int xDst, int yDst, int cx, int cy,
            HDC hdcSrc, int xSrc, int ySrc, DWORD rop)
{
    GdiDC *dst = Gdi_GetDC(hdcDst);
    GdiDC *src = Gdi_GetDC(hdcSrc);

    if (!dst || !dst->pixels) return FALSE;
    if (cx <= 0 || cy <= 0) return TRUE;

    if (rop == BLACKNESS) {
        RECT rc = {xDst, yDst, xDst + cx, yDst + cy};
        FillRect(hdcDst, &rc, g_StockGdi.black_brush);
        return TRUE;
    }
    if (rop == WHITENESS) {
        RECT rc = {xDst, yDst, xDst + cx, yDst + cy};
        FillRect(hdcDst, &rc, g_StockGdi.white_brush);
        return TRUE;
    }

    if (!src || !src->pixels) return FALSE;

    /* Compute clipped extents */
    int dst_clip_l = dst->clip_rect.left > 0 ? dst->clip_rect.left : 0;
    int dst_clip_t = dst->clip_rect.top > 0 ? dst->clip_rect.top : 0;
    int dst_clip_r = dst->clip_rect.right < dst->width ? dst->clip_rect.right : dst->width;
    int dst_clip_b = dst->clip_rect.bottom < dst->height ? dst->clip_rect.bottom : dst->height;

    int src_w = src->width;
    int src_h = src->height;

    for (int y = 0; y < cy; y++) {
        int cur_dst_y = yDst + y;
        int cur_src_y = ySrc + y;

        if (cur_dst_y < dst_clip_t || cur_dst_y >= dst_clip_b) continue;
        if (cur_src_y < 0 || cur_src_y >= src_h) continue;

        int cur_x_start = 0;
        int cur_x_end = cx;

        if (xDst < dst_clip_l) cur_x_start = dst_clip_l - xDst;
        if (xDst + cx > dst_clip_r) cur_x_end = dst_clip_r - xDst;
        if (xSrc < 0) cur_x_start = (cur_x_start > -xSrc) ? cur_x_start : -xSrc;
        if (xSrc + cx > src_w) cur_x_end = (cur_x_end < src_w - xSrc) ? cur_x_end : (src_w - xSrc);

        if (cur_x_start >= cur_x_end) continue;

        uint8_t *dst_ptr = dst->pixels + (cur_dst_y * dst->pitch + (xDst + cur_x_start));
        const uint8_t *src_ptr = src->pixels + (cur_src_y * src->pitch + (xSrc + cur_x_start));
        int count = cur_x_end - cur_x_start;

        if (rop == SRCCOPY) {
            memmove(dst_ptr, src_ptr, (size_t)count);
        } else if (rop == SRCAND) {
            for (int i = 0; i < count; i++) dst_ptr[i] &= src_ptr[i];
        } else if (rop == SRCPAINT) {
            for (int i = 0; i < count; i++) dst_ptr[i] |= src_ptr[i];
        } else if (rop == SRCINVERT) {
            for (int i = 0; i < count; i++) dst_ptr[i] ^= src_ptr[i];
        } else {
            memmove(dst_ptr, src_ptr, (size_t)count);
        }
    }
    return TRUE;
}

BOOL StretchBlt(HDC hdcDst, int xDst, int yDst, int cxDst, int cyDst,
                HDC hdcSrc, int xSrc, int ySrc, int cxSrc, int cySrc, DWORD rop)
{
    GdiDC *dst = Gdi_GetDC(hdcDst);
    GdiDC *src = Gdi_GetDC(hdcSrc);

    if (!dst || !dst->pixels || !src || !src->pixels) return FALSE;
    if (cxDst <= 0 || cyDst <= 0 || cxSrc <= 0 || cySrc <= 0) return FALSE;

    int step_x = (cxSrc << 16) / cxDst;
    int step_y = (cySrc << 16) / cyDst;

    int dst_w = dst->width;
    int dst_h = dst->height;
    int src_w = src->width;
    int src_h = src->height;

    int acc_y = 0;
    for (int y = 0; y < cyDst; y++) {
        int cur_dst_y = yDst + y;
        int sample_src_y = ySrc + (acc_y >> 16);

        if (cur_dst_y >= 0 && cur_dst_y < dst_h && sample_src_y >= 0 && sample_src_y < src_h) {
            uint8_t *dst_row = dst->pixels + (cur_dst_y * dst->pitch);
            const uint8_t *src_row = src->pixels + (sample_src_y * src->pitch);

            int acc_x = 0;
            for (int x = 0; x < cxDst; x++) {
                int cur_dst_x = xDst + x;
                int sample_src_x = xSrc + (acc_x >> 16);

                if (cur_dst_x >= 0 && cur_dst_x < dst_w && sample_src_x >= 0 && sample_src_x < src_w) {
                    uint8_t s_pixel = src_row[sample_src_x];
                    if (rop == SRCCOPY) {
                        dst_row[cur_dst_x] = s_pixel;
                    } else if (rop == SRCAND) {
                        dst_row[cur_dst_x] &= s_pixel;
                    } else if (rop == SRCPAINT) {
                        dst_row[cur_dst_x] |= s_pixel;
                    } else if (rop == SRCINVERT) {
                        dst_row[cur_dst_x] ^= s_pixel;
                    } else {
                        dst_row[cur_dst_x] = s_pixel;
                    }
                }
                acc_x += step_x;
            }
        }
        acc_y += step_y;
    }
    return TRUE;
}

int SetDIBitsToDevice(HDC hdc, int xDest, int yDest, DWORD w, DWORD h,
                      int xSrc, int ySrc, UINT StartScan, UINT cScanLines,
                      const void *lpvBits, const BITMAPINFO *lpbmi, UINT ColorUse)
{
    (void)StartScan;
    (void)ColorUse;
    GdiDC *dst = Gdi_GetDC(hdc);
    if (!dst || !dst->pixels || !lpvBits || !lpbmi) return 0;

    int bpp = lpbmi->bmiHeader.biBitCount ? lpbmi->bmiHeader.biBitCount : 8;
    int src_pitch = ((lpbmi->bmiHeader.biWidth * bpp + 31) / 32) * 4;

    const uint8_t *src = (const uint8_t *)lpvBits;
    for (DWORD y = 0; y < h && y < cScanLines; y++) {
        int dst_y = yDest + (int)y;
        int src_y = ySrc + (int)y;

        if (dst_y >= 0 && dst_y < dst->height) {
            uint8_t *dst_row = dst->pixels + (dst_y * dst->pitch + xDest);
            const uint8_t *src_row = src + (src_y * src_pitch + xSrc);
            int copy_w = (int)w;
            if (xDest + copy_w > dst->width) copy_w = dst->width - xDest;
            if (copy_w > 0) {
                memcpy(dst_row, src_row, (size_t)copy_w);
            }
        }
    }
    return (int)h;
}

int SetDIBits(HDC hdc, HBITMAP hbm, UINT start, UINT cLines,
              const void *lpBits, const BITMAPINFO *lpbmi, UINT ColorUse)
{
    (void)hdc;
    (void)ColorUse;
    GdiBitmap *bmp = (GdiBitmap *)Platform_ResolveHandle(hbm, HANDLE_TYPE_HBITMAP);
    if (!bmp || !bmp->bits || !lpBits || !lpbmi) return 0;

    int bpp = lpbmi->bmiHeader.biBitCount ? lpbmi->bmiHeader.biBitCount : 8;
    int src_pitch = ((lpbmi->bmiHeader.biWidth * bpp + 31) / 32) * 4;

    const uint8_t *src = (const uint8_t *)lpBits;
    for (UINT y = 0; y < cLines && (start + y) < (UINT)bmp->height; y++) {
        uint8_t *dst_row = bmp->bits + ((start + y) * bmp->pitch);
        const uint8_t *src_row = src + (y * src_pitch);
        memcpy(dst_row, src_row, (size_t)bmp->pitch);
    }
    return (int)cLines;
}

UINT SetDIBColorTable(HDC hdc, UINT iStart, UINT cEntries, const RGBQUAD *prgbq)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc || !dc->selected_bitmap || !prgbq) return 0;

    GdiBitmap *bmp = (GdiBitmap *)Platform_ResolveHandle(dc->selected_bitmap, HANDLE_TYPE_HBITMAP);
    if (!bmp) return 0;

    UINT count = 0;
    for (UINT i = 0; i < cEntries && (iStart + i) < 256; i++) {
        bmp->colors[iStart + i] = prgbq[i];
        count++;
    }
    return count;
}

/* ==========================================================================
 * Paint & Presentation Lifecycle
 * ========================================================================== */

HDC BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint)
{
    if (!lpPaint) return NULL;
    LogicalWindow *w = User_GetWindow(hWnd);

    HDC hdc = GetDC(hWnd);
    lpPaint->hdc = hdc;
    lpPaint->fErase = FALSE;
    lpPaint->rcPaint = w ? w->client_rect : (RECT){0, 0, 640, 480};
    lpPaint->fRestore = FALSE;
    lpPaint->fIncUpdate = FALSE;

    if (w) w->needs_paint = false;
    return hdc;
}

BOOL EndPaint(HWND hWnd, const PAINTSTRUCT *lpPaint)
{
    if (!lpPaint) return FALSE;

    /* Present window to SDL framebuffer */
    LogicalWindow *w = User_GetWindow(hWnd);
    if (w && w->surface_pixels) {
        ScreenSurface surf;
        surf.type = 1;
        surf.clip_left = 0;
        surf.clip_top = 0;
        surf.clip_right = w->surface_pitch;
        surf.clip_bottom = (w->client_rect.bottom - w->client_rect.top);
        surf.pitch = w->surface_pitch;
        surf.pixels = w->surface_pixels;

        Shandalar_UpdateSurface(&surf);
        Shandalar_PresentFrame();
    }

    ReleaseDC(hWnd, lpPaint->hdc);
    return TRUE;
}

BOOL InvalidateRect(HWND hWnd, const RECT *lpRect, BOOL bErase)
{
    (void)bErase;
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return FALSE;

    if (lpRect) {
        UnionRect(&w->update_rect, &w->update_rect, lpRect);
    } else {
        w->update_rect = w->client_rect;
    }
    w->needs_paint = true;
    return TRUE;
}

BOOL GdiFlush(void)
{
    HWND active = User_GetActiveWindowInternal();
    LogicalWindow *w = User_GetWindow(active);
    if (w && w->surface_pixels) {
        ScreenSurface surf;
        surf.type = 1;
        surf.clip_left = 0;
        surf.clip_top = 0;
        surf.clip_right = w->surface_pitch;
        surf.clip_bottom = (w->client_rect.bottom - w->client_rect.top);
        surf.pitch = w->surface_pitch;
        surf.pixels = w->surface_pixels;

        Shandalar_UpdateSurface(&surf);
        Shandalar_PresentFrame();
    }
    return TRUE;
}

DWORD GdiGetBatchLimit(void)
{
    return 1;
}

DWORD GdiSetBatchLimit(DWORD dw)
{
    (void)dw;
    return 1;
}

/* ==========================================================================
 * Text Rendering & Metrics
 * ========================================================================== */

/* Built-in 8x8 font glyph renderer */
static const uint8_t s_SimpleFont8x8[128][8] = {
    ['A'] = {0x18, 0x24, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x00},
    ['B'] = {0x7C, 0x42, 0x42, 0x7C, 0x42, 0x42, 0x7C, 0x00},
    ['C'] = {0x3C, 0x42, 0x40, 0x40, 0x40, 0x42, 0x3C, 0x00},
    ['D'] = {0x78, 0x44, 0x42, 0x42, 0x42, 0x44, 0x78, 0x00},
    ['E'] = {0x7E, 0x40, 0x40, 0x78, 0x40, 0x40, 0x7E, 0x00},
    ['F'] = {0x7E, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40, 0x00},
    ['G'] = {0x3C, 0x42, 0x40, 0x4E, 0x42, 0x42, 0x3C, 0x00},
    ['H'] = {0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x00},
    ['I'] = {0x3E, 0x1C, 0x18, 0x18, 0x18, 0x1C, 0x3E, 0x00},
    ['J'] = {0x1E, 0x0C, 0x0C, 0x0C, 0x4C, 0x4C, 0x38, 0x00},
    ['K'] = {0x44, 0x48, 0x50, 0x60, 0x50, 0x48, 0x44, 0x00},
    ['L'] = {0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7E, 0x00},
    ['M'] = {0x42, 0x66, 0x5A, 0x42, 0x42, 0x42, 0x42, 0x00},
    ['N'] = {0x42, 0x62, 0x52, 0x4A, 0x46, 0x42, 0x42, 0x00},
    ['O'] = {0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x00},
    ['P'] = {0x7C, 0x42, 0x42, 0x7C, 0x40, 0x40, 0x40, 0x00},
    ['Q'] = {0x3C, 0x42, 0x42, 0x42, 0x4A, 0x44, 0x3A, 0x00},
    ['R'] = {0x7C, 0x42, 0x42, 0x7C, 0x50, 0x48, 0x44, 0x00},
    ['S'] = {0x3C, 0x42, 0x40, 0x3C, 0x02, 0x42, 0x3C, 0x00},
    ['T'] = {0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00},
    ['U'] = {0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x00},
    ['V'] = {0x42, 0x42, 0x42, 0x42, 0x24, 0x24, 0x18, 0x00},
    ['W'] = {0x42, 0x42, 0x42, 0x42, 0x5A, 0x66, 0x42, 0x00},
    ['X'] = {0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x42, 0x00},
    ['Y'] = {0x42, 0x42, 0x24, 0x18, 0x18, 0x18, 0x18, 0x00},
    ['Z'] = {0x7E, 0x04, 0x08, 0x10, 0x20, 0x40, 0x7E, 0x00},
    ['0'] = {0x3C, 0x46, 0x4A, 0x52, 0x62, 0x42, 0x3C, 0x00},
    ['1'] = {0x18, 0x28, 0x08, 0x08, 0x08, 0x08, 0x3E, 0x00},
    ['2'] = {0x3C, 0x42, 0x02, 0x0C, 0x30, 0x40, 0x7E, 0x00},
    ['3'] = {0x3C, 0x42, 0x02, 0x1C, 0x02, 0x42, 0x3C, 0x00},
    ['4'] = {0x44, 0x44, 0x44, 0x7E, 0x04, 0x04, 0x04, 0x00},
    ['5'] = {0x7E, 0x40, 0x7C, 0x02, 0x02, 0x42, 0x3C, 0x00},
    ['6'] = {0x3C, 0x42, 0x40, 0x7C, 0x42, 0x42, 0x3C, 0x00},
    ['7'] = {0x7E, 0x02, 0x04, 0x08, 0x10, 0x20, 0x20, 0x00},
    ['8'] = {0x3C, 0x42, 0x42, 0x3C, 0x42, 0x42, 0x3C, 0x00},
    ['9'] = {0x3C, 0x42, 0x42, 0x3E, 0x02, 0x42, 0x3C, 0x00},
    [' '] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    ['.'] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00},
    [':'] = {0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00, 0x00},
    ['-'] = {0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00}
};

BOOL TextOutA(HDC hdc, int x, int y, LPCSTR lpString, int c)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    if (!dc || !dc->pixels || !lpString || c <= 0) return FALSE;

    uint8_t fg = (uint8_t)GetNearestPaletteIndex(dc->selected_palette, dc->text_color);
    uint8_t bg = (uint8_t)GetNearestPaletteIndex(dc->selected_palette, dc->bk_color);

    int cur_x = x;
    for (int i = 0; i < c; i++) {
        unsigned char ch = (unsigned char)lpString[i];
        if (ch >= 'a' && ch <= 'z') ch = ch - 'a' + 'A';
        if (ch >= 128) ch = ' ';

        for (int r = 0; r < 8; r++) {
            int py = y + r;
            if (py < dc->clip_rect.top || py >= dc->clip_rect.bottom || py < 0 || py >= dc->height) continue;
            uint8_t *row = dc->pixels + (py * dc->pitch);
            uint8_t row_bits = s_SimpleFont8x8[ch][r];

            for (int col = 0; col < 8; col++) {
                int px = cur_x + col;
                if (px < dc->clip_rect.left || px >= dc->clip_rect.right || px < 0 || px >= dc->width) continue;
                if (row_bits & (0x80 >> col)) {
                    row[px] = fg;
                } else if (dc->bk_mode == OPAQUE) {
                    row[px] = bg;
                }
            }
        }
        cur_x += 8;
    }
    return TRUE;
}

int DrawTextA(HDC hdc, LPCSTR lpchText, int cchText, LPRECT lprc, UINT format)
{
    if (!lpchText || !lprc) return 0;
    int len = (cchText < 0) ? (int)strlen(lpchText) : cchText;

    if (format & DT_CALCRECT) {
        lprc->right = lprc->left + (len * 8);
        lprc->bottom = lprc->top + 12;
        return 12;
    }

    int x = lprc->left;
    int y = lprc->top;

    if (format & DT_CENTER) {
        x = lprc->left + ((lprc->right - lprc->left) - (len * 8)) / 2;
    } else if (format & DT_RIGHT) {
        x = lprc->right - (len * 8);
    }
    if (format & DT_VCENTER) {
        y = lprc->top + ((lprc->bottom - lprc->top) - 8) / 2;
    }

    TextOutA(hdc, x, y, lpchText, len);
    return 12;
}

BOOL GetTextExtentPointA(HDC hdc, LPCSTR lpString, int cbString, LPSIZE lpSize)
{
    return GetTextExtentPoint32A(hdc, lpString, cbString, lpSize);
}

BOOL GetTextExtentPoint32A(HDC hdc, LPCSTR lpString, int cbString, LPSIZE lpSize)
{
    (void)hdc;
    if (!lpSize) return FALSE;
    int len = (cbString >= 0) ? cbString : (lpString ? (int)strlen(lpString) : 0);
    lpSize->cx = len * 8;
    lpSize->cy = 12;
    return TRUE;
}

BOOL GetTextMetricsA(HDC hdc, LPTEXTMETRICA lptm)
{
    (void)hdc;
    if (!lptm) return FALSE;
    memset(lptm, 0, sizeof(*lptm));
    lptm->tmHeight = 12;
    lptm->tmAscent = 9;
    lptm->tmDescent = 3;
    lptm->tmAveCharWidth = 8;
    lptm->tmMaxCharWidth = 8;
    lptm->tmWeight = 400;
    return TRUE;
}

BOOL GetCharWidthA(HDC hdc, UINT iFirstChar, UINT iLastChar, LPINT lpBuffer)
{
    (void)hdc;
    if (!lpBuffer) return FALSE;
    for (UINT i = iFirstChar; i <= iLastChar; i++) {
        lpBuffer[i - iFirstChar] = 8;
    }
    return TRUE;
}

BOOL GetCharABCWidthsA(HDC hdc, UINT uFirstChar, UINT uLastChar, LPABC lpabc)
{
    (void)hdc;
    if (!lpabc) return FALSE;
    for (UINT i = uFirstChar; i <= uLastChar; i++) {
        size_t idx = i - uFirstChar;
        lpabc[idx].abcA = 0;
        lpabc[idx].abcB = 8;
        lpabc[idx].abcC = 0;
    }
    return TRUE;
}

int GetDeviceCaps(HDC hdc, int nIndex)
{
    GdiDC *dc = Gdi_GetDC(hdc);
    switch (nIndex) {
        case HORZRES:
            return dc ? dc->width : 640;
        case VERTRES:
            return dc ? dc->height : 480;
        case BITSPIXEL:
            return 8;
        case PLANES:
            return 1;
        case NUMCOLORS:
        case SIZEPALETTE:
            return 256;
        case RASTERCAPS:
            return 0x0001 | 0x0002; /* RC_BITBLT | RC_STRETCHBLT */
        case LOGPIXELSX:
        case LOGPIXELSY:
            return 96;
        default:
            return 0;
    }
}
