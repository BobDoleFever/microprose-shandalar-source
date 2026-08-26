/*
 * Decompiled function: Pic_Subsystem_0043d1c3
 * Entry Point: 0043d1c3
 * Size: 2124 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043d1c3(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 arg_11;
  int iVar7;
  undefined4 arg_12;
  uint uVar8;
  undefined4 arg_13;
  uint uVar9;
  undefined4 arg_14;
  uint uVar10;
  undefined4 arg_15;
  uint uVar11;
  undefined4 arg_16;
  uint uVar12;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    uVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      do {
        Pic_Subsystem_00424500(s_prompts_txt_00521818,s_COPY_ARTIFACT_00521808);
        arg_20 = &local_10;
        uVar2 = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uVar8 = 0xffffffff;
        iVar7 = -1;
        iVar6 = -1;
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
        iVar6 = Action_ValidateTarget_00405802
                          (spell_id,2,2,0x200,0x40,0,0,uVar3,uVar4,uVar5,iVar6,iVar7,uVar8,uVar9,
                           uVar10,uVar11,uVar12,arg_18,uVar2,arg_20);
        if (iVar6 == 0) {
          g_ActivePlayer = 1;
        }
        else if (((&g_MasterCardColorTable)
                  [*(int *)(&g_ActiveCardsInPlay + local_10 * 0x5b20 + local_c * 0x120) * 0x34] &
                 0x40) == 0) {
          if (g_IsAiThinking != 1) {
            Ai_Util_004cc42d(s_Illegal_target__didn_t_enter_pla_00521824);
            Sleep(2000);
            Ai_Util_004cc42d(&DAT_00521858);
          }
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget +
                  target_id * 0x120 +
                  spell_id * 0x5b20 +
                  (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
               local_10;
          *(int *)(&g_CardSlot_AttachedAura +
                  target_id * 0x120 +
                  spell_id * 0x5b20 +
                  (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
               local_c;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      } while ((g_ActivePlayer != 1) &&
              (((&g_MasterCardColorTable)
                [*(int *)(&g_ActiveCardsInPlay + local_10 * 0x5b20 + local_c * 0x120) * 0x34] & 0x40
               ) == 0));
    }
    if (flags == 0x71) {
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar6 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,0x40,0,0,uVar3,uVar4,uVar5,iVar6,iVar7,uVar8
                         ,uVar9,uVar10,uVar11,uVar12);
      if (iVar6 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        bVar1 = false;
        if ((*(int *)(&g_MasterCardTypeTable +
                     *(int *)(&g_ActiveCardsInPlay +
                             *(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20) * 0x120) * 0x34) ==
             0x207) ||
           (*(int *)(&g_MasterCardTypeTable +
                    *(int *)(&g_ActiveCardsInPlay +
                            *(int *)(&g_CardSlot_CombatTarget +
                                    target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                            *(int *)(&g_CardSlot_AttachedAura +
                                    target_id * 0x120 + spell_id * 0x5b20) * 0x120) * 0x34) == 0x20d
           )) {
          bVar1 = true;
        }
        if (bVar1) {
          local_8 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId +
                                         *(int *)(&g_CardSlot_CombatTarget +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                                         *(int *)(&g_CardSlot_AttachedAura +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x120));
        }
        else {
          local_8 = FUN_0041d8a6(*(int *)(&g_ActiveCardsInPlay +
                                         *(int *)(&g_CardSlot_CombatTarget +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                                         *(int *)(&g_CardSlot_AttachedAura +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x120));
        }
        if (local_8 != -1) {
          *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = local_8;
          *(undefined4 *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
          *(undefined4 *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
               0x1000000;
          (&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] =
               (&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] | 4;
        }
        (&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20] =
             (&DAT_006a5f4d)
             [*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
              *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120];
        if (bVar1) {
          if (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) !=
              0) {
            *(int *)(&DAT_006b3010 + spell_id * 4) = *(int *)(&DAT_006b3010 + spell_id * 4) + 1;
          }
          if (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 0x40)
              != 0) {
            (&DAT_006b3018)[spell_id] = (&DAT_006b3018)[spell_id] + 1;
          }
          if (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 4) !=
              0) {
            *(int *)(&DAT_006b3020 + spell_id * 4) = *(int *)(&DAT_006b3020 + spell_id * 4) + 1;
          }
          (&DAT_006a2828)[spell_id] =
               (&DAT_006a2828)[spell_id] |
               (uint)(byte)(&g_MasterCardColorTable)
                           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) *
                            0x34];
          *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) |
               (spell_id == 0) - 1 & 0x400000 | 0x30082;
          DAT_00695f08 = spell_id;
          DAT_006b2e14 = target_id;
          FUN_00476205(g_DefendingPlayer,0xdb,s_Card_into_play_0052185c,0);
        }
        else {
          Pic_Subsystem_0042ac1f(spell_id,target_id);
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if ((((flags == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
        (g_OverworldMapGrid == target_id)) &&
       ((g_OverworldPlayerCoordX == spell_id &&
        (iVar6 = FUN_00471c32(spell_id,target_id), iVar6 != 0)))) {
      g_ActivePalette =
           *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
    }
    uVar2 = 0;
  }
  return uVar2;
}


