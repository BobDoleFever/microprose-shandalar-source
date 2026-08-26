/*
 * Decompiled function: Pic_Subsystem_004485d6
 * Entry Point: 004485d6
 * Size: 168 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_004485d6(int x,int y,int width,undefined4 arg_4)

{
  undefined4 uVar1;
  
  if ((width == 0x7d) &&
     ((((&DAT_006a5f3d)[y * 0x120 + x * 0x5b20] & 1) != 0 || (DAT_0068078c != 0)))) {
    uVar1 = 0;
  }
  else if (g_PlayerManaPool < 200) {
    uVar1 = 0;
  }
  else {
    g_ActivePalette = 0;
    g_OverworldPlayerCoordX = x;
    g_OverworldMapGrid = y;
    _DAT_006b2fe8 = arg_4;
    DAT_006b2d5c = 0xffffffff;
    Magic_ScanCards(width);
    uVar1 = g_ActivePalette;
  }
  return uVar1;
}


