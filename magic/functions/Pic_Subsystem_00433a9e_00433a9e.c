/*
 * Decompiled function: Pic_Subsystem_00433a9e
 * Entry Point: 00433a9e
 * Size: 229 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00433a9e(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_006b3010 + arg_1 * 4) * 0xc;
    }
    if (((arg_3 == 0x32) &&
        (((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] & 4) !=
         0)) && ((arg_1 == g_DefendingPlayer &&
                 ((g_OverworldPlayerCoordX == arg_1 &&
                  (((byte)*(undefined4 *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x22
                   ) == 2)))))) {
      g_ActivePalette = g_ActivePalette + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


