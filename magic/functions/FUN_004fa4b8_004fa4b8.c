/*
 * Decompiled function: FUN_004fa4b8
 * Entry Point: 004fa4b8
 * Size: 206 bytes
 */
#include "magic.h"


int FUN_004fa4b8(int arg_1,int arg_2,int arg_3)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  for (arg_1 = 0; arg_1 < 2; arg_1 = arg_1 + 1) {
    if ((arg_3 == -1) || (arg_3 == arg_1)) {
      for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_8 = local_8 + 1) {
        if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + arg_1 * 0x5b20) == arg_2) &&
           (((&g_CardSlot_Flags)[local_8 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
          local_c = local_c + 1;
        }
      }
    }
  }
  return local_c;
}


