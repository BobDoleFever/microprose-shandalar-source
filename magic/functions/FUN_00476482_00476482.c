/*
 * Decompiled function: FUN_00476482
 * Entry Point: 00476482
 * Size: 142 bytes
 */
#include "magic.h"


int FUN_00476482(int arg1,int arg2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return -1;
    }
    if (*(int *)(&DAT_007006e0 + local_8 * 4) == -1) break;
    local_8 = local_8 + 1;
  }
  *(int *)(&DAT_007006e0 + local_8 * 4) = arg1;
  *(int *)(&DAT_006a5750 + local_8 * 4) = arg2;
  *(int *)(&g_CardSlot_DisplayIndex + arg2 * 0x120 + arg1 * 0x5b20) = local_8;
  return local_8;
}


