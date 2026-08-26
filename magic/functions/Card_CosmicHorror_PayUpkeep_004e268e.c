/*
 * Decompiled function: Card_CosmicHorror_PayUpkeep
 * Entry Point: 004e268e
 * Size: 435 bytes
 */
#include "magic.h"


undefined4 Card_CosmicHorror_PayUpkeep(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x85) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) &&
     ((arg_1 == g_DefendingPlayer && (DAT_0063edc0 == arg_1)))) {
    *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    (&DAT_006a6049)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006a6049)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x03';
    (&DAT_006a6048)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006a6048)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x03';
  }
  if (arg_3 == 0x86) {
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Cosmic_Horror_deals_7_damage__0052ee7c,0);
    Mem_AllocOrFree_0041df33(arg_1,7,g_DialogPromptHwnd,g_DuelArenaHwnd);
    Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
  }
  if ((arg_3 == 199) &&
     (((int)(&DAT_0063ee34)[arg_1 * 8] < 3 || (*(int *)(&DAT_0063ee4c + arg_1 * 0x20) < 6)))) {
    Mem_AllocOrFree_0041df33(arg_1,7,arg_1,arg_2);
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}


