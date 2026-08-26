/*
 * Decompiled function: FUN_00418c1b
 * Entry Point: 00418c1b
 * Size: 1094 bytes
 */
#include "duel.h"


undefined4 FUN_00418c1b(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  if (((param_3 == 0x6c) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
    iVar1 = (&DAT_0068ee78)[param_1] * *(int *)(&DAT_0068ee80 + param_1 * 4) * 0xc;
    DAT_0068f2d4 = DAT_0068f2d4 + ((int)(iVar1 + (iVar1 >> 0x1f & 0xfU)) >> 4);
  }
  if (param_3 == 0x73) {
    if ((((&DAT_0068ee78)[param_1] != 0) && (iVar1 = FUN_0049b309(param_1,7,3), iVar1 != 0)) &&
       (((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) == 0 ||
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
          == 0)) && (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0)))) {
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
    if (((param_3 == 0x6d) && ((&DAT_0068ee78)[param_1] != 0)) &&
       ((iVar1 = FUN_0049b309(param_1,7,3), iVar1 != 0 &&
        (FUN_0042b6b0(param_1,0,3), DAT_00681ea4 != 1)))) {
      FUN_00488150(param_1,1,1);
      FUN_00434660(s_prompts_txt_004f2bdc,s_CORAL_HELM_004f2bd0);
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_10);
      iVar1 = FUN_0041e2a2(param_1,2,param_1,0x200,2,0,0,uVar2);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x72) {
      local_10 = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_c = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20] = 0;
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar1 = FUN_0041c0ab(local_10,local_c,0,param_1,2,2,0x200,2,0,0,uVar2);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar1 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,local_10,local_c);
        if (iVar1 != -1) {
          *(undefined2 *)(&DAT_006826d8 + iVar1 * 0x120 + param_1 * 0x5b20) = 2;
          *(undefined2 *)(&DAT_006826da + iVar1 * 0x120 + param_1 * 0x5b20) = 2;
        }
      }
    }
  }
  return 0;
}


