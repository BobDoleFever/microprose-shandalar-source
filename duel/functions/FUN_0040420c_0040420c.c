/*
 * Decompiled function: FUN_0040420c
 * Entry Point: 0040420c
 * Size: 679 bytes
 */
#include "duel.h"


undefined4 FUN_0040420c(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0x1047,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      iVar2 = FUN_00404a71(param_1,*(undefined4 *)
                                    (&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20));
      DAT_0068f2d4 = DAT_0068f2d4 - (int)(0x30 / (longlong)iVar2);
      FUN_00434660(s_prompts_txt_004f21e8,s_DESERT_TWISTER_004f21d8);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_c);
      iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x200,0x1047,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x71) {
      local_c = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_8 = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(local_c,local_8,0,param_1,2,2,0x200,0x1047,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(local_c,local_8,2);
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


