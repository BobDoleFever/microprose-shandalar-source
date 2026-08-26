/*
 * Decompiled function: Ai_Subsystem_004bd23f
 * Entry Point: 004bd23f
 * Size: 426 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004bd23f(int arg1,int arg2)

{
  uint uVar1;
  undefined4 local_8;
  
  if ((((&g_CardSlot_Flags)[arg1 * 0x5b20 + arg2 * 0x120] & 0x10) == 0) &&
     ((((&DAT_006a5f3e)[arg1 * 0x5b20 + arg2 * 0x120] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 2) == 0)))) {
    Magic_CombatPhase(arg1,arg2,0x72,arg1,0);
    DAT_006ff4ac = 1;
    DAT_006ff2d4 = 0xffffffff;
    uVar1 = *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120);
    Magic_TriggerCardEvent(arg1,arg2,0x6d,1 - arg1,0xffffffff);
    DAT_006ff4ac = 0;
    if (g_ActivePlayer == 1) {
      g_ActivePlayer = 0;
      Magic_DiscardToHandSize();
      local_8 = 0;
    }
    else {
      if (((uVar1 & 0x10) == 0) && (((&g_CardSlot_Flags)[arg1 * 0x5b20 + arg2 * 0x120] & 0x10) != 0)
         ) {
        FUN_00473e69(arg1,arg2,0x81);
      }
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x12);
      }
      Magic_EndTurnPhase();
      local_8 = 1;
    }
  }
  else {
    local_8 = 0;
  }
  return local_8;
}


