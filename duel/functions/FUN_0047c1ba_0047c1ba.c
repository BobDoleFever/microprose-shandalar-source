/*
 * Decompiled function: FUN_0047c1ba
 * Entry Point: 0047c1ba
 * Size: 3033 bytes
 */
#include "duel.h"


undefined4 FUN_0047c1ba(int param_1,int param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_24;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 1) {
    uVar3 = FUN_0047a090(param_1,param_2,1,0);
    return uVar3;
  }
  if (param_3 == 0x6c) {
    DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
  }
  if (param_3 == 0x71) {
    uVar3 = FUN_0047a090(param_1,param_2,0x71,0);
    return uVar3;
  }
  if (param_3 == 0x73) {
    bVar2 = false;
    if ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
         == 0)))) {
      bVar2 = true;
    }
    iVar4 = FUN_0049b309(param_1,7,1);
    if (iVar4 != 0) {
      bVar2 = true;
    }
    if (bVar2) {
      if ((param_1 == DAT_00676504) && (0 < DAT_0068f2c0)) {
        DAT_00676500 = DAT_00676500 | 3;
      }
      return 1;
    }
    return 0;
  }
  if (param_3 != 0x6d) {
    if (param_3 == 0x72) {
      local_8 = *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20);
      if (local_8 != 0) {
        if (local_8 == 1) {
          uVar3 = FUN_004d7d5e(0x38e);
          *(undefined4 *)
           (&DAT_006826c4 +
           *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) = uVar3;
          *(undefined4 *)
           (&DAT_006826c8 +
           *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) =
               *(undefined4 *)
                (&DAT_006826c4 +
                *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120);
          *(int *)(&DAT_0068ee80 + DAT_00690af0 * 4) =
               *(int *)(&DAT_0068ee80 + DAT_00690af0 * 4) + 1;
          (&DAT_0068ee88)[DAT_00690af0] = (&DAT_0068ee88)[DAT_00690af0] + 1;
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                   *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                        *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) | 2;
          FUN_0048c907(DAT_00690af0,DAT_0068efa0,0x6c,1 - DAT_00690af0,0xffffffff);
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                   *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                        *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) | 0x80
          ;
          FUN_0048c907(DAT_00690af0,DAT_0068efa0,0x71,1 - DAT_00690af0,0xffffffff);
        }
        else if ((local_8 == 2) && ((&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] != '\0')) {
          local_14 = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
          local_10 = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
          uVar3 = FUN_004d7d5e(0x38e,0xffffffff,0xffffffff,0xffffffff,0,0,0);
          uVar3 = FUN_004521e2(param_1,param_2,0,0,uVar3);
          iVar4 = FUN_0041c0ab(local_14,local_10,0,param_1,2,2,0x200,0,0,0,uVar3);
          if (iVar4 == 0) {
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
          [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
        }
      }
      *(undefined4 *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) = 0;
    }
    if (param_3 == 0x7f) {
      uVar3 = FUN_0047a090(param_1,param_2,0x7f,0);
      return uVar3;
    }
    if (((((param_3 == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) && (param_2 == DAT_00690c48)) &&
        ((param_1 == DAT_0068ecb0 && (iVar4 = FUN_0048a33f(param_1,param_2), iVar4 != 0)))) &&
       (*(int *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20) != 0)) {
      DAT_0066642c = *(undefined4 *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20);
    }
    if (param_3 == 199) {
      if (param_1 == DAT_00676504) {
        DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
      }
      else {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x30;
      }
    }
    return 0;
  }
  uVar3 = 0;
  local_24 = 3;
  if ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2) ==
       0)))) {
    FUN_004d9630(&DAT_005f6810,s_Get_mana__004f9b7c);
    local_24 = 0;
  }
  else {
    FUN_004d9630(&DAT_005f6810,s__Get_mana__004f9b88);
  }
  iVar4 = FUN_0049b309(param_1,7,1);
  if (iVar4 == 0) {
    FUN_004d9640(&DAT_005f6810,s__Change_to_Assembly_Worker__004f9bb8);
  }
  else {
    FUN_004d9640(&DAT_005f6810,s_Change_to_Assembly_Worker__004f9b98);
    if (DAT_0068f2c4 < 0x17) {
      local_24 = 1;
    }
  }
  if ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2) ==
       0)))) {
    uVar5 = FUN_004d7d5e(0x38e,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar5 = FUN_004521e2(param_1,param_2,0,0,uVar5);
    iVar4 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0,0,0,uVar5);
    if (iVar4 != 0) {
      FUN_004d9640(&DAT_005f6810,s_Pump_Assembly_Worker__004f9bd8);
      if ((DAT_0068f2c4 < 0x1e) && (0x16 < DAT_0068f2c4)) {
        local_24 = 2;
      }
      goto LAB_0047c563;
    }
  }
  FUN_004d9640(&DAT_005f6810,s__Pump_Assembly_Worker__004f9bf0);
LAB_0047c563:
  FUN_004d9640(&DAT_005f6810,s_Cancel__004f9c0c);
  if (DAT_0068f220 == 0) {
    local_8 = FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,&DAT_005f6810,local_24);
  }
  else {
    local_8 = 0;
  }
  *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
  if (local_8 == 0) {
    uVar3 = FUN_0047a090(param_1,param_2,0x6d,0);
    (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
  }
  else if (local_8 == 1) {
    uVar1 = *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20);
    *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x40000;
    FUN_0042b6b0(param_1,0,1);
    if ((uVar1 & 0x40000) == 0) {
      *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0xfffbffff;
    }
    (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    DAT_0068f0f4 = 0xffffffff;
  }
  else if (local_8 == 2) {
    FUN_00434660(s_prompts_txt_004f9c28,s_MISHRAS_FACTORY_004f9c18);
    uVar5 = FUN_004d7d5e(0x38e,0xffffffff,0xffffffff,0xffffffff,0,0,0,&DAT_006679f0,1,&local_14);
    uVar5 = FUN_004521e2(param_1,param_2,0,0,uVar5);
    iVar4 = FUN_0041e2a2(param_1,2,param_1,0x200,0,0,0,uVar5);
    if (iVar4 == 0) {
      DAT_00681ea4 = 1;
    }
    else {
      *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      FUN_0049b1eb(param_1,0,1);
      *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_14;
      *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
    }
    DAT_0068f0f4 = 0xffffffff;
  }
  else {
    DAT_00681ea4 = 1;
  }
  if (0 < DAT_0068f2c0) {
    DAT_0068f2c0 = DAT_0068f2c0 + -1;
  }
  return uVar3;
}


