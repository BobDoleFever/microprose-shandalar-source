/*
 * Decompiled function: FUN_0040ff7e
 * Entry Point: 0040ff7e
 * Size: 1617 bytes
 */
#include "duel.h"


undefined4 FUN_0040ff7e(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 0x73) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    FUN_0041bcf0(-(uint)(DAT_0068f100 == 0) & 0x68ed04,0,param_1,2,2,0x200,1,0,0,uVar1);
    if (((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
         == 0)) && (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (param_3 == 0x90) {
    FUN_00430768(0);
    uVar1 = 0;
  }
  else {
    if (param_3 == 0x6d) {
      if (param_1 == DAT_00676504) {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
      }
      *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      uVar1 = DAT_0068ed04;
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      FUN_0041bcf0(&DAT_0068ed04,0,param_1,2,2,0x200,1,0,0,uVar2);
      DAT_0068ece0 = 0xffffffff;
      FUN_0042b6b0(param_1,0,0);
      DAT_0068ed04 = uVar1;
      if (DAT_00681ea4 != 1) {
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
        local_c = 0;
        local_8 = 0;
        while (((local_c < DAT_00681ea0 && (local_8 == 0)) && (DAT_00681ea4 != 1))) {
          FUN_00434660(s_prompts_txt_004f296c,s_CANDLEABRA_OF_TAWNOS_004f2954);
          _sprintf(&DAT_006679f0,&DAT_006679f0,local_c + 1,DAT_00681ea0);
          uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0
                               ,&DAT_006679f0,1,&local_14);
          iVar3 = FUN_0041e2a2(param_1,2,param_1,0x200,1,0,0,uVar1);
          if (iVar3 == 0) {
            if (local_10 == -1) {
              (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
              DAT_00681ea4 = 1;
            }
            else {
              local_8 = 1;
            }
          }
          else {
            *(uint *)(&DAT_006826cc + local_14 * 0x5b20 + local_10 * 0x120) =
                 *(uint *)(&DAT_006826cc + local_14 * 0x5b20 + local_10 * 0x120) | 0x300000;
            FUN_00451482(0,0x20);
            *(int *)(&DAT_00682718 +
                    param_2 * 0x120 +
                    param_1 * 0x5b20 + (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] * 8
                    ) = local_14;
            *(int *)(&DAT_0068271c +
                    param_2 * 0x120 +
                    param_1 * 0x5b20 + (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] * 8
                    ) = local_10;
            (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] =
                 (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] + '\x01';
          }
          local_c = local_c + 1;
        }
        for (local_c = 0; local_c < (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20];
            local_c = local_c + 1) {
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8) *
                   0x5b20 + *(int *)(&DAT_0068271c +
                                    param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8) * 0x120) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8) *
                        0x5b20 + *(int *)(&DAT_0068271c +
                                         param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8) * 0x120)
               & 0xffcfffff;
        }
      }
      if (DAT_00681ea4 == 1) {
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0xffffffef;
      }
    }
    if (param_3 == 0x72) {
      for (local_c = 0; local_c < (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20];
          local_c = local_c + 1) {
        local_14 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8);
        local_10 = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8);
        uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
        iVar3 = FUN_0041c0ab(local_14,local_10,0,param_1,2,2,0x200,1,0,0,uVar1);
        if (iVar3 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          FUN_0048c907(local_14,local_10,1,0xffffffff,0xffffffff);
          *(uint *)(&DAT_006826cc + local_14 * 0x5b20 + local_10 * 0x120) =
               *(uint *)(&DAT_006826cc + local_14 * 0x5b20 + local_10 * 0x120) & 0xffffffef;
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


