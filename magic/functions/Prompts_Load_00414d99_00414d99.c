/*
 * Decompiled function: Prompts_Load_00414d99
 * Entry Point: 00414d99
 * Size: 448 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_00414d99(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005197dc,s_MANASHORT_005197d0);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_10);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      iVar2 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      CardQuery_ForEachPermanent(FUN_00414f59,iVar2);
      for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
        *(undefined4 *)(&DAT_0063ee90 + local_8 * 4 + iVar2 * 0x20) = 0;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


