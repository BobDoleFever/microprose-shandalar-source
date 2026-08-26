/*
 * Decompiled function: Card_DwarvenWarriors_MakeUnblockable
 * Entry Point: 004dc6c7
 * Size: 806 bytes
 */
#include "magic.h"


undefined4 Card_DwarvenWarriors_MakeUnblockable(int spell_id,int target_id,int flags)

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
  int local_8;
  
  if (flags == 0x73) {
    uVar1 = 0;
    if ((*(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0x2002;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar1 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      uVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ec34,s_DWARVEN_WARRIORS_0052ec20);
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0x2002;
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
        *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_8;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0x2002;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar5 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,2,2,0x200,2,0,0,uVar2,uVar3,uVar4,
                         iVar5,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_00696734,local_c,local_8);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


