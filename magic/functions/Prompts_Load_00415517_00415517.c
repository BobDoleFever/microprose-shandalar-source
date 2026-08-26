/*
 * Decompiled function: Prompts_Load_00415517
 * Entry Point: 00415517
 * Size: 434 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_00415517(int spell_id,int target_id,int flags)

{
  int color_mask;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,0,0,0,0xffffffff,0xffffffff,
                         0xffffffff,0xffffffff,0,0,0);
  }
  else {
    if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519828,s_SHATTER_00519820);
      iVar2 = CardTarget_PromptTargetPlayerOrCreature(spell_id,1 - spell_id,target_id);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x10;
      }
    }
    if (flags == 0x71) {
      iVar2 = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      iVar3 = Rules_ParseFilter_0040360b
                        (iVar2,color_mask,(char *)0x0,spell_id,2,2,0x200,0x40,0,0,0,0,0,-1,-1,
                         0xffffffff,0xffffffff,0,0,0);
      if (iVar3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(iVar2,color_mask,1);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


