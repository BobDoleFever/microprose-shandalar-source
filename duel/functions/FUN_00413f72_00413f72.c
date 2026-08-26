/*
 * Decompiled function: FUN_00413f72
 * Entry Point: 00413f72
 * Size: 412 bytes
 */
#include "duel.h"


undefined4 FUN_00413f72(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 +
                   (int)(0xc0 / (longlong)(*(int *)(&DAT_0068ef6c + DAT_00676504 * 0x20) + 1));
  }
  if (arg_3 == 0x73) {
    if (((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0
        )) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      DAT_0068f2d4 = DAT_0068f2d4 + -0xc;
      FUN_0049b2c1(arg_1,0,2);
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_0068f0f4 = 0;
    }
    if (((arg_3 == 0x7f) && (arg_2 == DAT_00690c48)) &&
       ((arg_1 == DAT_0068ecb0 && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0))))
    {
      FUN_0049b1a9(arg_1,0,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


