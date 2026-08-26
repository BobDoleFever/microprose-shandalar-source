/*
 * Decompiled function: Card_GaeasLiege_ResetLand
 * Entry Point: 004d7724
 * Size: 87 bytes
 */
#include "magic.h"


undefined4 Card_GaeasLiege_ResetLand(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x32) || (arg_3 == 0x33)) && (arg_2 == g_OverworldMapGrid)) &&
     (arg_1 == g_OverworldPlayerCoordX)) {
    g_ActivePalette = g_ActivePalette + *(int *)(&DAT_006b3000 + (7 - arg_1) * 4);
  }
  return 0;
}


