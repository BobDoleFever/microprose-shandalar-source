/*
 * Decompiled function: Card_IslandSanctuary_CheckActive
 * Entry Point: 004d328c
 * Size: 158 bytes
 */
#include "magic.h"


undefined4 Card_IslandSanctuary_CheckActive(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  
  if ((((arg_3 == 0x78) && (arg_2 == DAT_006b2d5c)) && (arg_1 == DAT_007006c8)) &&
     ((&DAT_0051aebd)
      [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
       * 0x34] != '\0')) {
    uVar1 = FUN_00473179(g_OverworldPlayerCoordX,g_OverworldMapGrid,0x34,0xffffffff);
    if ((uVar1 & 0x20) == 0) {
      g_ActivePalette = 1;
    }
  }
  return 0;
}


