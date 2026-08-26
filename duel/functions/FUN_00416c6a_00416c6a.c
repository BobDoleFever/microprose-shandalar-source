/*
 * Decompiled function: FUN_00416c6a
 * Entry Point: 00416c6a
 * Size: 537 bytes
 */
#include "duel.h"


undefined4 FUN_00416c6a(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_3 == 0x6c) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 + (*(int *)(&DAT_0068ed2c + DAT_00676504 * 0x20) * 3 + -6) * 4;
  }
  if (param_3 == 0x73) {
    iVar1 = FUN_0049b309(param_1,7,3);
    if (((iVar1 == 0) ||
        ((((&DAT_006826ce)[param_1 * 0x5b20 + param_2 * 0x120] & 3) != 0 &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x34] & 2)
          != 0)))) || (((&DAT_006826cc)[param_1 * 0x5b20 + param_2 * 0x120] & 0x10) != 0)) {
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
    if ((param_3 == 0x6d) && (FUN_0042b6b0(param_1,0,3), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f2b44,s_ROD_OF_RUIN_004f2b38);
      FUN_00461047(param_1,param_2,1);
      if (DAT_00681ea4 != 1) {
        *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
             *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      FUN_004612b0(param_1,param_2,0x72,1);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


