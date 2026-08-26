/*
 * Decompiled function: FUN_00471971
 * Entry Point: 00471971
 * Size: 329 bytes
 */
#include "magic.h"


undefined4 FUN_00471971(int arg1,int arg2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_14;
  
  if ((((&DAT_0051aed1)[*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 0x10)
       == 0) || (DAT_006ff2d4 == -1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (g_ActivePlayer != 1) {
    if ((!bVar1) && (DAT_00695df8 == 0)) {
      strcpy(&g_OverworldWorldState,s_Activate_00525c74);
      Ai_Subsystem_004b90de(arg1,arg2);
      if ((DAT_0063ee1c == 0) || (arg1 != g_CurrentTurnPhase)) {
        local_14 = -2;
      }
      else {
        local_14 = -1;
      }
      FUN_00475c8a(local_14,g_ScWillyScore,&g_OverworldWorldState,0x6d);
    }
    Magic_EndTurnPhase();
    uVar3 = DAT_006b2e14;
    uVar2 = DAT_00695f08;
    DAT_00695f08 = arg1;
    DAT_006b2e14 = arg2;
    FUN_00476205(g_DefendingPlayer,0xd2,s_Tapping_00525c80,0);
    DAT_00695f08 = uVar2;
    DAT_006b2e14 = uVar3;
  }
  return 1;
}


