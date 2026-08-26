/*
 * sidlib/sprite.c - MicroProse Sid Meier 2D Sprite Engine
 * Original Source Path: G:\NewMagic\sources\sidlib\sprite.c
 * Reconstructed ANSI C Implementation for Shandalar (Magic: The Gathering 1997)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/sprite.h"

/* Win32 / CRT IO compatibility helpers */
#ifndef _fileno
#define _fileno fileno
#endif
extern long _filelength(int fd);
extern void AssertOrLog(int cond, int file_id, int line, const char *fmt, ...);

/*
 * External Engine Surface Table & 16.16 Fixed-Point Scaling Globals
 */
extern SurfaceInfo* g_ScreenSurfaces[];         /* 0x0070a850: Table of active screen surface descriptors */
extern int*         g_SpriteEncodeCursor;       /* 0x0062517c: Write pointer in RLE sprite output buffer */
extern int32_t      g_SpriteScaleStepX;         /* 0x00624168: 16.16 fixed-point X increment */
extern int32_t      g_SpriteScaleStepY;         /* 0x0062416c: 16.16 fixed-point Y increment */
extern int32_t      g_SpriteScaleClampedW;      /* 0x00624170: Viewport-clamped destination width */
extern int32_t      g_SpriteScaleLookupX[];     /* 0x00624178: Map table from source X to scaled target X */
extern int32_t      g_SpriteScaleCachedH;       /* 0x00625180: Cached source sprite height */
extern int32_t      g_SpriteScaleAccX;          /* 0x00625184: 16.16 fixed-point X accumulator */
extern int32_t      g_SpriteScaleAccY;          /* 0x00625188: 16.16 fixed-point Y accumulator */
extern int32_t      g_SpriteScaleCachedTargetH; /* 0x0062518c: Cached target destination height */
extern int32_t      g_SpriteScaleClipLeft;      /* 0x00625190: Left clipping margin offset */
extern int32_t      g_SpriteScaleCachedTargetW; /* 0x00625194: Cached target destination width */
extern int32_t      g_SpriteScalePixelMap[];    /* 0x00625198: Map table from target X to source X */
extern int32_t      g_SpriteScaleCachedW;       /* 0x00626198: Cached source sprite width */

/* Link to raw Ghidra symbols for binary alignment */
#define g_ScreenSurfaces           DAT_0070a850
#define g_SpriteEncodeCursor       DAT_0062517c
#define g_SpriteScaleStepX         DAT_00624168
#define g_SpriteScaleStepY         DAT_0062416c
#define g_SpriteScaleClampedW      DAT_00624170
#define g_SpriteScaleLookupX       (&DAT_00624178)
#define g_SpriteScaleCachedH       DAT_00625180
#define g_SpriteScaleAccX          DAT_00625184
#define g_SpriteScaleAccY          DAT_00625188
#define g_SpriteScaleCachedTargetH DAT_0062518c
#define g_SpriteScaleClipLeft      DAT_00625190
#define g_SpriteScaleCachedTargetW DAT_00625194
#define g_SpriteScalePixelMap      (&DAT_00625198)
#define g_SpriteScaleCachedW       DAT_00626198

extern SurfaceInfo* DAT_0070a850[];
extern int*         DAT_0062517c;
extern int32_t      DAT_00624168;
extern int32_t      DAT_0062416c;
extern int32_t      DAT_00624170;
extern int32_t      DAT_00624178;
extern int32_t      DAT_00625180;
extern int32_t      DAT_00625184;
extern int32_t      DAT_00625188;
extern int32_t      DAT_0062518c;
extern int32_t      DAT_00625190;
extern int32_t      DAT_00625194;
extern int32_t      DAT_00625198;
extern int32_t      DAT_00626198;

/* ==========================================================================
 * Sprite_LoadAll - Load all sprites from a .SPR file into an array
 * ========================================================================== */
int Sprite_LoadAll(void **out_sprite_array, const char *filename)
{
    FILE *fp;
    int fd;
    size_t file_size;
    int *sprite_buf;
    int sprite_count = 0;

    fp = fopen(filename, "rb");
    AssertOrLog((int)(uintptr_t)fp, 0x53276c, 0xa3, "Could not open Sprite File: %s", filename);
    if (!fp) return 0;

    fd = _fileno(fp);
    file_size = _filelength(fd);
    sprite_buf = (int *)malloc(file_size);
    fread(sprite_buf, 1, file_size, fp);
    fclose(fp);

    /* Read sequential sprites delimited by -1 until EOF */
    while (*sprite_buf != -1) {
        *out_sprite_array = sprite_buf;
        out_sprite_array++;
        sprite_count++;
        sprite_buf = (int *)((uint8_t *)sprite_buf + *sprite_buf);
    }

    return sprite_count;
}

/* ==========================================================================
 * Sprite_LoadCount - Load up to max_count sprites from a .SPR file
 * ========================================================================== */
uint32_t Sprite_LoadCount(void **out_sprite_array, const char *filename, uint32_t max_count)
{
    FILE *fp;
    int fd;
    size_t file_size;
    int *sprite_buf;
    uint32_t loaded_count = 0;

    fp = fopen(filename, "rb");
    AssertOrLog((int)(uintptr_t)fp, 0x53276c, 0xc5, "Could not open Sprite File: %s", filename);
    if (!fp) return 0;

    fd = _fileno(fp);
    file_size = _filelength(fd);
    sprite_buf = (int *)malloc(file_size);
    fread(sprite_buf, 1, file_size, fp);
    fclose(fp);

    for (loaded_count = 0; (*sprite_buf != -1 && (loaded_count < max_count)); loaded_count++) {
        *out_sprite_array = sprite_buf;
        out_sprite_array++;
        sprite_buf = (int *)((uint8_t *)sprite_buf + *sprite_buf);
    }

    return loaded_count;
}

/* ==========================================================================
 * Sprite_ScanRunLength - Scan consecutive matching pixels along an axis
 * ========================================================================== */
int Sprite_ScanRunLength(int surface_id, int start_x, int start_y, int step_x, int step_y)
{
    int base_color;
    int current_color;
    int run_len;
    bool is_horizontal;
    int max_length;

    if (start_x < 0 || start_y < 0) {
        return -1;
    }

    is_horizontal = (step_x != 0);
    base_color = Surface_GetPixel(surface_id, start_x, start_y);
    max_length = (step_x == 0) ? step_y : step_x;

    run_len = 0;
    if (max_length > 0) {
        do {
            current_color = Surface_GetPixel(surface_id, start_x, start_y);
            if (current_color != base_color) break;
            run_len++;
            start_x += (uint32_t)is_horizontal;
            start_y += (uint32_t)(step_y != 0);
        } while (run_len < max_length);
    }

    return (run_len != max_length) ? run_len : -1;
}

/* ==========================================================================
 * Sprite_EncodeFromSurface - Compress surface rectangle into MicroProse RLE sprite
 * ========================================================================== */
void Sprite_EncodeFromSurface(int src_surface, int src_x, int src_y, uint32_t width, int height)
{
    char pixel;
    int *hdr;
    int *write_ptr;
    int start_y_offset = 0;
    int clip_bottom_calc;
    int clip_left_calc;
    int scan_x;
    int scan_y;
    int run_count;
    char scanline_buf[1024];
    char *p_line;
    uint32_t remaining_w;
    uint32_t skip_left;
    uint32_t opaque_len;
    uint8_t *run_header;
    char *dst_copy;

    /* 1. Calculate bounding box and transparent outer margins */
    scan_y = src_y + 1 + height;
    scan_x = src_x - 1;
    if (scan_x < 0 || scan_y < 0) {
        clip_bottom_calc = -1;
    } else {
        int target_w = width + 2;
        uint32_t color = Surface_GetPixel(src_surface, scan_x, scan_y);
        run_count = 0;
        int cur_x = scan_x;
        while (run_count < target_w) {
            if (Surface_GetPixel(src_surface, cur_x, scan_y) != color) break;
            run_count++;
            cur_x++;
        }
        clip_bottom_calc = (run_count != target_w) ? run_count : -1;
    }

    scan_y = src_y - 1;
    if (scan_x < 0 || scan_y < 0) {
        clip_left_calc = -1;
    } else {
        uint32_t color = Surface_GetPixel(src_surface, scan_x, scan_y);
        int target_h = height + 2;
        run_count = 0;
        while (run_count < target_h) {
            if (Surface_GetPixel(src_surface, scan_x, scan_y) != color) break;
            run_count++;
            scan_y++;
        }
        clip_left_calc = (run_count != target_h) ? run_count : -1;
    }

    /* 2. Skip top fully-transparent rows */
    hdr = g_SpriteEncodeCursor;
    write_ptr = g_SpriteEncodeCursor + 4;
    do {
        Surface_GetLine(scanline_buf, src_surface, src_x, src_y + start_y_offset, width);
        p_line = scanline_buf;
        remaining_w = width;
        pixel = scanline_buf[0];
        while (pixel == '\0' && remaining_w != 0) {
            pixel = *(++p_line);
            remaining_w--;
        }
    } while ((p_line - width == scanline_buf) && (++start_y_offset < height));

    /* 3. Populate Header: width, height, clip margins, origin offsets */
    *(int16_t *)((uint8_t *)hdr + 4) = (int16_t)width;
    *(int16_t *)((uint8_t *)hdr + 6) = (int16_t)height;
    *(int16_t *)((uint8_t *)hdr + 8) = (int16_t)clip_bottom_calc;
    *(int16_t *)((uint8_t *)hdr + 10) = (int16_t)clip_left_calc;
    *(int16_t *)((uint8_t *)hdr + 12) = (int16_t)start_y_offset;
    *(int16_t *)((uint8_t *)hdr + 14) = (int16_t)(height - start_y_offset);

    /* 4. Encode scanlines with RLE compression */
    for (; start_y_offset < height; start_y_offset++) {
        p_line = scanline_buf;
        remaining_w = width;
        pixel = scanline_buf[0];
        while (pixel == '\0' && remaining_w != 0) {
            pixel = *(++p_line);
            remaining_w--;
        }
        skip_left = (uint32_t)(p_line - scanline_buf);

        if (width == skip_left) {
            /* Entire row is transparent */
            *(uint8_t *)write_ptr = 0xFF;
            write_ptr = (int *)((uint8_t *)write_ptr + 1);
        } else {
            /* Row has visible pixels */
            *(char *)write_ptr = (char)skip_left;
            run_header = (uint8_t *)((uint8_t *)write_ptr + 1);

            int end_idx = (int)width;
            while (end_idx > 0 && scanline_buf[end_idx - 1] == '\0') {
                end_idx--;
            }
            opaque_len = end_idx - skip_left;

            /* Check if completely solid or masked */
            if (memchr(scanline_buf + skip_left, 0, opaque_len) == NULL) {
                *run_header = 0xFE;  /* Solid opaque block */
                run_header = (uint8_t *)((uint8_t *)write_ptr + 2);
            }
            *run_header = (uint8_t)opaque_len;

            p_line = scanline_buf + skip_left;
            dst_copy = (char *)(run_header + 1);

            /* Fast 32-bit copy */
            for (uint32_t dword_count = opaque_len >> 2; dword_count != 0; dword_count--) {
                *(uint32_t *)dst_copy = *(uint32_t *)p_line;
                p_line += 4;
                dst_copy += 4;
            }
            for (uint32_t byte_count = opaque_len & 3; byte_count != 0; byte_count--) {
                *dst_copy++ = *p_line++;
            }
            write_ptr = (int *)(run_header + 1 + opaque_len);
        }
        Surface_GetLine(scanline_buf, src_surface, src_x, src_y + start_y_offset + 1, width);
    }

    /* 5. Trim trailing empty rows and write terminating -1 */
    pixel = *(char *)((uint8_t *)write_ptr - 1);
    g_SpriteEncodeCursor = write_ptr;
    while (pixel == -1) {
        *(int16_t *)((uint8_t *)hdr + 14) -= 1;
        pixel = *(char *)((uint8_t *)g_SpriteEncodeCursor - 2);
        g_SpriteEncodeCursor = (int *)((uint8_t *)g_SpriteEncodeCursor - 1);
    }

    /* Align to 4 bytes */
    uintptr_t addr = (uintptr_t)g_SpriteEncodeCursor;
    if (addr & 1) addr += 1;
    if (addr & 2) addr += 2;
    g_SpriteEncodeCursor = (int *)addr;

    *g_SpriteEncodeCursor = -1;
    *hdr = (int)((uint8_t *)g_SpriteEncodeCursor - (uint8_t *)hdr);
}

/* ==========================================================================
 * Sprite_DrawDirect - Fast unclipped 2D sprite blitter
 * ========================================================================== */
void Sprite_DrawDirect(ScreenSurface *surf, int dst_x, int dst_y, const void *sprite_data)
{
    const uint8_t *raw_sprite = (const uint8_t *)sprite_data;
    if (!raw_sprite) return;

    int surf_type = surf->type;
    SurfaceInfo *surf_info = g_ScreenSurfaces[surf_type];
    int16_t visible_rows = *(int16_t *)(raw_sprite + 0x0E);
    int start_y = dst_y + *(int16_t *)(raw_sprite + 0x0C);
    int pitch = surf_info->pitch + surf_info->stride_extra;
    uint8_t *frame_ptr = surf_info->frame_buffer + (dst_x + pitch * start_y);
    const uint8_t *rle_stream = raw_sprite + 0x10;

    for (int row = 0; row < visible_rows; row++) {
        uint32_t skip_pixels = (uint32_t)*rle_stream++;
        if (skip_pixels != 0xFF) {
            uint32_t run_length = (uint32_t)*rle_stream++;
            bool is_masked = (run_length != 0xFE);
            if (!is_masked) {
                run_length = (uint32_t)*rle_stream++;
            }

            int cur_y = start_y + row;
            if (cur_y >= 0) {
                if (is_masked) {
                    if (surf_type == 0) {
                        for (uint32_t i = 0; i < run_length; i++) {
                            if (rle_stream[i] != 0) {
                                Surface_PutPixel(surf, dst_x + skip_pixels + i, cur_y, (uint32_t)rle_stream[i]);
                            }
                        }
                    } else {
                        for (uint32_t i = 0; i < run_length; i++) {
                            if (rle_stream[i] != 0) {
                                frame_ptr[skip_pixels + i] = rle_stream[i];
                            }
                        }
                    }
                    rle_stream += run_length;
                } else {
                    /* Solid row copy */
                    if (surf_type == 0) {
                        Surface_PutLine((void *)rle_stream, 0, dst_x + skip_pixels, cur_y, run_length);
                    } else {
                        uint8_t *dst_pixel = frame_ptr + skip_pixels;
                        const uint8_t *src_pixel = rle_stream;
                        for (uint32_t dword_count = run_length >> 2; dword_count != 0; dword_count--) {
                            *(uint32_t *)dst_pixel = *(const uint32_t *)src_pixel;
                            src_pixel += 4;
                            dst_pixel += 4;
                        }
                        for (uint32_t byte_count = run_length & 3; byte_count != 0; byte_count--) {
                            *dst_pixel++ = *src_pixel++;
                        }
                    }
                    rle_stream += run_length;
                }
            } else {
                rle_stream += run_length;
            }
        }
        frame_ptr += pitch;
    }
}

/* ==========================================================================
 * Sprite_DrawClipped - Viewport clipped 2D sprite blitter
 * ========================================================================== */
void Sprite_DrawClipped(ScreenSurface *surf, int dst_x, int dst_y, const void *sprite_data)
{
    const uint8_t *raw_sprite = (const uint8_t *)sprite_data;
    if (!raw_sprite) return;

    int clip_right = surf->clip_right;
    int clip_bottom = surf->clip_bottom;
    int clip_left = surf->clip_left;
    int clip_top = surf->clip_top;

    if (dst_x > clip_right || dst_y > clip_bottom) return;

    int16_t sprite_w = *(int16_t *)(raw_sprite + 4);
    int16_t sprite_h = *(int16_t *)(raw_sprite + 6);

    /* Fast-path if completely inside clipping box */
    if (clip_left <= dst_x && (dst_x + sprite_w <= clip_right) &&
        clip_top <= dst_y && (dst_y + sprite_h <= clip_bottom)) {
        Sprite_DrawDirect(surf, dst_x, dst_y, sprite_data);
        return;
    }

    int start_y = dst_y + *(int16_t *)(raw_sprite + 0x0C);
    int visible_rows = (int)*(int16_t *)(raw_sprite + 0x0E);

    if (dst_x <= clip_right && clip_left <= dst_x + sprite_w &&
        clip_top <= start_y + visible_rows && start_y <= clip_bottom) {

        int surf_type = surf->type;
        SurfaceInfo *surf_info = g_ScreenSurfaces[surf_type];
        int pitch = surf_info->pitch + surf_info->stride_extra;
        uint8_t *frame_ptr = surf_info->frame_buffer + (dst_x + pitch * start_y);
        const uint8_t *rle_stream = raw_sprite + 0x10;

        for (int row = 0; row < visible_rows; row++) {
            int cur_y = start_y + row;
            if (cur_y > clip_bottom) return;

            if (cur_y < clip_top) {
                /* Skip row outside top boundary */
                if (*rle_stream == 0xFF) {
                    rle_stream++;
                } else if (rle_stream[1] == 0xFE) {
                    rle_stream += rle_stream[2] + 3;
                } else {
                    rle_stream += rle_stream[1] + 2;
                }
            } else {
                uint32_t skip_pixels = (uint32_t)*rle_stream++;
                if (skip_pixels != 0xFF) {
                    uint32_t run_len = (uint32_t)*rle_stream++;
                    bool is_solid = (run_len == 0xFE);
                    if (is_solid) {
                        run_len = (uint32_t)*rle_stream++;
                    }

                    int render_x = dst_x + skip_pixels;
                    if (render_x <= clip_right) {
                        uint32_t clamped_run = run_len;
                        if ((int)(render_x + run_len) > clip_right) {
                            clamped_run = clip_right - render_x;
                        }

                        if (is_solid) {
                            if (surf_type == 0) {
                                Surface_PutLine((void *)rle_stream, 0, render_x, cur_y, clamped_run);
                            } else {
                                uint8_t *dst_pixel = frame_ptr + skip_pixels;
                                const uint8_t *src_pixel = rle_stream;
                                for (uint32_t dword_count = clamped_run >> 2; dword_count != 0; dword_count--) {
                                    *(uint32_t *)dst_pixel = *(const uint32_t *)src_pixel;
                                    src_pixel += 4;
                                    dst_pixel += 4;
                                }
                                for (uint32_t byte_count = clamped_run & 3; byte_count != 0; byte_count--) {
                                    *dst_pixel++ = *src_pixel++;
                                }
                            }
                        } else {
                            int start_offset = (render_x < clip_left) ? (clip_left - render_x) : 0;
                            for (uint32_t i = start_offset; i < clamped_run; i++) {
                                if (rle_stream[i] != 0) {
                                    if (surf_type == 0) {
                                        Surface_PutPixel(surf, render_x + i, cur_y, (uint32_t)rle_stream[i]);
                                    } else {
                                        frame_ptr[skip_pixels + i] = rle_stream[i];
                                    }
                                }
                            }
                        }
                    }
                    rle_stream += run_len;
                }
            }
            frame_ptr += pitch;
        }
    }
}

/* ==========================================================================
 * Sprite_DrawScaled - Fixed-point 16.16 stretch / scale sprite blitter
 * ========================================================================== */
void Sprite_DrawScaled(ScreenSurface *surf, int dst_x, int dst_y, int target_w, int target_h, const void *sprite_data)
{
    const uint8_t *raw_sprite = (const uint8_t *)sprite_data;
    if (!raw_sprite || dst_x > surf->clip_right || dst_y > surf->clip_bottom) return;

    int surf_type = surf->type;
    SurfaceInfo *surf_info = g_ScreenSurfaces[surf_type];
    int16_t sprite_w = *(int16_t *)(raw_sprite + 4);
    int16_t sprite_h = *(int16_t *)(raw_sprite + 6);

    /* Initialize fixed-point DDA scaling step ratios */
    if (g_SpriteScaleCachedTargetW != target_w || g_SpriteScaleCachedTargetH != target_h ||
        sprite_w != g_SpriteScaleCachedW || sprite_h != g_SpriteScaleCachedH) {

        g_SpriteScaleStepX = ((int32_t)sprite_w << 16) / target_w;
        g_SpriteScaleStepY = ((int32_t)sprite_h << 16) / target_h;

        int *lookup = (int *)g_SpriteScaleLookupX;
        for (int i = 0; i < 0x400; i++) lookup[i] = -1;

        g_SpriteScaleAccX = 0;
        for (int i = 0; i <= target_w + 2; i++) {
            int src_coord = g_SpriteScaleAccX >> 16;
            ((int *)g_SpriteScalePixelMap)[i] = src_coord;
            if (lookup[src_coord] == -1) lookup[src_coord] = i;
            g_SpriteScaleAccX += g_SpriteScaleStepX;
        }

        g_SpriteScaleCachedTargetW = target_w;
        g_SpriteScaleCachedTargetH = target_h;
        g_SpriteScaleCachedH = sprite_h;
        g_SpriteScaleCachedW = sprite_w;
    }

    g_SpriteScaleClipLeft = (dst_x < surf->clip_left) ? (surf->clip_left - dst_x) : 0;
    g_SpriteScaleClampedW = (surf->clip_right < dst_x + target_w) ? (surf->clip_right - dst_x) : target_w;

    int origin_y = (int)*(int16_t *)(raw_sprite + 0x0C);
    g_SpriteScaleAccY = 0;
    while ((g_SpriteScaleAccY >> 16) < origin_y) {
        g_SpriteScaleAccY += g_SpriteScaleStepY;
        dst_y++;
    }

    const uint8_t *rle_stream = raw_sprite + 0x10;
    int16_t visible_rows = *(int16_t *)(raw_sprite + 0x0E);
    int pitch = surf_info->pitch + surf_info->stride_extra;
    uint8_t *frame_ptr = surf_info->frame_buffer + (dst_x + pitch * dst_y);

    while ((g_SpriteScaleAccY >> 16) < (visible_rows + origin_y)) {
        int next_src_y = (g_SpriteScaleAccY + g_SpriteScaleStepY) >> 16;
        int cur_src_y = g_SpriteScaleAccY >> 16;
        uint32_t skip_pixels = (uint32_t)*rle_stream;

        if (skip_pixels != 0xFF) {
            const uint8_t *run_data = rle_stream + 1;
            uint32_t run_len = (uint32_t)*run_data++;
            bool is_solid = (run_len == 0xFE);
            if (is_solid) {
                run_len = (uint32_t)*run_data++;
            }

            if (surf->clip_top <= dst_y && dst_y <= surf->clip_bottom) {
                int scaled_start_x = ((int *)g_SpriteScaleLookupX)[skip_pixels];
                if (scaled_start_x < g_SpriteScaleClipLeft) scaled_start_x = g_SpriteScaleClipLeft;

                int scaled_end_x = ((int *)g_SpriteScaleLookupX)[skip_pixels + run_len];
                if (scaled_end_x > g_SpriteScaleClampedW) scaled_end_x = g_SpriteScaleClampedW;

                for (int x = scaled_start_x; x < scaled_end_x; x++) {
                    int src_pixel_x = ((int *)g_SpriteScalePixelMap)[x] - skip_pixels;
                    uint8_t color = run_data[src_pixel_x];
                    if (color != 0) {
                        if (surf_type == 0) {
                            Surface_PutPixel(surf, dst_x + x, dst_y, color);
                        } else {
                            frame_ptr[x] = color;
                        }
                    }
                }
            }
            rle_stream = run_data + run_len;
        } else {
            rle_stream++;
        }

        /* Advance Bresenham source row step */
        int row_delta = next_src_y - cur_src_y;
        while (row_delta > 1) {
            if (*rle_stream != 0xFF) {
                uint32_t len = rle_stream[1];
                rle_stream += (len == 0xFE) ? (rle_stream[2] + 3) : (len + 2);
            } else {
                rle_stream++;
            }
            row_delta--;
        }

        dst_y++;
        g_SpriteScaleAccY += g_SpriteScaleStepY;
        frame_ptr += pitch;
    }
}
