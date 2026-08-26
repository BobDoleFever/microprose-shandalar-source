/*
 * Decompiled function: Pic_Subsystem_0043c8f5
 * Entry Point: 0043c8f5
 * Size: 2249 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043c8f5(int spell_id,int target_id,int flags)

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
      Pic_Subsystem_00424500(s_prompts_txt_005217fc,s_UNSTABLE_MUTATION_005217e8);
      iVar2 = CardTarget_PromptTargetCreature(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
      if (((g_ActivePlayer != 1) && (g_ActivePlayerPriority == spell_id)) &&
         (((&DAT_006a5f3e)
           [*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
            *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] & 3
          ) != 0)) {
        g_SpellStackDepth = g_SpellStackDepth + -99;
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
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x32) || (flags == 0x33)) &&
       ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
        (((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
           g_OverworldMapGrid &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
           g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)))))) {
      g_ActivePalette = g_ActivePalette + 3;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == DAT_0063edc0)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_DefendingPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        DAT_006a4920 = DAT_006a4920 | 3;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (flags == 0x86) {
        *(short *)(&DAT_006a5f48 +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&DAT_006a5f48 +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -1;
        *(short *)(&DAT_006a5f4a +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&DAT_006a5f4a +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -1;
        *(int *)(&DAT_006a5f7c +
                *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
             *(int *)(&DAT_006a5f7c +
                     *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                             0x5b20) + 0x10000;
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x1b);
        }
      }
      if (flags == 199) {
        *(short *)(&DAT_006a5f48 +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&DAT_006a5f48 +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -1;
        *(short *)(&DAT_006a5f4a +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&DAT_006a5f4a +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -1;
        *(uint *)(&g_CardSlot_Abilities2 +
                 *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 +
                      *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                              0x5b20) | 0x6000000;
      }
      if (flags == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      if (flags == 199) {
        *(short *)(&DAT_006a5f48 +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&DAT_006a5f48 +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -2;
        *(short *)(&DAT_006a5f4a +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&DAT_006a5f4a +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -2;
        if (((g_ActivePlayerPriority == spell_id) && (g_DefendingPlayer == g_ActivePlayerPriority))
           && (((&g_CardSlot_Flags)
                [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20] & 0x40) == 0)) {
          g_SpellStackDepth = g_SpellStackDepth + -0x3c;
        }
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


