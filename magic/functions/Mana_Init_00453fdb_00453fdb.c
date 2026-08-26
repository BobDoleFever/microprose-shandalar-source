/*
 * Decompiled function: Mana_Init_00453fdb
 * Entry Point: 00453fdb
 * Size: 1016 bytes
 */
#include "magic.h"


undefined4 Mana_Init_00453fdb(int spell_id,int target_id,int flags)

{
  int color_mask;
  int iVar1;
  uint arg_11;
  uint arg_12;
  uint arg_13;
  int iVar2;
  int arg_15;
  uint arg_16;
  uint arg_17;
  uint arg_18;
  uint arg_19;
  uint arg_20;
  undefined4 local_14;
  int local_8;
  
  if (flags == 1) {
    local_14 = Minit_Subsystem_004528c0(spell_id,target_id,1,0);
  }
  else if (flags == 0x71) {
    local_14 = Minit_Subsystem_004528c0(spell_id,target_id,0x71,0);
  }
  else if (flags == 0x73) {
    local_14 = Minit_Subsystem_004528c0(spell_id,target_id,0x73,0);
  }
  else if (flags == 0x6d) {
    local_14 = 0;
    strcpy(&g_OverworldWorldState,s_Get_mana__00523fd0);
    strcat(&g_OverworldWorldState,s_Sacrifice_to_destroy_a_land__00523fdc);
    strcat(&g_OverworldWorldState,s_Cancel__00523ffc);
    (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    if (DAT_00695ec8 == 0) {
      local_8 = 0;
    }
    else if (DAT_006ff4ac == 0) {
      if (spell_id == g_CurrentTurnPhase) {
        local_8 = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,1);
      }
      else {
        local_8 = 1;
      }
    }
    else {
      local_8 = 0;
    }
    if (local_8 == 0) {
      local_14 = Minit_Subsystem_004528c0(spell_id,target_id,0x6d,0);
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    else if (local_8 == 1) {
      DAT_006ff2d4 = 0xffffffff;
      Pic_Subsystem_00424500(s_prompts_txt_00524014,s_STRIPMINE_00524008);
      iVar1 = CardTarget_PromptTargetPermanent(spell_id,1 - spell_id,target_id);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0xf);
        }
        Pic_Subsystem_0044867e(spell_id,target_id,3);
        FUN_0040d82b(spell_id,0,1);
      }
    }
    else {
      g_ActivePlayer = 1;
    }
    if (g_ActivePlayer == 1) {
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
  }
  else {
    if ((flags == 0x72) && ((&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] != '\0')
       ) {
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
                        (iVar1,color_mask,(char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,
                         iVar2,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(iVar1,color_mask,2);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if (flags == 0x7f) {
      local_14 = Minit_Subsystem_004528c0(spell_id,target_id,0x7f,0);
    }
    else {
      local_14 = 0;
    }
  }
  return local_14;
}


