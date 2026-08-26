/*
 * Decompiled function: FUN_100295a9
 * Entry Point: 100295a9
 * Size: 78 bytes
 */
#include "deckdll.h"


void FUN_100295a9(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_101cdeb0; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_10175560 + local_8 * 0x18));
  }
  DAT_101cdeb0 = 0;
  return;
}


