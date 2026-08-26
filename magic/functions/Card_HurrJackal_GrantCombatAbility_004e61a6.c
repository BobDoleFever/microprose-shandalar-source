/*
 * Decompiled function: Card_HurrJackal_GrantCombatAbility
 * Entry Point: 004e61a6
 * Size: 932 bytes
 */
#include "magic.h"


undefined4 Card_HurrJackal_GrantCombatAbility(int spell_id,int target_id,int flags)

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
  int local_10;
  int local_c;
  
  if (flags == 0x73) {
    if ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0) {
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
      iVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052efe0,s_HURR_JACKAL_0052efd4);
      arg_20 = &local_10;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar2 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        if (((&DAT_006a5f6d)[local_10 * 0x5b20 + local_c * 0x120] & 2) == 0) {
          g_SpellStackDepth = g_SpellStackDepth + -0x30;
        }
        else {
          g_SpellStackDepth = g_SpellStackDepth + 0x18;
        }
      }
    }
    if (flags == 0x72) {
      local_10 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_c = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar2 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (local_10,local_c,(char *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,
                         iVar2,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        iVar2 = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a4b64,local_10,local_c);
        if (iVar2 != -1) {
          *(uint *)(&g_CardSlot_Abilities1 + iVar2 * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + iVar2 * 0x120 + spell_id * 0x5b20) | 0x800000;
          *(undefined4 *)(&g_CardSlot_Abilities2 + local_10 * 0x5b20 + local_c * 0x120) = 0x8000000;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
  }
  return 0;
}


