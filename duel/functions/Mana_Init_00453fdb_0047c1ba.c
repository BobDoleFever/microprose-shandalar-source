/*
 * Decompiled function: Mana_Init_00453fdb
 * Entry Point: 0047c1ba
 * Size: 3033 bytes
 */
#include "duel.h"


undefined4 Mana_Init_00453fdb(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 arg_10;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 arg_11;
  int iVar8;
  undefined4 arg_12;
  uint uVar9;
  uint uVar10;
  undefined4 arg_14;
  uint uVar11;
  undefined4 arg_15;
  uint uVar12;
  undefined4 arg_16;
  uint uVar13;
  undefined4 arg_17;
  undefined *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_24;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 1) {
    uVar2 = FUN_0047a090(spell_id,target_id,1,0);
    return uVar2;
  }
  if (flags == 0x6c) {
    DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
  }
  if (flags == 0x71) {
    uVar2 = FUN_0047a090(spell_id,target_id,0x71,0);
    return uVar2;
  }
  if (flags == 0x73) {
    bVar1 = false;
    if ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] &
         2) == 0)))) {
      bVar1 = true;
    }
    iVar3 = FUN_0049b309(spell_id,7,1);
    if (iVar3 != 0) {
      bVar1 = true;
    }
    if (bVar1) {
      if ((spell_id == DAT_00676504) && (0 < DAT_0068f2c0)) {
        DAT_00676500 = DAT_00676500 | 3;
      }
      return 1;
    }
    return 0;
  }
  if (flags != 0x6d) {
    if (flags == 0x72) {
      local_8 = *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
      if (local_8 != 0) {
        if (local_8 == 1) {
          uVar2 = FUN_004d7d5e(0x38e);
          *(undefined4 *)
           (&DAT_006826c4 +
           *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = uVar2;
          *(undefined4 *)
           (&DAT_006826c8 +
           *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
               *(undefined4 *)
                (&DAT_006826c4 +
                *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120);
          *(int *)(&DAT_0068ee80 + DAT_00690af0 * 4) =
               *(int *)(&DAT_0068ee80 + DAT_00690af0 * 4) + 1;
          (&DAT_0068ee88)[DAT_00690af0] = (&DAT_0068ee88)[DAT_00690af0] + 1;
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                        *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) | 2
          ;
          FUN_0048c907(DAT_00690af0,DAT_0068efa0,0x6c,1 - DAT_00690af0,0xffffffff);
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                        *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) |
               0x80;
          FUN_0048c907(DAT_00690af0,DAT_0068efa0,0x71,1 - DAT_00690af0,0xffffffff);
        }
        else if ((local_8 == 2) && ((&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] != '\0'))
        {
          local_14 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
          local_10 = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
          uVar13 = 0;
          uVar12 = 0;
          uVar11 = 0;
          uVar10 = 0xffffffff;
          uVar9 = 0xffffffff;
          iVar8 = -1;
          iVar3 = FUN_004d7d5e(0x38e);
          uVar7 = 0;
          uVar6 = 0;
          uVar5 = FUN_004521e2(spell_id,target_id);
          iVar3 = Rules_ParseFilter_0041c0ab
                            (local_14,local_10,(undefined1 *)0x0,spell_id,2,2,0x200,0,0,0,uVar5,
                             uVar6,uVar7,iVar3,iVar8,uVar9,uVar10,uVar11,uVar12,uVar13);
          if (iVar3 == 0) {
            DAT_00681ea4 = 1;
          }
          else {
            local_c = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,local_14,local_10);
            if (local_c != -1) {
              *(undefined2 *)(&DAT_006826d8 + local_c * 0x120 + spell_id * 0x5b20) = 1;
              *(undefined2 *)(&DAT_006826da + local_c * 0x120 + spell_id * 0x5b20) = 1;
            }
          }
          (&DAT_006827b8)
          [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
        }
      }
      *(undefined4 *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
    }
    if (flags == 0x7f) {
      uVar2 = FUN_0047a090(spell_id,target_id,0x7f,0);
      return uVar2;
    }
    if (((((flags == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) && (target_id == DAT_00690c48)) &&
        ((spell_id == DAT_0068ecb0 && (iVar3 = FUN_0048a33f(spell_id,target_id), iVar3 != 0)))) &&
       (*(int *)(&DAT_006826c8 + target_id * 0x120 + spell_id * 0x5b20) != 0)) {
      DAT_0066642c = *(undefined4 *)(&DAT_006826c8 + target_id * 0x120 + spell_id * 0x5b20);
    }
    if (flags == 199) {
      if (spell_id == DAT_00676504) {
        DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
      }
      else {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x30;
      }
    }
    return 0;
  }
  uVar2 = 0;
  local_24 = 3;
  if ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2)
       == 0)))) {
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Get_mana__004f9b7c);
    local_24 = 0;
  }
  else {
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s__Get_mana__004f9b88);
  }
  iVar3 = FUN_0049b309(spell_id,7,1);
  if (iVar3 == 0) {
    FUN_004d9640((uint *)&DAT_005f6810,(uint *)s__Change_to_Assembly_Worker__004f9bb8);
  }
  else {
    FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Change_to_Assembly_Worker__004f9b98);
    if (DAT_0068f2c4 < 0x17) {
      local_24 = 1;
    }
  }
  if ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2)
       == 0)))) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    uVar4 = FUN_004d7d5e(0x38e);
    arg_12 = 0;
    arg_11 = 0;
    arg_10 = FUN_004521e2(spell_id,target_id);
    iVar3 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0,0,0,arg_10,arg_11,arg_12,uVar4,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if (iVar3 != 0) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Pump_Assembly_Worker__004f9bd8);
      if ((DAT_0068f2c4 < 0x1e) && (0x16 < DAT_0068f2c4)) {
        local_24 = 2;
      }
      goto LAB_0047c563;
    }
  }
  FUN_004d9640((uint *)&DAT_005f6810,(uint *)s__Pump_Assembly_Worker__004f9bf0);
LAB_0047c563:
  FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Cancel__004f9c0c);
  if (DAT_0068f220 == 0) {
    local_8 = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&DAT_005f6810,local_24);
  }
  else {
    local_8 = 0;
  }
  *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = local_8;
  if (local_8 == 0) {
    uVar2 = FUN_0047a090(spell_id,target_id,0x6d,0);
    (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
  }
  else if (local_8 == 1) {
    uVar5 = *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20);
    *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x40000;
    Ai_CalcManaRequirement_004ba890(spell_id,0,1);
    if ((uVar5 & 0x40000) == 0) {
      *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0xfffbffff;
    }
    (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    DAT_0068f0f4 = 0xffffffff;
  }
  else if (local_8 == 2) {
    FUN_00434660(s_prompts_txt_004f9c28,s_MISHRAS_FACTORY_004f9c18);
    arg_20 = &local_14;
    uVar4 = 1;
    arg_18 = &DAT_006679f0;
    uVar13 = 0;
    uVar12 = 0;
    uVar11 = 0;
    uVar10 = 0xffffffff;
    uVar9 = 0xffffffff;
    iVar8 = -1;
    iVar3 = FUN_004d7d5e(0x38e);
    uVar7 = 0;
    uVar6 = 0;
    uVar5 = FUN_004521e2(spell_id,target_id);
    iVar3 = Action_ValidateTarget_0041e2a2
                      (spell_id,2,spell_id,0x200,0,0,0,uVar5,uVar6,uVar7,iVar3,iVar8,uVar9,uVar10,
                       uVar11,uVar12,uVar13,arg_18,uVar4,arg_20);
    if (iVar3 == 0) {
      DAT_00681ea4 = 1;
    }
    else {
      *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      FUN_0049b1eb(spell_id,0,1);
      *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_14;
      *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_10;
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
    }
    DAT_0068f0f4 = 0xffffffff;
  }
  else {
    DAT_00681ea4 = 1;
  }
  if (0 < DAT_0068f2c0) {
    DAT_0068f2c0 = DAT_0068f2c0 + -1;
  }
  return uVar2;
}


