/*
 * Decompiled function: Prompts_Load_004f899b
 * Entry Point: 004f899b
 * Size: 1852 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004f899b(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
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
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 3;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    FUN_00403250((int *)(-(uint)(DAT_0063ee88 == 0) & 0x6b2d68),0,spell_id,2,2,0x200,0,0,0,uVar1,
                 arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if ((spell_id == g_ActivePlayerPriority) &&
       ((g_OverworldPlayerCoordY == 0 || (iVar2 = FUN_0040d949(spell_id,7,4), iVar2 == 0)))) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    return uVar1;
  }
  if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
     (spell_id == g_OverworldPlayerCoordX)) {
    iVar2 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                          spell_id * 0x5b20 + target_id * 0x120));
    g_SpellStackDepth = g_SpellStackDepth - (int)(0x24 / (longlong)iVar2);
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    local_18 = 0;
    local_10 = 0;
    while (((local_18 < g_TurnCounter && (local_10 == 0)) && (g_ActivePlayer != 1))) {
      local_14 = FUN_0041d963(spell_id,target_id,4);
      local_14 = local_14 + -1;
      Pic_Subsystem_00424500(s_prompts_txt_00530458,s_VOLCANIC_ERUPTION_00530444);
      sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,local_18 + 1,g_TurnCounter);
      if (local_14 == 4) {
        FUN_004f4a92(&g_OverworldGoldAmount,s_mountain_0053046c,0,s_PLAINS_00530464);
      }
      else if (local_14 == 0) {
        FUN_004f4a92(&g_OverworldGoldAmount,s_mountain_00530480,0,s_SWAMP_00530478);
      }
      else if (local_14 == 1) {
        FUN_004f4a92(&g_OverworldGoldAmount,s_mountain_00530494,0,s_ISLAND_0053048c);
      }
      else if (local_14 == 2) {
        FUN_004f4a92(&g_OverworldGoldAmount,s_mountain_005304a8,0,s_FOREST_005304a0);
      }
      arg_20 = &local_20;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      iVar2 = local_14;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,0,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        if (local_1c == -1) {
          g_ActivePlayer = 1;
        }
        else {
          local_10 = 1;
        }
      }
      else {
        *(uint *)(&g_CardSlot_Flags + local_20 * 0x5b20 + local_1c * 0x120) =
             *(uint *)(&g_CardSlot_Flags + local_20 * 0x5b20 + local_1c * 0x120) | 0x300000;
        Ai_Subsystem_004cc9c5(0,0x20);
        *(int *)(&g_CardSlot_CombatTarget +
                spell_id * 0x5b20 +
                target_id * 0x120 +
                (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
             local_20;
        *(int *)(&g_CardSlot_AttachedAura +
                spell_id * 0x5b20 +
                target_id * 0x120 +
                (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
             local_1c;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] + '\x01';
      }
      local_18 = local_18 + 1;
    }
    for (local_18 = 0;
        local_18 < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
        local_18 = local_18 + 1) {
      *(uint *)(&g_CardSlot_Flags +
               *(int *)(&g_CardSlot_CombatTarget +
                       spell_id * 0x5b20 + target_id * 0x120 + local_18 * 8) * 0x5b20 +
               *(int *)(&g_CardSlot_AttachedAura +
                       spell_id * 0x5b20 + target_id * 0x120 + local_18 * 8) * 0x120) =
           *(uint *)(&g_CardSlot_Flags +
                    *(int *)(&g_CardSlot_CombatTarget +
                            spell_id * 0x5b20 + target_id * 0x120 + local_18 * 8) * 0x5b20 +
                    *(int *)(&g_CardSlot_AttachedAura +
                            spell_id * 0x5b20 + target_id * 0x120 + local_18 * 8) * 0x120) &
           0xffcfffff;
    }
    if (g_ActivePlayer == 1) {
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
  }
  if (flags == 0x71) {
    local_14 = FUN_0041d963(spell_id,target_id,4);
    local_14 = local_14 + -1;
    local_8 = 0;
    for (local_18 = 0;
        local_18 < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
        local_18 = local_18 + 1) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      iVar2 = local_14;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget +
                                 local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20),(char *)0x0,
                         spell_id,2,2,0x200,0,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,uVar8,uVar9,
                         uVar10,uVar11);
      if (iVar2 == 0) {
        local_8 = local_8 + 1;
      }
      else {
        Pic_Subsystem_0044867e
                  (*(int *)(&g_CardSlot_CombatTarget +
                           local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20),
                   *(int *)(&g_CardSlot_AttachedAura +
                           local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20),2);
      }
    }
    if ((char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] == local_8) {
      g_ActivePlayer = 1;
    }
    if ((g_ActivePlayer != 1) &&
       (local_c = Pic_Subsystem_00451291(spell_id,DAT_006ff564), local_c != -1)) {
      *(undefined4 *)(&g_ActiveCardsInPlay + local_c * 0x120 + spell_id * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120);
      *(uint *)(&g_CardSlot_Flags + local_c * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + local_c * 0x120 + spell_id * 0x5b20) | 2;
      *(undefined4 *)(&DAT_006a5f74 + local_c * 0x120 + spell_id * 0x5b20) = 0x109;
      *(int *)(&g_CardSlot_ConvertedManaCost + local_c * 0x120 + spell_id * 0x5b20) =
           (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] - local_8;
      FUN_00476482(spell_id,local_c);
    }
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    Pic_Subsystem_0044867e(spell_id,target_id,1);
  }
  return 0;
}


