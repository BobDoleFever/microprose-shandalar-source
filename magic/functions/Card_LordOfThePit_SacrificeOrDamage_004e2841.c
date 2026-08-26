/*
 * Decompiled function: Card_LordOfThePit_SacrificeOrDamage
 * Entry Point: 004e2841
 * Size: 856 bytes
 */
#include "magic.h"


undefined4 Card_LordOfThePit_SacrificeOrDamage(int spell_id,int target_id,int flags)

{
  int iVar1;
  
  if ((((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
      (spell_id == g_OverworldPlayerCoordX)) && (*(int *)(&DAT_006b3010 + spell_id * 4) < 2)) {
    g_SpellStackDepth = g_SpellStackDepth + -0xa8;
  }
  if (flags == 0x87) {
    iVar1 = Card_LordOfThePit_FindSacrificeCandidate(spell_id,target_id);
    if (iVar1 == 0) {
      g_ActivePalette = g_ActivePalette | 1;
    }
  }
  if ((((flags == 0x85) && (target_id == g_OverworldMapGrid)) &&
      ((spell_id == g_OverworldPlayerCoordX &&
       ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0 &&
        (spell_id == g_DefendingPlayer)))))) && (DAT_0063edc0 == spell_id)) {
    *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
    iVar1 = Card_LordOfThePit_FindSacrificeCandidate(spell_id,target_id);
    if (iVar1 == 0) {
      DAT_006ff550 = DAT_006ff550 + 1;
    }
  }
  if (((flags == 4) && (target_id == g_OverworldMapGrid)) && (spell_id == g_OverworldPlayerCoordX))
  {
    *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
         *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
    iVar1 = Card_LordOfThePit_FindSacrificeCandidate(spell_id,target_id);
    if (iVar1 == 0) {
      g_ActivePalette = g_ActivePalette | 1;
    }
    else {
      *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x100000;
      Ai_Subsystem_004cc9c5(0,0x20);
      Pic_Subsystem_00424500(s_prompts_txt_0052eeac,s_LORD_OF_THE_PIT_0052ee9c);
      iVar1 = CardTarget_HasValidCreatureTarget(spell_id);
      *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0xffefffff;
      Pic_Subsystem_0044867e(spell_id,iVar1,3);
    }
  }
  if (flags == 0x86) {
    Ai_Subsystem_004cc56d
              (spell_id,spell_id,target_id,-1,-1,s_Lord_of_the_Pit_deals_7_damage__0052eeb8,0);
    Mem_AllocOrFree_0041df33(spell_id,7,g_DialogPromptHwnd,g_DuelArenaHwnd);
  }
  if (flags == 199) {
    iVar1 = Card_LordOfThePit_FindSacrificeCandidate(spell_id,target_id);
    if (iVar1 == 0) {
      Mem_AllocOrFree_0041df33(spell_id,7,g_DialogPromptHwnd,g_DuelArenaHwnd);
    }
  }
  if (((flags == 0x22) || (flags == 199)) &&
     ((target_id == g_OverworldMapGrid && (spell_id == g_OverworldPlayerCoordX)))) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
  }
  if (((flags == 0x8a) && (target_id == g_OverworldMapGrid)) &&
     (spell_id == g_OverworldPlayerCoordX)) {
    DAT_006ff19c = DAT_006ff19c + -0x30;
  }
  if (((flags == 0x8b) && (target_id == g_OverworldMapGrid)) &&
     (spell_id == g_OverworldPlayerCoordX)) {
    DAT_006ff19c = DAT_006ff19c + 0x30;
  }
  return 0;
}


