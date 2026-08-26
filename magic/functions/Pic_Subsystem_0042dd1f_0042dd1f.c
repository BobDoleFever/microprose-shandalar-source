/*
 * Decompiled function: Pic_Subsystem_0042dd1f
 * Entry Point: 0042dd1f
 * Size: 1461 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042dd1f(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
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
  undefined4 local_8;
  
  if (((flags == 199) && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 2) != 0)) &&
     ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1)) {
    if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_CurrentTurnPhase)
    {
      iVar1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * 0x18;
    }
    else {
      iVar1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * -0x18;
    }
  }
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
    uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    uVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,4,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005212d8,s_FEEDBACK_005212cc);
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,4,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_CurrentTurnPhase) {
          g_SpellStackDepth = g_SpellStackDepth + 0x30;
        }
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + -0x60;
        }
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,4,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == DAT_0063edc0)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_DefendingPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        DAT_006a4920 = DAT_006a4920 | 3;
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (flags == 0x86) {
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],1,
                   spell_id,target_id);
      }
      if (flags == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}


