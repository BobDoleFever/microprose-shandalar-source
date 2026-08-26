/*
 * Decompiled function: Prompts_Load_0041b1ae
 * Entry Point: 0041b1ae
 * Size: 1250 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_0041b1ae(int spell_id,int target_id,int flags)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 arg_12;
  uint uVar5;
  undefined4 arg_13;
  undefined4 arg_14;
  int iVar6;
  undefined4 arg_15;
  uint uVar7;
  undefined4 arg_16;
  uint uVar8;
  undefined4 arg_17;
  uint uVar9;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  uint uVar10;
  uint uVar11;
  undefined4 arg_19;
  uint uVar12;
  int *arg_20;
  uint uVar13;
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
      bVar2 = FUN_0041d9d2(spell_id,target_id,2);
      iVar4 = 1 << (bVar2 & 0x1f);
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      uVar3 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0x1047,0,0,uVar3,iVar4,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
    else {
      uVar12 = 0;
      uVar10 = 0;
      uVar9 = 2;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar4 = -1;
      uVar5 = 0;
      bVar2 = FUN_0041d9d2(spell_id,target_id,2);
      iVar4 = Rules_ParseFilter_0040360b
                        (DAT_006b2d3c,DAT_006b2d2c,(char *)0x0,spell_id,2,2,0,0,0,0,0,
                         1 << (bVar2 & 0x1f),uVar5,iVar4,iVar6,uVar7,uVar8,uVar9,uVar10,uVar12);
      if (iVar4 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 99;
      }
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      if (DAT_006b2d3c == -1) {
        Pic_Subsystem_00424500(s_prompts_txt_00519ad8,s_RED_BLAST_00519acc);
        arg_20 = &local_10;
        uVar3 = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar13 = 0;
        uVar11 = 0;
        uVar12 = 0;
        uVar10 = 0xffffffff;
        uVar9 = 0xffffffff;
        iVar6 = -1;
        iVar4 = -1;
        uVar8 = 0;
        bVar2 = FUN_0041d9d2(spell_id,target_id,2);
        uVar7 = 1 << (bVar2 & 0x1f);
        uVar5 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
        iVar4 = Action_ValidateTarget_00405802
                          (spell_id,2,1 - spell_id,0x200,0x1047,0,0,uVar5,uVar7,uVar8,iVar4,iVar6,
                           uVar9,uVar10,uVar12,uVar11,uVar13,arg_18,uVar3,arg_20);
        if (iVar4 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
          *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = DAT_006b2d3c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = DAT_006b2d2c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      local_8 = 0;
      if (DAT_006b2d3c == -1) {
        uVar13 = 0;
        uVar11 = 0;
        uVar12 = 0;
        uVar10 = 0xffffffff;
        uVar9 = 0xffffffff;
        iVar6 = -1;
        iVar4 = -1;
        uVar8 = 0;
        bVar2 = FUN_0041d9d2(spell_id,target_id,2);
        uVar7 = 1 << (bVar2 & 0x1f);
        uVar5 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
        iVar4 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0x200,0,0,0,uVar5,uVar7,uVar8,iVar4,
                           iVar6,uVar9,uVar10,uVar12,uVar11,uVar13);
        if (iVar4 != 0) {
          local_8 = local_8 + 1;
        }
      }
      else {
        uVar12 = 0;
        uVar10 = 0;
        uVar9 = 2;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar4 = -1;
        uVar5 = 0;
        bVar2 = FUN_0041d9d2(spell_id,target_id,2);
        iVar4 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0,0,0,0,0,1 << (bVar2 & 0x1f),uVar5,
                           iVar4,iVar6,uVar7,uVar8,uVar9,uVar10,uVar12);
        if (iVar4 != 0) {
          local_8 = local_8 + 1;
        }
      }
      if (local_8 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        local_10 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
        local_c = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        cVar1 = (&DAT_006a5f4d)[local_10 * 0x5b20 + local_c * 0x120];
        bVar2 = FUN_0041d9d2(spell_id,target_id,2);
        if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
          Pic_Subsystem_0044867e(local_10,local_c,2);
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}


