/*
 * Decompiled function: FUN_10013e46
 * Entry Point: 10013e46
 * Size: 78 bytes
 */
#include "deckdll.h"


void FUN_10013e46(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_10158728; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_101cf5f0 + local_8 * 0x18));
  }
  DAT_10158728 = 0;
  return;
}


