/*
 * Decompiled function: Pic_Subsystem_004345a9
 * Entry Point: 004345a9
 * Size: 1398 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_004345a9(int spell_id,int target_id,int flags)

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
  int local_8;
  
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
      Pic_Subsystem_00424500(s_prompts_txt_00521504,s_SPIRITLINK_005214f8);
      iVar2 = CardTarget_PromptTargetCreature(spell_id,2,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
      if (g_ActivePlayer != 1) {
        iVar2 = FUN_00473179(*(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20),
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20),0x32,0xffffffff);
        g_SpellStackDepth = g_SpellStackDepth + iVar2 * 0x18;
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
    if (((flags == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120
                 ) == DAT_006ff2e0)) &&
       (((&g_CardSlot_DamageReceived)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120]
         == (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] &&
        ((*(int *)(&g_CardSlot_TypeFlags +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
          *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) != 0)))))) {
      *(int *)(&g_CardSlot_CombatTarget +
              target_id * 0x120 +
              spell_id * 0x5b20 +
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) * 8) =
           g_OverworldPlayerCoordX;
      *(int *)(&g_CardSlot_AttachedAura +
              target_id * 0x120 +
              spell_id * 0x5b20 +
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) * 8) =
           g_OverworldMapGrid;
      *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
    }
    if ((((g_PlayerManaPool == 0xd7) && (g_OverworldMapGrid == target_id)) &&
        (g_OverworldPlayerCoordX == spell_id)) &&
       ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != 0 &&
        (spell_id == DAT_006a4b5c)))) {
      if (flags == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if (flags == 0x7e) {
        for (local_8 = 0;
            local_8 < *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20
                              ); local_8 = local_8 + 1) {
          (&g_PlayerCreatureCount)[spell_id] =
               (&g_PlayerCreatureCount)[spell_id] +
               *(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_AttachedAura +
                               target_id * 0x120 + spell_id * 0x5b20 + local_8 * 8) * 0x120 +
                       *(int *)(&g_CardSlot_CombatTarget +
                               target_id * 0x120 + spell_id * 0x5b20 + local_8 * 8) * 0x5b20);
        }
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


