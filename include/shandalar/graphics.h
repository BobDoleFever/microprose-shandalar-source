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
void Palette_SetColors(const void* palette, int start, int count);
void Haar_DecompressWavelet(const void* src, void* dst, int width, int height);
void Font_DrawText(HDC hdc, const char* str, int x, int y, uint32_t color);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_GRAPHICS_H */
