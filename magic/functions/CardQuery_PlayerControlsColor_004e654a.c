/*
 * Decompiled function: CardQuery_PlayerControlsColor
 * Entry Point: 004e654a
 * Size: 151 bytes
 */
#include "magic.h"


undefined4 CardQuery_PlayerControlsColor(int arg1,byte arg2)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if ((int)(&g_PlayerActiveCardCount)[arg1] <= local_8) {
      return 0;
    }
    iVar1 = FUN_00471c32(arg1,local_8);
    if ((iVar1 != 0) &&
       ((arg2 & (&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + arg1 * 0x5b20) * 0x34]) != 0))
    break;
    local_8 = local_8 + 1;
  }
  return 1;
}


