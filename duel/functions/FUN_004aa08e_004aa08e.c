/*
 * Decompiled function: FUN_004aa08e
 * Entry Point: 004aa08e
 * Size: 653 bytes
 */
#include "duel.h"


undefined4 FUN_004aa08e(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_3 == 0x74) {
    FUN_0043071d(0);
    uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar2);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      DAT_0068f2d4 = DAT_0068f2d4 + (((DAT_0068f2c4 < 0x15) - 1 & 0xfffffffe) * 3 + 0xc) * -4;
      if (DAT_0068f2c4 < 0x15) {
        DAT_0068f2d4 = DAT_0068f2d4 + -0xc;
      }
      FUN_00434660(s_prompts_txt_00506338,s_GIANT_GROWTH_00506328);
      iVar3 = FUN_00468130(param_1,param_1,param_2);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
    }
    if (param_3 == 0x71) {
      uVar2 = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      uVar1 = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar4 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar3 = FUN_0041c0ab(uVar2,uVar1,0,param_1,2,2,0x200,2,0,0,uVar4);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar3 = FUN_004a2b00(param_1,param_2,DAT_0066aaec,uVar2,uVar1);
        if (iVar3 != -1) {
          *(undefined2 *)(&DAT_006826d8 + iVar3 * 0x120 + param_1 * 0x5b20) = 3;
          *(undefined2 *)(&DAT_006826da + iVar3 * 0x120 + param_1 * 0x5b20) = 3;
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    if ((param_3 == 0x3b) && (iVar3 = FUN_0049b309(param_1,3,1), iVar3 != 0)) {
      *(int *)(&DAT_00666730 + param_1 * 4) = *(int *)(&DAT_00666730 + param_1 * 4) + 3;
      *(int *)(&DAT_00666738 + param_1 * 4) = *(int *)(&DAT_00666738 + param_1 * 4) + 3;
    }
    uVar2 = 0;
  }
  return uVar2;
}


