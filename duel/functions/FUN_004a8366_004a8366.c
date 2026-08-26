/*
 * Decompiled function: FUN_004a8366
 * Entry Point: 004a8366
 * Size: 641 bytes
 */
#include "duel.h"


undefined4 FUN_004a8366(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 == 0x74) {
    FUN_0043071d(0);
    if (DAT_0068f2c4 < 0x1e) {
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar3 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar2);
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00506220,s_BERSERK_00506218);
      iVar3 = FUN_00468130(param_1,param_1,param_2);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
    }
    if (param_3 == 0x71) {
      iVar3 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      iVar1 = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar4 = FUN_0041c0ab(iVar3,iVar1,0,param_1,2,2,0x200,2,0,0,uVar2);
      if (iVar4 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar4 = FUN_004a2b00(param_1,param_2,DAT_00681ec8,iVar3,iVar1);
        if (iVar4 != -1) {
          *(undefined4 *)(&DAT_006826e4 + iVar4 * 0x120 + param_1 * 0x5b20) = 0x80;
          *(undefined2 *)(&DAT_006826d8 + iVar4 * 0x120 + param_1 * 0x5b20) =
               *(undefined2 *)(&DAT_006826d4 + iVar1 * 0x120 + iVar3 * 0x5b20);
          *(uint *)(&DAT_006826f8 + iVar4 * 0x120 + param_1 * 0x5b20) =
               *(uint *)(&DAT_006826f8 + iVar4 * 0x120 + param_1 * 0x5b20) | 0x4000;
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
  }
  return 0;
}


