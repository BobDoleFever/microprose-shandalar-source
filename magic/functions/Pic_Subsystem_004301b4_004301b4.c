/*
 * Decompiled function: Pic_Subsystem_004301b4
 * Entry Point: 004301b4
 * Size: 158 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_004301b4(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b3000 + (7 - arg_1) * 4) - (&DAT_006b3018)[arg_1]) * 0xc;
    }
    if (arg_3 == 0x22) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


