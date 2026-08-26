/*
 * Decompiled function: Minit_Subsystem_00456dce
 * Entry Point: 00456dce
 * Size: 347 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00456dce(int x,int y,int width,int height)

{
  undefined4 uVar1;
  
  if (width == 0x73) {
    if (((((&DAT_006a5f3e)[y * 0x120 + x * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] &
         2) == 0)) && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (width == 0x6d) {
      g_SpellStackDepth = g_SpellStackDepth + -0xc;
      FUN_0040d901(x,height,1);
      *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
      DAT_006ff2d4 = height;
    }
    if ((((width == 0x7f) && (y == g_OverworldMapGrid)) && (x == g_OverworldPlayerCoordX)) &&
       (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      FUN_0040d7e9(x,height,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


