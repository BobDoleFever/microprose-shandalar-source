/*
 * Decompiled function: FUN_004fa423
 * Entry Point: 004fa423
 * Size: 149 bytes
 */
#include "magic.h"


int FUN_004fa423(int arg1,int arg2)

{
  int local_c;
  int local_8;
  
  local_c = 1;
  for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[arg1]; local_8 = local_8 + 1) {
    if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + arg1 * 0x5b20) == arg2) &&
       (((&g_CardSlot_Flags)[local_8 * 0x120 + arg1 * 0x5b20] & 2) == 0)) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}


