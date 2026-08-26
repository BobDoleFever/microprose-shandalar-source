/*
 * Decompiled function: Card_PirateShip_PingTarget
 * Entry Point: 004dfd39
 * Size: 347 bytes
 */
#include "magic.h"


bool Card_PirateShip_PingTarget(int spell_id,int target_id,int flags)

{
  bool bVar1;
  
  if (flags == 0x73) {
    bVar1 = (*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    bVar1 = false;
  }
  else {
    if (flags == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052eda0,s_PIRATE_SHIP_0052ed94);
      Card_DirectDamage_EvaluateBestTarget(spell_id,target_id);
      if (g_ActivePlayer != 1) {
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      Card_DirectDamage_PromptAndDealDamage(spell_id,target_id,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
    Card_PirateShip_HasIsland(spell_id,target_id,flags);
    bVar1 = false;
  }
  return bVar1;
}


