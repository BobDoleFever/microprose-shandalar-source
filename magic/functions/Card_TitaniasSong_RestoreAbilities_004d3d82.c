/*
 * Decompiled function: Card_TitaniasSong_RestoreAbilities
 * Entry Point: 004d3d82
 * Size: 125 bytes
 */
#include "magic.h"


undefined4 Card_TitaniasSong_RestoreAbilities(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x33) || (arg_3 == 0x32)) && (arg_2 == g_OverworldMapGrid)) &&
     (((arg_1 == g_OverworldPlayerCoordX &&
       (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 8) != 0)) &&
      (arg_1 != g_DefendingPlayer)))) {
    g_ActivePalette = g_ActivePalette + 2;
  }
  return 0;
}


