/*
 * Decompiled function: Card_GaeasLiege_IsForest
 * Entry Point: 004d788d
 * Size: 69 bytes
 */
#include "magic.h"


undefined4 Card_GaeasLiege_IsForest(undefined4 arg_1,undefined4 arg_2,int arg_3)

{
  if (*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
      == arg_3) {
    g_ActivePalette = g_ActivePalette + 1;
  }
  return 0;
}


