/*
 * Decompiled function: Mana_Init_004549ea
 * Entry Point: 004549ea
 * Size: 3033 bytes
 */
#include "magic.h"


undefined4 Mana_Init_004549ea(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 arg_10;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 arg_11;
  int iVar8;
  undefined4 arg_12;
  uint uVar9;
  uint uVar10;
  undefined4 arg_14;
  uint uVar11;
  undefined4 arg_15;
  uint uVar12;
  undefined4 arg_16;
  uint uVar13;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_24;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 1) {
    uVar2 = Minit_Subsystem_004528c0(spell_id,target_id,1,0);
    return uVar2;
  }
  if (flags == 0x6c) {
    g_SpellStackDepth = g_SpellStackDepth + 0x18;
  }
  if (flags == 0x71) {
    uVar2 = Minit_Subsystem_004528c0(spell_id,target_id,0x71,0);
    return uVar2;
  }
  if (flags == 0x73) {
    bVar1 = false;
    if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0)))
       ) {
      bVar1 = true;
    }
    iVar3 = FUN_0040d949(spell_id,7,1);
    if (iVar3 != 0) {
      bVar1 = true;
    }
    if (bVar1) {
      if ((spell_id == g_ActivePlayerPriority) && (0 < DAT_006ff550)) {
        DAT_006a4920 = DAT_006a4920 | 3;
      }
      return 1;
    }
    return 0;
  }
  if (flags != 0x6d) {
    if (flags == 0x72) {
      local_8 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      if (local_8 != 0) {
        if (local_8 == 1) {
          uVar2 = Pic_Subsystem_0045268f(0x38e);
          *(undefined4 *)
           (&g_CardSlot_CardId +
           *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
               uVar2;
          *(undefined4 *)
           (&g_CardSlot_Controller +
           *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
               *(undefined4 *)
                (&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120)
          ;
          *(int *)(&DAT_006b3010 + g_DialogPromptHwnd * 4) =
               *(int *)(&DAT_006b3010 + g_DialogPromptHwnd * 4) + 1;
          (&DAT_006b3018)[g_DialogPromptHwnd] = (&DAT_006b3018)[g_DialogPromptHwnd] + 1;
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                        0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                         target_id * 0x120 + spell_id * 0x5b20) * 0x120) | 2;
          Magic_TriggerCardEvent
                    (g_DialogPromptHwnd,g_DuelArenaHwnd,0x6c,1 - g_DialogPromptHwnd,0xffffffff);
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                        0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                         target_id * 0x120 + spell_id * 0x5b20) * 0x120) | 0x80;
          Magic_TriggerCardEvent
                    (g_DialogPromptHwnd,g_DuelArenaHwnd,0x71,1 - g_DialogPromptHwnd,0xffffffff);
        }
        else if ((local_8 == 2) &&
                ((&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] != '\0')) {
          local_14 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
          local_10 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
          uVar13 = 0;
          uVar12 = 0;
          uVar11 = 0;
          uVar10 = 0xffffffff;
          uVar9 = 0xffffffff;
          iVar8 = -1;
          iVar3 = Pic_Subsystem_0045268f(0x38e);
          uVar7 = 0;
          uVar6 = 0;
          uVar5 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
          iVar3 = Rules_ParseFilter_0040360b
                            (local_14,local_10,(char *)0x0,spell_id,2,2,0x200,0,0,0,uVar5,uVar6,
                             uVar7,iVar3,iVar8,uVar9,uVar10,uVar11,uVar12,uVar13);
          if (iVar3 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            local_c = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,local_14,local_10
                                  );
            if (local_c != -1) {
              *(undefined2 *)(&DAT_006a5f48 + local_c * 0x120 + spell_id * 0x5b20) = 1;
              *(undefined2 *)(&DAT_006a5f4a + local_c * 0x120 + spell_id * 0x5b20) = 1;
            }
          }
          (&g_CardSlot_TurnPlayed)
          [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
        }
      }
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
    }
    if (flags == 0x7f) {
      uVar2 = Minit_Subsystem_004528c0(spell_id,target_id,0x7f,0);
      return uVar2;
    }
    if (((((flags == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
         (target_id == g_OverworldMapGrid)) &&
        ((spell_id == g_OverworldPlayerCoordX &&
         (iVar3 = FUN_00471c32(spell_id,target_id), iVar3 != 0)))) &&
       (*(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) != 0)) {
      g_ActivePalette =
           *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
    }
    if (flags == 199) {
      if (spell_id == g_ActivePlayerPriority) {
        g_SpellStackDepth = g_SpellStackDepth + 0x30;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x30;
      }
    }
    return 0;
  }
  uVar2 = 0;
  local_24 = 3;
  if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))))
  {
    strcpy(&g_OverworldWorldState,s_Get_mana__00524058);
    local_24 = 0;
  }
  else {
    strcpy(&g_OverworldWorldState,s__Get_mana__00524064);
  }
  iVar3 = FUN_0040d949(spell_id,7,1);
  if (iVar3 == 0) {
    strcat(&g_OverworldWorldState,s__Change_to_Assembly_Worker__00524094);
  }
  else {
    strcat(&g_OverworldWorldState,s_Change_to_Assembly_Worker__00524074);
    if (g_ScWillyScore < 0x17) {
      local_24 = 1;
    }
  }
  if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))))
  {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    uVar4 = Pic_Subsystem_0045268f(0x38e);
    arg_12 = 0;
    arg_11 = 0;
    arg_10 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    iVar3 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0,0,0,arg_10,arg_11,arg_12,uVar4,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if (iVar3 != 0) {
      strcat(&g_OverworldWorldState,s_Pump_Assembly_Worker__005240b4);
      if ((g_ScWillyScore < 0x1e) && (0x16 < g_ScWillyScore)) {
        local_24 = 2;
      }
      goto LAB_00454d93;
    }
  }
  strcat(&g_OverworldWorldState,s__Pump_Assembly_Worker__005240cc);
LAB_00454d93:
  strcat(&g_OverworldWorldState,s_Cancel__005240e8);
  if (DAT_006ff4ac == 0) {
    local_8 = Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,local_24);
  }
  else {
    local_8 = 0;
  }
  *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = local_8;
  if (local_8 == 0) {
    uVar2 = Minit_Subsystem_004528c0(spell_id,target_id,0x6d,0);
    (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
  }
  else if (local_8 == 1) {
    uVar5 = *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20);
    *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x40000;
    Ai_CalcManaRequirement_004ba890(spell_id,0,1);
    if ((uVar5 & 0x40000) == 0) {
      *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0xfffbffff;
    }
    (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    DAT_006ff2d4 = 0xffffffff;
  }
  else if (local_8 == 2) {
    Pic_Subsystem_00424500(s_prompts_txt_00524104,s_MISHRAS_FACTORY_005240f4);
    arg_20 = &local_14;
    uVar4 = 1;
    arg_18 = &g_OverworldGoldAmount;
    uVar13 = 0;
    uVar12 = 0;
    uVar11 = 0;
    uVar10 = 0xffffffff;
    uVar9 = 0xffffffff;
    iVar8 = -1;
    iVar3 = Pic_Subsystem_0045268f(0x38e);
    uVar7 = 0;
    uVar6 = 0;
    uVar5 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    iVar3 = Action_ValidateTarget_00405802
                      (spell_id,2,spell_id,0x200,0,0,0,uVar5,uVar6,uVar7,iVar3,iVar8,uVar9,uVar10,
                       uVar11,uVar12,uVar13,arg_18,uVar4,arg_20);
    if (iVar3 == 0) {
      g_ActivePlayer = 1;
    }
    else {
      *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      FUN_0040d82b(spell_id,0,1);
      *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_14;
      *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_10;
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
    }
    DAT_006ff2d4 = 0xffffffff;
  }
  else {
    g_ActivePlayer = 1;
  }
  if (0 < DAT_006ff550) {
    DAT_006ff550 = DAT_006ff550 + -1;
  }
  return uVar2;
}


