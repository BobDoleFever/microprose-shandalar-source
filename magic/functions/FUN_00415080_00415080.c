/*
 * Decompiled function: FUN_00415080
 * Entry Point: 00415080
 * Size: 126 bytes
 */
#include "magic.h"


undefined4 FUN_00415080(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    if ((arg_1 == g_DefendingPlayer) || (0x14 < g_ScWillyScore)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (arg_3 == 0x71) {
      FUN_00410cc0(arg_1,arg_2,DAT_0068a658,-1,-1);
      Pic_Subsystem_0044867e(arg_1,arg_2,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


