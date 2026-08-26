/*
 * Decompiled function: Minit_Subsystem_00466d29
 * Entry Point: 00466d29
 * Size: 563 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00466d29(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (arg_3 == 0x73) {
    iVar1 = FUN_0040d949(arg_1,7,1);
    if (((iVar1 == 0) ||
        ((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)))) ||
       (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,7,1), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,0,1), g_ActivePlayer != 1)) {
      Pic_Subsystem_0044867e(arg_1,arg_2,3);
    }
    if (arg_3 == 0x72) {
      if (arg_1 == g_CurrentTurnPhase) {
        strcpy(&g_OverworldWorldState,s_Heads_Tails_00524744);
      }
      else {
        strcpy(&g_OverworldWorldState,s_Call_the_coin_flip__Heads_Tails_00524754);
      }
      iVar1 = FUN_0040a1d2(1);
      iVar1 = Ai_Subsystem_004cc56d(1 - arg_1,arg_1,arg_2,-1,-1,&g_OverworldWorldState,iVar1);
      strcpy(&g_OverworldWorldState,&DAT_00524778);
      iVar3 = Ai_Subsystem_004b7d38(s_Bottle_of_Suleiman_0052477c);
      if (iVar3 == iVar1) {
        Mem_AllocOrFree_0041df33(arg_1,5,g_DialogPromptHwnd,g_DuelArenaHwnd);
      }
      else {
        iVar1 = Pic_Subsystem_0045268f(0x37a);
        iVar1 = Pic_Subsystem_00451291(arg_1,iVar1);
        if (iVar1 != -1) {
          Pic_Subsystem_0042ac1f(arg_1,iVar1);
          *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg_1 * 0x5b20) | 0x10;
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


