/*
 * Decompiled function: Card_DrudgeSkeletons_Regenerate
 * Entry Point: 004d817b
 * Size: 1616 bytes
 */
#include "magic.h"


undefined4 Card_DrudgeSkeletons_Regenerate(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_006ff694 + arg_1 * 0x20) = *(int *)(&DAT_006ff694 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    if (((g_ActivePlayerPriority == arg_1) && (g_DefendingPlayer == arg_1)) &&
       ((*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) != 0 &&
        (g_ScWillyScore < 0x1a)))) {
      uVar1 = 0;
    }
    else {
      iVar2 = FUN_0040d949(arg_1,1,1);
      if ((iVar2 == 0) ||
         (0x1ffff < (int)(*(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) &
                         0xffff0000))) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else if (arg_3 == 0x90) {
    Ai_CalcLifeAdvantage(0);
    uVar1 = 0;
  }
  else {
    if (((arg_3 == 0x6d) &&
        (iVar2 = FUN_0040d949(arg_1,1,1), uVar1 = g_OverworldPlayerCoordY, iVar2 != 0)) &&
       ((int)(*(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffff0000) <
        0x20000)) {
      if (((&DAT_006a5f62)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0xf) == 0) {
        g_OverworldPlayerCoordY = 2;
      }
      else {
        g_OverworldPlayerCoordY = 1;
      }
      if (g_DefendingPlayer == arg_1) {
        Ai_CalcManaRequirement_004ba890(arg_1,1,-1);
        if (g_TurnCounter < 1) {
          g_ActivePlayer = 1;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,1,1);
        g_TurnCounter = 1;
      }
      g_OverworldPlayerCoordY = uVar1;
      *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xf0000;
      if (g_ActivePlayer != 1) {
        *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) +
             g_TurnCounter * 0x10001;
        if (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
          *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (*(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff);
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20] = 0;
        if (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20] & 8) != 0) {
          *(uint *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20)
               & 0xfff7ffff;
          iVar2 = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,g_DialogPromptHwnd,
                               g_DuelArenaHwnd);
          if (iVar2 != -1) {
            *(undefined2 *)(&DAT_006a5f48 + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      uVar1 = FUN_0040a305(*(int *)(&DAT_0063edd4 + arg_1 * 0x20),0,
                           2 - *(int *)(&g_CardSlot_ConvertedManaCost +
                                       arg_2 * 0x120 + arg_1 * 0x5b20));
    }
    else {
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


