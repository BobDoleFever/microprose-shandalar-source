/*
 * Decompiled function: Card_NorthernPaladin_DestroyBlack
 * Entry Point: 004da482
 * Size: 982 bytes
 */
#include "magic.h"


undefined4 Card_NorthernPaladin_DestroyBlack(int spell_id,int target_id,int flags)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint uVar7;
  int iVar8;
  undefined4 arg_12;
  uint uVar9;
  undefined4 arg_13;
  uint uVar10;
  undefined4 arg_14;
  uint uVar11;
  undefined4 arg_15;
  uint uVar12;
  undefined4 arg_16;
  uint uVar13;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (flags == 1) {
    *(int *)(&DAT_006ff6a4 + spell_id * 0x20) = *(int *)(&DAT_006ff6a4 + spell_id * 0x20) + 1;
  }
  if (flags == 0x73) {
    bVar6 = (*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
    if ((bVar6) && (iVar2 = FUN_0040d949(spell_id,5,2), iVar2 == 0)) {
      bVar6 = false;
    }
    uVar3 = 0;
    if (bVar6) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      bVar1 = FUN_0041d9d2(spell_id,target_id,1);
      iVar2 = 1 << (bVar1 & 0x1f);
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      uVar3 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0x1047,0,0,uVar3,iVar2,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar3 = 0;
  }
  else {
    if ((((flags == 0x6d) && (iVar2 = FUN_0040d949(spell_id,5,2), iVar2 != 0)) &&
        ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,5,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052eb70,s_NORTHERN_PALADIN_0052eb5c);
      arg_20 = &local_c;
      uVar3 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar13 = 0;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0xffffffff;
      uVar9 = 0xffffffff;
      iVar8 = -1;
      iVar2 = -1;
      uVar7 = 0;
      bVar1 = FUN_0041d9d2(spell_id,target_id,1);
      uVar5 = 1 << (bVar1 & 0x1f);
      uVar4 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,2,0x200,0x1047,0,0,uVar4,uVar5,uVar7,iVar2,iVar8,uVar9,uVar10,
                         uVar11,uVar12,uVar13,arg_18,uVar3,arg_20);
      if (iVar2 == 0) {
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
      uVar13 = 0;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0xffffffff;
      uVar9 = 0xffffffff;
      iVar8 = -1;
      iVar2 = -1;
      uVar7 = 0;
      bVar1 = FUN_0041d9d2(spell_id,target_id,1);
      uVar5 = 1 << (bVar1 & 0x1f);
      uVar4 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,2,2,0x200,0x1047,0,0,uVar4,uVar5,uVar7
                         ,iVar2,iVar8,uVar9,uVar10,uVar11,uVar12,uVar13);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(local_c,local_8,2);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}


