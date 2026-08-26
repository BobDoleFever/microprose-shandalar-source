/*
 * Decompiled function: Card_OrcishArtillery_ShootTarget
 * Entry Point: 004e0ab7
 * Size: 357 bytes
 */
#include "magic.h"


bool Card_OrcishArtillery_ShootTarget(int spell_id,int target_id,int flags)

{
  int iVar1;
  bool bVar2;
  
  if (flags == 0x73) {
    bVar2 = (*(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0;
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    bVar2 = false;
  }
  else {
    if (flags == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ede4,s_ORCISH_ARTILLERY_0052edd0);
      Card_DirectDamage_EvaluateBestTarget(spell_id,target_id);
      if (g_ActivePlayer != 1) {
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      iVar1 = Card_DirectDamage_PromptAndDealDamage(spell_id,target_id,0x72,2);
      if (iVar1 != 0) {
        Mem_AllocOrFree_0041df33(spell_id,3,spell_id,target_id);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
    bVar2 = false;
  }
  return bVar2;
}


