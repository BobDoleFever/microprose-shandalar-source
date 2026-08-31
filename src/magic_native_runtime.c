#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <mach/mach.h>
#include <mach/mach_vm.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include "shandalar/magic_native_runtime.h"
#include "shandalar/win32_compat.h"


#define MAGIC_IMAGE_VIRTUAL_BASE ((uintptr_t)0x00400000u)
#define MAGIC_IMAGE_SIZE ((size_t)3322368u)
#define MAGIC_HEAP_SIZE ((size_t)0x10000000u)
#define MAGIC_ALLOCATION_MARKER 0x4d414749u
#define MAGIC_CALL_TOKEN_BASE 0x0f000000u
#define MAGIC_CALL_TOKEN_LIMIT 4096u
#define MAGIC_FILE_LIMIT 128u

typedef struct MagicAllocationHeader {
    uint32_t marker;
    uint32_t size;
    uint64_t reserved;
} MagicAllocationHeader;

typedef struct MagicFileLayout {
    char *pointer;
    int count;
    int padding;
    char *base;
    int flags;
    int file_number;
    int character_buffer;
    int buffer_size;
    char *temporary_name;
} MagicFileLayout;

typedef struct MagicFileEntry {
    MagicFileLayout *proxy;
    FILE *host_file;
} MagicFileEntry;

static uintptr_t g_ImageBase;
static uintptr_t g_HeapBase;
static uintptr_t g_ImageLowBase;
static uintptr_t g_HeapLowBase;
static uintptr_t g_HeapCursor;
static uintptr_t g_Callables[MAGIC_CALL_TOKEN_LIMIT];
static uint32_t g_CallableCount;
static MagicFileEntry g_Files[MAGIC_FILE_LIMIT];
static uint32_t *g_ArgvSlot;
static uint32_t *g_CtypeSlot;
static int g_MbCurMax = 1;
static int g_ImageLoaded;
static char g_ProgramPath[1024];

extern uintptr_t WinMain(void *instance, void *previous_instance,
                         char *command_line, int show_state);
extern uintptr_t MagicNative_ResolveRecoveredCallable(uint32_t address);
extern const char *Platform_ResolveAssetPath(const char *path);


static size_t AlignSize(size_t size)
{
    return (size + 15u) & ~(size_t)15u;
}


static uintptr_t MapMemory(size_t size)
{
    void *result = mmap(NULL, size, PROT_READ | PROT_WRITE,
                        MAP_PRIVATE | MAP_ANON, -1, 0);
    if (result == MAP_FAILED) {
        fprintf(stderr, "mmap: %s\n", strerror(errno));
        return 0;
    }
    return (uintptr_t)result;
}


void *MagicNative_Malloc(size_t size)
{
    if (size == 0) {
        size = 1;
    }
    size_t allocation_size = AlignSize(sizeof(MagicAllocationHeader) + size);
    if (g_HeapCursor + allocation_size > g_HeapBase + MAGIC_HEAP_SIZE) {
        errno = ENOMEM;
        return NULL;
    }

    MagicAllocationHeader *header = (MagicAllocationHeader *)g_HeapCursor;
    g_HeapCursor += allocation_size;
    header->marker = MAGIC_ALLOCATION_MARKER;
    header->size = (uint32_t)size;
    header->reserved = 0;
    void *memory = header + 1;
    memset(memory, 0, size);
    return memory;
}


size_t MagicNative_AllocationSize(void *memory)
{
    if (memory == NULL) {
        return 0;
    }
    MagicAllocationHeader *header = (MagicAllocationHeader *)memory - 1;
    if (header->marker != MAGIC_ALLOCATION_MARKER) {
        return 0;
    }
    return header->size;
}


void *MagicNative_Realloc(void *memory, size_t size)
{
    if (memory == NULL) {
        return MagicNative_Malloc(size);
    }
    size_t old_size = MagicNative_AllocationSize(memory);
    if (old_size >= size) {
        return memory;
    }
    void *replacement = MagicNative_Malloc(size);
    if (replacement != NULL) {
        memcpy(replacement, memory, old_size);
    }
    return replacement;
}


void MagicNative_Free(void *memory)
{
    (void)memory;
}


int MagicNative_LoadImage(const char *image_path)
{
    if (g_ImageLoaded) {
        return 0;
    }
    g_ImageBase = MapMemory(MAGIC_IMAGE_SIZE);
    g_HeapBase = MapMemory(MAGIC_HEAP_SIZE);
    if (g_ImageBase == 0 || g_HeapBase == 0) {
        return -1;
    }
    g_ImageLowBase = (uint32_t)g_ImageBase;
    g_HeapLowBase = (uint32_t)g_HeapBase;

    FILE *image = fopen(image_path, "rb");
    if (image == NULL) {
        perror(image_path);
        return -1;
    }
    size_t count = fread((void *)g_ImageBase, 1, MAGIC_IMAGE_SIZE, image);
    fclose(image);
    if (count != MAGIC_IMAGE_SIZE) {
        fprintf(stderr, "The recovered MAGIC.EXE image has an incorrect size.\n");
        return -1;
    }

    g_HeapCursor = g_HeapBase;
    g_ImageLoaded = 1;
    Platform_InitWin32Subsystems();
    return 0;
}


void MagicNative_SetArguments(int argc, char **argv)
{
    if (!g_ImageLoaded) {
        return;
    }
    uint32_t *native_argv = MagicNative_Malloc((size_t)(argc + 1) * sizeof(uint32_t));
    for (int index = 0; index < argc; ++index) {
        size_t length = strlen(argv[index]) + 1;
        char *argument = MagicNative_Malloc(length);
        memcpy(argument, argv[index], length);
        native_argv[index] = (uint32_t)(uintptr_t)argument;
    }
    native_argv[argc] = 0;
    g_ArgvSlot = MagicNative_Malloc(sizeof(uint32_t));
    *g_ArgvSlot = (uint32_t)(uintptr_t)native_argv;
    if (argc > 0) {
        snprintf(g_ProgramPath, sizeof(g_ProgramPath), "%s", argv[0]);
    }
}


uintptr_t MagicNative_ArgvSlot(void)
{
    return (uintptr_t)g_ArgvSlot;
}


uintptr_t MagicNative_CopyProgramPath(char *buffer, size_t size)
{
    if (size != 0) {
        snprintf(buffer, size, "%s", g_ProgramPath);
    }
    return (uintptr_t)buffer;
}


uintptr_t MagicNative_HostPointer(uintptr_t recovered_address)
{
    if (recovered_address == 0 || recovered_address > UINT32_MAX) {
        return recovered_address;
    }
    if (recovered_address >= MAGIC_IMAGE_VIRTUAL_BASE &&
        recovered_address < MAGIC_IMAGE_VIRTUAL_BASE + MAGIC_IMAGE_SIZE) {
        return g_ImageBase + recovered_address - MAGIC_IMAGE_VIRTUAL_BASE;
    }
    if (recovered_address >= g_ImageLowBase &&
        recovered_address < g_ImageLowBase + MAGIC_IMAGE_SIZE) {
        return g_ImageBase + recovered_address - g_ImageLowBase;
    }
    if (recovered_address >= g_HeapLowBase &&
        recovered_address < g_HeapLowBase + MAGIC_HEAP_SIZE) {
        return g_HeapBase + recovered_address - g_HeapLowBase;
    }
    return recovered_address;
}


uintptr_t MagicNative_GlobalAddress(uint32_t recovered_address)
{
    return g_ImageBase + recovered_address - MAGIC_IMAGE_VIRTUAL_BASE;
}


int MagicNative_Run(const char *command_line)
{
    char command_buffer[512];
    snprintf(command_buffer, sizeof(command_buffer), "%s", command_line);
    return (int)WinMain((void *)(uintptr_t)1, NULL, command_buffer, 1);
}


void MagicNative_Shutdown(void)
{
    if (!g_ImageLoaded) {
        return;
    }
    Platform_ShutdownWin32Subsystems();
    munmap((void *)g_HeapBase, MAGIC_HEAP_SIZE);
    munmap((void *)g_ImageBase, MAGIC_IMAGE_SIZE);
    g_HeapBase = 0;
    g_ImageBase = 0;
    g_ImageLoaded = 0;
}


uintptr_t MagicNative_RegisterCallable(uintptr_t function_address)
{
    if (function_address >= MAGIC_CALL_TOKEN_BASE &&
        function_address < MAGIC_CALL_TOKEN_BASE + MAGIC_CALL_TOKEN_LIMIT * 4u) {
        return function_address;
    }
    if (function_address <= UINT32_MAX && function_address < MAGIC_CALL_TOKEN_BASE) {
        return function_address;
    }
    for (uint32_t index = 0; index < g_CallableCount; ++index) {
        if (g_Callables[index] == function_address) {
            return MAGIC_CALL_TOKEN_BASE + index * 4u;
        }
    }
    if (g_CallableCount >= MAGIC_CALL_TOKEN_LIMIT) {
        return 0;
    }
    uint32_t index = g_CallableCount++;
    g_Callables[index] = function_address;
    return MAGIC_CALL_TOKEN_BASE + index * 4u;
}


uintptr_t MagicNative_ResolveCallable(uint32_t recovered_address)
{
    if (recovered_address >= MAGIC_CALL_TOKEN_BASE) {
        uint32_t index = (recovered_address - MAGIC_CALL_TOKEN_BASE) / 4u;
        if (index < g_CallableCount) {
            return g_Callables[index];
        }
    }
    return MagicNative_ResolveRecoveredCallable(recovered_address);
}


static MagicFileEntry *FindFile(void *proxy)
{
    for (size_t index = 0; index < MAGIC_FILE_LIMIT; ++index) {
        if (g_Files[index].proxy == proxy) {
            return &g_Files[index];
        }
    }
    return NULL;
}


static void SetFileEndFlag(MagicFileEntry *entry)
{
    if (entry != NULL && feof(entry->host_file)) {
        entry->proxy->flags |= 0x10;
    }
}


uintptr_t MagicNative_Fopen(const char *path, const char *mode)
{
    const char *resolved_path = Platform_ResolveAssetPath(path);
    FILE *host_file = fopen(resolved_path, mode);
    if (host_file == NULL) {
        return 0;
    }
    for (size_t index = 0; index < MAGIC_FILE_LIMIT; ++index) {
        if (g_Files[index].proxy == NULL) {
            MagicFileLayout *proxy = MagicNative_Malloc(sizeof(*proxy));
            proxy->file_number = fileno(host_file);
            g_Files[index].proxy = proxy;
            g_Files[index].host_file = host_file;
            return (uintptr_t)proxy;
        }
    }
    fclose(host_file);
    return 0;
}


uintptr_t MagicNative_Fclose(void *proxy)
{
    MagicFileEntry *entry = FindFile(proxy);
    if (entry == NULL) {
        return (uintptr_t)-1;
    }
    int result = fclose(entry->host_file);
    entry->proxy = NULL;
    entry->host_file = NULL;
    return (uintptr_t)result;
}


uintptr_t MagicNative_Fread(void *buffer, size_t size, size_t count, void *proxy)
{
    MagicFileEntry *entry = FindFile(proxy);
    if (entry == NULL) {
        return 0;
    }
    size_t result = fread(buffer, size, count, entry->host_file);
    SetFileEndFlag(entry);
    return result;
}


uintptr_t MagicNative_Fwrite(const void *buffer, size_t size, size_t count, void *proxy)
{
    MagicFileEntry *entry = FindFile(proxy);
    return entry == NULL ? 0 : fwrite(buffer, size, count, entry->host_file);
}


uintptr_t MagicNative_Fseek(void *proxy, long offset, int origin)
{
    MagicFileEntry *entry = FindFile(proxy);
    if (entry == NULL) {
        return (uintptr_t)-1;
    }
    entry->proxy->flags &= ~0x10;
    return (uintptr_t)fseek(entry->host_file, offset, origin);
}


uintptr_t MagicNative_Ftell(void *proxy)
{
    MagicFileEntry *entry = FindFile(proxy);
    return entry == NULL ? (uintptr_t)-1 : (uintptr_t)ftell(entry->host_file);
}


uintptr_t MagicNative_Fgets(char *buffer, int size, void *proxy)
{
    MagicFileEntry *entry = FindFile(proxy);
    if (entry == NULL) {
        return 0;
    }
    char *result = fgets(buffer, size, entry->host_file);
    SetFileEndFlag(entry);
    return (uintptr_t)result;
}


uintptr_t MagicNative_Fgetc(void *proxy)
{
    MagicFileEntry *entry = FindFile(proxy);
    if (entry == NULL) {
        return (uintptr_t)EOF;
    }
    int result = fgetc(entry->host_file);
    SetFileEndFlag(entry);
    return (uintptr_t)result;
}


uintptr_t MagicNative_Fprintf(void *proxy, const char *format, ...)
{
    MagicFileEntry *entry = FindFile(proxy);
    if (entry == NULL) {
        return (uintptr_t)-1;
    }
    va_list arguments;
    va_start(arguments, format);
    int result = vfprintf(entry->host_file, format, arguments);
    va_end(arguments);
    return (uintptr_t)result;
}


uintptr_t MagicNative_Fscanf(void *proxy, const char *format, ...)
{
    MagicFileEntry *entry = FindFile(proxy);
    if (entry == NULL) {
        return (uintptr_t)-1;
    }
    va_list arguments;
    va_start(arguments, format);
    int result = vfscanf(entry->host_file, format, arguments);
    va_end(arguments);
    return (uintptr_t)result;
}


uintptr_t MagicNative_GetProcAddress(void *module, const char *name)
{
    FARPROC function = GetProcAddress((HMODULE)module, name);
    return MagicNative_RegisterCallable((uintptr_t)function);
}


uintptr_t MagicNative_LoadBitmapA(void *instance, const char *name)
{
    (void)instance;
    (void)name;
    return 0;
}


uintptr_t MagicNative_StackProbe(void)
{
    return 0;
}


uintptr_t __allshl(unsigned int shift, uint32_t value)
{
    return (uint64_t)value << (shift & 63u);
}


uintptr_t MagicNative_AtExit(uintptr_t (*function)(void))
{
    return (uintptr_t)atexit((void (*)(void))function);
}


uintptr_t MagicNative_Errno(void)
{
    return (uintptr_t)&errno;
}


uintptr_t MagicNative_MbCurMax(void)
{
    return (uintptr_t)&g_MbCurMax;
}


uintptr_t MagicNative_Pctype(void)
{
    if (g_CtypeSlot == NULL) {
        uint16_t *table = MagicNative_Malloc(512u * sizeof(uint16_t));
        g_CtypeSlot = MagicNative_Malloc(sizeof(uint32_t));
        *g_CtypeSlot = (uint32_t)(uintptr_t)(table + 128);
    }
    return (uintptr_t)g_CtypeSlot;
}


uintptr_t MagicNative_Isctype(int character, int mask)
{
    unsigned char value = (unsigned char)character;
    int result = 0;
    if ((mask & 0x001) && isupper(value)) result |= 0x001;
    if ((mask & 0x002) && islower(value)) result |= 0x002;
    if ((mask & 0x004) && isdigit(value)) result |= 0x004;
    if ((mask & 0x008) && isspace(value)) result |= 0x008;
    if ((mask & 0x010) && ispunct(value)) result |= 0x010;
    if ((mask & 0x020) && iscntrl(value)) result |= 0x020;
    if ((mask & 0x100) && isalpha(value)) result |= 0x100;
    return (uintptr_t)result;
}


uintptr_t MagicNative_Itoa(int value, char *buffer, int radix)
{
    if (radix == 16) {
        snprintf(buffer, 34, "%x", (unsigned int)value);
    } else {
        snprintf(buffer, 34, "%d", value);
    }
    return (uintptr_t)buffer;
}


uintptr_t MagicNative_Strlwr(char *text)
{
    for (char *cursor = text; cursor != NULL && *cursor != '\0'; ++cursor) {
        *cursor = (char)tolower((unsigned char)*cursor);
    }
    return (uintptr_t)text;
}


uintptr_t MagicNative_SplitPath(const char *path, char *drive, char *directory,
                                char *filename, char *extension)
{
    if (drive != NULL) drive[0] = '\0';
    const char *slash = strrchr(path, '/');
    const char *backslash = strrchr(path, '\\');
    if (backslash != NULL && (slash == NULL || backslash > slash)) slash = backslash;
    const char *name = slash == NULL ? path : slash + 1;
    if (directory != NULL) {
        size_t length = slash == NULL ? 0 : (size_t)(slash - path + 1);
        memcpy(directory, path, length);
        directory[length] = '\0';
    }
    const char *dot = strrchr(name, '.');
    if (dot == NULL) dot = name + strlen(name);
    if (filename != NULL) {
        size_t length = (size_t)(dot - name);
        memcpy(filename, name, length);
        filename[length] = '\0';
    }
    if (extension != NULL) snprintf(extension, 256, "%s", *dot == '.' ? dot : "");
    return 0;
}


uintptr_t MagicNative_Vsnprintf(char *buffer, size_t size, const char *format, void *arguments)
{
    (void)arguments;
    return (uintptr_t)snprintf(buffer, size, "%s", format == NULL ? "" : format);
}


uintptr_t MagicNative_Assert(int condition, const char *file, int line)
{
    if (!condition) {
        fprintf(stderr, "Recovered assertion failed at %s:%d.\n",
                file == NULL ? "unknown" : file, line);
    }
    return (uintptr_t)condition;
}


uintptr_t MagicNative_Open(const char *path, int flags, ...)
{
    int native_flags = flags & ~0x8000;
    return (uintptr_t)open(Platform_ResolveAssetPath(path), native_flags, 0666);
}


uintptr_t MagicNative_Mkdir(const char *path)
{
    return (uintptr_t)mkdir(path, 0777);
}


uintptr_t MagicNative_FileLength(int descriptor)
{
    struct stat status;
    return fstat(descriptor, &status) == 0 ? (uintptr_t)status.st_size : (uintptr_t)-1;
}


uintptr_t MagicNative_Tell(int descriptor)
{
    return (uintptr_t)lseek(descriptor, 0, SEEK_CUR);
}


uintptr_t MagicNative_Fileno(void *proxy)
{
    MagicFileEntry *entry = FindFile(proxy);
    return entry == NULL ? (uintptr_t)-1 : (uintptr_t)fileno(entry->host_file);
}


uintptr_t Mem_AllocOrFree_00513bd0(void)
{
    return 0;
}
