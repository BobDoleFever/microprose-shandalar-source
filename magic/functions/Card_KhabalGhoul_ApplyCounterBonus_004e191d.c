/*
 * Decompiled function: Card_KhabalGhoul_ApplyCounterBonus
 * Entry Point: 004e191d
 * Size: 270 bytes
 */
#include "magic.h"


undefined4 Card_KhabalGhoul_ApplyCounterBonus(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x85) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) &&
     ((arg_1 == g_DefendingPlayer && (arg_1 == DAT_0063edc0)))) {
    *(uint *)(&g_CardSlot_SpecialState + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&g_CardSlot_SpecialState + arg_1 * 0x5b20 + arg_2 * 0x120) | 1;
    (&DAT_006a6049)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (&DAT_006a6049)[arg_1 * 0x5b20 + arg_2 * 0x120] + '\x02';
  }
  if (arg_3 == 0x86) {
    Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
  }
  if ((arg_3 == 199) && ((int)(&DAT_0063ee34)[arg_1 * 8] < 2)) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}


