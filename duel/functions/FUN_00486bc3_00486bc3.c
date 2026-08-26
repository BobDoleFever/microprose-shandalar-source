/*
 * Decompiled function: FUN_00486bc3
 * Entry Point: 00486bc3
 * Size: 79 bytes
 */
#include "duel.h"


void FUN_00486bc3(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_005f76d4; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_00664870 + local_8 * 0x18));
  }
  DAT_005f76d4 = 0;
  return;
}


