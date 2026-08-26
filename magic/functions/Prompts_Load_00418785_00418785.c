/*
 * Decompiled function: Prompts_Load_00418785
 * Entry Point: 00418785
 * Size: 1231 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_00418785(int spell_id,int target_id,int flags)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 arg_11;
  uint uVar5;
  undefined4 arg_12;
  uint uVar6;
  undefined4 arg_13;
  undefined4 arg_14;
  int iVar7;
  undefined4 arg_15;
  uint uVar8;
  undefined4 arg_16;
  uint uVar9;
  undefined4 arg_17;
  undefined1 *arg_18;
  uint uVar10;
  undefined4 arg_18_00;
  uint uVar11;
  undefined4 arg_19;
  int *arg_20;
  uint uVar12;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    if (DAT_006b2d3c == -1) {
      Ai_GetOpponentPlayerScore(0);
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      uVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0xff,0,0,uVar2,arg_11,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
    else if (((spell_id == g_CurrentTurnPhase) ||
             ((spell_id == g_ActivePlayerPriority && (g_DefendingPlayer == g_CurrentTurnPhase)))) &&
            (iVar3 = Rules_ParseFilter_0040360b
                               (DAT_006b2d3c,DAT_006b2d2c,(char *)0x0,spell_id,2,2,0,0xff,0,0,0,0,0,
                                -1,-1,0xffffffff,0xffffffff,2,0,0), iVar3 != 0)) {
      uVar2 = 99;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      g_SpellStackDepth = g_SpellStackDepth + -0x18;
      if (DAT_006b2d3c == -1) {
        Pic_Subsystem_00424500(s_prompts_txt_005199f4,s_ANY_LACE_005199e8);
        arg_20 = &local_14;
        uVar2 = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uVar8 = 0xffffffff;
        iVar7 = -1;
        iVar3 = -1;
        uVar6 = 0;
        uVar5 = 0;
        uVar4 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
        iVar3 = Action_ValidateTarget_00405802
                          (spell_id,2,2,0x200,0xff,0,0,uVar4,uVar5,uVar6,iVar3,iVar7,uVar8,uVar9,
                           uVar10,uVar11,uVar12,arg_18,uVar2,arg_20);
        if (iVar3 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_14;
          *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_10;
          (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        }
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = DAT_006b2d3c;
        *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = DAT_006b2d2c;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    if (flags == 0x71) {
      local_8 = 0;
      if (DAT_006b2d3c == -1) {
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uVar8 = 0xffffffff;
        iVar7 = -1;
        iVar3 = -1;
        uVar6 = 0;
        uVar5 = 0;
        uVar4 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
        iVar3 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120
                                   ),(char *)0x0,spell_id,2,2,0x200,0xff,0,0,uVar4,uVar5,uVar6,iVar3
                           ,iVar7,uVar8,uVar9,uVar10,uVar11,uVar12);
        if (iVar3 != 0) {
          local_8 = local_8 + 1;
        }
      }
      else {
        iVar3 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120
                                   ),(char *)0x0,spell_id,2,2,0,0xff,0,0,0,0,0,-1,-1,0xffffffff,
                           0xffffffff,2,0,0);
        if (iVar3 != 0) {
          local_8 = local_8 + 1;
        }
      }
      if (local_8 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        local_14 = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
        local_10 = *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
        local_c = FUN_00473cc5((&DAT_0051aebe)
                               [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120)
                                * 0x34]);
        bVar1 = FUN_0041d9d2(spell_id,target_id,local_c);
        (&DAT_006a5f4d)[local_14 * 0x5b20 + local_10 * 0x120] = (char)(1 << (bVar1 & 0x1f));
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x1d);
        }
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


