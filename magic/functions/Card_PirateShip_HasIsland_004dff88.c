/*
 * Decompiled function: Card_PirateShip_HasIsland
 * Entry Point: 004dff88
 * Size: 175 bytes
 */
#include "magic.h"


undefined4 Card_PirateShip_HasIsland(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0) {
    iVar1 = FUN_0041d963(arg_1,arg_2,2);
    if (*(int *)(&DAT_0063ee30 + iVar1 * 4 + arg_1 * 0x20) == 0) {
      Pic_Subsystem_0044867e(arg_1,arg_2,2);
    }
  }
  if (arg_3 == 0x79) {
    iVar1 = FUN_0041d963(arg_1,arg_2,2);
    if (*(int *)(&DAT_0063ee30 + iVar1 * 4 + (1 - arg_1) * 0x20) == 0) {
      g_ActivePalette = 1;
    }
  }
  return 0;
}


