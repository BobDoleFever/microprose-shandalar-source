/*
 * Decompiled function: FUN_00415057
 * Entry Point: 00415057
 * Size: 1012 bytes
 */
#include "duel.h"


undefined4 FUN_00415057(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  if (param_3 == 0x73) {
    if (((((byte)DAT_00681eb0 & 4) == 0) || (iVar1 = FUN_0049b309(param_1,7,2), iVar1 == 0)) ||
       (((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) != 0 &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
          != 0)) ||
        ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) != 0 ||
         (iVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,0xffffffff,0xffffffff,
                               0xffffffff,0,0,0), iVar1 == 0)))))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 99;
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
    uVar2 = 0;
  }
  else {
    if (((param_3 == 0x6d) && (iVar1 = FUN_0049b309(param_1,7,2), iVar1 != 0)) &&
       (FUN_0042b6b0(param_1,0,2), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f2ab8,s_AMULET_KROOG_004f2aa8);
      iVar1 = FUN_0041e2a2(param_1,2,param_1,0x200,0,0,0,0,0,0,DAT_0068f104,0xffffffff,0xffffffff,
                           0xffffffff,0,0,0,&DAT_006679f0,1,&local_c);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      local_c = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_8 = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
      iVar1 = FUN_0041c0ab(local_c,local_8,0,param_1,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,0xffffffff,
                           0xffffffff,0xffffffff,0,0,0);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else if (*(int *)(&DAT_006826e4 + local_c * 0x5b20 + local_8 * 0x120) != 0) {
        *(int *)(&DAT_006826e4 + local_c * 0x5b20 + local_8 * 0x120) =
             *(int *)(&DAT_006826e4 + local_c * 0x5b20 + local_8 * 0x120) + -1;
      }
    }
    if (((param_3 == 0x3b) && (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0))
       && (iVar1 = FUN_0049b309(param_1,7,2), iVar1 != 0)) {
      *(int *)(&DAT_00666738 + param_1 * 4) = *(int *)(&DAT_00666738 + param_1 * 4) + 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}


