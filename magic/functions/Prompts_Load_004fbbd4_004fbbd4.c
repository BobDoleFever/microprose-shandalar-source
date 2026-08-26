/*
 * Decompiled function: Prompts_Load_004fbbd4
 * Entry Point: 004fbbd4
 * Size: 1103 bytes
 */
#include "magic.h"


int Prompts_Load_004fbbd4(int spell_id,int target_id,int flags)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    local_8 = 0;
    local_10 = 0;
    while (((local_10 < 500 && (local_8 == 0)) &&
           (*(int *)(&DAT_006ff710 + local_10 * 4 + spell_id * 2000) != -1))) {
      if (((&g_MasterCardColorTable)
           [*(int *)(&DAT_006ff710 + local_10 * 4 + spell_id * 2000) * 0x34] & 2) != 0) {
        local_8 = 1;
      }
      local_10 = local_10 + 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        Pic_Subsystem_00424500(s_prompts_txt_005305b8,s_RAISEDEAD_005305ac);
        do {
          local_c = Pic_Load_004509e8(spell_id,(int)(&DAT_006ff710 + spell_id * 2000),500,
                                      &g_OverworldGoldAmount,0);
          if (local_c == -1) break;
        } while (((&g_MasterCardColorTable)
                  [*(int *)(&DAT_006ff710 + local_c * 4 + spell_id * 2000) * 0x34] & 2) == 0);
      }
      else {
        local_c = FUN_004fd9c0(spell_id,2);
      }
      if (((local_c == -1) || (*(int *)(&DAT_006ff710 + local_c * 4 + spell_id * 2000) == -1)) ||
         (((&g_MasterCardColorTable)[*(int *)(&DAT_006ff710 + local_c * 4 + spell_id * 2000) * 0x34]
          & 2) == 0)) {
        g_ActivePlayer = 1;
      }
      else {
        iVar1 = Pic_Subsystem_00451291
                          (spell_id,*(int *)(&DAT_006ff710 + local_c * 4 + spell_id * 2000));
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + iVar1 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + iVar1 * 0x120) | 0x20;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = spell_id;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = iVar1;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = local_c;
      }
    }
    if (flags == 0x71) {
      iVar1 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      if (((iVar1 == -1) || (*(int *)(&DAT_006ff710 + iVar1 * 4 + spell_id * 2000) == -1)) ||
         (((&g_MasterCardColorTable)[*(int *)(&DAT_006ff710 + iVar1 * 4 + spell_id * 2000) * 0x34] &
          2) == 0)) {
        *(undefined4 *)
         (&g_CardSlot_CardId +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             0xffffffff;
      }
      else {
        Pic_Subsystem_00449223(spell_id,iVar1);
        *(uint *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20
                 + *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
             *(uint *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) *
                      0x5b20 + *(int *)(&g_CardSlot_AttachedAura +
                                       target_id * 0x120 + spell_id * 0x5b20) * 0x120) & 0xffffffdf;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    local_8 = 0;
  }
  return local_8;
}


