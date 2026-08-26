/*
 * Decompiled function: Minit_Subsystem_0045a825
 * Entry Point: 0045a825
 * Size: 474 bytes
 */
#include "magic.h"


bool Minit_Subsystem_0045a825(int spell_id,int target_id,int flags)

{
  bool bVar1;
  int iVar2;
  
  if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
     (spell_id == g_OverworldPlayerCoordX)) {
    Card_SetCounters(spell_id,target_id,3);
  }
  if (((flags == 0x32) || (flags == 0x33)) &&
     ((target_id == g_OverworldMapGrid && (spell_id == g_OverworldPlayerCoordX)))) {
    iVar2 = Card_GetCounters(spell_id,target_id);
    g_ActivePalette = g_ActivePalette + iVar2;
  }
  if (flags == 0x73) {
    iVar2 = Card_GetCounters(spell_id,target_id);
    bVar1 = 0 < iVar2;
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    bVar1 = false;
  }
  else {
    if ((flags == 0x6d) && (iVar2 = Card_GetCounters(spell_id,target_id), 0 < iVar2)) {
      Pic_Subsystem_00424500(s_prompts_txt_005243ac,s_TRISKELION_005243a0);
      iVar2 = Card_DirectDamage_EvaluateBestTarget(spell_id,target_id);
      if (iVar2 != 0) {
        *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x6000000;
        Card_DecrementCounter(spell_id,target_id);
      }
    }
    if (flags == 0x72) {
      Card_DirectDamage_PromptAndDealDamage(spell_id,target_id,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    bVar1 = false;
  }
  return bVar1;
}


