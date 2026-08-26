/*
 * Decompiled function: CardTarget_HasValidCreatureTarget
 * Entry Point: 004e6bff
 * Size: 461 bytes
 */
#include "magic.h"


int CardTarget_HasValidCreatureTarget(int arg_1)

{
  int iVar1;
  int iVar2;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((arg_1 == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
    iVar1 = Action_ValidateTarget_00405802
                      (arg_1,arg_1,arg_1,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                       &g_OverworldGoldAmount,0,&local_1c);
    if (iVar1 == 0) {
      local_20 = -1;
    }
    else {
      local_20 = local_18;
    }
  }
  else {
    local_20 = -1;
    local_14 = 0x7fff;
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_10 = local_10 + 1) {
      local_c = *(int *)(&g_CardSlot_CardId + local_10 * 0x120 + arg_1 * 0x5b20);
      if ((((local_c != -1) && (((&g_CardSlot_Flags)[local_10 * 0x120 + arg_1 * 0x5b20] & 2) != 0))
          && (((&g_MasterCardColorTable)[local_c * 0x34] & 2) != 0)) &&
         ((&DAT_006a5f50)[local_10 * 0x120 + arg_1 * 0x5b20] != '\x03')) {
        iVar1 = FUN_00473179(arg_1,local_10,0x32,0xffffffff);
        iVar2 = FUN_00473179(arg_1,local_10,0x33,0xffffffff);
        local_8 = (iVar1 + 2) * (iVar2 + 2);
        if (local_8 < local_14) {
          local_20 = local_10;
          local_14 = local_8;
        }
      }
    }
  }
  if ((local_20 != -1) && (g_IsAiThinking != 1)) {
    Magic_UpkeepPhase(0xf);
  }
  return local_20;
}


