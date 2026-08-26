/*
 * Decompiled function: Card_TitaniasSong_RemoveAbilities
 * Entry Point: 004d3d1d
 * Size: 101 bytes
 */
#include "magic.h"


undefined4 Card_TitaniasSong_RemoveAbilities(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x33) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) &&
     (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
    g_ActivePalette = g_ActivePalette + 3;
  }
  return 0;
}


