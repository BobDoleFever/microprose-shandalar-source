/*
 * Decompiled function: FUN_00408cce
 * Entry Point: 00408cce
 * Size: 642 bytes
 */
#include "duel.h"


undefined4 FUN_00408cce(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_3 == 0x74) {
    if ((DAT_00676504 == param_1) && (iVar2 = FUN_0049b309(param_1,7,2), iVar2 == 0)) {
      return 0;
    }
    uVar3 = 1;
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = DAT_00681ea0;
      FUN_00434660(s_prompts_txt_004f2658,s_DISINTEGRATE_004f2648);
      iVar2 = FUN_00461047(param_1,param_2,
                           *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20));
      if (iVar2 != 0) {
        iVar2 = FUN_00404a71(param_1,*(undefined4 *)
                                      (&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20));
        DAT_0068f2d4 = DAT_0068f2d4 - (int)(0x30 / (longlong)iVar2);
      }
    }
    if (param_3 == 0x71) {
      iVar2 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      iVar1 = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      iVar4 = FUN_004612b0(param_1,param_2,0x71,
                           *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20));
      if ((iVar4 != 0) && (*(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) != -1)) {
        iVar4 = FUN_004a2b00(param_1,param_2,DAT_00676514,iVar2,iVar1);
        if (iVar4 != -1) {
          *(undefined4 *)(&DAT_006826e4 + iVar4 * 0x120 + param_1 * 0x5b20) = 0x200;
        }
        *(undefined4 *)(&DAT_006826fc + iVar2 * 0x5b20 + iVar1 * 0x120) = 0x8000000;
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}


