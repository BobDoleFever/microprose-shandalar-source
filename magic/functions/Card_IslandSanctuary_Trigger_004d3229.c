/*
 * Decompiled function: Card_IslandSanctuary_Trigger
 * Entry Point: 004d3229
 * Size: 99 bytes
 */
#include "magic.h"


undefined4 Card_IslandSanctuary_Trigger(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x78) && (arg_2 == DAT_006b2d5c)) && (arg_1 == DAT_007006c8)) {
    iVar1 = FUN_00473179(g_OverworldPlayerCoordX,g_OverworldMapGrid,0x32,0xffffffff);
    if (2 < iVar1) {
      g_ActivePalette = 1;
    }
  }
  return 0;
}


