/*
 * Decompiled function: FUN_004a805d
 * Entry Point: 004a805d
 * Size: 777 bytes
 */
#include "duel.h"


undefined4 FUN_004a805d(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_3 == 0x74) {
    if ((DAT_00676504 == param_1) && (iVar2 = FUN_0049b309(param_1,7,2), iVar2 == 0)) {
      uVar3 = 0;
    }
    else {
      FUN_0043071d(0);
      uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      uVar3 = FUN_0041bcf0(0,0,param_1,2,param_1,0x200,2,0,0,uVar3);
    }
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_0050620c,s_HOWL_FROM_BEYOND_005061f8);
      iVar2 = FUN_00468130(param_1,param_1,param_2);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_0068f2d4 = DAT_0068f2d4 + (((DAT_0068f2c4 < 0x15) - 1 & 0xfffffffe) * 3 + 9) * -4;
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = DAT_00681ea0;
        if ((DAT_00676504 == param_1) &&
           (((&DAT_006826ce)
             [*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] & 3) != 0)) {
          DAT_0068f2d4 = DAT_0068f2d4 + -99;
        }
      }
    }
    if (param_3 == 0x71) {
      uVar3 = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      uVar1 = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar4 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(uVar3,uVar1,0,param_1,2,2,0x200,2,0,0,uVar4);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar2 = FUN_004a2b00(param_1,param_2,DAT_0066aaec,uVar3,uVar1);
        if (iVar2 != -1) {
          *(short *)(&DAT_006826d8 + iVar2 * 0x120 + param_1 * 0x5b20) =
               (short)*(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20);
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}


