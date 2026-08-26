/*
 * Decompiled function: FUN_004097cf
 * Entry Point: 004097cf
 * Size: 492 bytes
 */
#include "duel.h"


undefined4 FUN_004097cf(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_004f26a0,s_DRAIN_POWER_004f2694);
      iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x1000,0,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff
                           ,0xffffffff,0,0,0,&DAT_006679f0,1,&local_14);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_14;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x71) {
      local_8 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      FUN_00467d65(FUN_004099bb,local_8);
      if (local_8 != param_1) {
        for (local_c = 0; local_c < 8; local_c = local_c + 1) {
          *(int *)(&DAT_0068f2e0 + local_c * 4 + param_1 * 0x20) =
               *(int *)(&DAT_0068f2e0 + local_c * 4 + param_1 * 0x20) +
               *(int *)(&DAT_0068f2e0 + local_c * 4 + local_8 * 0x20);
          *(undefined4 *)(&DAT_0068f2e0 + local_c * 4 + local_8 * 0x20) = 0;
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


