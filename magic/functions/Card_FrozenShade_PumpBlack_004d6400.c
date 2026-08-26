/*
 * Decompiled function: Card_FrozenShade_PumpBlack
 * Entry Point: 004d6400
 * Size: 774 bytes
 */
#include "magic.h"


undefined4 Card_FrozenShade_PumpBlack(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x6c) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0x20;
  }
  if (arg_3 == 1) {
    *(int *)(&DAT_006ff6a0 + arg_1 * 0x20) = *(int *)(&DAT_006ff6a0 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    if ((*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) ||
       (iVar1 = FUN_0040d949(arg_1,4,1), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,4,1), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,4,1), g_ActivePlayer != 1)) {
      *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
      *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      if (g_ActivePlayerPriority == arg_1) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20] = 0;
        *(undefined4 *)
         (&g_CardSlot_ConvertedManaCost +
         *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) = 0x20;
        iVar1 = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,g_DialogPromptHwnd,
                             g_DuelArenaHwnd);
        if (iVar1 != -1) {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + arg_1 * 0x5b20) = 0x20;
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


