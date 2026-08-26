/*
 * Decompiled function: Prompts_Load_004f8672
 * Entry Point: 004f8672
 * Size: 572 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004f8672(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (iVar1 = FUN_0040d949(spell_id,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      iVar1 = (&g_PlayerCreatureCount)[spell_id];
      iVar3 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                            target_id * 0x120 + spell_id * 0x5b20));
      g_SpellStackDepth = g_SpellStackDepth - (iVar1 * 0x18) / iVar3;
      Pic_Subsystem_00424500(s_prompts_txt_00530438,s_STREAMOFLIFE_00530428);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                         &g_OverworldGoldAmount,1,&local_c);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      (&g_PlayerCreatureCount)
      [*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20)] =
           (&g_PlayerCreatureCount)
           [*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20)] +
           *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


