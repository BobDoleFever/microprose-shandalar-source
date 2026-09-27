/*
 * shandalar/catalog.h - MicroProse Card Catalog Archive & Color Quantization Engine
 * Original Author: Ned Way (NedCard/Catalog.c)
 * Comments follow Simplified Technical English (ASD-STE100) rules.
 */
#ifndef SHANDALAR_CATALOG_H
#define SHANDALAR_CATALOG_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Maximum number of catalog files that can be open at the same time. */
#define MAX_OPEN_CATALOGS 5

/*
 * Catalog File Entry Descriptor.
 * Holds file position and size information for a resource in the .CAT file.
 */
typedef struct CatalogEntry {
    uint32_t hash;               /* 32-bit hash value of the file name for binary search. */
    uint32_t offset;             /* Byte offset of the file data from the start of the archive. */
    uint32_t size;               /* Total length of uncompressed file data in bytes. */
} CatalogEntry;

/*
 * Open Catalog Descriptor.
 * Holds runtime state for an open catalog file archive.
 */
typedef struct CatalogDescriptor {
    FILE         *file_handle;   /* Active file pointer. */
    uint32_t      entry_count;   /* Total number of files in the catalog. */
    CatalogEntry *entries;       /* Pointer to the sorted array of catalog entries. */
    CatalogEntry *cached_entry;  /* Pointer to the most recently accessed entry. */
    char          filepath[260]; /* Full file system path to the catalog archive. */
} CatalogDescriptor;

/*
 * Color Octree Node for 256-Color Palette Reduction.
 * Used to reduce 24-bit RGB colors to an 8-bit palette.
 */
typedef struct ColorOctreeNode {
    int32_t                 is_leaf;         /* Set to 1 if this node is a leaf, or 0 if a branch. */
    int32_t                 palette_index;   /* Palette color index (0 to 255). */
    struct ColorOctreeNode *children[8];     /* Pointers to 8 sub-octant child nodes. */
    uint8_t                *cluster_indices; /* Array of color indices assigned to this cluster. */
    size_t                  cluster_count;   /* Number of colors in the cluster. */
} ColorOctreeNode;

/*
 * Catalog Subsystem API Functions
 */

/*
 * Catalog_Open
 * Purpose: Open a .CAT catalog file and read its index table.
 * Parameter catalog_filename: The path of the catalog file.
 * Returns: An integer handle (1 to 5) on success, or 0 on error.
 */
int Catalog_Open(const char *catalog_filename);

/*
 * Catalog_Close
 * Purpose: Close an open catalog file and free its allocated index memory.
 * Parameter catalog_handle: The handle of the catalog (1 to 5).
 * Returns: True if closed successfully, or false if the handle was invalid.
 */
bool Catalog_Close(int catalog_handle);

/*
 * Catalog_FindEntry
 * Purpose: Search for a file inside the catalog using binary search.
 * Parameter cat: Pointer to the catalog descriptor.
 * Parameter filename: The name of the file to search for.
 * Returns: Pointer to the CatalogEntry if found, or NULL if not found.
 */
void* Catalog_FindEntry(CatalogDescriptor *cat, const char *filename);

/*
 * Catalog_ReadFile
 * Purpose: Read file data from a catalog archive into memory.
 * Parameter cat_handle: The handle of the catalog (1 to 5).
 * Parameter filename: The name of the file to read.
 * Parameter out_buffer: Address of the destination memory pointer.
 * Returns: Total number of bytes read, or -1 on error.
 */
size_t Catalog_ReadFile(int cat_handle, const char *filename, void **out_buffer);

/*
 * Catalog_ComputeFilenameHash
 * Purpose: Calculate a 32-bit hash value from a file path.
 * Parameter filepath: The path string to hash.
 * Returns: Calculated 32-bit hash value.
 */
uint32_t Catalog_ComputeFilenameHash(const char *filepath);

/*
 * Catalog_CompareEntryHash
 * Purpose: Comparison function for bsearch.
 * Parameter a: Pointer to the first hash value.
 * Parameter b: Pointer to the second hash value.
 * Returns: -1 if a < b, 1 if a > b, or 0 if a == b.
 */
int Catalog_CompareEntryHash(const int *a, const int *b);

/*
 * Palette Quantization & Error Diffusion API Functions
 */

/*
 * Palette_LoadTRFile
 * Purpose: Load a palette mapping file and initialize the color reduction tables.
 * Parameter palette_csv: Path to the palette color definitions CSV file.
 * Parameter image_path: Path to the reference image file (optional, can be NULL).
 * Returns: Pointer to the loaded palette buffer.
 */
void* Palette_LoadTRFile(const char *palette_csv, const char *image_path);

/*
 * Palette_InitSquareDistanceTable
 * Purpose: Precompute Euclidean color distance lookup tables for fast RGB matching.
 */
void Palette_InitSquareDistanceTable(void);

/*
 * Palette_BuildFastColorLookup
 * Purpose: Generate lookup tables for rapid conversion from RGB to palette indices.
 */
void Palette_BuildFastColorLookup(void);

/*
 * Color_FindNearestRGB
 * Purpose: Find the closest matching RGB color in the active palette.
 * Parameter rgb_color: The source 24-bit RGB color.
 * Returns: The closest 24-bit RGB color from the palette.
 */
uint32_t Color_FindNearestRGB(uint32_t rgb_color);

/*
 * Color_FindNearestPaletteIndex
 * Purpose: Find the palette index (0 to 255) that best matches an RGB color.
 * Parameter rgb_color: The source 24-bit RGB color.
 * Returns: An 8-bit palette index (0 to 255).
 */
uint32_t Color_FindNearestPaletteIndex(uint32_t rgb_color);

/*
 * Palette_DitherBitmapRGB
 * Purpose: Apply Floyd-Steinberg error diffusion dithering to a 24-bit image.
 * Parameter dither_mode: Dither configuration flags.
 * Parameter serpentine: Set to 1 for serpentine scanning (left-to-right, then right-to-left).
 * Parameter src_pixels: Pointer to source 24-bit RGB pixel buffer.
 * Parameter width: Width of the image in pixels.
 * Parameter height: Height of the image in pixels.
 * Parameter stride: Row pitch in bytes.
 * Returns: Pointer to the dithered image pixel buffer.
 */
uint32_t* Palette_DitherBitmapRGB(uint32_t *dither_mode, int serpentine, uint32_t *src_pixels, int width, int height, int stride);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_CATALOG_H */
