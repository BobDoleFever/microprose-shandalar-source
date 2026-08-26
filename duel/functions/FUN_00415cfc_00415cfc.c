/*
 * Decompiled function: FUN_00415cfc
 * Entry Point: 00415cfc
 * Size: 1948 bytes
 */
#include "duel.h"


undefined4 FUN_00415cfc(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  if (((param_3 == 0x6c) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
    *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
         *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) | 0x10;
  }
  if (param_3 == 0x73) {
    if ((((((&DAT_006826ce)[param_1 * 0x5b20 + param_2 * 0x120] & 3) == 0) ||
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x34] & 2)
          == 0)) && (((&DAT_006826cc)[param_1 * 0x5b20 + param_2 * 0x120] & 0x10) == 0)) &&
       (iVar1 = FUN_0049b309(param_1,7,4), iVar1 != 0)) {
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar1 = FUN_0041bcf0(0,0,param_1,1 - param_1,1 - param_1,0x200,0,0,0,uVar2);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if (((param_3 == 0x6d) && (iVar1 = FUN_0049b309(param_1,7,4), iVar1 != 0)) &&
       (FUN_0042b6b0(param_1,0,4), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f2af4,s_BRONZE_TABLET_004f2ae4);
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_c);
      iVar1 = FUN_0041e2a2(param_1,1 - param_1,1 - param_1,0x200,0x7f,0,0,uVar2);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120) = local_c;
        *(int *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120) = local_8;
        (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 1;
        *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
             *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      local_c = *(int *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120);
      local_8 = *(int *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120);
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar1 = FUN_0041c0ab(local_c,local_8,0,param_1,1 - param_1,1 - param_1,0x200,0x7f,0,0,uVar2);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_004348b2(s_prompts_txt_004f2b10,s_BRONZE_TABLET_004f2b00);
        uVar2 = FUN_0045102d(1 - param_1,param_1,param_2,0xffffffff,0xffffffff,
                             &DAT_006679f0 +
                             ((uint)((int)(&DAT_00681ea8)[1 - param_1] < 10) * 5 + 5) * 0x32,0);
        *(undefined4 *)(&DAT_006826e4 + param_1 * 0x5b20 + param_2 * 0x120) = uVar2;
        iVar1 = *(int *)(&DAT_006826e4 + param_1 * 0x5b20 + param_2 * 0x120);
        if (iVar1 == 0) {
          if (*(int *)(&DAT_006826c4 +
                      *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
                      *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120) != -1) {
            if (param_1 == DAT_00676510) {
              FUN_004d76dd(*(undefined4 *)
                            (&DAT_006826c4 +
                            *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
                            *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120));
            }
            else {
              FUN_004d7510(*(undefined4 *)
                            (&DAT_006826c4 +
                            *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
                            *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120));
            }
            *(uint *)(&DAT_006826cc +
                     *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
                     *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120) =
                 *(uint *)(&DAT_006826cc +
                          *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
                          *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120) ^
                 0x1000;
            FUN_0046e571(DAT_00690af0,DAT_0068efa0,4);
          }
          if (param_1 == DAT_00676510) {
            FUN_004d7510(*(undefined4 *)(&DAT_006826c4 + local_c * 0x5b20 + local_8 * 0x120));
          }
          else {
            FUN_004d76dd(*(undefined4 *)(&DAT_006826c4 + local_c * 0x5b20 + local_8 * 0x120));
          }
          *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) =
               *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) ^ 0x1000;
          FUN_0046e571(local_c,local_8,4);
        }
        else if (iVar1 == 1) {
          (&DAT_00681ea8)[1 - param_1] = (&DAT_00681ea8)[1 - param_1] + -10;
          if (*(int *)(&DAT_006826c4 +
                      *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
                      *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120) != -1) {
            FUN_0046e571(DAT_00690af0,DAT_0068efa0,2);
          }
        }
        else if ((iVar1 == 2) &&
                ((&DAT_00681ea8)[1 - param_1] = 0,
                *(int *)(&DAT_006826c4 +
                        *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
                        *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120) != -1)
                ) {
          FUN_0046e571(DAT_00690af0,DAT_0068efa0,2);
        }
      }
    }
  }
  return 0;
}


