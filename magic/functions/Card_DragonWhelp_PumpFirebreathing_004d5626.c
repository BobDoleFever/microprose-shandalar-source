/*
 * Decompiled function: Card_DragonWhelp_PumpFirebreathing
 * Entry Point: 004d5626
 * Size: 1528 bytes
 */
#include "magic.h"


undefined4 Card_DragonWhelp_PumpFirebreathing(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_006ff6a0 + arg_1 * 0x20) = *(int *)(&DAT_006ff6a0 + arg_1 * 0x20) + 1;
  }
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    *(undefined4 *)(&g_CardSlot_TargetSlot + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(undefined4 *)(&g_CardSlot_TargetSlot + arg_1 * 0x5b20 + arg_2 * 0x120);
  }
  if (arg_3 == 0x73) {
    uVar1 = FUN_0040d949(arg_1,4,1);
  }
  else if (arg_3 == 0x90) {
    Ai_CalcLifeAdvantage(0);
    uVar1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar2 = FUN_0040d949(arg_1,4,1), iVar2 != 0)) {
      if (arg_1 == g_DefendingPlayer) {
        Ai_CalcManaRequirement_004ba890(arg_1,4,-1);
        if (g_TurnCounter < 1) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_TargetSlot + arg_1 * 0x5b20 + arg_2 * 0x120) = g_TurnCounter;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,4,1);
        *(undefined4 *)(&g_CardSlot_TargetSlot + arg_1 * 0x5b20 + arg_2 * 0x120) = 1;
      }
      if (g_ActivePlayer == 1) {
        *(undefined4 *)(&g_CardSlot_TargetSlot + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + arg_1 * 0x5b20 + arg_2 * 0x120) = arg_1;
        *(int *)(&g_CardSlot_AttachedAura + arg_1 * 0x5b20 + arg_2 * 0x120) = arg_2;
        (&g_CardSlot_TurnPlayed)[arg_1 * 0x5b20 + arg_2 * 0x120] = 1;
        if (*(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) == 0) {
          *(uint *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) =
               *(uint *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x80000;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) ==
          -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20) +
             (*(uint *)(&g_CardSlot_TargetSlot + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xff);
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120] = 0;
        if (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
              *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120] & 8) !=
            0) {
          *(uint *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20) =
               *(uint *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120
                        + *(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20)
               & 0xfff7ffff;
          iVar2 = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,g_DialogPromptHwnd,
                               g_DuelArenaHwnd);
          if (iVar2 != -1) {
            *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      uVar1 = FUN_0040d949(arg_1,4,1);
    }
    else {
      if ((arg_3 == 0x8f) && (*(int *)(&DAT_0063eea0 + arg_1 * 0x20) != 0)) {
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (arg_3 == 199) {
        if (arg_1 == g_ActivePlayerPriority) {
          g_SpellStackDepth =
               g_SpellStackDepth + (*(int *)(&DAT_0063ee40 + arg_1 * 0x20) * 3 + 3) * 4;
        }
        else {
          g_SpellStackDepth =
               g_SpellStackDepth + (*(int *)(&DAT_0063ee40 + arg_1 * 0x20) * 3 + 3) * -4;
        }
      }
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        *(undefined4 *)(&g_CardSlot_TargetSlot + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(undefined4 *)(&g_CardSlot_TargetSlot + arg_1 * 0x5b20 + arg_2 * 0x120);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


