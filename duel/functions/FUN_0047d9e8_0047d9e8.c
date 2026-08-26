/*
 * Decompiled function: FUN_0047d9e8
 * Entry Point: 0047d9e8
 * Size: 477 bytes
 */
#include "duel.h"


undefined4 FUN_0047d9e8(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if ((arg_3 == 0x71) && (DAT_0066aaf4 != 1)) {
    FUN_0048d00c(8);
  }
  if (arg_3 == 0x73) {
    if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0
        )))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0049b2c1(arg_1,6,3);
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_0068f0f4 = 6;
    }
    if (((arg_3 == 0x7f) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      if (((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0) ||
          (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) ==
           0)) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
        FUN_0049b1a9(arg_1,6,3);
      }
      *(uint *)(&DAT_0068f360 + arg_1 * 4) = *(uint *)(&DAT_0068f360 + arg_1 * 4) | 0x40;
    }
    uVar1 = 0;
  }
  return uVar1;
}


