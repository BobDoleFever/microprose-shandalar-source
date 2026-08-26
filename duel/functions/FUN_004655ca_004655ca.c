/*
 * Decompiled function: FUN_004655ca
 * Entry Point: 004655ca
 * Size: 766 bytes
 */
#include "duel.h"


undefined4 FUN_004655ca(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (param_3 == 0x73) {
    if ((*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,1,0,0,uVar1);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if (param_3 == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8e10,s_LEY_DRUID_004f8e04);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_c);
      iVar2 = FUN_0041e2a2(param_1,2,param_1,0x200,1,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x72) {
      local_c = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_8 = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(local_c,local_8,0,param_1,2,2,0x200,1,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) =
             *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) & 0xffffffef;
        FUN_0048c907(local_c,local_8,1,0xffffffff,0xffffffff);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
    }
  }
  return 0;
}


