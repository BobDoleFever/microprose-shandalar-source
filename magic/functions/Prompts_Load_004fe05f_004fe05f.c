/*
 * Decompiled function: Prompts_Load_004fe05f
 * Entry Point: 004fe05f
 * Size: 1568 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004fe05f(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined *arg_18;
  uint uVar9;
  uint uVar10;
  int *arg_20;
  uint uVar11;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        Pic_Subsystem_00424500(s_prompts_txt_00530934,s_PYROTECHNICS_00530924);
        local_c = 0;
        while ((local_c < 4 && (g_ActivePlayer != 1))) {
          arg_20 = &local_14;
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
                            (spell_id,2,1 - spell_id,0x1200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,
                             uVar7,uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
          if (iVar5 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) | 0x200000;
            Ai_Subsystem_004cc9c5(0,0x20);
            *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8)
                 = local_14;
            *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8)
                 = local_10;
            (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
                 (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
          }
          local_c = local_c + 1;
        }
        for (local_c = 0;
            local_c < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            local_c = local_c + 1) {
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura +
                           target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x120 +
                   *(int *)(&g_CardSlot_CombatTarget +
                           target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura +
                                target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x120 +
                        *(int *)(&g_CardSlot_CombatTarget +
                                target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x5b20) &
               0xffcfffff;
        }
        if (g_ActivePlayer == 1) {
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        }
      }
      else {
        for (local_c = 0; local_c < 4; local_c = local_c + 1) {
          Card_DirectDamage_EvaluateBestTarget(spell_id,target_id);
          *(undefined4 *)
           (&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20 + (3 - local_c) * 8) =
               *(undefined4 *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
          *(undefined4 *)
           (&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20 + (3 - local_c) * 8) =
               *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 4;
        }
      }
    }
    if (flags == 0x71) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        local_8 = 0;
        for (local_c = 0;
            local_c < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
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
                                     target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                             (char *)0x0,spell_id,2,2,0x1200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,
                             uVar7,uVar8,uVar9,uVar10,uVar11);
          if (iVar5 == 0) {
            local_8 = local_8 + 1;
          }
          else {
            FUN_0041db67(*(int *)(&g_CardSlot_CombatTarget +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),1,spell_id,
                         target_id);
          }
        }
        if ((char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] == local_8) {
          g_ActivePlayer = 1;
        }
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
      else {
        for (local_c = 0; local_c < 4; local_c = local_c + 1) {
          *(undefined4 *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)
                (&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)
                (&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
          Card_DirectDamage_PromptAndDealDamage(spell_id,target_id,0x71,1);
        }
      }
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


