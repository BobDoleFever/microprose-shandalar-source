/*
 * Decompiled function: FUN_0045bff5
 * Entry Point: 0045bff5
 * Size: 504 bytes
 */
#include "duel.h"


undefined4 FUN_0045bff5(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_8;
  
  if ((param_3 == 0x73) || (param_3 == 0x6d)) {
    FUN_00434660(s_prompts_txt_004f8a20,s_ROYAL_ASSASSIN_004f8a10);
    local_8 = FUN_0045c613(param_1,param_2,param_3,1 - param_1);
  }
  if (param_3 == 0x90) {
    FUN_0043071d(0);
    local_8 = 0;
  }
  else {
    if (param_3 == 0x72) {
      uVar1 = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      uVar2 = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,1,0);
      iVar4 = FUN_0041c0ab(uVar1,uVar2,0,param_1,2,2,0x200,2,0,0,uVar3);
      if (iVar4 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(uVar1,uVar2,2);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
      local_8 = 0;
    }
    if (((param_3 == 0x8a) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + 0x30;
    }
    if (((param_3 == 0x8b) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + -0x30;
    }
  }
  return local_8;
}


