/*
 * Decompiled function: FUN_00416a4b
 * Entry Point: 00416a4b
 * Size: 543 bytes
 */
#include "duel.h"


undefined4 FUN_00416a4b(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
    DAT_0068f2d4 = DAT_0068f2d4 + 0x60;
  }
  if (param_3 == 0x73) {
    iVar1 = FUN_0049b309(param_1,7,8);
    if (((iVar1 == 0) ||
        ((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) != 0 &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
          != 0)))) || (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(1);
    uVar2 = 0;
  }
  else {
    if (((param_3 == 0x6d) && (iVar1 = FUN_0049b309(param_1,7,8), iVar1 != 0)) &&
       (FUN_0042b6b0(param_1,0,8), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f2b2c,s_ALADDIN_RING_004f2b1c);
      FUN_00461047(param_1,param_2,4);
      if (DAT_00681ea4 != 1) {
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      FUN_004612b0(param_1,param_2,0x72,4);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


