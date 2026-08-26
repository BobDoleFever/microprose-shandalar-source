/*
 * Decompiled function: Card_MarrowThieves_Regenerate
 * Entry Point: 004d94e1
 * Size: 1564 bytes
 */
#include "magic.h"


undefined4 Card_MarrowThieves_Regenerate(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_006ff698 + arg_1 * 0x20) = *(int *)(&DAT_006ff698 + arg_1 * 0x20) + 1;
  }
  if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  if (arg_3 == 0x73) {
    uVar1 = FUN_0040d949(arg_1,2,1);
  }
  else if (arg_3 == 0x90) {
    Ai_CalcLifeAdvantage(0);
    uVar1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar2 = FUN_0040d949(arg_1,2,1), iVar2 != 0)) {
      if (g_DefendingPlayer == arg_1) {
        Ai_CalcManaRequirement_004ba890(arg_1,2,-1);
        if (g_TurnCounter < 1) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = g_TurnCounter;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,2,1);
        *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      if (g_ActivePlayer == 1) {
        *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        if (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
          *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) ==
          -1) {
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
        [*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        if (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
              *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 8) !=
            0) {
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
      uVar1 = FUN_0040d949(arg_1,2,1);
    }
    else {
      if ((arg_3 == 0x8f) && (*(int *)(&DAT_0063ee98 + arg_1 * 0x20) != 0)) {
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (arg_3 == 199) {
        if (g_ActivePlayerPriority == arg_1) {
          g_SpellStackDepth = g_SpellStackDepth + (&DAT_0063ee38)[arg_1 * 8] * 0xc;
        }
        else {
          g_SpellStackDepth = g_SpellStackDepth + (&DAT_0063ee38)[arg_1 * 8] * -0xc;
        }
      }
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


