/*
 * Decompiled function: ___initstdio
 * Entry Point: 0040a1d0
 * Size: 338 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___initstdio
   
   Library: Visual Studio 1998 Debug */

void ___initstdio(void)

{
  uint32_t local_8;
  
  if (DAT_00415690 == 0) {
    DAT_00415690 = 0x200;
  }
  else if (DAT_00415690 < 0x14) {
    DAT_00415690 = 0x14;
  }
  DAT_00414344 = __calloc_dbg(DAT_00415690,4,2,"_file.c",0x84);
  if (DAT_00414344 == (uint8_t *)0x0) {
    DAT_00415690 = 0x14;
    DAT_00414344 = __calloc_dbg(0x14,4,2,"_file.c",0x87);
    if (DAT_00414344 == (uint8_t *)0x0) {
      __amsg_exit(0x1a);
    }
  }
  for (local_8 = 0; (int)local_8 < 0x14; local_8 = local_8 + 1) {
    *(uint8_t ***)(DAT_00414344 + local_8 * 4) = &PTR_DAT_00413940 + local_8 * 8;
  }
  for (local_8 = 0; (int)local_8 < 3; local_8 = local_8 + 1) {
    if ((*(int *)(*(int *)((int)&DAT_004156c0 + ((int)(local_8 & 0xffffffe0) >> 3)) +
                 (local_8 & 0x1f) * 8) == -1) ||
       (*(int *)(*(int *)((int)&DAT_004156c0 + ((int)(local_8 & 0xffffffe0) >> 3)) +
                (local_8 & 0x1f) * 8) == 0)) {
      *(int32_t *)(&DAT_00413950 + local_8 * 0x20) = 0xffffffff;
    }
  }
  return;
}


