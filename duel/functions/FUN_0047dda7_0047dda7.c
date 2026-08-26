/*
 * Decompiled function: FUN_0047dda7
 * Entry Point: 0047dda7
 * Size: 339 bytes
 */
#include "duel.h"


undefined4 FUN_0047dda7(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 1) {
    uVar1 = FUN_0047a090(arg_1,arg_2,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0) &&
       ((((&DAT_006826ce)[arg_1 * 0x5b20 + arg_2 * 0x120] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] & 2) == 0
        )))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0049b235(arg_1,0,1);
      *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
      DAT_0068f0f4 = 0;
      DAT_00692c70 = 0;
      FUN_00467d65(FUN_0047dd22,arg_1);
      if (DAT_00692c70 == 7) {
        FUN_0049b235(arg_1,0,2);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


