/*
 * Decompiled function: FUN_00468def
 * Entry Point: 00468def
 * Size: 1486 bytes
 */
#include "duel.h"


undefined4 FUN_00468def(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == 0x71) {
    local_8 = DAT_0066642c;
    uVar1 = FUN_004693bd(1 - param_1);
    FUN_0046951b(param_1,param_2,uVar1);
    DAT_0066642c = local_8;
  }
  if (param_3 == 0x73) {
    if (((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
         == 0)) &&
       ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0 &&
        (iVar2 = FUN_0049b309(param_1,3,2), iVar2 != 0)))) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,
                           *(undefined4 *)
                            (&DAT_006826e4 +
                            *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                            (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20),
                           0xffffffff,0xffffffff,0x10,0,0);
      iVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if ((((param_3 == 0x6d) &&
         ((*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0)) &&
        (iVar2 = FUN_00468b20(param_1,param_2,
                              *(undefined4 *)
                               (&DAT_006826e4 +
                               *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120
                               + (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20)
                             ), iVar2 != 0)) && (FUN_0042b6b0(param_1,3,2), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f9390,s_ASWANJAGUAR_004f9384);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,
                           *(undefined4 *)
                            (&DAT_006826e4 +
                            *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                            (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20),
                           0xffffffff,0xffffffff,0x10,0,0,&DAT_006679f0,1,&local_14);
      iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_14;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        local_c = *(undefined4 *)
                   (&DAT_00618ad8 +
                   *(int *)(&DAT_004ff590 +
                           *(int *)(&DAT_006826c4 + local_14 * 0x5b20 + local_10 * 0x120) * 0x34) *
                   0x98);
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,
                           *(undefined4 *)
                            (&DAT_006826e4 +
                            *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                            (char)(&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20),
                           0xffffffff,0xffffffff,0x10,0,0);
      iVar2 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x22);
        }
        FUN_0046e571(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                     *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),1);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20] = 0;
    }
  }
  return 0;
}


