/*
 * Decompiled function: Pic_Subsystem_0043c0b2
 * Entry Point: 0043c0b2
 * Size: 194 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043c0b2(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 0x33) && (g_OverworldPlayerCoordX == arg_1)) &&
        (((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] & 0x14)
         == 0)) &&
       ((((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x20) == 0 &&
        (((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] & 2) !=
         0)))) {
      g_ActivePalette = g_ActivePalette + 2;
    }
    uVar1 = 0;
  }
  return uVar1;
}


