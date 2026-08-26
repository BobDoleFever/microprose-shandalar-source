/*
 * Decompiled function: FUN_004028e4
 * Entry Point: 004028e4
 * Size: 140 bytes
 */
#include "duel.h"


undefined4 FUN_004028e4(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  (&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      FUN_004a2b00(arg_1,arg_2,DAT_0066aac8,-1,-1);
      FUN_0049b1a9(arg_1,0,1);
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


