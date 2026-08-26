/*
 * Decompiled function: Pic_Subsystem_0042e2d9
 * Entry Point: 0042e2d9
 * Size: 1333 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042e2d9(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
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
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    uVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005212f0,s_BRAINWASH_005212e4);
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar5 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_8;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        if (local_c == spell_id) {
          iVar5 = FUN_00473179(local_c,local_8,0x32,0xffffffff);
          g_SpellStackDepth = g_SpellStackDepth - (iVar5 * 0xc) / 2;
        }
        else {
          iVar5 = FUN_00473179(local_c,local_8,0x32,0xffffffff);
          g_SpellStackDepth = g_SpellStackDepth + (iVar5 * 0xc) / 2;
        }
      }
    }
    if (flags == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar5 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
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
    if (((((g_PlayerManaPool == 0xdc) && (g_ScWillyScore == 0x15)) &&
         ((g_OverworldMapGrid == target_id &&
          ((g_OverworldPlayerCoordX == spell_id && (g_DefendingPlayer == DAT_006a4b5c)))))) &&
        (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) &&
       (((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] == DAT_00695f08 &&
        (*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
         DAT_006b2e14)))) {
      iVar5 = FUN_0040d949(g_DefendingPlayer,7,3);
      if (iVar5 == 0) {
        DAT_0068a65c = 1;
      }
      else {
        if (flags == 0x7d) {
          g_ActivePalette = g_ActivePalette | 2;
        }
        if (flags == 0x7e) {
          Magic_CombatPhase(spell_id,target_id,0x7e,spell_id,0);
          Ai_CalcManaRequirement_004ba890(g_DefendingPlayer,0,3);
          Magic_DiscardToHandSize();
          if (g_ActivePlayer == 1) {
            DAT_0068a65c = 1;
            g_ActivePlayer = 0;
          }
          else {
            *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
                 1;
          }
        }
      }
    }
    if ((flags == 0x79) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) {
      iVar5 = FUN_0040d949(g_DefendingPlayer,7,3);
      if (iVar5 == 0) {
        g_ActivePalette = 1;
      }
      uVar1 = 0;
    }
    else {
      if ((flags == 0x22) || (flags == 199)) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


