/*
 * Decompiled function: Pic_Subsystem_0043812a
 * Entry Point: 0043812a
 * Size: 754 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043812a(int spell_id,int target_id,int flags)

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
      Pic_Subsystem_00424500(s_prompts_txt_005215f0,&DAT_005215ec);
      iVar2 = CardTarget_PromptTargetCreature(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
      if ((g_ActivePlayer != 1) && (spell_id != g_CurrentTurnPhase)) {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
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
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
          g_OverworldMapGrid) &&
        ((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] ==
         g_OverworldPlayerCoordX)) &&
       ((g_OverworldMapGrid != -1 &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0)))) {
      if (flags == 0x33) {
        g_ActivePalette = g_ActivePalette + 2;
      }
      if (flags == 0x34) {
        g_ActivePalette = g_ActivePalette | 0x400;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


