/*
 * Decompiled function: Prompts_Load_004ff17f
 * Entry Point: 004ff17f
 * Size: 492 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004ff17f(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00530998,s_DRAIN_POWER_0053098c);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_14);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_14;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_10
        ;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      local_8 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      CardQuery_ForEachPermanent(FUN_004ff36b,local_8);
      if (local_8 != spell_id) {
        for (local_c = 0; local_c < 8; local_c = local_c + 1) {
          *(int *)(&DAT_0063ee90 + local_c * 4 + spell_id * 0x20) =
               *(int *)(&DAT_0063ee90 + local_c * 4 + spell_id * 0x20) +
               *(int *)(&DAT_0063ee90 + local_c * 4 + local_8 * 0x20);
          *(undefined4 *)(&DAT_0063ee90 + local_c * 4 + local_8 * 0x20) = 0;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


