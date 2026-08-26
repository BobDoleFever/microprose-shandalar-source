/*
 * Decompiled function: FUN_004a8b71
 * Entry Point: 004a8b71
 * Size: 484 bytes
 */
#include "duel.h"


undefined4 FUN_004a8b71(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_3 == 0x74) {
    FUN_0043071d(0);
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00506274,s_SWORD_TO_PLOWSHARES_00506260);
      iVar2 = FUN_00468130(param_1,1 - param_1,param_2);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
    }
    if (param_3 == 0x71) {
      iVar2 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      uVar1 = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar4 = FUN_0041c0ab(iVar2,uVar1,0,param_1,2,2,0x200,2,0,0,uVar3);
      if (iVar4 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar4 = FUN_0048b81a(iVar2,uVar1,0x32,0xffffffff);
        (&DAT_00681ea8)[iVar2] = (&DAT_00681ea8)[iVar2] + iVar4;
        FUN_0046e571(iVar2,uVar1,4);
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


