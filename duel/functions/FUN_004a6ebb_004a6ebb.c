/*
 * Decompiled function: FUN_004a6ebb
 * Entry Point: 004a6ebb
 * Size: 126 bytes
 */
#include "duel.h"


undefined4 FUN_004a6ebb(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    if ((arg_1 == DAT_00666458) || (0x14 < DAT_0068f2c4)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (arg_3 == 0x71) {
      FUN_004a2b00(arg_1,arg_2,DAT_00666420,-1,-1);
      FUN_0046e571(arg_1,arg_2,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


