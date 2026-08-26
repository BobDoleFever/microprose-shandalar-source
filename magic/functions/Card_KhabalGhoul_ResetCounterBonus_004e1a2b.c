/*
 * Decompiled function: Card_KhabalGhoul_ResetCounterBonus
 * Entry Point: 004e1a2b
 * Size: 269 bytes
 */
#include "magic.h"


undefined4 Card_KhabalGhoul_ResetCounterBonus(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x85) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) &&
     ((arg_1 == g_DefendingPlayer && (DAT_0063edc0 == arg_1)))) {
    *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    (&DAT_006a604a)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006a604a)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x01';
  }
  if (arg_3 == 0x86) {
    Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
  }
  if ((arg_3 == 199) && ((int)(&DAT_0063ee38)[arg_1 * 8] < 1)) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}


