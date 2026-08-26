/*
 * Decompiled function: Mana_Init_004555c8
 * Entry Point: 004555c8
 * Size: 2960 bytes
 */
#include "magic.h"


undefined4 Mana_Init_004555c8(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 arg_10;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_24;
  undefined4 local_20;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x22) {
    uVar1 = Pic_Subsystem_0045268f(0x1fc);
    *(undefined4 *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) = uVar1;
    *(undefined4 *)(&g_CardSlot_Controller + spell_id * 0x5b20 + target_id * 0x120) = 0;
    (&DAT_006b3018)[spell_id] = (&DAT_006b3018)[spell_id] + -1;
    *(int *)(&DAT_006b3010 + spell_id * 4) = *(int *)(&DAT_006b3010 + spell_id * 4) + -1;
    DAT_00679ec8 = spell_id;
    DAT_00679ec4 = target_id;
    CardQuery_ForEachPermanent(Minit_Subsystem_00456158,spell_id);
  }
  if (((flags == 0x77) && (target_id == g_OverworldMapGrid)) &&
     (spell_id == g_OverworldPlayerCoordX)) {
    uVar1 = Pic_Subsystem_0045268f(0x1fc);
    *(undefined4 *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) = uVar1;
    return 0;
  }
  if (flags == 1) {
    uVar1 = Minit_Subsystem_004528c0(spell_id,target_id,1,0);
    return uVar1;
  }
  if (flags == 0x71) {
    uVar1 = Minit_Subsystem_004528c0(spell_id,target_id,0x71,0);
    return uVar1;
  }
  if (flags == 0x73) {
    local_18 = 0;
    if ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0)))
       ) {
      local_18 = 1;
    }
    iVar2 = FUN_0040d949(spell_id,7,1);
    if (iVar2 == 0) {
      return local_18;
    }
    return 1;
  }
  if (flags != 0x6d) {
    if (flags == 0x72) {
      local_8 = *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120);
      if (local_8 != 0) {
        if (local_8 == 1) {
          uVar1 = Pic_Subsystem_0045268f(0x38e);
          *(undefined4 *)
           (&g_CardSlot_CardId +
           *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120) =
               uVar1;
          *(undefined4 *)
           (&g_CardSlot_Controller +
           *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120) =
               *(undefined4 *)
                (&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
                *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120)
          ;
          *(int *)(&DAT_006b3010 + g_DialogPromptHwnd * 4) =
               *(int *)(&DAT_006b3010 + g_DialogPromptHwnd * 4) + 1;
          (&DAT_006b3018)[g_DialogPromptHwnd] = (&DAT_006b3018)[g_DialogPromptHwnd] + 1;
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                   0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) | 2;
          Magic_TriggerCardEvent
                    (g_DialogPromptHwnd,g_DuelArenaHwnd,0x6c,1 - g_DialogPromptHwnd,0xffffffff);
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                   0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) | 0x80;
          Magic_TriggerCardEvent
                    (g_DialogPromptHwnd,g_DuelArenaHwnd,0x71,1 - g_DialogPromptHwnd,0xffffffff);
        }
        else if ((local_8 == 2) &&
                ((&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] != '\0')) {
          local_14 = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
          local_10 = *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
          uVar11 = 0;
          uVar10 = 0;
          uVar9 = 0;
          uVar8 = 0xffffffff;
          uVar7 = 0xffffffff;
          iVar6 = -1;
          iVar2 = Pic_Subsystem_0045268f(0x38e);
          uVar5 = 0;
          uVar4 = 0;
          uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
          iVar2 = Rules_ParseFilter_0040360b
                            (local_14,local_10,(char *)0x0,spell_id,2,2,0x200,0,0,0,uVar3,uVar4,
                             uVar5,iVar2,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
          if (iVar2 == 0) {
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
          [*(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
        }
      }
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120) = 0;
    }
    if (flags == 0x7f) {
      uVar1 = Minit_Subsystem_004528c0(spell_id,target_id,0x7f,0);
      return uVar1;
    }
    return 0;
  }
  local_20 = 0;
  local_24 = 3;
  if ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
     ((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0))))
  {
    strcpy(&g_OverworldWorldState,s_Get_mana__00524110);
    local_24 = 0;
  }
  else {
    strcpy(&g_OverworldWorldState,s__Get_mana__0052411c);
  }
  iVar2 = FUN_0040d949(spell_id,7,1);
  if (iVar2 == 0) {
    strcat(&g_OverworldWorldState,s__Re_change_to_Assembly_Worker__0052414c);
  }
  else {
    strcat(&g_OverworldWorldState,s_Re_change_to_Assembly_Worker__0052412c);
  }
  if ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
     ((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0))))
  {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    uVar1 = Pic_Subsystem_0045268f(0x38e);
    arg_12 = 0;
    arg_11 = 0;
    arg_10 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    iVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0,0,0,arg_10,arg_11,arg_12,uVar1,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if (iVar2 != 0) {
      strcat(&g_OverworldWorldState,s_Pump_Assembly_Worker__00524170);
      if ((g_ScWillyScore < 0x1e) && (0x16 < g_ScWillyScore)) {
        local_24 = 2;
      }
      goto LAB_004559f9;
    }
  }
  strcat(&g_OverworldWorldState,s__Pump_Assembly_Worker__00524188);
LAB_004559f9:
  strcat(&g_OverworldWorldState,s_Cancel__005241a4);
  if (DAT_006ff4ac == 0) {
    local_8 = Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,local_24);
  }
  else {
    local_8 = 0;
  }
  *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = local_8;
  if (local_8 == 0) {
    local_20 = Minit_Subsystem_004528c0(spell_id,target_id,0x6d,0);
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
  }
  else if (local_8 == 1) {
    uVar3 = *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120);
    *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x40000;
    Ai_CalcManaRequirement_004ba890(spell_id,0,1);
    if ((uVar3 & 0x40000) == 0) {
      *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) & 0xfffbffff;
    }
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    DAT_006ff2d4 = 0xffffffff;
  }
  else if (local_8 == 2) {
    Pic_Subsystem_00424500(s_prompts_txt_005241c0,s_ASSEMBLY_WORKER_005241b0);
    arg_20 = &local_14;
    uVar1 = 1;
    arg_18 = &g_OverworldGoldAmount;
    uVar11 = 0;
    uVar10 = 0;
    uVar9 = 0;
    uVar8 = 0xffffffff;
    uVar7 = 0xffffffff;
    iVar6 = -1;
    iVar2 = Pic_Subsystem_0045268f(0x38e);
    uVar5 = 0;
    uVar4 = 0;
    uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    iVar2 = Action_ValidateTarget_00405802
                      (spell_id,2,spell_id,0x200,0,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,uVar8,
                       uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
    if (iVar2 == 0) {
      g_ActivePlayer = 1;
    }
    else {
      *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      FUN_0040d82b(spell_id,0,1);
      *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_14;
      *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_10;
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
    }
    DAT_006ff2d4 = 0xffffffff;
  }
  else {
    g_ActivePlayer = 1;
  }
  return local_20;
}


