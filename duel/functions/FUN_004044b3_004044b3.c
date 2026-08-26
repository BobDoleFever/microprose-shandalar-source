/*
 * Decompiled function: FUN_004044b3
 * Entry Point: 004044b3
 * Size: 1470 bytes
 */
#include "duel.h"


undefined4 FUN_004044b3(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    FUN_0041bcf0(-(uint)(DAT_0068f100 == 0) & 0x68ed04,0,param_1,2,2,0x200,2,0,0,uVar1);
    if ((DAT_00676504 == param_1) &&
       ((DAT_0068ed04 == 0 || (iVar2 = FUN_0049b309(param_1,7,2), iVar2 == 0)))) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      local_c = 0;
      local_8 = 0;
      while (((local_c < DAT_00681ea0 && (local_8 == 0)) && (DAT_00681ea4 != 1))) {
        FUN_00434660(s_prompts_txt_004f2204,s_WINTER_BLAST_004f21f4);
        _sprintf(&DAT_006679f0,&DAT_006679f0,local_c + 1,DAT_00681ea0);
        uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                             &DAT_006679f0,1,&local_14);
        iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x200,2,0,0,uVar1);
        if (iVar2 == 0) {
          if (local_10 == -1) {
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
                  param_1 * 0x5b20 + (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] * 8)
               = local_14;
          *(int *)(&DAT_0068271c +
                  param_2 * 0x120 +
                  param_1 * 0x5b20 + (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] * 8)
               = local_10;
          (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] =
               (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] + '\x01';
        }
        local_c = local_c + 1;
      }
      for (local_c = 0; local_c < (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20];
          local_c = local_c + 1) {
        *(uint *)(&DAT_006826cc +
                 *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8) * 0x5b20
                 + *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8) *
                   0x120) =
             *(uint *)(&DAT_006826cc +
                      *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8) *
                      0x5b20 + *(int *)(&DAT_0068271c +
                                       param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8) * 0x120) &
             0xffcfffff;
      }
      if (DAT_00681ea4 == 1) {
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      }
    }
    if (param_3 == 0x71) {
      for (local_c = 0; local_c < (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20];
          local_c = local_c + 1) {
        uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
        iVar2 = FUN_0041c0ab(*(undefined4 *)
                              (&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8),
                             *(undefined4 *)
                              (&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8),0,
                             param_1,2,2,0x200,2,0,0,uVar1);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          FUN_004a7b83(*(undefined4 *)
                        (&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8),
                       *(undefined4 *)
                        (&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8));
          uVar3 = FUN_0048b81a(*(undefined4 *)
                                (&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8),
                               *(undefined4 *)
                                (&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8),
                               0x34,0xffffffff);
          if ((uVar3 & 0x20) != 0) {
            FUN_004af950(*(undefined4 *)
                          (&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8),
                         *(undefined4 *)
                          (&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + local_c * 8),2,
                         param_1,param_2);
          }
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


