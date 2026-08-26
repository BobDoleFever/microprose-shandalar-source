/*
 * Decompiled function: Palette_Subsystem_004a7814
 * Entry Point: 004a7814
 * Size: 529 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004a7814(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x73) {
    iVar1 = FUN_0040d949(arg_1,7,2);
    if ((iVar1 == 0) ||
       ((*(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x20014) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    Ai_CalcLifeAdvantage(0);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = Palette_Subsystem_004a7d05(arg_1,arg_2), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,2);
      if (g_ActivePlayer != 1) {
        Ai_CalcManaRequirement_004ba890(arg_1,4,-1);
      }
      if (g_ActivePlayer != 1) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) =
             g_TurnCounter;
        *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
      }
    }
    if ((arg_3 == 0x72) &&
       (0 < *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120))) {
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x27);
      }
      Palette_Subsystem_004a7a25
                (g_DialogPromptHwnd,g_DuelArenaHwnd,
                 *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120));
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


