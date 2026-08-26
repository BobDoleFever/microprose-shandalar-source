/*
 * Decompiled function: Pic_Subsystem_0042bb2e
 * Entry Point: 0042bb2e
 * Size: 951 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042bb2e(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 1;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    uVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521288,s_ANIMATE_WALL_00521278);
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar5 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,
                         uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_8;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    if (flags == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar5 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
        *(uint *)(&g_CardSlot_Abilities1 +
                 *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) *
                 0x120 + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                         0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 +
                      *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) *
                      0x120 + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                              0x5b20) | 0x800;
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((flags == 0x77) && (target_id == g_OverworldMapGrid)) &&
       ((spell_id == g_OverworldPlayerCoordX &&
        (*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) != -1)))) {
      *(uint *)(&g_CardSlot_Abilities1 +
               *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) * 0x120
               + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 +
                    *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) *
                    0x120 + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                            0x5b20) & 0xfffff7ff;
    }
    uVar1 = 0;
  }
  return uVar1;
}


