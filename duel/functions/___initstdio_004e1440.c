/*
 * Decompiled function: ___initstdio
 * Entry Point: 004e1440
 * Size: 338 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___initstdio
   
   Library: Visual Studio 1998 Debug */

void ___initstdio(void)

{
  uint local_8;
  
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
  for (local_8 = 0; (int)local_8 < 0x14; local_8 = local_8 + 1) {
    *(undefined ***)(DAT_006c1c98 + local_8 * 4) = &PTR_DAT_00509750 + local_8 * 8;
  }
  for (local_8 = 0; (int)local_8 < 3; local_8 = local_8 + 1) {
    if ((*(int *)(*(int *)((int)&DAT_006c1b90 + ((int)(local_8 & 0xffffffe0) >> 3)) +
                 (local_8 & 0x1f) * 8) == -1) ||
       (*(int *)(*(int *)((int)&DAT_006c1b90 + ((int)(local_8 & 0xffffffe0) >> 3)) +
                (local_8 & 0x1f) * 8) == 0)) {
      *(undefined4 *)(&DAT_00509760 + local_8 * 0x20) = 0xffffffff;
    }
  }
  return;
}


