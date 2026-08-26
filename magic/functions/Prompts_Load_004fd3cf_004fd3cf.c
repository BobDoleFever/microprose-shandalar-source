/*
 * Decompiled function: Prompts_Load_004fd3cf
 * Entry Point: 004fd3cf
 * Size: 533 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004fd3cf(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (iVar1 = FUN_0040d949(spell_id,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0053071c,s_MINDTWIST_00530710);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_10);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      for (local_8 = 0;
          local_8 < *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
          local_8 = local_8 + 1) {
        Prompts_Load_0046fa40
                  (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),1,0);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


