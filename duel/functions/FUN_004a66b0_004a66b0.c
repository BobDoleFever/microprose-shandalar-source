/*
 * Decompiled function: FUN_004a66b0
 * Entry Point: 004a66b0
 * Size: 210 bytes
 */
#include "duel.h"


undefined4 FUN_004a66b0(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if ((((arg_3 == 0x73) && (DAT_0068f2c4 == 10)) && (DAT_00681eb4 == arg_1)) &&
     ((*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0 && (DAT_0068f230 == -1)))) {
    DAT_00676500 = DAT_00676500 | 3;
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6d) {
      *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    }
    if (arg_3 == 0x72) {
      FUN_0046e571(DAT_00690af0,DAT_0068efa0,4);
      FUN_00487ce1(arg_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


