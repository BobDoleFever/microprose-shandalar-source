/*
 * Decompiled function: Minit_Subsystem_00464723
 * Entry Point: 00464723
 * Size: 1029 bytes
 */
#include "magic.h"


int Minit_Subsystem_00464723(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  if (arg_3 == 0x73) {
    iVar1 = FUN_0040d949(arg_1,7,2);
  }
  else if (arg_3 == 0x90) {
    DAT_0062785c = 2;
    iVar1 = 0;
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,7,2), iVar1 != 0)) &&
       ((Ai_CalcManaRequirement_004ba890(arg_1,0,2), g_ActivePlayer != 1 &&
        (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)))) {
      *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) + 1;
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
          iVar1 = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,g_DialogPromptHwnd,
                               g_DuelArenaHwnd);
          if (iVar1 != -1) {
            *(undefined2 *)(&DAT_006a5f48 + iVar1 * 0x120 + arg_1 * 0x5b20) = 1;
            *(uint *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + arg_1 * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      iVar1 = *(int *)(&DAT_0063edec + arg_1 * 0x20) / 2;
    }
    else {
      if ((arg_3 == 0x8f) && (1 < *(int *)(&DAT_0063eeac + arg_1 * 0x20))) {
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (arg_3 == 199) {
        if (arg_1 == g_ActivePlayerPriority) {
          g_SpellStackDepth =
               g_SpellStackDepth + ((*(int *)(&DAT_0063ee4c + arg_1 * 0x20) / 2) * 3 + 3) * 4;
        }
        else {
          g_SpellStackDepth =
               g_SpellStackDepth + ((*(int *)(&DAT_0063ee4c + arg_1 * 0x20) / 2) * 3 + 3) * -4;
        }
      }
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}


