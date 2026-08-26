/*
 * Decompiled function: FUN_00472616
 * Entry Point: 00472616
 * Size: 175 bytes
 */
#include "magic.h"


undefined4 FUN_00472616(int arg_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if ((int)(&g_PlayerActiveCardCount)[arg_1] <= local_8) {
      return 0;
    }
    if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + arg_1 * 0x5b20) != -1) &&
        (((&g_CardSlot_Flags)[local_8 * 0x120 + arg_1 * 0x5b20] & 6) != 0)) &&
       (iVar1 = FUN_004726c5(arg_1,local_8), iVar1 != 0)) break;
    local_8 = local_8 + 1;
  }
  return 1;
}


