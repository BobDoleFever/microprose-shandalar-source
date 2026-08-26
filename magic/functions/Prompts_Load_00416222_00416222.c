/*
 * Decompiled function: Prompts_Load_00416222
 * Entry Point: 00416222
 * Size: 777 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_00416222(int spell_id,int target_id,int flags)

{
  int color_mask;
  int iVar1;
  undefined4 uVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  int iVar3;
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
    if ((g_ActivePlayerPriority == spell_id) && (iVar1 = FUN_0040d949(spell_id,7,2), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      Ai_GetOpponentPlayerScore(0);
      arg_19_00 = 0;
      arg_18_00 = 0;
      arg_17_00 = 0;
      arg_16_00 = 0xffffffff;
      arg_15_00 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13_00 = 0xffffffff;
      arg_12_00 = 0;
      arg_11_00 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      uVar2 = FUN_00403250((int *)0x0,0,spell_id,2,spell_id,0x200,2,0,0,uVar2,arg_11_00,arg_12_00,
                           arg_13_00,arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519898,s_HOWL_FROM_BEYOND_00519884);
      iVar1 = CardTarget_PromptTargetCreature(spell_id,spell_id,target_id);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_SpellStackDepth =
             g_SpellStackDepth + (((g_ScWillyScore < 0x15) - 1 & 0xfffffffe) * 3 + 9) * -4;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
        if ((g_ActivePlayerPriority == spell_id) &&
           (((&DAT_006a5f3e)
             [*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] &
            3) != 0)) {
          g_SpellStackDepth = g_SpellStackDepth + -99;
        }
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
      iVar3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar3 = Rules_ParseFilter_0040360b
                        (iVar1,color_mask,(char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,
                         iVar3,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        iVar1 = FUN_00410cc0(spell_id,target_id,DAT_006a2854,iVar1,color_mask);
        if (iVar1 != -1) {
          *(short *)(&DAT_006a5f48 + iVar1 * 0x120 + spell_id * 0x5b20) =
               (short)*(undefined4 *)
                       (&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


