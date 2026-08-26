/*
 * shandalar/display_shim.h - Modern Display & GDI Translation Layer (SDL2 Backend)
 * Comments follow Simplified Technical English (ASD-STE100) rules.
 */
#ifndef SHANDALAR_DISPLAY_SHIM_H
#define SHANDALAR_DISPLAY_SHIM_H

#include "types.h"
#include "graphics.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Modern Display Configuration.
 * Holds configuration settings for the active window and renderer.
 */
typedef struct DisplayConfig {
    int         window_width;      /* Virtual display width (default: 640 or 1024). */
    int         window_height;     /* Virtual display height (default: 480 or 768). */
    int         scale_factor;      /* Integer scaling multiplier (1x, 2x, 3x). */
    bool        fullscreen;        /* True for fullscreen mode, false for windowed. */
    bool        vsync;             /* True to synchronize frame presentation with display refresh. */
    const char *window_title;      /* Window title bar text. */
} DisplayConfig;

/*
 * Display Shim API Functions
 */

/*
 * Shandalar_DisplayInit
 * Purpose: Initialize the modern display backend, create window, renderer, and texture.
 * Parameter config: Pointer to the display configuration settings.
 * Returns: 1 on success, or 0 on failure.
 */
int Shandalar_DisplayInit(const DisplayConfig *config);

/*
 * Shandalar_DisplayShutdown
 * Purpose: Destroy display textures, renderer, window, and shut down video subsystem.
 */
void Shandalar_DisplayShutdown(void);

/*
 * Shandalar_SetPalette
 * Purpose: Update the 256-color palette lookup table used for 8-bit pixel conversion.
 * Parameter palette_rgb256: Pointer to an array of 256 32-bit RGB color values.
 */
void Shandalar_SetPalette(const uint32_t *palette_rgb256);

/*
 * Shandalar_SetPaletteEntry
 * Purpose: Update a single color index (0 to 255) in the active display palette.
 * Parameter index: Palette index to update (0 to 255).
 * Parameter r: Red color component (0 to 255).
 * Parameter g: Green color component (0 to 255).
 * Parameter b: Blue color component (0 to 255).
 */
void Shandalar_SetPaletteEntry(uint8_t index, uint8_t r, uint8_t g, uint8_t b);

/*
 * Shandalar_UpdateSurface
 * Purpose: Convert an 8-bit paletted surface buffer to 32-bit RGBA and copy to texture.
 * Parameter surf: Pointer to the ScreenSurface descriptor to update.
 */
void Shandalar_UpdateSurface(const ScreenSurface *surf);

/*
 * Shandalar_PresentFrame
 * Purpose: Clear renderer, copy converted framebuffer texture, and present to screen.
 */
void Shandalar_PresentFrame(void);

/*
 * Shandalar_PollEvents
 * Purpose: Process window and input events from the operating system event queue.
 * Translates OS events into Win32 messages and dispatches to window procedures.
 * Returns: 1 if the application should continue running, or 0 if a quit event was received.
 */
int Shandalar_PollEvents(void);

/*
 * Win32 GDI & DirectDraw Translation Shims
 */

/*
 * Shim_CreateDIBSection
 * Purpose: Allocate an 8-bit or 24-bit software device-independent bitmap buffer.
 * Parameter width: Width of the bitmap in pixels.
 * Parameter height: Height of the bitmap in pixels.
 * Parameter bpp: Bits per pixel (8 for paletted, 24 for RGB, 32 for RGBA).
 * Parameter out_bits: Address of the pointer to receive the pixel buffer address.
 * Returns: A pseudo-HBITMAP handle on success, or NULL on failure.
 */
void* Shim_CreateDIBSection(int width, int height, int bpp, void **out_bits);

/*
 * Shim_BitBlt
 * Purpose: Copy a rectangular pixel region from a source surface to a destination surface.
 * Parameter dst_surf: Destination surface pointer.
 * Parameter dst_x: Destination X coordinate.
 * Parameter dst_y: Destination Y coordinate.
 * Parameter width: Width of the region to copy.
 * Parameter height: Height of the region to copy.
 * Parameter src_surf: Source surface pointer.
 * Parameter src_x: Source X coordinate.
 * Parameter src_y: Source Y coordinate.
 * Parameter rop: Raster operation code.
 * Returns: 1 on success, or 0 on error.
 */
int Shim_BitBlt(ScreenSurface *dst_surf, int dst_x, int dst_y, int width, int height,
                const ScreenSurface *src_surf, int src_x, int src_y, uint32_t rop);

/*
 * Shim_StretchBlt
 * Purpose: Copy and scale a rectangular pixel region from a source to a destination surface.
 */
int Shim_StretchBlt(ScreenSurface *dst_surf, int dst_x, int dst_y, int dst_w, int dst_h,
                    const ScreenSurface *src_surf, int src_x, int src_y, int src_w, int src_h,
                    uint32_t rop);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_DISPLAY_SHIM_H */
