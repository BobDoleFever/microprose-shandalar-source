/*
 * Decompiled function: Card_BrothersOfFire_Ping
 * Entry Point: 004df04a
 * Size: 450 bytes
 */
#include "magic.h"


undefined4 Card_BrothersOfFire_Ping(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  
  if (flags == 0x73) {
    iVar1 = FUN_0040d949(spell_id,4,2);
    if ((iVar1 == 0) || (iVar1 = FUN_0040d949(spell_id,7,3), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    uVar2 = 0;
  }
  else {
    if (flags == 0x6d) {
      DAT_006b2d40 = 1;
      Ai_CalcManaRequirement_004ba890(spell_id,4,2);
      if (g_ActivePlayer != 1) {
        Pic_Subsystem_00424500(s_prompts_txt_0052ed48,s_BROTHERS_OF_FIRE_0052ed34);
      }
      Card_DirectDamage_EvaluateBestTarget(spell_id,target_id);
    }
    if (flags == 0x72) {
      iVar1 = Card_DirectDamage_PromptAndDealDamage(spell_id,target_id,0x72,1);
      if (iVar1 != 0) {
        *(uint *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                 ) = *(uint *)(&g_CardSlot_Flags +
                              *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20)
                              * 0x5b20 +
                              *(int *)(&g_CardSlot_SicknessState +
                                      target_id * 0x120 + spell_id * 0x5b20) * 0x120) & 0xffffffef;
        Mem_AllocOrFree_0041df33(spell_id,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


