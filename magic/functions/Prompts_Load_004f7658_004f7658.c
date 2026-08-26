/*
 * Decompiled function: Prompts_Load_004f7658
 * Entry Point: 004f7658
 * Size: 529 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004f7658(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    if ((spell_id == g_ActivePlayerPriority) && (iVar1 = FUN_0040d949(spell_id,7,3), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00530350,s_BRAINGEYSER_00530344);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                         &g_OverworldGoldAmount,1,&local_14);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             g_TurnCounter;
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_14;
        *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_10
        ;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    if (flags == 0x71) {
      local_8 = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
      for (local_c = 0;
          local_c < *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120);
          local_c = local_c + 1) {
        FUN_0046f5d1(local_8);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


