/*
 * Decompiled function: FUN_0045b71b
 * Entry Point: 0045b71b
 * Size: 1284 bytes
 */
#include "duel.h"


undefined4 FUN_0045b71b(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == 1) {
    *(int *)(&DAT_0068f334 + param_1 * 0x20) = *(int *)(&DAT_0068f334 + param_1 * 0x20) + 1;
  }
  if (param_3 == 0x73) {
    bVar3 = (*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0;
    if ((bVar3) && (iVar1 = FUN_0049b309(param_1,2,2), iVar1 == 0)) {
      bVar3 = false;
    }
    if ((bVar3) && (iVar1 = FUN_0049b309(param_1,7,4), iVar1 == 0)) {
      bVar3 = false;
    }
    uVar2 = 0;
    if (bVar3) {
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0x40)
      ;
      uVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0x1047,0,0,uVar2);
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
    uVar2 = 0;
  }
  else {
    if ((param_3 == 0x6d) &&
       ((*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0)) {
      DAT_0068ece0 = 2;
      FUN_0042b6b0(param_1,2,2);
      if (DAT_00681ea4 != 1) {
        FUN_00434660(s_prompts_txt_004f89e4,s_TIME_ELEMENTAL_004f89d4);
        uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,
                             0x40,&DAT_006679f0,1,&local_c);
        iVar1 = FUN_0041e2a2(param_1,2,1 - param_1,0x200,0x1047,0,0,uVar2);
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
    }
    if (param_3 == 0x72) {
      local_c = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_8 = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0x40)
      ;
      iVar1 = FUN_0041c0ab(local_c,local_8,0,param_1,2,2,0x200,0x1047,0,0,uVar2);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_004af82a(local_c,local_8);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
    }
    if (((param_3 == 0x15) || (param_3 == 199)) &&
       (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 4) != 0)) {
      FUN_004a2b00(param_1,param_2,DAT_0066674c,param_1,0xffffffff);
    }
    if (((param_3 == 0x1a) || (param_3 == 199)) &&
       ((DAT_0068f2c4 == 0x17 && ((&DAT_006826de)[param_2 * 0x120 + param_1 * 0x5b20] != -1)))) {
      FUN_004a2b00(param_1,param_2,DAT_0066674c,param_1,0xffffffff);
    }
    if ((param_3 == 0x22) || (param_3 == 199)) {
      *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
    }
    if (((param_3 == 0x8a) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + 0x78;
    }
    if (((param_3 == 0x8b) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + -0x78;
    }
    uVar2 = 0;
  }
  return uVar2;
}


