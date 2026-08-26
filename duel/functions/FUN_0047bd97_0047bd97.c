/*
 * Decompiled function: FUN_0047bd97
 * Entry Point: 0047bd97
 * Size: 310 bytes
 */
#include "duel.h"


undefined4 FUN_0047bd97(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int local_8;
  
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
      FUN_00487ce1(arg_1);
      FUN_00487ce1(arg_1);
      for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
        if (0 < (int)(&DAT_0068ee78)[arg_1]) {
          Palette_Color_0049ae00(arg_1,0,0);
        }
      }
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    uVar1 = 0;
  }
  return uVar1;
}


