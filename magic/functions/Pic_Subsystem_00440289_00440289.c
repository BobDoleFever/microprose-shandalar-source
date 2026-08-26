/*
 * Decompiled function: Pic_Subsystem_00440289
 * Entry Point: 00440289
 * Size: 1027 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00440289(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 6;
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
           (*(int *)(&DAT_0063ee48 + g_CurrentTurnPhase * 0x20) +
            *(int *)(&DAT_006b2e40 + g_CurrentTurnPhase * 0x20) / 2 +
           *(int *)(&DAT_0063ee4c + g_CurrentTurnPhase * 0x20)) * 0x18;
    }
    if (flags == 0x73) {
      if ((((byte)g_PlayerHandCardCount & 4) != 0) &&
         (iVar2 = FUN_0040dcca(spell_id,target_id,7,2), iVar2 != 0)) {
        iVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,1 << ((byte)local_8 & 0x1f),0,
                             DAT_006ff2e0,0xffffffff,0xffffffff,0xffffffff,0x20,0,0);
        if (iVar2 != 0) {
          return 99;
        }
      }
      uVar1 = 0;
    }
    else {
      if (((flags == 0x6d) &&
          (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)) &&
         (Ai_Subsystem_004be192(spell_id,target_id,0,2), g_ActivePlayer != 1)) {
        Pic_Subsystem_00424500(s_prompts_txt_0052196c,s_CIRCLE_OF_PROTECTION_00521954);
        iVar2 = Action_ValidateTarget_00405802
                          (spell_id,2,2,0x200,0,0,0,0,1 << ((byte)local_8 & 0x1f),0,DAT_006ff2e0,-1,
                           0xffffffff,0xffffffff,0x20,0,0,&g_OverworldGoldAmount,1,&local_10);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               local_c;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      if (flags == 0x72) {
        iVar2 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0x200,0,0,0,0,
                           1 << ((byte)local_8 & 0x1f),0,DAT_006ff2e0,-1,0xffffffff,0xffffffff,0x20,
                           0,0);
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
        [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


