/*
 * Decompiled function: Prompts_Load_0041c8e1
 * Entry Point: 0041c8e1
 * Size: 697 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_0041c8e1(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if ((((byte)g_PlayerHandCardCount & 4) == 0) ||
       (iVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,0xffffffff,
                             0xffffffff,0xffffffff,0x20,0,0), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 99;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519bdc,s_EYE_FOR_EYE_00519bd0);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,0xffffffff,0x20,0
                         ,0,&g_OverworldGoldAmount,1,&local_c);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if ((int)(&g_PlayerCreatureCount)[1 - spell_id] < 1) {
          g_SpellStackDepth = g_SpellStackDepth + 1000;
        }
        else {
          g_SpellStackDepth =
               g_SpellStackDepth +
               (*(int *)(&g_CardSlot_ConvertedManaCost + local_c * 0x5b20 + local_8 * 0x120) * 100)
               / (int)(&g_PlayerCreatureCount)[1 - spell_id];
        }
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      Mem_AllocOrFree_0041df33
                ((int)(char)(&g_CardSlot_DamageReceived)
                            [*(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20) * 0x120],
                 *(int *)(&g_CardSlot_ConvertedManaCost +
                         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x5b20 +
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x120),spell_id,target_id);
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


