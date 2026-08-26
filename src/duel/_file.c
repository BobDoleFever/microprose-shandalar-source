/*
 * _file.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 2
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: ___initstdio
 * Entry Point: 004e1440
 * Size: 338 bytes
 */


/* Library Function - Single Match
    ___initstdio
   
   Library: Visual Studio 1998 Debug */

void ___initstdio(void)

{
  uint32_t slot_idx;
  
  if (DAT_006c2ca0 == 0) {
    DAT_006c2ca0 = 0x200;
  }
  else if (DAT_006c2ca0 < 0x14) {
    DAT_006c2ca0 = 0x14;
  }
  DAT_006c1c98 = __calloc_dbg(DAT_006c2ca0,4,2,"_file.c",0x84);
  if (DAT_006c1c98 == 0) {
    DAT_006c2ca0 = 0x14;
    DAT_006c1c98 = __calloc_dbg(0x14,4,2,"_file.c",0x87);
    if (DAT_006c1c98 == 0) {
      __amsg_exit(0x1a);
    }
  }
  for (slot_idx = 0; (int)slot_idx < 0x14; slot_idx = slot_idx + 1) {
    *(uint8_t ***)(DAT_006c1c98 + slot_idx * 4) = &PTR_DAT_00509750 + slot_idx * 8;
  }
  for (slot_idx = 0; (int)slot_idx < 3; slot_idx = slot_idx + 1) {
    if ((*(int *)(*(int *)((int)&DAT_006c1b90 + ((int)(slot_idx & 0xffffffe0) >> 3)) +
                 (slot_idx & 0x1f) * 8) == -1) ||
       (*(int *)(*(int *)((int)&DAT_006c1b90 + ((int)(slot_idx & 0xffffffe0) >> 3)) +
                (slot_idx & 0x1f) * 8) == 0)) {
      *(int32_t *)(&DAT_00509760 + slot_idx * 0x20) = 0xffffffff;
    }
  }
  return;
}



/*
 * Decompiled function: ___endstdio
 * Entry Point: 004e15a0
 * Size: 36 bytes
 */


/* Library Function - Single Match
    ___endstdio
   
   Library: Visual Studio 1998 Debug */

void ___endstdio(void)

{
  __flushall();
  if (DAT_00509460 != '\0') {
    __fcloseall();
  }
  return;
}



