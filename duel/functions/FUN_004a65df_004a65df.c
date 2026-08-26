/*
 * Decompiled function: FUN_004a65df
 * Entry Point: 004a65df
 * Size: 189 bytes
 */
#include "duel.h"


undefined4 FUN_004a65df(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (((arg_3 == 0x72) || (arg_3 == 0x86)) || (arg_3 == 0x7e)) {
    DAT_00690af0 = *(undefined4 *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20);
    DAT_0068efa0 = *(undefined4 *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20);
    uVar1 = (**(code **)(&DAT_004ff5a0 +
                        *(int *)(&DAT_006826c0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34))
                      (arg_1,arg_2,arg_3);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


