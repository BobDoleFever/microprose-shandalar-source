/*
 * Decompiled function: FUN_00402cc1
 * Entry Point: 00402cc1
 * Size: 572 bytes
 */
#include "duel.h"


undefined4 FUN_00402cc1(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == 0x74) {
    if ((DAT_00676504 == param_1) && (iVar1 = FUN_0049b309(param_1,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      iVar1 = (&DAT_00681ea8)[param_1];
      iVar3 = FUN_00404a71(param_1,*(undefined4 *)
                                    (&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20));
      DAT_0068f2d4 = DAT_0068f2d4 - (iVar1 * 0x18) / iVar3;
      FUN_00434660(s_prompts_txt_004f2140,s_STREAMOFLIFE_004f2130);
      iVar1 = FUN_0041e2a2(param_1,2,param_1,0x1000,0,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,
                           0xffffffff,0,0,0,&DAT_006679f0,1,&local_c);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = DAT_00681ea0;
        *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x71) {
      (&DAT_00681ea8)[*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20)] =
           (&DAT_00681ea8)[*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20)] +
           *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20);
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


