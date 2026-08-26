/*
 * Decompiled function: FUN_004187f1
 * Entry Point: 004187f1
 * Size: 1066 bytes
 */
#include "duel.h"


undefined4 FUN_004187f1(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  int local_c;
  
  if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
    DAT_0068f2d4 = DAT_0068f2d4 + (*(int *)(&DAT_0068ee80 + param_1 * 4) * 0xc) / 2;
  }
  if (param_3 == 0x73) {
    if (((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
         == 0)) &&
       ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0 &&
        (iVar1 = FUN_0049b309(param_1,7,1), iVar1 != 0)))) {
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar2);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if (((param_3 == 0x6d) && (iVar1 = FUN_0049b309(param_1,7,1), iVar1 != 0)) &&
       (FUN_0042b6b0(param_1,0,1), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f2bc4,s_HELM_OF_CHATZUK_004f2bb4);
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_10);
      iVar1 = FUN_0041e2a2(param_1,2,param_1,0x200,2,0,0,uVar2);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      local_10 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_c = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar1 = FUN_0041c0ab(local_10,local_c,0,param_1,2,2,0x200,2,0,0,uVar2);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar1 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,local_10,local_c);
        if (iVar1 != -1) {
          *(undefined4 *)(&DAT_006826e4 + iVar1 * 0x120 + param_1 * 0x5b20) = 0x40;
        }
        *(undefined4 *)(&DAT_006826fc + local_c * 0x120 + local_10 * 0x5b20) = 0x8000000;
      }
    }
  }
  return 0;
}


