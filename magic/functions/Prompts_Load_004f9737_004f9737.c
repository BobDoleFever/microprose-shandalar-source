/*
 * Decompiled function: Prompts_Load_004f9737
 * Entry Point: 004f9737
 * Size: 1153 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004f9737(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int *arg_20;
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
  undefined *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
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
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    FUN_00403250(&local_10,0,spell_id,2,2,0x200,2,0x40,0,uVar1,arg_11,arg_12,arg_13,arg_14,arg_15,
                 arg_16,arg_17,arg_18_00,arg_19);
    if (local_10 < 2) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      local_c = 0;
      while ((local_c < 2 && (g_ActivePlayer != 1))) {
        Pic_Subsystem_00424500(s_prompts_txt_005304c4,s_ASHESTOASHES_005304b4);
        arg_20 = (int *)(&g_CardSlot_CombatTarget +
                        target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
        uVar1 = 1;
        arg_18 = &g_OverworldGoldAmount + local_c * 0xfa;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar5 = -1;
        uVar4 = 0;
        uVar3 = 0;
        uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
        iVar5 = Action_ValidateTarget_00405802
                          (spell_id,2,1 - spell_id,0x200,2,0x40,0,uVar2,uVar3,uVar4,iVar5,iVar6,
                           uVar7,uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
        if (iVar5 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura +
                           local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_CombatTarget +
                           local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura +
                                local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                        *(int *)(&g_CardSlot_CombatTarget +
                                local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) |
               0x300000;
          Ai_Subsystem_004cc9c5(0,0x20);
        }
        local_c = local_c + 1;
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 2;
      for (local_c = 0;
          local_c < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
          local_c = local_c + 1) {
        *(uint *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_AttachedAura +
                         local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_CombatTarget +
                         local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_AttachedAura +
                              local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget +
                              local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) &
             0xffcfffff;
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      }
    }
    if (flags == 0x71) {
      local_8 = 0;
      for (local_c = 0;
          local_c < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
          local_c = local_c + 1) {
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar5 = -1;
        uVar4 = 0;
        uVar3 = 0;
        uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
        iVar5 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget +
                                   local_c * 8 + target_id * 0x120 + spell_id * 0x5b20),
                           *(int *)(&g_CardSlot_AttachedAura +
                                   local_c * 8 + target_id * 0x120 + spell_id * 0x5b20),(char *)0x0,
                           spell_id,2,2,0x200,2,0x40,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,
                           uVar9,uVar10,uVar11);
        if (iVar5 == 0) {
          local_8 = local_8 + 1;
        }
        else {
          Pic_Subsystem_0044867e
                    (*(int *)(&g_CardSlot_CombatTarget +
                             local_c * 8 + target_id * 0x120 + spell_id * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura +
                             local_c * 8 + target_id * 0x120 + spell_id * 0x5b20),4);
        }
      }
      if (local_8 == 2) {
        g_ActivePlayer = 1;
      }
      else {
        Mem_AllocOrFree_0041df33(spell_id,5,spell_id,target_id);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


