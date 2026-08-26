/*
 * Decompiled function: Card_IslandFishJasconius_DestroyIfNoIslands
 * Entry Point: 004e04be
 * Size: 194 bytes
 */
#include "magic.h"


undefined4 Card_IslandFishJasconius_DestroyIfNoIslands(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (arg_3 == 0x79) {
    iVar1 = FUN_0041d963(arg_1,arg_2,4);
    if (*(int *)(&DAT_0063ee30 + iVar1 * 4 + (1 - arg_1) * 0x20) == 0) {
      g_ActivePalette = 1;
    }
  }
  if ((arg_3 == 0x1a) && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) {
    FUN_00410cc0(arg_1,arg_2,DAT_00695df4,arg_1,arg_2);
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  return 0;
}


