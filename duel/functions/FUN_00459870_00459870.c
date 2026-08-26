/*
 * Decompiled function: FUN_00459870
 * Entry Point: 00459870
 * Size: 168 bytes
 */
#include "duel.h"


undefined4 FUN_00459870(int arg_1,int arg_2,int arg_3)

{
  int arg_4;
  undefined4 uVar1;
  
  arg_4 = FUN_0048c367((&DAT_004ff596)
                       [*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34]);
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f320 + arg_4 * 4 + arg_1 * 0x20) =
         *(int *)(&DAT_0068f320 + arg_4 * 4 + arg_1 * 0x20) + 2;
  }
  if (((arg_3 == 0x73) || (arg_3 == 0x6d)) || (arg_3 == 0x72)) {
    uVar1 = FUN_004593fd(arg_1,arg_2,arg_3,arg_4,1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


