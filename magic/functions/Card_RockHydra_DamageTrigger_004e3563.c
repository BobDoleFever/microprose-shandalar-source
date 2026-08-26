/*
 * Decompiled function: Card_RockHydra_DamageTrigger
 * Entry Point: 004e3563
 * Size: 129 bytes
 */
#include "magic.h"


undefined4 Card_RockHydra_DamageTrigger(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  char cVar2;
  
  if (((arg_3 == 0x34) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    cVar2 = FUN_0041d9d2(arg_1,arg_2,5);
    g_ActivePalette = g_ActivePalette | 0x800 << (cVar2 - 1U & 0x1f);
    uVar1 = g_ActivePalette;
    Card_RockHydra_UpdateStatsFromHeads(arg_1,arg_2,5);
    g_ActivePalette = uVar1;
  }
  return 0;
}


