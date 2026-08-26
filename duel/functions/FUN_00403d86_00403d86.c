/*
 * Decompiled function: FUN_00403d86
 * Entry Point: 00403d86
 * Size: 1153 bytes
 */
#include "duel.h"


undefined4 FUN_00403d86(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    FUN_0041bcf0(&local_10,0,param_1,2,2,0x200,2,0x40,0,uVar1);
    if (local_10 < 2) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      local_c = 0;
      while ((local_c < 2 && (DAT_00681ea4 != 1))) {
        FUN_00434660(s_prompts_txt_004f21cc,s_ASHESTOASHES_004f21bc);
        uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                             &DAT_006679f0 + local_c * 0xfa,1,
                             &DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120 + local_c * 8);
        iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x200,2,0x40,0,uVar1);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_0068271c + local_c * 8 + param_1 * 0x5b20 + param_2 * 0x120) *
                   0x120 + *(int *)(&DAT_00682718 + local_c * 8 + param_1 * 0x5b20 + param_2 * 0x120
                                   ) * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_0068271c + local_c * 8 + param_1 * 0x5b20 + param_2 * 0x120) *
                        0x120 + *(int *)(&DAT_00682718 +
                                        local_c * 8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20)
               | 0x300000;
          FUN_00451482(0,0x20);
        }
        local_c = local_c + 1;
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 2;
      for (local_c = 0; local_c < (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20];
          local_c = local_c + 1) {
        *(uint *)(&DAT_006826cc +
                 *(int *)(&DAT_0068271c + local_c * 8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120
                 + *(int *)(&DAT_00682718 + local_c * 8 + param_1 * 0x5b20 + param_2 * 0x120) *
                   0x5b20) =
             *(uint *)(&DAT_006826cc +
                      *(int *)(&DAT_0068271c + local_c * 8 + param_1 * 0x5b20 + param_2 * 0x120) *
                      0x120 + *(int *)(&DAT_00682718 +
                                      local_c * 8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20) &
             0xffcfffff;
      }
      if (DAT_00681ea4 == 1) {
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      }
    }
    if (param_3 == 0x71) {
      local_8 = 0;
      for (local_c = 0; local_c < (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20];
          local_c = local_c + 1) {
        uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
        iVar2 = FUN_0041c0ab(*(undefined4 *)
                              (&DAT_00682718 + local_c * 8 + param_1 * 0x5b20 + param_2 * 0x120),
                             *(undefined4 *)
                              (&DAT_0068271c + local_c * 8 + param_1 * 0x5b20 + param_2 * 0x120),0,
                             param_1,2,2,0x200,2,0x40,0,uVar1);
        if (iVar2 == 0) {
          local_8 = local_8 + 1;
        }
        else {
          FUN_0046e571(*(undefined4 *)
                        (&DAT_00682718 + local_c * 8 + param_1 * 0x5b20 + param_2 * 0x120),
                       *(undefined4 *)
                        (&DAT_0068271c + local_c * 8 + param_1 * 0x5b20 + param_2 * 0x120),4);
        }
      }
      if (local_8 == 2) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_004afd1c(param_1,5,param_1,param_2);
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


