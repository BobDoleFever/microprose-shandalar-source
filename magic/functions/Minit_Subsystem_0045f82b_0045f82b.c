/*
 * Decompiled function: Minit_Subsystem_0045f82b
 * Entry Point: 0045f82b
 * Size: 1408 bytes
 */
#include "magic.h"


int Minit_Subsystem_0045f82b(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  int y;
  int height;
  int local_c;
  
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         ((&g_PlayerCreatureCount)[g_ActivePlayerPriority] -
         (&g_PlayerCreatureCount)[g_CurrentTurnPhase]) * 0x18;
  }
  if ((((g_PlayerManaPool == 0xc9) || (arg_3 == 199)) &&
      ((arg_2 == g_OverworldMapGrid &&
       ((arg_1 == g_OverworldPlayerCoordX && (arg_1 == g_DefendingPlayer)))))) &&
     ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)))) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      Card_IncrementCounter(arg_1,arg_2);
      Ai_Subsystem_004cc9c5(0,0x20);
    }
  }
  if (arg_3 == 0x73) {
    if ((((g_ScWillyScore == 4) && (iVar2 = Card_GetCounters(arg_1,arg_2), iVar2 != 0)) &&
        (iVar2 = FUN_0040d949(DAT_0063edc0,7,4), iVar2 != 0)) &&
       (((&g_CardSlot_ConvertedManaCost)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0)) {
      if (DAT_0063edc0 == g_CurrentTurnPhase) {
        local_c = 1;
      }
      else {
        if (((int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] <
             (int)(&g_PlayerCreatureCount)[g_CurrentTurnPhase]) ||
           (iVar2 = Card_GetCounters(arg_1,arg_2),
           (int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] < iVar2)) {
          local_c = 1;
        }
        else {
          local_c = 0;
        }
        if (local_c != 0) {
          DAT_006a4920 = DAT_006a4920 | 3;
        }
      }
    }
    else {
      local_c = 0;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
      *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) != -1)) {
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) = 0;
      if (((int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] <
           (int)(&g_PlayerCreatureCount)[g_CurrentTurnPhase]) ||
         (iVar2 = Card_GetCounters(arg_1,arg_2),
         (int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] < iVar2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (((g_IsAiThinking != 1) && (DAT_006fedc0 == 0)) && (DAT_0063edc0 != 1)) {
        bVar1 = true;
      }
      if (bVar1) {
        Ai_CalcManaRequirement_004ba890(DAT_0063edc0,0,4);
        if (g_ActivePlayer == 1) {
          g_ActivePlayer = -1;
        }
        else {
          Card_DecrementCounter(g_DialogPromptHwnd,g_DuelArenaHwnd);
        }
      }
    }
    if (((g_PlayerManaPool == 0xcb) || (arg_3 == 199)) &&
       ((((arg_2 == g_OverworldMapGrid &&
          ((arg_1 == g_OverworldPlayerCoordX && (arg_1 == g_DefendingPlayer)))) &&
         (DAT_006a4b5c == arg_1)) &&
        (((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)) &&
         (iVar2 = Card_GetCounters(arg_1,arg_2), iVar2 != 0)))))) {
      if (arg_3 == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        iVar2 = arg_1;
        height = arg_2;
        y = Card_GetCounters(arg_1,arg_2);
        Mem_AllocOrFree_0041df33(g_DefendingPlayer,y,iVar2,height);
        iVar2 = Card_GetCounters(arg_1,arg_2);
        Mem_AllocOrFree_0041df33(1 - g_DefendingPlayer,iVar2,arg_1,arg_2);
      }
    }
    local_c = 0;
  }
  return local_c;
}


