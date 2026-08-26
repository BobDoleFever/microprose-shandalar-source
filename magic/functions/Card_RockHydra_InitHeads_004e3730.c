/*
 * Decompiled function: Card_RockHydra_InitHeads
 * Entry Point: 004e3730
 * Size: 91 bytes
 */
#include "magic.h"


undefined4 Card_RockHydra_InitHeads(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  
  if (((arg_3 == 0x34) && (g_OverworldMapGrid == arg_2)) && (arg_1 == g_OverworldPlayerCoordX)) {
    cVar1 = FUN_0041d9d2(arg_1,arg_2,4);
    g_ActivePalette = g_ActivePalette | 0x800 << (cVar1 - 1U & 0x1f);
  }
  return 0;
}


