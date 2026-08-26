/*
 * Decompiled function: FUN_004a7352
 * Entry Point: 004a7352
 * Size: 434 bytes
 */
#include "duel.h"


undefined4 FUN_004a7352(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_3 == 0x74) {
    FUN_0043071d(0);
    uVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0x40,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,
                         0xffffffff,0,0,0);
  }
  else {
    if (((param_3 == 0x6c) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      FUN_00434660(s_prompts_txt_0050619c,s_SHATTER_00506194);
      iVar3 = FUN_00468831(param_1,1 - param_1,param_2);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x10;
      }
    }
    if (param_3 == 0x71) {
      uVar2 = *(undefined4 *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120);
      uVar1 = *(undefined4 *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120);
      iVar3 = FUN_0041c0ab(uVar2,uVar1,0,param_1,2,2,0x200,0x40,0,0,0,0,0,0xffffffff,0xffffffff,
                           0xffffffff,0xffffffff,0,0,0);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(uVar2,uVar1,1);
      }
      (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


