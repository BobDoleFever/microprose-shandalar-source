/*
 * Decompiled function: FUN_004a9e2f
 * Entry Point: 004a9e2f
 * Size: 607 bytes
 */
#include "duel.h"


undefined4 FUN_004a9e2f(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_3 == 0x74) {
    FUN_0043071d(0);
    uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0x40,0,0,uVar2);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_0050631c,s_CRUMBLE_00506314);
      iVar3 = FUN_00468831(param_1,1 - param_1,param_2);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
    }
    if (param_3 == 0x71) {
      iVar3 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      uVar2 = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar4 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar5 = FUN_0041c0ab(iVar3,uVar2,0,param_1,2,2,0x200,0x40,0,0,uVar4);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        cVar1 = (&DAT_004ff597)
                [*(int *)(&DAT_006826c4 +
                         *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                         *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) *
                 0x34];
        iVar5 = FUN_0049aa14((int)(char)(&DAT_004ff598)
                                        [*(int *)(&DAT_006826c4 +
                                                 *(int *)(&DAT_00682718 +
                                                         param_2 * 0x120 + param_1 * 0x5b20) *
                                                 0x5b20 + *(int *)(&DAT_0068271c +
                                                                  param_2 * 0x120 + param_1 * 0x5b20
                                                                  ) * 0x120) * 0x34],0,99);
        (&DAT_00681ea8)[iVar3] = (&DAT_00681ea8)[iVar3] + cVar1 + iVar5;
        FUN_0046e571(iVar3,uVar2,2);
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


