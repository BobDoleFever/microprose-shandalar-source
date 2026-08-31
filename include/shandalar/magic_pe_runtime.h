#ifndef SHANDALAR_MAGIC_PE_RUNTIME_H
#define SHANDALAR_MAGIC_PE_RUNTIME_H

#include <stddef.h>
#include <stdint.h>

#ifndef _WIN32
#error "The MAGIC PE runtime requires a Windows target."
#endif

#include <windows.h>

typedef uint32_t RecoveredAddress32;
typedef uint32_t RecoveredCode32;

int MagicPe_Initialize(HINSTANCE instance);
void MagicPe_Shutdown(void);
void *MagicPe_Address(RecoveredAddress32 address, size_t size);
uintptr_t MagicPe_GlobalAddress(RecoveredAddress32 address);
uintptr_t MagicPe_ResolveCallable(RecoveredCode32 address);
uintptr_t MagicPe_RegisterCallable(uintptr_t function_address);
int MagicPe_EnterDataDirectory(void);
int MagicPe_RunRecoveredWinMain(LPSTR command_line, int show_state);
int MagicPe_ReportError(const char *operation, DWORD error_code);
const char *MagicPe_LookupSymbolName(RecoveredAddress32 address);
void MagicPe_TraceFile(const char *operation, const char *path, int success);
void MagicPe_TraceResource(const char *type, const char *name, HRSRC handle);
HMODULE WINAPI MagicPe_LoadLibraryA(LPCSTR name);
FARPROC WINAPI MagicPe_GetProcAddress(HMODULE module, LPCSTR name);
uint64_t __cdecl MagicPe_AllShl(unsigned int shift, uint32_t value);
uintptr_t __cdecl MagicPe_Assert(const char *expression, const char *file,
                                 unsigned int line);
uintptr_t __cdecl MagicPe_StackProbe(void);

#endif
