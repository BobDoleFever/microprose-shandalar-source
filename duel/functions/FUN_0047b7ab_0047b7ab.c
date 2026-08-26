/*
 * Decompiled function: FUN_0047b7ab
 * Entry Point: 0047b7ab
 * Size: 1016 bytes
 */
#include "duel.h"


undefined4 FUN_0047b7ab(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_14;
  int local_8;
  
  if (param_3 == 1) {
    local_14 = FUN_0047a090(param_1,param_2,1,0);
  }
  else if (param_3 == 0x71) {
    local_14 = FUN_0047a090(param_1,param_2,0x71,0);
  }
  else if (param_3 == 0x73) {
    local_14 = FUN_0047a090(param_1,param_2,0x73,0);
  }
  else if (param_3 == 0x6d) {
    local_14 = 0;
    FUN_004d9630(&DAT_005f6810,s_Get_mana__004f9af4);
    FUN_004d9640(&DAT_005f6810,s_Sacrifice_to_destroy_a_land__004f9b00);
    FUN_004d9640(&DAT_005f6810,s_Cancel__004f9b20);
    (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    if (DAT_00666748 == 0) {
      local_8 = 0;
    }
    else if (DAT_0068f220 == 0) {
      if (param_1 == DAT_00676510) {
        local_8 = FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,&DAT_005f6810,1);
      }
      else {
        local_8 = 1;
      }
    }
    else {
      local_8 = 0;
    }
    if (local_8 == 0) {
      local_14 = FUN_0047a090(param_1,param_2,0x6d,0);
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
    else if (local_8 == 1) {
      DAT_0068f0f4 = 0xffffffff;
      FUN_00434660(s_prompts_txt_004f9b38,s_STRIPMINE_004f9b2c);
      iVar3 = FUN_00468550(param_1,1 - param_1,param_2);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0xf);
        }
        FUN_0046e571(param_1,param_2,3);
        FUN_0049b1eb(param_1,0,1);
      }
    }
    else {
      DAT_00681ea4 = 1;
    }
    if (DAT_00681ea4 == 1) {
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
  }
  else {
    if ((param_3 == 0x72) && ((&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] != '\0')) {
      uVar1 = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      uVar2 = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar4 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar3 = FUN_0041c0ab(uVar1,uVar2,0,param_1,2,2,0x200,1,0,0,uVar4);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(uVar1,uVar2,2);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
    }
    if (param_3 == 0x7f) {
      local_14 = FUN_0047a090(param_1,param_2,0x7f,0);
    }
    else {
      local_14 = 0;
    }
  }
  return local_14;
}


