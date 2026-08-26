/*
 * Decompiled function: Card_NettlingImp_CheckEndTurn
 * Entry Point: 004db401
 * Size: 1224 bytes
 */
#include "magic.h"


bool Card_NettlingImp_CheckEndTurn(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    iVar2 = Card_GetCounters(arg_1,arg_2);
    bVar1 = 1 < iVar2;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar2 = Card_GetCounters(arg_1,arg_2), 1 < iVar2)) {
      *(int *)(&g_CardSlot_CombatTarget + arg_1 * 0x5b20 + arg_2 * 0x120) = arg_1;
      *(int *)(&g_CardSlot_AttachedAura + arg_1 * 0x5b20 + arg_2 * 0x120) = arg_2;
      (&g_CardSlot_TurnPlayed)[arg_1 * 0x5b20 + arg_2 * 0x120] = 1;
      if (*(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) == 0) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x80000;
      }
      Card_RemoveCounters(arg_1,arg_2,2);
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) ==
          -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                *(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20) + 1;
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                *(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20) +
             0x100;
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
            *(undefined2 *)(&DAT_006a5f48 + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(undefined2 *)(&DAT_006a5f4a + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (((((g_PlayerManaPool == 0xcd) || (arg_3 == 199)) && (g_OverworldMapGrid == arg_2)) &&
        ((g_OverworldPlayerCoordX == arg_1 && (DAT_006b303c != 0)))) && (DAT_006a4b5c == arg_1)) {
      if (arg_3 == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        Card_IncrementCounter(arg_1,arg_2);
      }
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
    }
    bVar1 = false;
  }
  return bVar1;
}


