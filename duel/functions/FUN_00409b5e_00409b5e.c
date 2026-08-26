/*
 * Decompiled function: FUN_00409b5e
 * Entry Point: 00409b5e
 * Size: 347 bytes
 */
#include "duel.h"


undefined4 FUN_00409b5e(int x,int y,int width,int arg_4)

{
  undefined4 uVar1;
  
  if (width == 0x73) {
    if (((((&DAT_006826ce)[y * 0x120 + x * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) * 0x34] & 2) == 0)) &&
       (((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (width == 0x6d) {
      DAT_0068f2d4 = DAT_0068f2d4 + -0xc;
      FUN_0049b2c1(x,arg_4,1);
      *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) =
           *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) | 0x10;
      DAT_0068f0f4 = arg_4;
    }
    if ((((width == 0x7f) && (y == DAT_00690c48)) && (x == DAT_0068ecb0)) &&
       (((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      FUN_0049b1a9(x,arg_4,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


