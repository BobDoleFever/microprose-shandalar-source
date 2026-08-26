/*
 * Decompiled function: FUN_0047a090
 * Entry Point: 0047a090
 * Size: 494 bytes
 */
#include "duel.h"


undefined4 FUN_0047a090(int x,int y,int width,int height)

{
  undefined4 uVar1;
  
  if ((width == 0x71) && (DAT_0066aaf4 != 1)) {
    FUN_0048d00c(height + 8);
  }
  if (width == 0x73) {
    if ((((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[y * 0x120 + x * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) * 0x34] & 2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (width == 0x6d) {
      FUN_0049b2c1(x,height,1);
      *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) =
           *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) | 0x10;
      DAT_0068f0f4 = height;
    }
    if (((width == 0x7f) && (DAT_00690c48 == y)) && (x == DAT_0068ecb0)) {
      if (((((&DAT_006826ce)[y * 0x120 + x * 0x5b20] & 3) == 0) ||
          (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) * 0x34] & 2) == 0)) &&
         (((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
        FUN_0049b1a9(x,height,1);
      }
      *(uint *)(&DAT_0068f360 + x * 4) =
           *(uint *)(&DAT_0068f360 + x * 4) | 1 << ((byte)height & 0x1f);
    }
    uVar1 = 0;
  }
  return uVar1;
}


