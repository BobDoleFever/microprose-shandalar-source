/*
 * Decompiled function: FUN_0047cd98
 * Entry Point: 0047cd98
 * Size: 2960 bytes
 */
#include "duel.h"


undefined4 FUN_0047cd98(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 0x22) {
    uVar2 = FUN_004d7d5e(0x1fc);
    *(undefined4 *)(&DAT_006826c4 + param_1 * 0x5b20 + param_2 * 0x120) = uVar2;
    *(undefined4 *)(&DAT_006826c8 + param_1 * 0x5b20 + param_2 * 0x120) = 0;
    (&DAT_0068ee88)[param_1] = (&DAT_0068ee88)[param_1] + -1;
    *(int *)(&DAT_0068ee80 + param_1 * 4) = *(int *)(&DAT_0068ee80 + param_1 * 4) + -1;
    DAT_00692c6c = param_1;
    DAT_00692c68 = param_2;
    FUN_00467d65(FUN_0047d928,param_1);
  }
  if (((param_3 == 0x77) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
    uVar2 = FUN_004d7d5e(0x1fc);
    *(undefined4 *)(&DAT_006826c4 + param_1 * 0x5b20 + param_2 * 0x120) = uVar2;
    return 0;
  }
  if (param_3 == 1) {
    uVar2 = FUN_0047a090(param_1,param_2,1,0);
    return uVar2;
  }
  if (param_3 == 0x71) {
    uVar2 = FUN_0047a090(param_1,param_2,0x71,0);
    return uVar2;
  }
  if (param_3 == 0x73) {
    local_18 = 0;
    if ((((&DAT_006826cc)[param_1 * 0x5b20 + param_2 * 0x120] & 0x10) == 0) &&
       ((((&DAT_006826ce)[param_1 * 0x5b20 + param_2 * 0x120] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x34] & 2)
         == 0)))) {
      local_18 = 1;
    }
    iVar3 = FUN_0049b309(param_1,7,1);
    if (iVar3 == 0) {
      return local_18;
    }
    return 1;
  }
  if (param_3 != 0x6d) {
    if (param_3 == 0x72) {
      local_8 = *(int *)(&DAT_006826e4 + param_1 * 0x5b20 + param_2 * 0x120);
      if (local_8 != 0) {
        if (local_8 == 1) {
          uVar2 = FUN_004d7d5e(0x38e);
          *(undefined4 *)
           (&DAT_006826c4 +
           *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
           *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120) = uVar2;
          *(undefined4 *)
           (&DAT_006826c8 +
           *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
           *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120) =
               *(undefined4 *)
                (&DAT_006826c4 +
                *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
                *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120);
          *(int *)(&DAT_0068ee80 + DAT_00690af0 * 4) =
               *(int *)(&DAT_0068ee80 + DAT_00690af0 * 4) + 1;
          (&DAT_0068ee88)[DAT_00690af0] = (&DAT_0068ee88)[DAT_00690af0] + 1;
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
                   *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
                        *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20) | 2;
          FUN_0048c907(DAT_00690af0,DAT_0068efa0,0x6c,1 - DAT_00690af0,0xffffffff);
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
                   *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
                        *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20) |
               0x80;
          FUN_0048c907(DAT_00690af0,DAT_0068efa0,0x71,1 - DAT_00690af0,0xffffffff);
        }
        else if ((local_8 == 2) && ((&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] != '\0')) {
          local_14 = *(undefined4 *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120);
          local_10 = *(undefined4 *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120);
          uVar2 = FUN_004d7d5e(0x38e,0xffffffff,0xffffffff,0xffffffff,0,0,0);
          uVar2 = FUN_004521e2(param_1,param_2,0,0,uVar2);
          iVar3 = FUN_0041c0ab(local_14,local_10,0,param_1,2,2,0x200,0,0,0,uVar2);
          if (iVar3 == 0) {
            DAT_00681ea4 = 1;
          }
          else {
            local_c = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,local_14,local_10);
            if (local_c != -1) {
              *(undefined2 *)(&DAT_006826d8 + local_c * 0x120 + param_1 * 0x5b20) = 1;
              *(undefined2 *)(&DAT_006826da + local_c * 0x120 + param_1 * 0x5b20) = 1;
            }
          }
          (&DAT_006827b8)
          [*(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
           *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120] = 0;
        }
      }
      *(undefined4 *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120) = 0;
    }
    if (param_3 == 0x7f) {
      uVar2 = FUN_0047a090(param_1,param_2,0x7f,0);
      return uVar2;
    }
    return 0;
  }
  local_20 = 0;
  local_24 = 3;
  if ((((&DAT_006826cc)[param_1 * 0x5b20 + param_2 * 0x120] & 0x10) == 0) &&
     ((((&DAT_006826ce)[param_1 * 0x5b20 + param_2 * 0x120] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x34] & 2) ==
       0)))) {
    FUN_004d9630(&DAT_005f6810,s_Get_mana__004f9c34);
    local_24 = 0;
  }
  else {
    FUN_004d9630(&DAT_005f6810,s__Get_mana__004f9c40);
  }
  iVar3 = FUN_0049b309(param_1,7,1);
  if (iVar3 == 0) {
    FUN_004d9640(&DAT_005f6810,s__Re_change_to_Assembly_Worker__004f9c70);
  }
  else {
    FUN_004d9640(&DAT_005f6810,s_Re_change_to_Assembly_Worker__004f9c50);
  }
  if ((((&DAT_006826cc)[param_1 * 0x5b20 + param_2 * 0x120] & 0x10) == 0) &&
     ((((&DAT_006826ce)[param_1 * 0x5b20 + param_2 * 0x120] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x34] & 2) ==
       0)))) {
    uVar2 = FUN_004d7d5e(0x38e,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar2 = FUN_004521e2(param_1,param_2,0,0,uVar2);
    iVar3 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0,0,0,uVar2);
    if (iVar3 != 0) {
      FUN_004d9640(&DAT_005f6810,s_Pump_Assembly_Worker__004f9c94);
      if ((DAT_0068f2c4 < 0x1e) && (0x16 < DAT_0068f2c4)) {
        local_24 = 2;
      }
      goto LAB_0047d1c9;
    }
  }
  FUN_004d9640(&DAT_005f6810,s__Pump_Assembly_Worker__004f9cac);
LAB_0047d1c9:
  FUN_004d9640(&DAT_005f6810,s_Cancel__004f9cc8);
  if (DAT_0068f220 == 0) {
    local_8 = FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,&DAT_005f6810,local_24);
  }
  else {
    local_8 = 0;
  }
  *(int *)(&DAT_006826e4 + param_1 * 0x5b20 + param_2 * 0x120) = local_8;
  if (local_8 == 0) {
    local_20 = FUN_0047a090(param_1,param_2,0x6d,0);
    (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 0;
  }
  else if (local_8 == 1) {
    uVar1 = *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120);
    *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
         *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) | 0x40000;
    FUN_0042b6b0(param_1,0,1);
    if ((uVar1 & 0x40000) == 0) {
      *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
           *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) & 0xfffbffff;
    }
    (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 0;
    DAT_0068f0f4 = 0xffffffff;
  }
  else if (local_8 == 2) {
    FUN_00434660(s_prompts_txt_004f9ce4,s_ASSEMBLY_WORKER_004f9cd4);
    uVar2 = FUN_004d7d5e(0x38e,0xffffffff,0xffffffff,0xffffffff,0,0,0,&DAT_006679f0,1,&local_14);
    uVar2 = FUN_004521e2(param_1,param_2,0,0,uVar2);
    iVar3 = FUN_0041e2a2(param_1,2,param_1,0x200,0,0,0,uVar2);
    if (iVar3 == 0) {
      DAT_00681ea4 = 1;
    }
    else {
      *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) =
           *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + param_2 * 0x120) | 0x10;
      FUN_0049b1eb(param_1,0,1);
      *(undefined4 *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120) = local_14;
      *(undefined4 *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120) = local_10;
      (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 1;
    }
    DAT_0068f0f4 = 0xffffffff;
  }
  else {
    DAT_00681ea4 = 1;
  }
  return local_20;
}


