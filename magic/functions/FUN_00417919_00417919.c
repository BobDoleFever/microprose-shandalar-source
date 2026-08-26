/*
 * Decompiled function: FUN_00417919
 * Entry Point: 00417919
 * Size: 139 bytes
 */
#include "magic.h"


undefined4 FUN_00417919(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((arg_3 == 0x32) &&
       (((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] & 4) !=
        0)) {
      g_ActivePalette = g_ActivePalette + 2;
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


