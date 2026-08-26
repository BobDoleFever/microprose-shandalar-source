/*
 * sid/glue_timer.c - High-Precision Hardware Timer & Profiling Clock
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier / MicroProse (1997)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/glue.h"

/*
 * Timer_InitVxD
 * Purpose: Initialize high precision timer via MPStime VXD driver.
 * Procedure:
 * 1. Verify if VXD device handle is already open.
 * 2. Call CreateFileA on MPStime VXD path if not open.
 * 3. Execute DeviceIoControl code 1 to initialize timer.
 * 4. Return success status.
 */
/*
 * Decompiled function: Timer_InitVxD
 * Entry Point: 004cd63b
 * Size: 168 bytes
 */

int Timer_InitVxD(void)

{
  int local_8;
  
  if (DAT_006410e4 == (HANDLE)0x0) {
    DAT_006410e4 = CreateFileA(s_____MPStime_VXD_0052e63c,0,0,(LPSECURITY_ATTRIBUTES)0x0,0,0x4000000
                               ,(HANDLE)0x0);
    AssertOrLog((uint)(DAT_006410e4 != (HANDLE)0xffffffff),0x52e674,0x2c4,
                s_Could_Not_Load_Dave_s_Extra_Cool_0052e64c);
    DeviceIoControl(DAT_006410e4,1,(LPVOID)0x0,0,&local_8,4,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
    AssertOrLog((uint)(local_8 == 0x100),0x52e6c4,0x2cb,s_Could_Not_Initialize_Dave_s_Extr_0052e694)
    ;
  }
  return 1;
}

/*
 * Timer_GetTicks
 * Purpose: Query high precision hardware timer ticks.
 * Procedure:
 * 1. Execute DeviceIoControl code 2 on VXD handle.
 * 2. Return 32-bit hardware tick counter.
 */
/*
 * Decompiled function: Timer_GetTicks
 * Entry Point: 004cd6e3
 * Size: 50 bytes
 */

int Timer_GetTicks(void)

{
  int local_8;
  
  DeviceIoControl(DAT_006410e4,2,(LPVOID)0x0,0,&local_8,4,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
  return local_8;
}

/*
 * Timer_MarkStart
 * Purpose: Record baseline timestamp for performance profiling.
 * Procedure:
 * 1. Read current hardware timer ticks.
 * 2. Store timestamp in start timestamp global.
 */
/*
 * Decompiled function: Timer_MarkStart
 * Entry Point: 004cd715
 * Size: 21 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Timer_MarkStart(void)

{
  _DAT_00565728 = Timer_GetTicks();
  return;
}

/*
 * Timer_GetElapsedFraction
 * Purpose: Compute percentage of elapsed time against reference interval.
 * Procedure:
 * 1. Read current timer ticks.
 * 2. Calculate elapsed delta from baseline.
 * 3. Compute scaled percentage value.
 */
/*
 * Decompiled function: Timer_GetElapsedFraction
 * Entry Point: 004cd72a
 * Size: 53 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Timer_GetElapsedFraction(void)

{
  int status;
  
  status = Timer_GetTicks();
  return ((status - _DAT_00565728) * 100) / 0x151d;
}

