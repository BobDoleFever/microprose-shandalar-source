/*
 * Decompiled function: Pic_Subsystem_0043a32c
 * Entry Point: 0043a32c
 * Size: 2364 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043a32c(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  int arg_15;
  undefined4 arg_15_00;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uVar1 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    uVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005216b0,s_INSTILL_ENERGY_005216a0);
      iVar2 = CardTarget_PromptTargetCreature(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
      if ((g_ActivePlayer != 1) && (g_ActivePlayerPriority == spell_id)) {
        if (((&DAT_0051aebd)
             [*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                      target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) * 0x34] ==
             '\0') &&
           (((&DAT_006a5f69)
             [*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] &
            8) == 0)) {
          g_SpellStackDepth = g_SpellStackDepth + -0x30;
        }
        if ((((&DAT_0051aed0)
              [*(int *)(&g_CardSlot_CardId +
                       *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                       0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                       target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) * 0x34] & 1)
             != 0) &&
           (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) == spell_id))
        {
          g_SpellStackDepth = g_SpellStackDepth + 0x30;
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        if (((&g_CardSlot_Flags)
             [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
              (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20] & 2) !=
            0) {
          *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 1;
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) &
               0xfffcffff;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      iVar2 = FUN_00473cc5((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
      if ((*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) ||
         (iVar2 = FUN_0040dcca(spell_id,target_id,7,0), iVar2 != 0)) {
        if (((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)
            && ((((&g_CardSlot_Flags)
                  [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20] & 0x10) != 0 && (g_DefendingPlayer == g_OverworldPlayerCoordX))))
           && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)) {
          uVar1 = 1;
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if ((flags == 0x6d) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
        iVar2 = FUN_00473cc5((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_006330d0 + iVar2 * 4) != 0) {
          Ai_Subsystem_004be192(spell_id,target_id,0,0);
        }
        if (g_ActivePlayer != 1) {
          *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
        }
      }
      if (flags == 0x72) {
        if (*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) == -1) {
          g_ActivePlayer = 1;
        }
        else {
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) &
               0xffffffef;
        }
      }
      if ((((((g_PlayerManaPool == 0xd4) && (g_OverworldMapGrid == target_id)) &&
            (g_OverworldPlayerCoordX == spell_id)) &&
           ((*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) != 0 &&
            ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1)))) &&
          ((*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) != -1 &&
           ((DAT_00695f08 == spell_id && (DAT_006b2e14 == target_id)))))) &&
         (spell_id == DAT_006a4b5c)) {
        if (flags == 0x7d) {
          g_ActivePalette = g_ActivePalette | 2;
        }
        if (flags == 0x7e) {
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) | 0x30000;
        }
      }
      if (((flags == 0x22) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


