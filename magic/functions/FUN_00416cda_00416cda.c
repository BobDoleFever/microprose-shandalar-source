/*
 * Decompiled function: FUN_00416cda
 * Entry Point: 00416cda
 * Size: 92 bytes
 */
#include "magic.h"


undefined4 FUN_00416cda(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      FUN_00410cc0(arg_1,arg_2,DAT_0068a670,-1,-1);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


