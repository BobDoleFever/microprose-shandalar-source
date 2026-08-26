/*
 * Decompiled function: Minit_Subsystem_0045ebe4
 * Entry Point: 0045ebe4
 * Size: 1647 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045ebe4(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
     (spell_id == g_OverworldPlayerCoordX)) {
    g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_0063ee4c + spell_id * 0x20) * 6;
  }
  if (flags == 0x73) {
    if ((((byte)g_PlayerHandCardCount & 4) == 0) ||
       ((((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) != 0 &&
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) != 0)
          ) || (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) != 0)) ||
        ((iVar1 = FUN_0040d949(spell_id,7,3), iVar1 == 0 ||
         (iVar1 = FUN_00403250((int *)0x0,0,spell_id,spell_id,spell_id,0x200,0,0,0,0,0,0,
                               DAT_006ff2e0,0xffffffff,0xffffffff,0xffffffff,0x20,0,0), iVar1 == 0))
        )))) {
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
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,3), g_ActivePlayer != 1)) {
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      local_10 = 0;
      local_c = 0;
      while (((local_10 < 2 && (local_c == 0)) && (g_ActivePlayer != 1))) {
        Pic_Subsystem_00424500(s_prompts_txt_0052457c,s_CONSERVATOR_00524570);
        iVar1 = Action_ValidateTarget_00405802
                          (spell_id,spell_id,spell_id,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,
                           0xffffffff,0x20,0,0,&g_OverworldGoldAmount,3,&local_18);
        if (iVar1 == 0) {
          if (local_14 == -1) {
            g_ActivePlayer = 1;
          }
          else {
            local_c = 1;
          }
        }
        else {
          *(uint *)(&g_CardSlot_Flags + local_18 * 0x5b20 + local_14 * 0x120) =
               *(uint *)(&g_CardSlot_Flags + local_18 * 0x5b20 + local_14 * 0x120) | 0x200000;
          Ai_Subsystem_004cc9c5(0,0x20);
          *(int *)(&g_CardSlot_CombatTarget +
                  spell_id * 0x5b20 +
                  target_id * 0x120 +
                  (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
               local_18;
          *(int *)(&g_CardSlot_AttachedAura +
                  spell_id * 0x5b20 +
                  target_id * 0x120 +
                  (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
               local_14;
          (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] =
               (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] + '\x01';
        }
        local_10 = local_10 + 1;
      }
      for (local_10 = 0;
          local_10 < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
          local_10 = local_10 + 1) {
        *(uint *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_AttachedAura +
                         spell_id * 0x5b20 + target_id * 0x120 + local_10 * 8) * 0x120 +
                 *(int *)(&g_CardSlot_CombatTarget +
                         spell_id * 0x5b20 + target_id * 0x120 + local_10 * 8) * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_AttachedAura +
                              spell_id * 0x5b20 + target_id * 0x120 + local_10 * 8) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget +
                              spell_id * 0x5b20 + target_id * 0x120 + local_10 * 8) * 0x5b20) &
             0xffcfffff;
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      }
      else {
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_8 = 0;
      for (local_10 = 0;
          local_10 < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
          local_10 = local_10 + 1) {
        local_18 = *(int *)(&g_CardSlot_CombatTarget +
                           local_10 * 8 + target_id * 0x120 + spell_id * 0x5b20);
        local_14 = *(int *)(&g_CardSlot_AttachedAura +
                           local_10 * 8 + target_id * 0x120 + spell_id * 0x5b20);
        iVar1 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget +
                                   local_10 * 8 + target_id * 0x120 + spell_id * 0x5b20),
                           *(int *)(&g_CardSlot_AttachedAura +
                                   local_10 * 8 + target_id * 0x120 + spell_id * 0x5b20),(char *)0x0
                           ,spell_id,(byte)spell_id,(byte)spell_id,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1
                           ,0xffffffff,0xffffffff,0x20,0,0);
        if (iVar1 == 0) {
          local_8 = local_8 + 1;
        }
        else if (*(int *)(&g_CardSlot_ConvertedManaCost + local_18 * 0x5b20 + local_14 * 0x120) != 0
                ) {
          *(int *)(&g_CardSlot_ConvertedManaCost + local_18 * 0x5b20 + local_14 * 0x120) =
               *(int *)(&g_CardSlot_ConvertedManaCost + local_18 * 0x5b20 + local_14 * 0x120) + -1;
        }
      }
      if ((char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] == local_8) {
        g_ActivePlayer = 1;
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


