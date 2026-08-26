/*
 * Decompiled function: FUN_004f8295
 * Entry Point: 004f8295
 * Size: 140 bytes
 */
#include "magic.h"


undefined4 FUN_004f8295(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  (&DAT_006a5f4c)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      FUN_00410cc0(arg_1,arg_2,DAT_006a2824,-1,-1);
      FUN_0040d7e9(arg_1,0,1);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


