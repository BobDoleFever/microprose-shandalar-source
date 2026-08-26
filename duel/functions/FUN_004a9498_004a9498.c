/*
 * Decompiled function: FUN_004a9498
 * Entry Point: 004a9498
 * Size: 700 bytes
 */
#include "duel.h"


undefined4 FUN_004a9498(int param_1,int param_2,int param_3)

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
      FUN_00434660(s_prompts_txt_005062dc,&DAT_005062d4);
      iVar3 = FUN_00468130(param_1,param_1,param_2);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676510) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
        }
        if (((&DAT_006826fc)
             [*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] & 0x20) != 0) {
          DAT_0068f2d4 = DAT_0068f2d4 + -99;
        }
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
        iVar3 = FUN_004a2b00(param_1,param_2,DAT_00667994,uVar2,uVar1);
        if (iVar3 != -1) {
          *(undefined4 *)(&DAT_006826fc + iVar3 * 0x120 + param_1 * 0x5b20) = 0;
          *(undefined4 *)(&DAT_006826e4 + iVar3 * 0x120 + param_1 * 0x5b20) = 0x20;
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


