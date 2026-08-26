/*
 * Decompiled function: Minit_Subsystem_004617ad
 * Entry Point: 004617ad
 * Size: 1012 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004617ad(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
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
  int local_c;
  int local_8;
  
  if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
     (spell_id == g_OverworldPlayerCoordX)) {
    g_SpellStackDepth =
         g_SpellStackDepth + *(int *)(&DAT_006b2e5c + g_ActivePlayerPriority * 0x20) * 3;
  }
  if (flags == 0x73) {
    if (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
           (iVar1 = FUN_0040d949(spell_id,7,3), iVar1 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       ((iVar1 = FUN_0040d949(spell_id,7,3), iVar1 != 0 &&
        (Ai_CalcManaRequirement_004ba890(spell_id,0,3), g_ActivePlayer != 1)))) {
      Pic_Subsystem_00424500(s_prompts_txt_005245b4,s_JANDORS_SADDLEBAGS_005245a0);
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,uVar8,
                         uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,
                         iVar1,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) & 0xffffffef;
      }
    }
  }
  return 0;
}


