/*
 * Decompiled function: Card_DragonWhelp_EndTurnCheck
 * Entry Point: 004d5c1e
 * Size: 1907 bytes
 */
#include "magic.h"


int Card_DragonWhelp_EndTurnCheck(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int arg_2_00;
  int arg_3_00;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_006ff6a0 + arg_1 * 0x20) = *(int *)(&DAT_006ff6a0 + arg_1 * 0x20) + 1;
  }
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  if (arg_3 == 0x73) {
    iVar2 = FUN_0040d949(arg_1,4,1);
  }
  else if (arg_3 == 0x90) {
    Ai_CalcLifeAdvantage(0);
    iVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) &&
       (iVar2 = FUN_0040d949(arg_1,4,1), uVar1 = g_OverworldPlayerCoordY, iVar2 != 0)) {
      g_TurnCounter = 0;
      if (arg_1 == g_DefendingPlayer) {
        if (((arg_1 == g_ActivePlayerPriority) ||
            ((*(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff0000) ==
             0x30000)) || (DAT_00627864 != 1)) {
          g_OverworldPlayerCoordY = -1;
        }
        else {
          g_OverworldPlayerCoordY =
               3 - ((*(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff0000)
                   >> 0x10);
        }
        Ai_CalcManaRequirement_004ba890(arg_1,4,-1);
        g_OverworldPlayerCoordY = uVar1;
        if (g_TurnCounter < 1) {
          g_ActivePlayer = 1;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,4,1);
        g_TurnCounter = 1;
      }
      *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff0000;
      if (g_ActivePlayer == 1) {
        *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
      else {
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
            *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      arg_3_00 = 3;
      arg_2_00 = 0;
      iVar2 = FUN_0040d949(arg_1,4,1);
      iVar2 = FUN_0040a305(iVar2,arg_2_00,arg_3_00);
      iVar2 = iVar2 - *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    else {
      if (((((g_PlayerManaPool == 0xcd) || (arg_3 == 199)) && (arg_2 == g_OverworldMapGrid)) &&
          ((arg_1 == g_OverworldPlayerCoordX &&
           ((&g_CardSlot_ConvertedManaCost)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\0')))) &&
         (arg_1 == DAT_006a4b5c)) {
        if (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) < 4) {
          *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(undefined4 *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20);
        }
        else {
          if (arg_3 == 0x7d) {
            g_ActivePalette = g_ActivePalette | 2;
          }
          if ((arg_3 == 0x7e) || (arg_3 == 199)) {
            Pic_Subsystem_0044867e(arg_1,arg_2,2);
          }
        }
      }
      if (arg_3 == 199) {
        if (arg_1 == g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_0063ee40 + arg_1 * 0x20) * 0xc;
        }
        else {
          g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_0063ee40 + arg_1 * 0x20) * -0xc;
        }
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}


