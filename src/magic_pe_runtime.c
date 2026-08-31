#include <ctype.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shandalar/magic_pe_runtime.h"
#include "magic_pe_image.h"


_Static_assert(sizeof(void *) == 4, "MAGIC.EXE requires 32-bit pointers.");
_Static_assert(sizeof(uintptr_t) == 4, "MAGIC.EXE requires 32-bit uintptr_t.");

static HINSTANCE g_Instance;
static uint8_t *g_Image;
static unsigned int g_TraceFlags;

enum {
    MAGIC_PE_TRACE_IMPORTS = 1u << 0,
    MAGIC_PE_TRACE_CALLS = 1u << 1,
    MAGIC_PE_TRACE_FILES = 1u << 2,
    MAGIC_PE_TRACE_RESOURCES = 1u << 3
};

extern uintptr_t MagicPe_ResolveRecoveredCallable(RecoveredCode32 address);
extern int __cdecl MagicRecovered_WinMain(HINSTANCE instance,
                                           HINSTANCE previous_instance,
                                           LPSTR command_line,
                                           int show_state);


static uint32_t MagicPe_Crc32(const uint8_t *data, size_t size)
{
    uint32_t value = 0xffffffffu;
    for (size_t index = 0; index < size; ++index) {
        value ^= data[index];
        for (unsigned int bit = 0; bit < 8; ++bit) {
            uint32_t mask = 0u - (value & 1u);
            value = (value >> 1) ^ (0xedb88320u & mask);
        }
    }
    return ~value;
}


static int MagicPe_ShouldBreak(void)
{
    char value[8];
    DWORD length = GetEnvironmentVariableA(
        "SHANDALAR_PE_BREAK_ON_ERROR", value, (DWORD)sizeof(value)
    );
    return length != 0 && value[0] == '1';
}


static unsigned int MagicPe_ReadTraceFlags(void)
{
    char value[128];
    DWORD length = GetEnvironmentVariableA(
        "SHANDALAR_PE_TRACE", value, (DWORD)sizeof(value)
    );
    if (length == 0 || length >= sizeof(value)) {
        return 0;
    }
    unsigned int flags = 0;
    for (char *token = strtok(value, ","); token != NULL;
         token = strtok(NULL, ",")) {
        if (_stricmp(token, "imports") == 0) {
            flags |= MAGIC_PE_TRACE_IMPORTS;
        } else if (_stricmp(token, "calls") == 0) {
            flags |= MAGIC_PE_TRACE_CALLS;
        } else if (_stricmp(token, "files") == 0) {
            flags |= MAGIC_PE_TRACE_FILES;
        } else if (_stricmp(token, "resources") == 0) {
            flags |= MAGIC_PE_TRACE_RESOURCES;
        } else if (_stricmp(token, "all") == 0) {
            flags = 0xffffffffu;
        }
    }
    return flags;
}


static int MagicPe_IsExecutableAddress(uintptr_t address)
{
    MEMORY_BASIC_INFORMATION information;
    if (address == 0 || VirtualQuery(
            (LPCVOID)address, &information, sizeof(information)
        ) != sizeof(information)) {
        return 0;
    }
    if (information.State != MEM_COMMIT ||
        (information.Protect & (PAGE_GUARD | PAGE_NOACCESS)) != 0) {
        return 0;
    }
    DWORD protection = information.Protect & 0xffu;
    return protection == PAGE_EXECUTE || protection == PAGE_EXECUTE_READ ||
           protection == PAGE_EXECUTE_READWRITE ||
           protection == PAGE_EXECUTE_WRITECOPY;
}


int MagicPe_ReportError(const char *operation, DWORD error_code)
{
    char message[1024];
    snprintf(
        message,
        sizeof(message),
        "%s failed with Windows error %lu.",
        operation,
        (unsigned long)error_code
    );
    fprintf(stderr, "MAGIC PE: %s\n", message);
    if (MagicPe_ShouldBreak()) {
        DebugBreak();
    }
    MessageBoxA(NULL, message, "Recovered MAGIC.EXE", MB_OK | MB_ICONERROR);
    return -1;
}


static int MagicPe_ModuleDirectory(char *buffer, size_t size)
{
    DWORD length = GetModuleFileNameA(g_Instance, buffer, (DWORD)size);
    if (length == 0 || length >= size) {
        return MagicPe_ReportError("GetModuleFileNameA", GetLastError());
    }
    char *separator = strrchr(buffer, '\\');
    char *slash = strrchr(buffer, '/');
    if (slash != NULL && (separator == NULL || slash > separator)) {
        separator = slash;
    }
    if (separator == NULL) {
        return MagicPe_ReportError("Find executable directory", ERROR_BAD_PATHNAME);
    }
    *separator = '\0';
    return 0;
}


static int MagicPe_LoadImage(void)
{
    char directory[MAX_PATH];
    char path[MAX_PATH];
    if (MagicPe_ModuleDirectory(directory, sizeof(directory)) != 0) {
        return -1;
    }
    int written = snprintf(path, sizeof(path), "%s\\magic_image.bin", directory);
    if (written < 0 || (size_t)written >= sizeof(path)) {
        return MagicPe_ReportError("Build image path", ERROR_BUFFER_OVERFLOW);
    }

    g_Image = VirtualAlloc(
        (LPVOID)(uintptr_t)MAGIC_PE_IMAGE_BASE,
        MAGIC_PE_VIRTUAL_SIZE,
        MEM_RESERVE | MEM_COMMIT,
        PAGE_READWRITE
    );
    if (g_Image != (uint8_t *)(uintptr_t)MAGIC_PE_IMAGE_BASE) {
        if (g_Image != NULL) {
            VirtualFree(g_Image, 0, MEM_RELEASE);
            g_Image = NULL;
        }
        return MagicPe_ReportError(
            "Reserve recovered image address", ERROR_INVALID_ADDRESS
        );
    }

    FILE *input = fopen(path, "rb");
    if (input == NULL) {
        return MagicPe_ReportError("Open magic_image.bin", ERROR_FILE_NOT_FOUND);
    }
    size_t count = fread(g_Image, 1, MAGIC_PE_IMAGE_SIZE, input);
    int trailing_byte = fgetc(input);
    fclose(input);
    if (count != MAGIC_PE_IMAGE_SIZE || trailing_byte != EOF) {
        return MagicPe_ReportError("Read magic_image.bin", ERROR_BAD_LENGTH);
    }

    const IMAGE_DOS_HEADER *dos = (const IMAGE_DOS_HEADER *)g_Image;
    if (dos->e_magic != IMAGE_DOS_SIGNATURE || dos->e_lfanew <= 0 ||
        (uint32_t)dos->e_lfanew > MAGIC_PE_IMAGE_SIZE - sizeof(IMAGE_NT_HEADERS32)) {
        return MagicPe_ReportError("Validate DOS header", ERROR_BAD_EXE_FORMAT);
    }
    const IMAGE_NT_HEADERS32 *nt =
        (const IMAGE_NT_HEADERS32 *)(g_Image + (uint32_t)dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE ||
        nt->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC ||
        nt->OptionalHeader.ImageBase != MAGIC_PE_IMAGE_BASE ||
        nt->OptionalHeader.SizeOfImage != MAGIC_PE_VIRTUAL_SIZE) {
        return MagicPe_ReportError("Validate PE image", ERROR_BAD_EXE_FORMAT);
    }
    if (MagicPe_Crc32(g_Image, MAGIC_PE_IMAGE_SIZE) != MAGIC_PE_IMAGE_CRC32) {
        return MagicPe_ReportError("Validate PE image checksum", ERROR_CRC);
    }
    return 0;
}


int MagicPe_Initialize(HINSTANCE instance)
{
    if (g_Image != NULL) {
        return 0;
    }
    g_Instance = instance;
    g_TraceFlags = MagicPe_ReadTraceFlags();
    if (MagicPe_LoadImage() != 0) {
        MagicPe_Shutdown();
        return -1;
    }
    if (g_TraceFlags != 0) {
        fprintf(
            stderr,
            "MAGIC PE: module=%p image=%p pointer-size=%u\n",
            (void *)instance,
            (void *)g_Image,
            (unsigned int)sizeof(void *)
        );
    }
    return 0;
}


void MagicPe_Shutdown(void)
{
    if (g_Image != NULL) {
        VirtualFree(g_Image, 0, MEM_RELEASE);
        g_Image = NULL;
    }
    g_Instance = NULL;
    g_TraceFlags = 0;
}


void *MagicPe_Address(RecoveredAddress32 address, size_t size)
{
    uint64_t start = address;
    uint64_t end = start + size;
    uint64_t image_end = (uint64_t)MAGIC_PE_IMAGE_BASE + MAGIC_PE_IMAGE_SIZE;
    if (g_Image == NULL || start < MAGIC_PE_IMAGE_BASE || end < start || end > image_end) {
        SetLastError(ERROR_INVALID_ADDRESS);
        return NULL;
    }
    return (void *)(uintptr_t)address;
}


uintptr_t MagicPe_GlobalAddress(RecoveredAddress32 address)
{
    return (uintptr_t)MagicPe_Address(address, 1);
}


uintptr_t MagicPe_RegisterCallable(uintptr_t function_address)
{
    return function_address;
}


uintptr_t MagicPe_ResolveCallable(RecoveredCode32 address)
{
    uintptr_t result = MagicPe_ResolveRecoveredCallable(address);
    if (result != 0) {
        if ((g_TraceFlags & MAGIC_PE_TRACE_CALLS) != 0) {
            fprintf(stderr, "MAGIC PE: recovered callable 0x%08lx -> %p\n",
                    (unsigned long)address, (void *)result);
        }
        return result;
    }
    if (address >= MAGIC_PE_IMAGE_BASE &&
        address < MAGIC_PE_IMAGE_BASE + MAGIC_PE_IMAGE_SIZE) {
        SetLastError(ERROR_INVALID_ADDRESS);
        if ((g_TraceFlags & MAGIC_PE_TRACE_CALLS) != 0) {
            const char *symbol_name = MagicPe_LookupSymbolName(address);
            if (symbol_name != NULL) {
                fprintf(stderr, "MAGIC PE: unknown recovered callable 0x%08lx (%s)\n",
                        (unsigned long)address, symbol_name);
            } else {
                fprintf(stderr, "MAGIC PE: unknown recovered callable 0x%08lx\n",
                        (unsigned long)address);
            }
        }
        return 0;
    }
    if (!MagicPe_IsExecutableAddress((uintptr_t)address)) {
        SetLastError(ERROR_INVALID_ADDRESS);
        if ((g_TraceFlags & MAGIC_PE_TRACE_CALLS) != 0) {
            fprintf(stderr, "MAGIC PE: rejected native callable 0x%08lx\n",
                    (unsigned long)address);
        }
        return 0;
    }
    return (uintptr_t)address;
}


void MagicPe_TraceFile(const char *operation, const char *path, int success)
{
    if ((g_TraceFlags & MAGIC_PE_TRACE_FILES) != 0) {
        fprintf(stderr, "MAGIC PE: file %s(%s) -> %s\n",
                operation != NULL ? operation : "access",
                path != NULL ? path : "<null>",
                success ? "success" : "failed");
    }
}


void MagicPe_TraceResource(const char *type, const char *name, HRSRC handle)
{
    if ((g_TraceFlags & MAGIC_PE_TRACE_RESOURCES) != 0) {
        fprintf(stderr, "MAGIC PE: resource FindResourceA(type=%s, name=%s) -> %p\n",
                type != NULL ? type : "<null>",
                name != NULL ? name : "<null>",
                (void *)handle);
    }
}


int MagicPe_EnterDataDirectory(void)
{
    char directory[MAX_PATH];
    DWORD length = GetEnvironmentVariableA(
        "SHANDALAR_DATA_DIR_WIN", directory, (DWORD)sizeof(directory)
    );
    if (length == 0 || length >= sizeof(directory)) {
        return MagicPe_ReportError(
            "Read SHANDALAR_DATA_DIR_WIN",
            length == 0 ? ERROR_ENVVAR_NOT_FOUND : ERROR_BUFFER_OVERFLOW
        );
    }
    DWORD attributes = GetFileAttributesA(directory);
    if (attributes == INVALID_FILE_ATTRIBUTES ||
        (attributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
        return MagicPe_ReportError("Validate game data directory", GetLastError());
    }
    if (!SetCurrentDirectoryA(directory)) {
        return MagicPe_ReportError("Enter game data directory", GetLastError());
    }
    if (GetFileAttributesA("ADVINTER.pic") == INVALID_FILE_ATTRIBUTES &&
        GetFileAttributesA("advinter.pic") == INVALID_FILE_ATTRIBUTES) {
        return MagicPe_ReportError("Find ADVINTER.pic", ERROR_FILE_NOT_FOUND);
    }
    return 0;
}


int MagicPe_RunRecoveredWinMain(LPSTR command_line, int show_state)
{
    if (g_Image == NULL) {
        return MagicPe_ReportError("Start recovered WinMain", ERROR_INVALID_ADDRESS);
    }
    return MagicRecovered_WinMain(g_Instance, NULL, command_line, show_state);
}


HMODULE WINAPI MagicPe_LoadLibraryA(LPCSTR name)
{
    HMODULE module = LoadLibraryA(name);
    if ((g_TraceFlags & MAGIC_PE_TRACE_IMPORTS) != 0) {
        char path[MAX_PATH] = "<not loaded>";
        if (module != NULL) {
            GetModuleFileNameA(module, path, (DWORD)sizeof(path));
        }
        fprintf(stderr, "MAGIC PE: LoadLibraryA(%s) -> %s\n",
                name == NULL ? "<null>" : name, path);
    }
    return module;
}


FARPROC WINAPI MagicPe_GetProcAddress(HMODULE module, LPCSTR name)
{
    FARPROC function = GetProcAddress(module, name);
    if ((g_TraceFlags & MAGIC_PE_TRACE_IMPORTS) != 0) {
        if (((uintptr_t)name >> 16) == 0) {
            fprintf(stderr, "MAGIC PE: GetProcAddress ordinal %lu -> %p\n",
                    (unsigned long)(uintptr_t)name, (void *)function);
        } else {
            fprintf(stderr, "MAGIC PE: GetProcAddress %s -> %p\n", name,
                    (void *)function);
        }
    }
    return function;
}


uint64_t __cdecl MagicPe_AllShl(unsigned int shift, uint32_t value)
{
    return (uint64_t)value << (shift & 63u);
}


uintptr_t __cdecl MagicPe_Assert(const char *expression, const char *file,
                                 unsigned int line)
{
    fprintf(stderr, "MAGIC PE: assertion '%s' failed at %s:%u.\n",
            expression == NULL ? "<unknown>" : expression,
            file == NULL ? "<unknown>" : file,
            line);
    if (MagicPe_ShouldBreak()) {
        DebugBreak();
    }
    return 0;
}


uintptr_t __cdecl MagicPe_StackProbe(void)
{
    return 0;
}


int *__p___mb_cur_max(void)
{
    static int mb_cur_max;
    mb_cur_max = ___mb_cur_max_func();
    return &mb_cur_max;
}


const unsigned short **__p__pctype(void)
{
    static const unsigned short *pctype_ptr;
    pctype_ptr = __pctype_func();
    return &pctype_ptr;
}


int __cdecl _atexit(void (*func)(void))
{
    return atexit(func);
}
