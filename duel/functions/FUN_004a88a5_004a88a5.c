/*
 * Decompiled function: FUN_004a88a5
 * Entry Point: 004a88a5
 * Size: 624 bytes
 */
#include "duel.h"


undefined4 FUN_004a88a5(int param_1,int param_2,int param_3)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (param_3 == 0x74) {
    FUN_0043071d(0);
    uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar3 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar3);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00506254,s_BLOODLUST_00506248);
      iVar4 = FUN_00468130(param_1,param_1,param_2);
      if (iVar4 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_0068f2d4 = DAT_0068f2d4 + ((uint)(DAT_0068f2c4 < 0x15) * 3 + 3) * -8;
      }
    }
    if (param_3 == 0x71) {
      iVar4 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      iVar1 = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar5 = FUN_0041c0ab(iVar4,iVar1,0,param_1,2,2,0x200,2,0,0,uVar3);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar5 = FUN_004a2b00(param_1,param_2,DAT_0066aaec,iVar4,iVar1);
        if (iVar5 != -1) {
          *(undefined2 *)(&DAT_006826d8 + iVar5 * 0x120 + param_1 * 0x5b20) = 4;
          sVar2 = FUN_0049aa14(4,0,*(short *)(&DAT_006826d6 + iVar4 * 0x5b20 + iVar1 * 0x120) + -1);
          *(short *)(&DAT_006826da + iVar5 * 0x120 + param_1 * 0x5b20) = -sVar2;
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}


