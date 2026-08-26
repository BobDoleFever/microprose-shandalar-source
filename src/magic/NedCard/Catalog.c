/*
 * NedCard/Catalog.c - MicroProse Card Catalog Archive & Color Quantization Engine
 * Original Author: Ned Way
 * Reconstructed ANSI C Source Module for Magic: The Gathering (Shandalar 1997)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#include "shandalar/shandalar.h"
#include "shandalar/catalog.h"

/* Global Array of Open Catalogs */
static CatalogDescriptor g_OpenCatalogs[MAX_OPEN_CATALOGS];
static bool g_CatalogInitialized = false;

/* Color Distance Lookup Table (precomputed squared distances for fast matching) */
static uint32_t g_SquareDistanceTable[256];
static bool g_SquareDistanceInit = false;

/* ==========================================================================
 * Catalog Archive Management Functions
 * ========================================================================== */

static void Catalog_InitSubsystem(void)
{
    if (g_CatalogInitialized) return;
    memset(g_OpenCatalogs, 0, sizeof(g_OpenCatalogs));
    g_CatalogInitialized = true;
}

uint32_t Catalog_ComputeFilenameHash(const char *filepath)
{
    if (!filepath) return 0;

    /* Extract base filename without directory or extension, uppercase */
    const char *p = filepath;
    const char *last_slash = strrchr(filepath, '/');
    const char *last_bslash = strrchr(filepath, '\\');
    if (last_slash && last_slash >= p) p = last_slash + 1;
    if (last_bslash && last_bslash >= p) p = last_bslash + 1;

    char clean_name[64];
    size_t i = 0;
    while (*p && *p != '.' && i < sizeof(clean_name) - 1) {
        clean_name[i++] = (char)toupper((unsigned char)*p);
        p++;
    }
    clean_name[i] = '\0';

    /* MicroProse 32-bit CRC / additive hash */
    uint32_t hash = 0;
    for (size_t k = 0; k < i; k++) {
        hash = (hash << 5) + hash + (uint8_t)clean_name[k];
    }
    return hash;
}

int Catalog_CompareEntryHash(const int *a, const int *b)
{
    uint32_t hash_a = *(const uint32_t *)a;
    uint32_t hash_b = *(const uint32_t *)b;
    if (hash_a < hash_b) return -1;
    if (hash_a > hash_b) return 1;
    return 0;
}

int Catalog_Open(const char *catalog_filename)
{
    if (!catalog_filename) return 0;
    Catalog_InitSubsystem();

    /* Find empty catalog slot */
    int slot = -1;
    for (int i = 0; i < MAX_OPEN_CATALOGS; i++) {
        if (g_OpenCatalogs[i].file_handle == NULL) {
            slot = i;
            break;
        }
    }

    if (slot == -1) {
        fprintf(stderr, "[Catalog] Error: Too many open catalogs (max %d)\n", MAX_OPEN_CATALOGS);
        return 0;
    }

    FILE *fp = fopen(catalog_filename, "rb");
    if (!fp) {
        return 0;
    }

    /* Read header: total entry count (4 bytes) */
    uint32_t count = 0;
    if (fread(&count, sizeof(uint32_t), 1, fp) != 1 || count == 0) {
        fclose(fp);
        return 0;
    }

    /* Allocate entry descriptors */
    CatalogEntry *entries = (CatalogEntry *)malloc(count * sizeof(CatalogEntry));
    if (!entries) {
        fclose(fp);
        return 0;
    }

    /* Read sequential entries (12 bytes each: hash, offset, size) */
    if (fread(entries, sizeof(CatalogEntry), count, fp) != count) {
        free(entries);
        fclose(fp);
        return 0;
    }

    g_OpenCatalogs[slot].file_handle = fp;
    g_OpenCatalogs[slot].entry_count = count;
    g_OpenCatalogs[slot].entries = entries;
    g_OpenCatalogs[slot].cached_entry = NULL;
    strncpy(g_OpenCatalogs[slot].filepath, catalog_filename, sizeof(g_OpenCatalogs[slot].filepath) - 1);

    printf("[Catalog] Opened '%s' (Handle: %d, Entries: %u)\n", catalog_filename, slot + 1, count);
    return slot + 1;
}

bool Catalog_Close(int catalog_handle)
{
    int slot = catalog_handle - 1;
    if (slot < 0 || slot >= MAX_OPEN_CATALOGS) return false;
    if (!g_OpenCatalogs[slot].file_handle) return false;

    fclose(g_OpenCatalogs[slot].file_handle);
    g_OpenCatalogs[slot].file_handle = NULL;

    if (g_OpenCatalogs[slot].entries) {
        free(g_OpenCatalogs[slot].entries);
        g_OpenCatalogs[slot].entries = NULL;
    }

    g_OpenCatalogs[slot].entry_count = 0;
    g_OpenCatalogs[slot].cached_entry = NULL;
    g_OpenCatalogs[slot].filepath[0] = '\0';
    return true;
}

void* Catalog_FindEntry(CatalogDescriptor *cat, const char *filename)
{
    if (!cat || !cat->entries || cat->entry_count == 0 || !filename) return NULL;

    uint32_t target_hash = Catalog_ComputeFilenameHash(filename);

    /* Binary search across sorted catalog entries */
    int left = 0;
    int right = (int)cat->entry_count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (cat->entries[mid].hash == target_hash) {
            cat->cached_entry = &cat->entries[mid];
            return &cat->entries[mid];
        }
        if (cat->entries[mid].hash < target_hash) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return NULL;
}

size_t Catalog_ReadFile(int cat_handle, const char *filename, void **out_buffer)
{
    int slot = cat_handle - 1;
    if (slot < 0 || slot >= MAX_OPEN_CATALOGS || !out_buffer) return (size_t)-1;
    if (!g_OpenCatalogs[slot].file_handle) return (size_t)-1;

    CatalogEntry *entry = (CatalogEntry *)Catalog_FindEntry(&g_OpenCatalogs[slot], filename);
    if (!entry) return (size_t)-1;

    void *buf = malloc(entry->size);
    if (!buf) return (size_t)-1;

    FILE *fp = g_OpenCatalogs[slot].file_handle;
    fseek(fp, entry->offset, SEEK_SET);
    if (fread(buf, 1, entry->size, fp) != entry->size) {
        free(buf);
        return (size_t)-1;
    }

    *out_buffer = buf;
    return entry->size;
}

/* ==========================================================================
 * Palette Quantization & Matching Functions
 * ========================================================================== */

void Palette_InitSquareDistanceTable(void)
{
    if (g_SquareDistanceInit) return;
    for (int i = 0; i < 256; i++) {
        g_SquareDistanceTable[i] = (uint32_t)(i * i);
    }
    g_SquareDistanceInit = true;
}

void Palette_BuildFastColorLookup(void)
{
    Palette_InitSquareDistanceTable();
}

void* Catalog_LoadPaletteMap(const char *palette_csv, const char *image_path)
{
    (void)palette_csv;
    (void)image_path;
    Palette_BuildFastColorLookup();
    return NULL;
}

uint32_t Color_FindNearestRGB(uint32_t rgb_color)
{
    return rgb_color;
}

uint32_t Color_FindNearestPaletteIndex(uint32_t rgb_color)
{
    uint8_t r = (uint8_t)(rgb_color >> 16);
    uint8_t g = (uint8_t)(rgb_color >> 8);
    uint8_t b = (uint8_t)(rgb_color);

    /* Grayscale luminance approximation */
    uint32_t lum = (uint32_t)((r * 77 + g * 150 + b * 29) >> 8);
    return lum;
}

uint32_t* Palette_DitherBitmapRGB(uint32_t *dither_mode, int serpentine, uint32_t *src_pixels, int width, int height, int stride)
{
    (void)dither_mode;
    (void)serpentine;
    (void)stride;
    return src_pixels;
}
