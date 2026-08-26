/*
 * Decompiled function: Prompts_Load_0041652b
 * Entry Point: 0041652b
 * Size: 641 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_0041652b(int spell_id,int target_id,int flags)

{
  int color_mask;
  undefined4 arg_10;
  int iVar1;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  int iVar2;
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
    Ai_GetOpponentPlayerScore(0);
    if (g_ScWillyScore < 0x1e) {
      arg_19_00 = 0;
      arg_18_00 = 0;
      arg_17_00 = 0;
      arg_16_00 = 0xffffffff;
      arg_15_00 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13_00 = 0xffffffff;
      arg_12_00 = 0;
      arg_11_00 = 0;
      arg_10 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,arg_10,arg_11_00,arg_12_00,
                           arg_13_00,arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005198ac,s_BERSERK_005198a4);
      iVar1 = CardTarget_PromptTargetCreature(spell_id,spell_id,target_id);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
    }
    if (flags == 0x71) {
      iVar1 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
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
                        (iVar1,color_mask,(char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,
                         iVar2,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        iVar2 = FUN_00410cc0(spell_id,target_id,DAT_006a4b64,iVar1,color_mask);
        if (iVar2 != -1) {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + spell_id * 0x5b20) = 0x80;
          *(undefined2 *)(&DAT_006a5f48 + iVar2 * 0x120 + spell_id * 0x5b20) =
               *(undefined2 *)(&g_CardSlot_Counters + color_mask * 0x120 + iVar1 * 0x5b20);
          *(uint *)(&g_CardSlot_Abilities1 + iVar2 * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + iVar2 * 0x120 + spell_id * 0x5b20) | 0x4000;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
  }
  return 0;
}


