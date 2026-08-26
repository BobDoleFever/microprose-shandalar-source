/*
 * Decompiled function: FUN_0045bc1f
 * Entry Point: 0045bc1f
 * Size: 982 bytes
 */
#include "duel.h"


undefined4 FUN_0045bc1f(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == 1) {
    *(int *)(&DAT_0068f334 + param_1 * 0x20) = *(int *)(&DAT_0068f334 + param_1 * 0x20) + 1;
  }
  if (param_3 == 0x73) {
    bVar4 = (*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0;
    if ((bVar4) && (iVar2 = FUN_0049b309(param_1,5,2), iVar2 == 0)) {
      bVar4 = false;
    }
    uVar3 = 0;
    if (bVar4) {
      bVar1 = FUN_004af7bb(param_1,param_2,1,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      uVar3 = FUN_004521e2(param_1,param_2,1 << (bVar1 & 0x1f));
      uVar3 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0x1047,0,0,uVar3);
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
    uVar3 = 0;
  }
  else {
    if ((((param_3 == 0x6d) && (iVar2 = FUN_0049b309(param_1,5,2), iVar2 != 0)) &&
        ((*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0)) &&
       (FUN_0042b6b0(param_1,5,2), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f8a04,s_NORTHERN_PALADIN_004f89f0);
      bVar1 = FUN_004af7bb(param_1,param_2,1,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_c);
      uVar3 = FUN_004521e2(param_1,param_2,1 << (bVar1 & 0x1f));
      iVar2 = FUN_0041e2a2(param_1,2,2,0x200,0x1047,0,0,uVar3);
      if (iVar2 == 0) {
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
      local_c = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_8 = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      bVar1 = FUN_004af7bb(param_1,param_2,1,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      uVar3 = FUN_004521e2(param_1,param_2,1 << (bVar1 & 0x1f));
      iVar2 = FUN_0041c0ab(local_c,local_8,0,param_1,2,2,0x200,0x1047,0,0,uVar3);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(local_c,local_8,2);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}


