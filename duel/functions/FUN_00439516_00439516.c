/*
 * Decompiled function: FUN_00439516
 * Entry Point: 00439516
 * Size: 79 bytes
 */
#include "duel.h"


void FUN_00439516(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_00663df8; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_00616a10 + local_8 * 0x18));
  }
  DAT_00663df8 = 0;
  return;
}


