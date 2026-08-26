/*
 * Decompiled function: Minit_Subsystem_004622d9
 * Entry Point: 004622d9
 * Size: 1012 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004622d9(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    if (((((byte)g_PlayerHandCardCount & 4) == 0) ||
        (iVar1 = FUN_0040d949(spell_id,7,2), iVar1 == 0)) ||
       (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0))
        || ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0 ||
            (iVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,
                                  0xffffffff,0xffffffff,0xffffffff,0,0,0), iVar1 == 0)))))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 99;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if (((flags == 0x6d) && (iVar1 = FUN_0040d949(spell_id,7,2), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_005245ec,s_AMULET_KROOG_005245dc);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,0xffffffff
                         ,0,0,0,&g_OverworldGoldAmount,1,&local_c);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      iVar1 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,
                         0xffffffff,0xffffffff,0,0,0);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else if (*(int *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + local_c * 0x5b20) != 0) {
        *(int *)(&g_CardSlot_ConvertedManaCost + local_c * 0x5b20 + local_8 * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost + local_c * 0x5b20 + local_8 * 0x120) + -1;
      }
    }
    if (((flags == 0x3b) &&
        (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       (iVar1 = FUN_0040d949(spell_id,7,2), iVar1 != 0)) {
      *(int *)(&DAT_00695eb8 + spell_id * 4) = *(int *)(&DAT_00695eb8 + spell_id * 4) + 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}


