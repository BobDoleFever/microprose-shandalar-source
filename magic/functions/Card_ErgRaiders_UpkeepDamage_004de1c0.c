/*
 * Decompiled function: Card_ErgRaiders_UpkeepDamage
 * Entry Point: 004de1c0
 * Size: 414 bytes
 */
#include "magic.h"


undefined4 Card_ErgRaiders_UpkeepDamage(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 199) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) &&
     ((arg_1 == g_DefendingPlayer &&
      ((*(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x30044) == 0)))) {
    if ((arg_1 == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
      Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Erg_Raiders_take_2_life__0052ec90,0);
    }
    Mem_AllocOrFree_0041df33(arg_1,2,arg_1,arg_2);
  }
  if (((g_PlayerManaPool == 0xcd) && (arg_2 == g_OverworldMapGrid)) &&
     ((arg_1 == g_OverworldPlayerCoordX &&
      (((arg_1 == g_DefendingPlayer && (arg_1 == DAT_006a4b5c)) &&
       ((*(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x30044) == 0)))))) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x7e) {
      if ((arg_1 == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
        Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Erg_Raiders_take_2_life__0052ecac,0);
      }
      Mem_AllocOrFree_0041df33(arg_1,2,arg_1,arg_2);
    }
  }
  return 0;
}


