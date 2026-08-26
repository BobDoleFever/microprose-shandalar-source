/*
 * Decompiled function: Card_StoneGiant_Fling
 * Entry Point: 004dc2ca
 * Size: 1021 bytes
 */
#include "magic.h"


undefined4 Card_StoneGiant_Fling(int spell_id,int target_id,int flags)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 arg_11;
  int iVar7;
  undefined4 arg_12;
  uint uVar8;
  undefined4 arg_13;
  undefined4 arg_14;
  uint uVar9;
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
    uVar2 = 0;
    if ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      uVar1 = (int)*(short *)(&g_CardSlot_Counters + target_id * 0x120 + spell_id * 0x5b20) - 1U |
              0x2000;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      uVar2 = FUN_00403250((int *)0x0,0,spell_id,spell_id,spell_id,0x200,2,0,0,uVar2,arg_11,arg_12,
                           arg_13,arg_14,uVar1,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ec14,s_STONE_GIANT_0052ec08);
      arg_20 = &local_10;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      iVar3 = FUN_00473179(spell_id,target_id,0x32,0xffffffff);
      uVar1 = iVar3 - 1U | 0x2000;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar3 = -1;
      uVar6 = 0;
      uVar5 = 0;
      uVar4 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar3 = Action_ValidateTarget_00405802
                        (spell_id,spell_id,spell_id,0x200,2,0,0,uVar4,uVar5,uVar6,iVar3,iVar7,uVar8,
                         uVar1,uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_10 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_c = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar1 = (int)*(short *)(&g_CardSlot_Counters + target_id * 0x120 + spell_id * 0x5b20) - 1U |
              0x2000;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar3 = -1;
      uVar6 = 0;
      uVar5 = 0;
      uVar4 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar3 = Rules_ParseFilter_0040360b
                        (local_10,local_c,(char *)0x0,spell_id,(byte)spell_id,(byte)spell_id,0x200,2
                         ,0,0,uVar4,uVar5,uVar6,iVar3,iVar7,uVar8,uVar1,uVar9,uVar10,uVar11);
      if (iVar3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        iVar3 = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,local_10,local_c);
        if (iVar3 != -1) {
          (&DAT_006a5f50)[iVar3 * 0x120 + spell_id * 0x5b20] = 5;
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar3 * 0x120 + spell_id * 0x5b20) = 0x20;
          *(undefined4 *)(&g_CardSlot_Abilities2 + local_10 * 0x5b20 + local_c * 0x120) = 0x8000000;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


