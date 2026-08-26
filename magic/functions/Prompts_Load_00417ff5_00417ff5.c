/*
 * Decompiled function: Prompts_Load_00417ff5
 * Entry Point: 00417ff5
 * Size: 607 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_00417ff5(int spell_id,int target_id,int flags)

{
  char cVar1;
  int color_mask;
  undefined4 uVar2;
  int iVar3;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  int iVar4;
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
    uVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uVar2,arg_11_00,arg_12_00,
                         arg_13_00,arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005199a8,s_CRUMBLE_005199a0);
      iVar3 = CardTarget_PromptTargetPlayerOrCreature(spell_id,1 - spell_id,target_id);
      if (iVar3 == 0) {
        g_ActivePlayer = 1;
      }
    }
    if (flags == 0x71) {
      iVar3 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar4 = Rules_ParseFilter_0040360b
                        (iVar3,color_mask,(char *)0x0,spell_id,2,2,0x200,0x40,0,0,arg_11,arg_12,
                         arg_13,iVar4,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar4 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        cVar1 = (&DAT_0051aebf)
                [*(int *)(&g_CardSlot_CardId +
                         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x5b20 +
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x120) * 0x34];
        iVar4 = FUN_0040a305((int)(char)(&DAT_0051aec0)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 *(int *)(&g_CardSlot_CombatTarget +
                                                         target_id * 0x120 + spell_id * 0x5b20) *
                                                 0x5b20 + *(int *)(&g_CardSlot_AttachedAura +
                                                                  target_id * 0x120 +
                                                                  spell_id * 0x5b20) * 0x120) * 0x34
                                        ],0,99);
        (&g_PlayerCreatureCount)[iVar3] = (&g_PlayerCreatureCount)[iVar3] + cVar1 + iVar4;
        Pic_Subsystem_0044867e(iVar3,color_mask,2);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


