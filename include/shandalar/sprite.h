/*
 * shandalar/sprite.h - MicroProse Sid Meier 2D Sprite Engine Header
 * Original Source Path: G:\NewMagic\sources\sidlib\sprite.h
 */
#ifndef SHANDALAR_SPRITE_H
#define SHANDALAR_SPRITE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Sprite Record Header (MicroProse RLE 2D Sprite Format)
 */
typedef struct SpriteHeader {
    int32_t  total_size;      /* 0x00: Total uint8_t size of sprite record */
    int16_t  width;           /* 0x04: Full canvas width */
    int16_t  height;          /* 0x06: Full canvas height */
    int16_t  clip_left;       /* 0x08: Left transparent margin */
    int16_t  clip_top;        /* 0x0A: Top transparent margin */
    int16_t  offset_y;        /* 0x0C: First non-empty row index */
    int16_t  visible_height;  /* 0x0E: Number of encoded rows */
    uint8_t  data[];          /* 0x10: RLE compressed scanline uint8_t stream */
} SpriteHeader;

/*
 * Surface Metadata Struct (Internal MicroProse Display Buffer)
 */
typedef struct SurfaceInfo {
    uint8_t  padding_0[0x18];
    uint8_t *frame_buffer;    /* 0x18: Raw pixel memory buffer */
    uint8_t  padding_1[0x04];
    int32_t  stride_extra;    /* 0x20: Alignment padding per scanline */
    uint8_t  padding_2[0x08];
    int32_t  pitch;           /* 0x2C: Base scanline pitch in bytes */
} SurfaceInfo;

/*
 * Screen Surface / Viewport Clipping Descriptor
 */
typedef struct ScreenSurface {
    int32_t  type;            /* 0x00: 0 = Direct Draw / VRAM, 1 = Memory Bitmap Buffer */
    int32_t  clip_left;       /* 0x04: Viewport Left boundary */
    int32_t  clip_top;        /* 0x08: Viewport Top boundary */
    int32_t  clip_right;      /* 0x0C: Viewport Right boundary */
    int32_t  clip_bottom;     /* 0x10: Viewport Bottom boundary */
    uint8_t *pixels;          /* 0x14: Pointer to target framebuffer */
    int32_t  pitch;           /* 0x18: Stride / bytes per scanline */
} ScreenSurface;

/*
 * Surface Helper Functions (from sidlib/Kimpic.c)
 */
uint32_t Surface_GetPixel(int surface_id, int x, int y);
void     Surface_PutPixel(void *surface, int x, int y, uint32_t color);
void     Surface_GetLine(void *dst_line, int surface_id, int x, int y, int width);
void     Surface_PutLine(void *src_data, int unused, int x, int y, uint32_t count);

/*
 * Sprite Subsystem API
 */

/* Load all sprites from a .SPR archive file into an array of pointers */
int      Sprite_LoadAll(void **out_sprite_array, const char *filename);

/* Load up to max_count sprites from a .SPR archive file */
uint32_t Sprite_LoadCount(void **out_sprite_array, const char *filename, uint32_t max_count);

/* Scan consecutive matching pixels along an axis */
int      Sprite_ScanRunLength(int surface_id, int start_x, int start_y, int step_x, int step_y);

/* Encode a raw surface rectangle into MicroProse RLE sprite format */
void     Sprite_EncodeFromSurface(int src_surface, int src_x, int src_y, uint32_t width, int height);

/* Fast blit unclipped sprite to surface */
void     Sprite_DrawDirect(ScreenSurface *surf, int dst_x, int dst_y, const void *sprite_data);

/* Draw sprite with viewport rectangle clipping */
void     Sprite_DrawClipped(ScreenSurface *surf, int dst_x, int dst_y, const void *sprite_data);

/* Draw sprite with 16.16 fixed-point scaling / stretch blit */
void     Sprite_DrawScaled(ScreenSurface *surf, int dst_x, int dst_y, int target_w, int target_h, const void *sprite_data);

/*
 * PCX / .PIC Full-Screen Backdrop & Panel Decoder
 */
typedef struct PicImage {
    int      width;
    int      height;
    int      pitch;
    uint8_t *pixels;
    uint8_t  palette[768]; /* 256 RGB triplets */
    bool     has_palette;
} PicImage;

/* Load and decode an 8-bit paletted MicroProse .PIC / PCX image file */
PicImage* Pic_LoadFile(const char *filename);

/* Free allocated PicImage memory */
void      Pic_Free(PicImage *pic);

/* Blit PicImage directly onto a ScreenSurface with bounds clipping */
void      Pic_Draw(ScreenSurface *surf, int dst_x, int dst_y, const PicImage *pic);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_SPRITE_H */
