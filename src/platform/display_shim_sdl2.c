/*
 * src/platform/display_shim_sdl2.c - Modern SDL2 Display & GDI Translation Layer
 * Modern cross-platform backend for MicroProse Magic: The Gathering (1997)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <SDL.h>

#include "shandalar/shandalar.h"
#include "shandalar/sprite.h"
#include "shandalar/display_shim.h"

/*
 * Internal Display State
 */
static struct {
    SDL_Window   *window;
    SDL_Renderer *renderer;
    SDL_Texture  *frame_texture;
    uint32_t     *rgba_pixel_buffer;
    uint32_t      palette_lut[256];
    int           virtual_width;
    int           virtual_height;
    int           window_width;
    int           window_height;
    bool          is_initialized;
} g_DisplayState = {0};

/* ==========================================================================
 * Shandalar_DisplayInit - Create SDL2 window, renderer, and streaming texture
 * ========================================================================== */
int Shandalar_DisplayInit(const DisplayConfig *config)
{
    if (g_DisplayState.is_initialized) {
        return 1;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        fprintf(stderr, "[DisplayShim] SDL_Init failed: %s\n", SDL_GetError());
        return 0;
    }

    int v_width = (config && config->window_width > 0) ? config->window_width : 640;
    int v_height = (config && config->window_height > 0) ? config->window_height : 480;
    int scale = (config && config->scale_factor > 0) ? config->scale_factor : 2;
    const char *title = (config && config->window_title) ? config->window_title : "Magic: The Gathering (Shandalar 1997)";

    int win_w = v_width * scale;
    int win_h = v_height * scale;

    uint32_t window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
    if (config && config->fullscreen) {
        window_flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    }

    g_DisplayState.window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        win_w,
        win_h,
        window_flags
    );

    if (!g_DisplayState.window) {
        fprintf(stderr, "[DisplayShim] SDL_CreateWindow failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    uint32_t render_flags = SDL_RENDERER_ACCELERATED;
    if (!config || config->vsync) {
        render_flags |= SDL_RENDERER_PRESENTVSYNC;
    }

    g_DisplayState.renderer = SDL_CreateRenderer(g_DisplayState.window, -1, render_flags);
    if (!g_DisplayState.renderer) {
        /* Fallback to software renderer */
        g_DisplayState.renderer = SDL_CreateRenderer(g_DisplayState.window, -1, SDL_RENDERER_SOFTWARE);
    }

    if (!g_DisplayState.renderer) {
        fprintf(stderr, "[DisplayShim] SDL_CreateRenderer failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(g_DisplayState.window);
        SDL_Quit();
        return 0;
    }

    /* Configure integer scaling letterbox view */
    SDL_RenderSetLogicalSize(g_DisplayState.renderer, v_width, v_height);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0"); /* Nearest-neighbor sharp pixels */

    /* Create streaming 32-bit RGBA texture for fast CPU framebuffer uploads */
    g_DisplayState.frame_texture = SDL_CreateTexture(
        g_DisplayState.renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        v_width,
        v_height
    );

    if (!g_DisplayState.frame_texture) {
        fprintf(stderr, "[DisplayShim] SDL_CreateTexture failed: %s\n", SDL_GetError());
        SDL_DestroyRenderer(g_DisplayState.renderer);
        SDL_DestroyWindow(g_DisplayState.window);
        SDL_Quit();
        return 0;
    }

    SDL_SetTextureBlendMode(g_DisplayState.frame_texture, SDL_BLENDMODE_NONE);

    g_DisplayState.rgba_pixel_buffer = (uint32_t *)malloc(v_width * v_height * sizeof(uint32_t));
    if (!g_DisplayState.rgba_pixel_buffer) {
        fprintf(stderr, "[DisplayShim] Failed to allocate RGBA conversion buffer\n");
        return 0;
    }

    g_DisplayState.virtual_width = v_width;
    g_DisplayState.virtual_height = v_height;
    g_DisplayState.window_width = win_w;
    g_DisplayState.window_height = win_h;
    g_DisplayState.is_initialized = true;

    /* Initialize default grayscale palette */
    for (int i = 0; i < 256; i++) {
        g_DisplayState.palette_lut[i] = 0xFF000000U | ((uint32_t)i << 16) | ((uint32_t)i << 8) | (uint32_t)i;
    }

    printf("[DisplayShim] Initialized modern display (%dx%d -> %dx%d scale)\n",
           v_width, v_height, win_w, win_h);
    return 1;
}

/* ==========================================================================
 * Shandalar_DisplayShutdown - Destroy window, renderer, and free resources
 * ========================================================================== */
void Shandalar_DisplayShutdown(void)
{
    if (!g_DisplayState.is_initialized) return;

    if (g_DisplayState.rgba_pixel_buffer) {
        free(g_DisplayState.rgba_pixel_buffer);
        g_DisplayState.rgba_pixel_buffer = NULL;
    }

    if (g_DisplayState.frame_texture) {
        SDL_DestroyTexture(g_DisplayState.frame_texture);
        g_DisplayState.frame_texture = NULL;
    }

    if (g_DisplayState.renderer) {
        SDL_DestroyRenderer(g_DisplayState.renderer);
        g_DisplayState.renderer = NULL;
    }

    if (g_DisplayState.window) {
        SDL_DestroyWindow(g_DisplayState.window);
        g_DisplayState.window = NULL;
    }

    SDL_Quit();
    g_DisplayState.is_initialized = false;
}

/* ==========================================================================
 * Shandalar_SetPalette - Update active 256-color palette table
 * ========================================================================== */
void Shandalar_SetPalette(const uint32_t *palette_rgb256)
{
    if (!palette_rgb256) return;

    for (int i = 0; i < 256; i++) {
        uint32_t c = palette_rgb256[i];
        /* Ensure alpha is 0xFF (fully opaque) */
        g_DisplayState.palette_lut[i] = 0xFF000000U | (c & 0x00FFFFFFU);
    }
}

/* ==========================================================================
 * Shandalar_SetPaletteEntry - Update a single palette color index
 * ========================================================================== */
void Shandalar_SetPaletteEntry(uint8_t index, uint8_t r, uint8_t g, uint8_t b)
{
    g_DisplayState.palette_lut[index] = 0xFF000000U | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
}

/* ==========================================================================
 * Shandalar_UpdateSurface - Convert 8-bit paletted surface to 32-bit RGBA texture
 * ========================================================================== */
void Shandalar_UpdateSurface(const ScreenSurface *surf)
{
    if (!g_DisplayState.is_initialized || !surf || !surf->pixels) return;

    const uint8_t *src = surf->pixels;
    uint32_t *dst = g_DisplayState.rgba_pixel_buffer;
    const uint32_t *lut = g_DisplayState.palette_lut;

    int w = (surf->clip_right > 0 && surf->clip_right <= g_DisplayState.virtual_width) ?
            surf->clip_right : g_DisplayState.virtual_width;
    int h = (surf->clip_bottom > 0 && surf->clip_bottom <= g_DisplayState.virtual_height) ?
            surf->clip_bottom : g_DisplayState.virtual_height;
    int src_stride = (surf->pitch > 0) ? surf->pitch : w;

    /* Fast palette expansion: 8-bit index -> 32-bit ARGB8888 */
    for (int y = 0; y < h; y++) {
        const uint8_t *row_src = src + (y * src_stride);
        uint32_t *row_dst = dst + (y * g_DisplayState.virtual_width);

        for (int x = 0; x < w; x++) {
            row_dst[x] = lut[row_src[x]];
        }
    }

    /* Stream pixel buffer directly to GPU texture */
    SDL_UpdateTexture(
        g_DisplayState.frame_texture,
        NULL,
        g_DisplayState.rgba_pixel_buffer,
        g_DisplayState.virtual_width * sizeof(uint32_t)
    );
}

/* ==========================================================================
 * Shandalar_PresentFrame - Render and flip backbuffer
 * ========================================================================== */
void Shandalar_PresentFrame(void)
{
    if (!g_DisplayState.is_initialized) return;

    SDL_RenderClear(g_DisplayState.renderer);
    SDL_RenderCopy(g_DisplayState.renderer, g_DisplayState.frame_texture, NULL, NULL);
    SDL_RenderPresent(g_DisplayState.renderer);
}

/* ==========================================================================
 * Shandalar_PollEvents - Process OS events and map to Win32 message events
 * ========================================================================== */
int Shandalar_PollEvents(void)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                return 0;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    /* Escape key handler */
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    /* WM_LBUTTONDOWN equivalent */
                } else if (event.button.button == SDL_BUTTON_RIGHT) {
                    /* WM_RBUTTONDOWN equivalent */
                }
                break;

            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    /* WM_LBUTTONUP equivalent */
                } else if (event.button.button == SDL_BUTTON_RIGHT) {
                    /* WM_RBUTTONUP equivalent */
                }
                break;

            case SDL_MOUSEMOTION:
                /* WM_MOUSEMOVE equivalent */
                break;

            default:
                break;
        }
    }
    return 1;
}

/* ==========================================================================
 * Shim_CreateDIBSection - Allocate a software bitmap section
 * ========================================================================== */
void* Shim_CreateDIBSection(int width, int height, int bpp, void **out_bits)
{
    if (width <= 0 || height <= 0 || !out_bits) return NULL;

    size_t bytes_per_pixel = (bpp == 8) ? 1 : ((bpp == 24) ? 3 : 4);
    size_t buffer_size = (size_t)width * (size_t)height * bytes_per_pixel;

    void *buffer = calloc(1, buffer_size);
    if (!buffer) return NULL;

    *out_bits = buffer;
    return buffer;
}

/* ==========================================================================
 * Shim_BitBlt - 2D software rectangular blit
 * ========================================================================== */
int Shim_BitBlt(ScreenSurface *dst_surf, int dst_x, int dst_y, int width, int height,
                const ScreenSurface *src_surf, int src_x, int src_y, uint32_t rop)
{
    (void)rop;
    if (!dst_surf || !src_surf || !dst_surf->pixels || !src_surf->pixels) return 0;

    int dst_w = (dst_surf->clip_right > 0) ? dst_surf->clip_right : 640;
    int dst_h = (dst_surf->clip_bottom > 0) ? dst_surf->clip_bottom : 480;
    int src_w = (src_surf->clip_right > 0) ? src_surf->clip_right : 640;
    int src_h = (src_surf->clip_bottom > 0) ? src_surf->clip_bottom : 480;

    int dst_pitch = (dst_surf->pitch > 0) ? dst_surf->pitch : dst_w;
    int src_pitch = (src_surf->pitch > 0) ? src_surf->pitch : src_w;

    for (int y = 0; y < height; y++) {
        int cur_dst_y = dst_y + y;
        int cur_src_y = src_y + y;

        if (cur_dst_y < 0 || cur_dst_y >= dst_h) continue;
        if (cur_src_y < 0 || cur_src_y >= src_h) continue;

        uint8_t *dst_row = dst_surf->pixels + (cur_dst_y * dst_pitch + dst_x);
        const uint8_t *src_row = src_surf->pixels + (cur_src_y * src_pitch + src_x);

        int copy_w = width;
        if (dst_x + copy_w > dst_w) copy_w = dst_w - dst_x;
        if (copy_w > 0) {
            memcpy(dst_row, src_row, copy_w);
        }
    }
    return 1;
}

/* ==========================================================================
 * Shim_StretchBlt - 2D software stretched / scaled blit
 * ========================================================================== */
int Shim_StretchBlt(ScreenSurface *dst_surf, int dst_x, int dst_y, int dst_w, int dst_h,
                    const ScreenSurface *src_surf, int src_x, int src_y, int src_w, int src_h,
                    uint32_t rop)
{
    (void)rop;
    if (!dst_surf || !src_surf || !dst_surf->pixels || !src_surf->pixels) return 0;
    if (dst_w <= 0 || dst_h <= 0 || src_w <= 0 || src_h <= 0) return 0;

    int max_dst_w = (dst_surf->clip_right > 0) ? dst_surf->clip_right : 640;
    int max_dst_h = (dst_surf->clip_bottom > 0) ? dst_surf->clip_bottom : 480;
    int max_src_w = (src_surf->clip_right > 0) ? src_surf->clip_right : 640;
    int max_src_h = (src_surf->clip_bottom > 0) ? src_surf->clip_bottom : 480;

    int dst_pitch = (dst_surf->pitch > 0) ? dst_surf->pitch : max_dst_w;
    int src_pitch = (src_surf->pitch > 0) ? src_surf->pitch : max_src_w;

    int step_x = (src_w << 16) / dst_w;
    int step_y = (src_h << 16) / dst_h;

    int acc_y = 0;
    for (int y = 0; y < dst_h; y++) {
        int cur_dst_y = dst_y + y;
        int sample_src_y = src_y + (acc_y >> 16);

        if (cur_dst_y >= 0 && cur_dst_y < max_dst_h && sample_src_y < max_src_h) {
            uint8_t *dst_row = dst_surf->pixels + (cur_dst_y * dst_pitch);
            const uint8_t *src_row = src_surf->pixels + (sample_src_y * src_pitch);

            int acc_x = 0;
            for (int x = 0; x < dst_w; x++) {
                int cur_dst_x = dst_x + x;
                int sample_src_x = src_x + (acc_x >> 16);

                if (cur_dst_x >= 0 && cur_dst_x < max_dst_w && sample_src_x < max_src_w) {
                    dst_row[cur_dst_x] = src_row[sample_src_x];
                }
                acc_x += step_x;
            }
        }
        acc_y += step_y;
    }
    return 1;
}
