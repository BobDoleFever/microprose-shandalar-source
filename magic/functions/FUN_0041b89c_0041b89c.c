/*
 * Decompiled function: FUN_0041b89c
 * Entry Point: 0041b89c
 * Size: 158 bytes
 */
#include "magic.h"


undefined4 FUN_0041b89c(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if ((int)(&DAT_006b3008)[arg_1] < 8) {
        g_SpellStackDepth = g_SpellStackDepth + -0x3c;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
    if (arg_3 == 0x71) {
      FUN_0040d875(arg_1,1,3);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


