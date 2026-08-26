/*
 * Decompiled function: FUN_004ad687
 * Entry Point: 004ad687
 * Size: 158 bytes
 */
#include "duel.h"


undefined4 FUN_004ad687(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      if ((int)(&DAT_0068ee78)[arg_1] < 8) {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x3c;
      }
      else {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
      }
    }
    if (arg_3 == 0x71) {
      FUN_0049b235(arg_1,1,3);
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


