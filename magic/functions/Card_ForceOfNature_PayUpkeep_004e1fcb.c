/*
 * Decompiled function: Card_ForceOfNature_PayUpkeep
 * Entry Point: 004e1fcb
 * Size: 310 bytes
 */
#include "magic.h"


undefined4 Card_ForceOfNature_PayUpkeep(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x85) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) &&
     ((arg_1 == g_DefendingPlayer && (DAT_0063edc0 == arg_1)))) {
    *(uint *)(&g_CardSlot_SpecialState + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&g_CardSlot_SpecialState + arg_1 * 0x5b20 + arg_2 * 0x120) | 1;
    (&DAT_006a604b)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (&DAT_006a604b)[arg_1 * 0x5b20 + arg_2 * 0x120] + '\x04';
  }
  if (arg_3 == 0x86) {
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Force_of_Nature_deals_8_damage__0052ee28,0);
    Mem_AllocOrFree_0041df33(arg_1,8,g_DialogPromptHwnd,g_DuelArenaHwnd);
  }
  if ((arg_3 == 199) && (*(int *)(&DAT_0063ee3c + arg_1 * 0x20) < 4)) {
    Mem_AllocOrFree_0041df33(arg_1,8,arg_1,arg_2);
  }
  return 0;
}


