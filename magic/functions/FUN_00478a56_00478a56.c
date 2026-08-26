/*
 * Decompiled function: FUN_00478a56
 * Entry Point: 00478a56
 * Size: 78 bytes
 */
#include "magic.h"


void FUN_00478a56(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_00680778; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_006fefb0 + local_8 * 0x18));
  }
  DAT_00680778 = 0;
  return;
}


