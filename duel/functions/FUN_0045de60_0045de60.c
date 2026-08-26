/*
 * Decompiled function: FUN_0045de60
 * Entry Point: 0045de60
 * Size: 806 bytes
 */
#include "duel.h"


undefined4 FUN_0045de60(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == 0x73) {
    uVar1 = 0;
    if ((*(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) & 0x20010) == 0) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0x2002,0xffffffff,0,0,0);
      uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
    uVar1 = 0;
  }
  else {
    if ((param_3 == 0x6d) &&
       ((*(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) & 0x20010) == 0)) {
      FUN_00434660(s_prompts_txt_004f8ac8,s_DWARVEN_WARRIORS_004f8ab4);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0x2002,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_c);
      iVar2 = FUN_0041e2a2(param_1,2,param_1,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120) = local_c;
        *(undefined4 *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120) = local_8;
        (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 1;
        *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
             *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      local_c = *(undefined4 *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120);
      local_8 = *(undefined4 *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0x2002,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(local_c,local_8,0,param_1,2,2,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_006667b0,local_c,local_8);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


