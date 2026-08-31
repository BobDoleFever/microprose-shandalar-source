/*
 * src/platform/win32_compat.c - Master Win32 Emulation & Subsystem Coordinator
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/win32_internal.h"
#include "shandalar/display_shim.h"

/* Global Program Arguments Pointer for __p___argv */
static char **g_ProgramArgv = NULL;

char*** __p___argv(void)
{
    return &g_ProgramArgv;
}

void SetProgramArgv(char **argv)
{
    g_ProgramArgv = argv;
}

/* Subsystem Master Lifecycle Initializer */
void Platform_InitWin32Subsystems(void)
{
    Platform_HandleInit();
    User_InternalInit();
    Message_InternalInit();
    Gdi_InternalInit();
    Kernel_InternalInit();
    Config_InternalInit();
    Multimedia_InternalInit();
}

void Platform_ShutdownWin32Subsystems(void)
{
    Multimedia_InternalShutdown();
    Config_InternalShutdown();
    Kernel_InternalShutdown();
    Gdi_InternalShutdown();
    Message_InternalShutdown();
    User_InternalShutdown();
    Platform_HandleShutdown();
}
