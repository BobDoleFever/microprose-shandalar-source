/*
 * Decompiled function: Pic_Subsystem_0043fe8e
 * Entry Point: 0043fe8e
 * Size: 1014 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043fe8e(int spell_id,int target_id,int flags,int height)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
        (g_OverworldPlayerCoordX == spell_id)) &&
       (iVar2 = FUN_004fa4b8(spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20),spell_id),
       iVar2 == 0)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_0063ee30 + height * 4 + g_CurrentTurnPhase * 0x20) +
           *(int *)(&DAT_006b2e40 + height * 4 + g_CurrentTurnPhase * 0x20) / 2) * 0x18;
    }
    if (flags == 0x73) {
      if (((((byte)g_PlayerHandCardCount & 4) == 0) ||
          (iVar2 = FUN_0040dcca(spell_id,target_id,7,1), iVar2 == 0)) ||
         (iVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,1 << ((byte)height & 0x1f),0,
                               DAT_006ff2e0,0xffffffff,0xffffffff,0xffffffff,0x20,0,0), iVar2 == 0))
      {
        uVar1 = 0;
      }
      else {
        uVar1 = 99;
      }
    }
    else {
      if (((flags == 0x6d) &&
          (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)) &&
         (Ai_Subsystem_004be192(spell_id,target_id,0,1), g_ActivePlayer != 1)) {
        Pic_Subsystem_00424500(s_prompts_txt_00521948,s_CIRCLE_OF_PROTECTION_00521930);
        iVar2 = Action_ValidateTarget_00405802
                          (spell_id,2,2,0x200,0,0,0,0,1 << ((byte)height & 0x1f),0,DAT_006ff2e0,-1,
                           0xffffffff,0xffffffff,0x20,0,0,&g_OverworldGoldAmount,1,&local_c);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               local_8;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      if (flags == 0x72) {
        iVar2 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0x200,0,0,0,0,
                           1 << ((byte)height & 0x1f),0,DAT_006ff2e0,-1,0xffffffff,0xffffffff,0x20,0
                           ,0);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else if (*(int *)(&g_CardSlot_ConvertedManaCost +
                         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x5b20 +
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x120) != 0) {
          *(undefined4 *)
           (&g_CardSlot_ConvertedManaCost +
           *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
        }
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


