/*
 * Decompiled function: FUN_0040dedd
 * Entry Point: 0040dedd
 * Size: 940 bytes
 */
#include "duel.h"


undefined4 FUN_0040dedd(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 0x73) {
    iVar1 = FUN_0049b309(param_1,7,2);
    if (((iVar1 == 0) ||
        ((((&DAT_006826ce)[param_1 * 0x5b20 + param_2 * 0x120] & 3) != 0 &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x34] & 2)
          != 0)))) || (((&DAT_006826cc)[param_1 * 0x5b20 + param_2 * 0x120] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((((param_3 == 0x6d) && (((&DAT_006826cc)[param_1 * 0x5b20 + param_2 * 0x120] & 0x10) == 0))
        && (iVar1 = FUN_0049b309(param_1,7,2), iVar1 != 0)) &&
       (FUN_0042b6b0(param_1,0,2), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f28ac,s_MILLSTONE_004f28a0);
      iVar1 = FUN_0041e2a2(param_1,2,1 - param_1,0x1000,0,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff
                           ,0xffffffff,0,0,0,&DAT_006679f0,1,&local_18);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120) = local_18;
        *(undefined4 *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120) = local_14;
        (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 1;
        *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
             *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      iVar1 = *(int *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120] = 0;
      for (local_c = 0; local_c < 2; local_c = local_c + 1) {
        local_10 = *(int *)(&DAT_006669f0 + iVar1 * 2000);
        if (local_10 != -1) {
          FUN_004d7acc(iVar1,0);
          local_8 = FUN_004d695b(iVar1,local_10);
          if (local_8 != -1) {
            FUN_0046f02d(iVar1,local_8);
            *(undefined4 *)(&DAT_006826c4 + local_8 * 0x120 + iVar1 * 0x5b20) = 0xffffffff;
          }
        }
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x18);
        }
        if ((DAT_0068f2c4 == 0x1f) && (DAT_00666458 == DAT_00676510)) {
          DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
        }
      }
    }
    if (param_3 == 199) {
      if (param_1 == DAT_00676504) {
        DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
      }
      else {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


