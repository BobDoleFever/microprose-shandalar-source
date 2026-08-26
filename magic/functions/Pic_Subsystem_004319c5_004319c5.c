/*
 * Decompiled function: Pic_Subsystem_004319c5
 * Entry Point: 004319c5
 * Size: 1294 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_004319c5(int spell_id,int target_id,int flags)

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
    uVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521464,s_EVIL_PRESENCE_00521454);
      iVar2 = CardTarget_PromptTargetPermanent(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
      if (g_ActivePlayer != 1) {
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_CurrentTurnPhase) {
          g_SpellStackDepth =
               g_SpellStackDepth +
               (int)(0x40 / (longlong)(*(int *)(&DAT_0063ee4c + g_CurrentTurnPhase * 0x20) + 1));
        }
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + -0x60;
        }
        if (*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                    target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) == 0) {
          g_SpellStackDepth = g_SpellStackDepth + -0xf0;
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
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
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
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 1;
        iVar2 = FUN_0041d963(spell_id,target_id,
                             *(int *)(&g_CardSlot_ConvertedManaCost +
                                     target_id * 0x120 + spell_id * 0x5b20));
        *(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
             iVar2 + -1;
        *(uint *)(&g_CardSlot_Abilities2 +
                 *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 +
                      *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                              0x5b20) | 0x1000000;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if ((((flags == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
        ((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
          g_OverworldMapGrid &&
         (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
           g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))))) &&
       (iVar2 = FUN_00471c32(spell_id,target_id), iVar2 != 0)) {
      iVar2 = FUN_0041d963(spell_id,target_id,
                           *(int *)(&g_CardSlot_ConvertedManaCost +
                                   target_id * 0x120 + spell_id * 0x5b20));
      g_ActivePalette = iVar2 + -1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


