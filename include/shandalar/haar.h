/*
 * shandalar/haar.h - MicroProse 2D Haar Wavelet Image Decompression Engine
 * Original Author: Ned Way (NedCard/haar.c)
 */
#ifndef SHANDALAR_HAAR_H
#define SHANDALAR_HAAR_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Haar Wavelet Compressed Image Header
 */
typedef struct HaarHeader {
    uint32_t magic;              /* 0x00: Format identifier */
    uint32_t width;              /* 0x04: Image pixel width */
    uint32_t height;             /* 0x08: Image pixel height */
    uint32_t wavelet_levels;     /* 0x0C: Decomposition level depth */
    uint32_t wavelet_pieces;     /* 0x28: Number of wavelet blocks (1, 4, 16) */
    uint32_t data_length;        /* 0x90: Compressed stream size */
} HaarHeader;

/*
 * Haar Subsystem API
 */
void* Haar_DecompressWaveletImage(const HaarHeader *hdr, void *dst_buffer);
void  Haar_Transform2D_Inverse(void *band_data, int offset, int length);
void  Haar_ReconstructBands(void *dst_pixels, const void *src_bands, int width, int height);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_HAAR_H */
