/*
 * Decompiled function: FUN_00405831
 * Entry Point: 00405831
 * Size: 906 bytes
 */
#include "duel.h"


undefined4 FUN_00405831(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    iVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0x40,0,0,uVar1);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else if ((DAT_00676504 == param_1) && (iVar2 = FUN_0049b309(param_1,7,2), iVar2 == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_004f224c,s_DETONATE_004f2240);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_c);
      iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x200,0x40,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = DAT_00681ea0;
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x71) {
      local_c = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_8 = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(local_c,local_8,0,param_1,2,2,0x200,0x40,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else if ((int)(char)(&DAT_004ff597)
                          [*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_c * 0x5b20) * 0x34] +
               (int)(char)(&DAT_004ff598)
                          [*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_c * 0x5b20) * 0x34] ==
               *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20)) {
        FUN_004afd1c(local_c,*(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20),
                     param_1,param_2);
        FUN_0046e571(local_c,local_8,1);
      }
      else {
        DAT_00681ea4 = 1;
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


