/*
 * Decompiled function: Card_XenicPoltergeist_AnimateArtifact
 * Entry Point: 004d2610
 * Size: 970 bytes
 */
#include "magic.h"


undefined4 Card_XenicPoltergeist_AnimateArtifact(int spell_id,int target_id,int flags)

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
  int local_14;
  int local_10;
  int local_c;
  
  if (flags == 0x73) {
    if ((*(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0) {
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
      iVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0x40,2,0,uVar1,arg_11,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (flags == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052e97c,s_XENIC_POLTERGEIST_0052e968);
      arg_20 = &local_14;
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
                        (spell_id,2,spell_id,0x200,0x40,2,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_14;
        *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_10;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_14 = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
      local_10 = *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
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
                        (local_14,local_10,(char *)0x0,spell_id,2,2,0x200,0x40,2,0,uVar3,uVar4,uVar5
                         ,iVar2,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        local_c = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006809d8,local_14,local_10);
        if ((local_c != -1) &&
           (iVar2 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId + local_14 * 0x5b20 + local_10 * 0x120)
                                ), iVar2 != -1)) {
          *(int *)(&g_CardSlot_Controller + local_c * 0x120 + spell_id * 0x5b20) = iVar2;
          (&g_MasterCardColorTable)[iVar2 * 0x34] = 0x42;
          *(short *)(&DAT_0051aec4 + iVar2 * 0x34) =
               (short)(char)(&DAT_0051aec0)
                            [*(int *)(&g_CardSlot_CardId + local_14 * 0x5b20 + local_10 * 0x120) *
                             0x34];
          *(undefined2 *)(&DAT_0051aec2 + iVar2 * 0x34) =
               *(undefined2 *)(&DAT_0051aec4 + iVar2 * 0x34);
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
  }
  return 0;
}


