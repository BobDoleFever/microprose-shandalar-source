/*
 * Decompiled function: Card_RoyalAssassin_DestroyTapped
 * Entry Point: 004da858
 * Size: 504 bytes
 */
#include "magic.h"


undefined4 Card_RoyalAssassin_DestroyTapped(int spell_id,int target_id,int flags)

{
  int card_id;
  int color_mask;
  uint arg_11;
  uint arg_12;
  uint arg_13;
  int iVar1;
  int arg_15;
  uint arg_16;
  uint arg_17;
  uint arg_18;
  uint arg_19;
  uint arg_20;
  undefined4 local_8;
  
  if ((flags == 0x73) || (flags == 0x6d)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052eb8c,s_ROYAL_ASSASSIN_0052eb7c);
    local_8 = Card_Targeting_PromptCreature(spell_id,target_id,flags,1 - spell_id);
  }
  if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    local_8 = 0;
  }
  else {
    if (flags == 0x72) {
      card_id = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 1;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar1 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (card_id,color_mask,(char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,
                         arg_13,iVar1,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(card_id,color_mask,2);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      local_8 = 0;
    }
    if (((flags == 0x8a) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      DAT_006ff19c = DAT_006ff19c + 0x30;
    }
    if (((flags == 0x8b) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      DAT_006ff19c = DAT_006ff19c + -0x30;
    }
  }
  return local_8;
}


