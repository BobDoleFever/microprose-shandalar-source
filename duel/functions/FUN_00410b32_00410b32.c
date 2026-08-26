/*
 * Decompiled function: FUN_00410b32
 * Entry Point: 00410b32
 * Size: 716 bytes
 */
#include "duel.h"


undefined4 FUN_00410b32(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == 0x73) {
    iVar1 = FUN_0049b309(param_1,7,3);
    if ((((iVar1 == 0) || (DAT_00666458 != param_1)) ||
        ((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) != 0 &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
          != 0)))) || (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((((param_3 == 0x6d) && (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0))
        && (iVar1 = FUN_0049b309(param_1,7,3), iVar1 != 0)) &&
       ((DAT_00666458 == param_1 && (FUN_0042b6b0(param_1,0,3), DAT_00681ea4 != 1)))) {
      FUN_00434660(s_prompts_txt_004f29a4,s_DISRUPTING_SCEPTER_004f2990);
      iVar1 = FUN_0041e2a2(param_1,2,1 - param_1,0x1000,0,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff
                           ,0xffffffff,0,0,0,&DAT_006679f0,1,&local_c);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      FUN_00488150(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),0,0);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


