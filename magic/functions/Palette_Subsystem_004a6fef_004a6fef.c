/*
 * Decompiled function: Palette_Subsystem_004a6fef
 * Entry Point: 004a6fef
 * Size: 1486 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004a6fef(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 arg_10;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 arg_11;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (flags == 0x71) {
    local_8 = g_ActivePalette;
    uVar1 = Palette_Subsystem_004a75bd(1 - spell_id);
    Palette_Subsystem_004a771b(spell_id,target_id,uVar1);
    g_ActivePalette = local_8;
  }
  if (flags == 0x73) {
    if (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
           (iVar2 = FUN_0040d949(spell_id,3,2), iVar2 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0x10;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      uVar1 = *(undefined4 *)
               (&g_CardSlot_ConvertedManaCost +
               *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      arg_10 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,arg_10,arg_11,arg_12,arg_13,uVar1,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if ((((flags == 0x6d) &&
         ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) &&
        (iVar2 = Palette_Subsystem_004a6d20
                           (spell_id,target_id,
                            *(int *)(&g_CardSlot_ConvertedManaCost +
                                    *(int *)(&g_CardSlot_TypeFlags +
                                            target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                    (char)(&g_CardSlot_DamageReceived)
                                          [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20)),
        iVar2 != 0)) && (Ai_CalcManaRequirement_004ba890(spell_id,3,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052cb50,s_ASWANJAGUAR_0052cb44);
      arg_20 = &local_14;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0x10;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar2 = *(int *)(&g_CardSlot_ConvertedManaCost +
                      *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_DamageReceived)
                                    [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar6,iVar2,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_14;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        local_c = *(undefined4 *)
                   (&DAT_006b3088 +
                   *(int *)(&g_MasterCardTypeTable +
                           *(int *)(&g_CardSlot_CardId + local_14 * 0x5b20 + local_10 * 0x120) *
                           0x34) * 0x98);
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0x10;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar2 = *(int *)(&g_CardSlot_ConvertedManaCost +
                      *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_DamageReceived)
                                    [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,iVar6,iVar2,uVar7,
                         uVar8,uVar9,uVar10,uVar11);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x22);
        }
        Pic_Subsystem_0044867e
                  (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                   *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),1);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
  }
  return 0;
}


