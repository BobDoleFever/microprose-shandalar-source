/*
 * Decompiled function: FUN_004a9d72
 * Entry Point: 004a9d72
 * Size: 189 bytes
 */
#include "duel.h"


undefined4 FUN_004a9d72(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0x74) {
    FUN_0043071d(1);
    uVar1 = 1;
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00506308,s_LIGHTNING_BOLT_005062f8);
      iVar2 = FUN_00461047(param_1,param_2,3);
      if (iVar2 != 0) {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x24;
      }
    }
    if (param_3 == 0x71) {
      FUN_004612b0(param_1,param_2,0x71,3);
      FUN_0046e571(param_1,param_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


