/*
 * Decompiled function: FUN_00419e1e
 * Entry Point: 00419e1e
 * Size: 718 bytes
 */
#include "duel.h"


undefined4 FUN_00419e1e(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c [30];
  
  if (param_3 == 0x73) {
    if (((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
         == 0)) && (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (param_3 == 0x6d) {
      FUN_00434660(s_prompts_txt_004f2c6c,s_GLASSES_OF_URZA_004f2c5c);
      iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x1000,0,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff
                           ,0xffffffff,0,0,0,&DAT_006679f0,1,&local_90);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_90;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_8c;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      local_94 = 0;
      local_88 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      if (((DAT_0066aaf4 != 1) && (param_1 == 0)) && (DAT_0068f0b0 == 0)) {
        for (local_84 = 0; local_84 < (int)(&DAT_00666408)[local_88]; local_84 = local_84 + 1) {
          local_80 = *(int *)(&DAT_006826c4 + local_88 * 0x5b20 + local_84 * 0x120);
          if ((local_80 != -1) && (((&DAT_006826cc)[local_88 * 0x5b20 + local_84 * 0x120] & 2) == 0)
             ) {
            local_7c[local_94] = local_80;
            local_94 = local_94 + 1;
          }
        }
        FUN_004d6639(0,local_7c,local_94,s_Target_Player_s_Hand_004f2c80,0,&DAT_004f2c78);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


