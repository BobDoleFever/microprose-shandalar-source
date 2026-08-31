#ifndef SHANDALAR_MAGIC_NATIVE_RUNTIME_H
#define SHANDALAR_MAGIC_NATIVE_RUNTIME_H

#include <stddef.h>
#include <stdint.h>

int MagicNative_LoadImage(const char *image_path);
void MagicNative_SetArguments(int argc, char **argv);
int MagicNative_Run(const char *command_line);
void MagicNative_Shutdown(void);

void *MagicNative_Malloc(size_t size);
void *MagicNative_Realloc(void *memory, size_t size);
void MagicNative_Free(void *memory);
size_t MagicNative_AllocationSize(void *memory);

uintptr_t MagicNative_RegisterCallable(uintptr_t function_address);
uintptr_t MagicNative_ResolveCallable(uint32_t recovered_address);
uintptr_t MagicNative_HostPointer(uintptr_t recovered_address);
uintptr_t MagicNative_GlobalAddress(uint32_t recovered_address);
uintptr_t MagicNative_CopyProgramPath(char *buffer, size_t size);

#endif
