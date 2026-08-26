/*
 * Decompiled function: Card_PirateShip_CheckIslandwalk
 * Entry Point: 004dfe94
 * Size: 244 bytes
 */
#include "magic.h"


undefined4 Card_PirateShip_CheckIslandwalk(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int arg1;
  int iVar2;
  int local_8;
  
  if ((arg_3 == 0x1a) && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) {
    bVar1 = true;
    arg1 = 1 - arg_1;
    for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[arg1]; local_8 = local_8 + 1) {
      iVar2 = FUN_00471c32(arg1,local_8);
      if ((iVar2 != 0) && ((char)(&g_CardSlot_ColorMask)[local_8 * 0x120 + arg1 * 0x5b20] == arg_2))
      {
        bVar1 = false;
        break;
      }
    }
    if (bVar1) {
      (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] + 2;
    }
  }
  Card_PirateShip_HasIsland(arg_1,arg_2,arg_3);
  return 0;
}


