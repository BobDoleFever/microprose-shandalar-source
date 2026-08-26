/*
 * Decompiled function: Minit_Subsystem_0045b156
 * Entry Point: 0045b156
 * Size: 940 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045b156(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    iVar1 = FUN_0040d949(spell_id,7,2);
    if (((iVar1 == 0) ||
        ((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) != 0))
        )) || (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((((flags == 0x6d) &&
         (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
        (iVar1 = FUN_0040d949(spell_id,7,2), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_005243e0,s_MILLSTONE_005243d4);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_18);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_18;
        *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_14
        ;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      iVar1 = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
      for (local_c = 0; local_c < 2; local_c = local_c + 1) {
        local_10 = *(int *)(&DAT_0069e730 + iVar1 * 2000);
        if (local_10 != -1) {
          Pic_Subsystem_004523fd(iVar1,0);
          local_8 = Pic_Subsystem_00451291(iVar1,local_10);
          if (local_8 != -1) {
            Pic_Subsystem_0044913a(iVar1,local_8);
            *(undefined4 *)(&g_CardSlot_CardId + local_8 * 0x120 + iVar1 * 0x5b20) = 0xffffffff;
          }
        }
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x18);
        }
        if ((g_ScWillyScore == 0x1f) && (g_DefendingPlayer == g_CurrentTurnPhase)) {
          g_SpellStackDepth = g_SpellStackDepth + 0x18;
        }
      }
    }
    if (flags == 199) {
      if (spell_id == g_ActivePlayerPriority) {
        g_SpellStackDepth = g_SpellStackDepth + 0x18;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


