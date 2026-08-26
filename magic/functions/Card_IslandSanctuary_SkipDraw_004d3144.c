/*
 * Decompiled function: Card_IslandSanctuary_SkipDraw
 * Entry Point: 004d3144
 * Size: 101 bytes
 */
#include "magic.h"


undefined4 Card_IslandSanctuary_SkipDraw(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x78) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    iVar1 = FUN_00473179(DAT_007006c8,DAT_006b2d5c,0x32,arg_2);
    if (1 < iVar1) {
      g_ActivePalette = 1;
    }
  }
  return 0;
}


