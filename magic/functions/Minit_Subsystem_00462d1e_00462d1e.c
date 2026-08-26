/*
 * Decompiled function: Minit_Subsystem_00462d1e
 * Entry Point: 00462d1e
 * Size: 608 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00462d1e(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&DAT_0063edec + g_ActivePlayerPriority * 0x20) * 3 + -0xc) * 4;
    *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
  }
  if (arg_3 == 0x73) {
    iVar1 = FUN_0040d949(arg_1,7,2);
    if ((iVar1 == 0) || (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,7,2), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,2);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      Card_DirectDamage_EvaluateBestTarget(arg_1,arg_2);
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      Card_DirectDamage_PromptAndDealDamage(arg_1,arg_2,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffffffef;
    }
    if (((arg_3 == 0x22) || (arg_3 == 199)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) {
      Pic_Subsystem_0044867e(arg_1,arg_2,2);
    }
    uVar2 = 0;
  }
  return uVar2;
}


