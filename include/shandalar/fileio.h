/*
 * shandalar/fileio.h - File System, CSV Parsers, and Archive IO
 */
#ifndef SHANDALAR_FILEIO_H
#define SHANDALAR_FILEIO_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CSV & Text Loaders */
int  Csv_LoadMaster(const char* path);
int  Csv_LoadInfo(const char* path);
int  Csv_ReadConcise(const char* path);
int  Csv_WriteConcise(const char* path);
int  Hints_Load(const char* path);
int  Story_Load(const char* path);
int  Tale_Load(const char* path);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_FILEIO_H */
