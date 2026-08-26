/*
 * Decompiled function: FUN_004a8b15
 * Entry Point: 004a8b15
 * Size: 92 bytes
 */
#include "duel.h"


undefined4 FUN_004a8b15(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      FUN_004a2b00(arg_1,arg_2,DAT_00666438,-1,-1);
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


