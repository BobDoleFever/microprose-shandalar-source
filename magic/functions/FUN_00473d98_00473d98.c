/*
 * Decompiled function: FUN_00473d98
 * Entry Point: 00473d98
 * Size: 209 bytes
 */
#include "magic.h"


int FUN_00473d98(int arg_1)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_10 = 0;
  for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[arg_1]; local_c = local_c + 1) {
    iVar1 = *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + local_c * 0x120);
    if ((((iVar1 != -1) && (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + local_c * 0x120] & 2) == 0)) &&
        (((&g_MasterCardColorTable)[iVar1 * 0x34] & 1) != 0)) &&
       ((&DAT_0051aebe)[iVar1 * 0x34] != '\0')) {
      local_10 = local_10 + 1;
    }
  }
  return local_10;
}


