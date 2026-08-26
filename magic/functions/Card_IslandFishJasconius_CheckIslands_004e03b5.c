/*
 * Decompiled function: Card_IslandFishJasconius_CheckIslands
 * Entry Point: 004e03b5
 * Size: 265 bytes
 */
#include "magic.h"


undefined4 Card_IslandFishJasconius_CheckIslands(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_00471c32(g_OverworldPlayerCoordX,g_OverworldMapGrid);
  if ((iVar2 != 0) &&
     ((&DAT_0051aebd)
      [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
       * 0x34] == '\x01')) {
    if (arg_3 == 0x34) {
      cVar1 = FUN_0041d963(arg_1,arg_2,2);
      g_ActivePalette = g_ActivePalette | 1 << (cVar1 - 1U & 0x1f);
    }
    if ((arg_3 == 0x32) || (arg_3 == 0x33)) {
      g_ActivePalette = g_ActivePalette + 1;
    }
    if ((arg_3 == 0x77) && (((&g_CardSlot_Abilities1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x80) != 0))
    {
      *(uint *)(&g_CardSlot_Abilities2 +
               g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 +
                    g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) | 0xe000000;
    }
  }
  return 0;
}


