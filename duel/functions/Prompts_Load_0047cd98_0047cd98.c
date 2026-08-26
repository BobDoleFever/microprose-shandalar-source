/*
 * Decompiled function: Prompts_Load_0047cd98
 * Entry Point: 0047cd98
 * Size: 2960 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0047cd98(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 arg_10;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_24;
  undefined4 local_20;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x22) {
    uVar1 = FUN_004d7d5e(0x1fc);
    *(undefined4 *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) = uVar1;
    *(undefined4 *)(&DAT_006826c8 + spell_id * 0x5b20 + target_id * 0x120) = 0;
    (&DAT_0068ee88)[spell_id] = (&DAT_0068ee88)[spell_id] + -1;
    *(int *)(&DAT_0068ee80 + spell_id * 4) = *(int *)(&DAT_0068ee80 + spell_id * 4) + -1;
    DAT_00692c6c = spell_id;
    DAT_00692c68 = target_id;
    FUN_00467d65(FUN_0047d928,spell_id);
  }
  if (((flags == 0x77) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    uVar1 = FUN_004d7d5e(0x1fc);
    *(undefined4 *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) = uVar1;
    return 0;
  }
  if (flags == 1) {
    uVar1 = FUN_0047a090(spell_id,target_id,1,0);
    return uVar1;
  }
  if (flags == 0x71) {
    uVar1 = FUN_0047a090(spell_id,target_id,0x71,0);
    return uVar1;
  }
  if (flags == 0x73) {
    local_18 = 0;
    if ((((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
       ((((&DAT_006826ce)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) * 0x34] &
         2) == 0)))) {
      local_18 = 1;
    }
    iVar2 = FUN_0049b309(spell_id,7,1);
    if (iVar2 == 0) {
      return local_18;
    }
    return 1;
  }
  if (flags != 0x6d) {
    if (flags == 0x72) {
      local_8 = *(int *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120);
      if (local_8 != 0) {
        if (local_8 == 1) {
          uVar1 = FUN_004d7d5e(0x38e);
          *(undefined4 *)
           (&DAT_006826c4 +
           *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120) = uVar1;
          *(undefined4 *)
           (&DAT_006826c8 +
           *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120) =
               *(undefined4 *)
                (&DAT_006826c4 +
                *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
                *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120);
          *(int *)(&DAT_0068ee80 + DAT_00690af0 * 4) =
               *(int *)(&DAT_0068ee80 + DAT_00690af0 * 4) + 1;
          (&DAT_0068ee88)[DAT_00690af0] = (&DAT_0068ee88)[DAT_00690af0] + 1;
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                   *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                        *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) |
               2;
          FUN_0048c907(DAT_00690af0,DAT_0068efa0,0x6c,1 - DAT_00690af0,0xffffffff);
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                   *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                        *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) |
               0x80;
          FUN_0048c907(DAT_00690af0,DAT_0068efa0,0x71,1 - DAT_00690af0,0xffffffff);
        }
        else if ((local_8 == 2) && ((&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] != '\0'))
        {
          local_14 = *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120);
          local_10 = *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
          uVar11 = 0;
          uVar10 = 0;
          uVar9 = 0;
          uVar8 = 0xffffffff;
          uVar7 = 0xffffffff;
          iVar6 = -1;
          iVar2 = FUN_004d7d5e(0x38e);
          uVar5 = 0;
          uVar4 = 0;
          uVar3 = FUN_004521e2(spell_id,target_id);
          iVar2 = Rules_ParseFilter_0041c0ab
                            (local_14,local_10,(undefined1 *)0x0,spell_id,2,2,0x200,0,0,0,uVar3,
                             uVar4,uVar5,iVar2,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
          if (iVar2 == 0) {
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
          [*(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
        }
      }
      *(undefined4 *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120) = 0;
    }
    if (flags == 0x7f) {
      uVar1 = FUN_0047a090(spell_id,target_id,0x7f,0);
      return uVar1;
    }
    return 0;
  }
  local_20 = 0;
  local_24 = 3;
  if ((((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
     ((((&DAT_006826ce)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2)
       == 0)))) {
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Get_mana__004f9c34);
    local_24 = 0;
  }
  else {
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s__Get_mana__004f9c40);
  }
  iVar2 = FUN_0049b309(spell_id,7,1);
  if (iVar2 == 0) {
    FUN_004d9640((uint *)&DAT_005f6810,(uint *)s__Re_change_to_Assembly_Worker__004f9c70);
  }
  else {
    FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Re_change_to_Assembly_Worker__004f9c50);
  }
  if ((((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
     ((((&DAT_006826ce)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2)
       == 0)))) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    uVar1 = FUN_004d7d5e(0x38e);
    arg_12 = 0;
    arg_11 = 0;
    arg_10 = FUN_004521e2(spell_id,target_id);
    iVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0,0,0,arg_10,arg_11,arg_12,uVar1,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if (iVar2 != 0) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Pump_Assembly_Worker__004f9c94);
      if ((DAT_0068f2c4 < 0x1e) && (0x16 < DAT_0068f2c4)) {
        local_24 = 2;
      }
      goto LAB_0047d1c9;
    }
  }
  FUN_004d9640((uint *)&DAT_005f6810,(uint *)s__Pump_Assembly_Worker__004f9cac);
LAB_0047d1c9:
  FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Cancel__004f9cc8);
  if (DAT_0068f220 == 0) {
    local_8 = FUN_0045102d(spell_id,spell_id,target_id,-1,-1,&DAT_005f6810,local_24);
  }
  else {
    local_8 = 0;
  }
  *(int *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) = local_8;
  if (local_8 == 0) {
    local_20 = FUN_0047a090(spell_id,target_id,0x6d,0);
    (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
  }
  else if (local_8 == 1) {
    uVar3 = *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120);
    *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x40000;
    FUN_0042b6b0(spell_id,0,1);
    if ((uVar3 & 0x40000) == 0) {
      *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0xfffbffff;
    }
    (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    DAT_0068f0f4 = 0xffffffff;
  }
  else if (local_8 == 2) {
    FUN_00434660(s_prompts_txt_004f9ce4,s_ASSEMBLY_WORKER_004f9cd4);
    arg_20 = &local_14;
    uVar1 = 1;
    arg_18 = &DAT_006679f0;
    uVar11 = 0;
    uVar10 = 0;
    uVar9 = 0;
    uVar8 = 0xffffffff;
    uVar7 = 0xffffffff;
    iVar6 = -1;
    iVar2 = FUN_004d7d5e(0x38e);
    uVar5 = 0;
    uVar4 = 0;
    uVar3 = FUN_004521e2(spell_id,target_id);
    iVar2 = Action_ValidateTarget_0041e2a2
                      (spell_id,2,spell_id,0x200,0,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,uVar8,
                       uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
    if (iVar2 == 0) {
      DAT_00681ea4 = 1;
    }
    else {
      *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      FUN_0049b1eb(spell_id,0,1);
      *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = local_14;
      *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = local_10;
      (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
    }
    DAT_0068f0f4 = 0xffffffff;
  }
  else {
    DAT_00681ea4 = 1;
  }
  return local_20;
}


