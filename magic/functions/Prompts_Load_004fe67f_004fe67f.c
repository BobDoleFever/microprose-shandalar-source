/*
 * Decompiled function: Prompts_Load_004fe67f
 * Entry Point: 004fe67f
 * Size: 642 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004fe67f(int spell_id,int target_id,int flags)

{
  int arg_5;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (iVar1 = FUN_0040d949(spell_id,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           g_TurnCounter;
      Pic_Subsystem_00424500(s_prompts_txt_00530950,s_DISINTEGRATE_00530940);
      iVar1 = Card_DirectDamage_EvaluateBestTarget(spell_id,target_id);
      if (iVar1 != 0) {
        iVar1 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20));
        g_SpellStackDepth = g_SpellStackDepth - (int)(0x30 / (longlong)iVar1);
      }
    }
    if (flags == 0x71) {
      iVar1 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      arg_5 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      iVar3 = Card_DirectDamage_PromptAndDealDamage
                        (spell_id,target_id,0x71,
                         *(int *)(&g_CardSlot_ConvertedManaCost +
                                 target_id * 0x120 + spell_id * 0x5b20));
      if ((iVar3 != 0) &&
         (*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
        iVar3 = FUN_00410cc0(spell_id,target_id,DAT_006a49ec,iVar1,arg_5);
        if (iVar3 != -1) {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar3 * 0x120 + spell_id * 0x5b20) = 0x200
          ;
        }
        *(undefined4 *)(&g_CardSlot_Abilities2 + arg_5 * 0x120 + iVar1 * 0x5b20) = 0x8000000;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


