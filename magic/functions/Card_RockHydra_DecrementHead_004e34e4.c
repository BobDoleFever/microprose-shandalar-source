/*
 * Decompiled function: Card_RockHydra_DecrementHead
 * Entry Point: 004e34e4
 * Size: 127 bytes
 */
#include "magic.h"


undefined4 Card_RockHydra_DecrementHead(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  char cVar2;
  
  if (((arg_3 == 0x34) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    cVar2 = FUN_0041d9d2(arg_1,arg_2,1);
    g_ActivePalette = g_ActivePalette | 0x800 << (cVar2 - 1U & 0x1f);
    uVar1 = g_ActivePalette;
    Card_RockHydra_UpdateStatsFromHeads(arg_1,arg_2,1);
    g_ActivePalette = uVar1;
  }
  return 0;
}


