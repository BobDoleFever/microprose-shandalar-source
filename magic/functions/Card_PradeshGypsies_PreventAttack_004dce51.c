/*
 * Decompiled function: Card_PradeshGypsies_PreventAttack
 * Entry Point: 004dce51
 * Size: 1258 bytes
 */
#include "magic.h"


undefined4 Card_PradeshGypsies_PreventAttack(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  undefined4 arg_11;
  int iVar7;
  undefined4 arg_12;
  uint uVar8;
  undefined4 arg_13;
  uint uVar9;
  undefined4 arg_14;
  uint uVar10;
  undefined4 arg_15;
  uint uVar11;
  undefined4 arg_16;
  uint uVar12;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    bVar4 = (*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
    if ((bVar4) && (iVar1 = FUN_0040d949(spell_id,3,1), iVar1 == 0)) {
      bVar4 = false;
    }
    if ((bVar4) && (iVar1 = FUN_0040d949(spell_id,7,2), iVar1 == 0)) {
      bVar4 = false;
    }
    uVar2 = 0;
    if (bVar4) {
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
      uVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      DAT_006b2d40 = 1;
      Ai_CalcManaRequirement_004ba890(spell_id,3,1);
      if (g_ActivePlayer != 1) {
        Pic_Subsystem_00424500(s_prompts_txt_0052ec68,s_PRADESH_GYPSIES_0052ec58);
        arg_20 = &local_10;
        uVar2 = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uVar8 = 0xffffffff;
        iVar7 = -1;
        iVar1 = -1;
        uVar6 = 0;
        uVar5 = 0;
        uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
        iVar1 = Action_ValidateTarget_00405802
                          (spell_id,2,spell_id,0x200,2,0,0,uVar3,uVar5,uVar6,iVar1,iVar7,uVar8,uVar9
                           ,uVar10,uVar11,uVar12,arg_18,uVar2,arg_20);
        if (iVar1 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
          *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
          *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        }
      }
    }
    if (flags == 0x72) {
      local_10 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_c = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar1 = -1;
      uVar6 = 0;
      uVar5 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (local_10,local_c,(char *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar5,uVar6,
                         iVar1,iVar7,uVar8,uVar9,uVar10,uVar11,uVar12);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        local_8 = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,local_10,local_c);
        if (local_8 != -1) {
          *(undefined2 *)(&DAT_006a5f48 + local_8 * 0x120 + spell_id * 0x5b20) = 0xfffe;
          *(undefined2 *)(&DAT_006a5f4a + local_8 * 0x120 + spell_id * 0x5b20) = 0;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if ((((flags == 0x3b) &&
         ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) &&
        (iVar1 = FUN_0040d949(spell_id,3,1), iVar1 != 0)) &&
       (iVar1 = FUN_0040d949(spell_id,7,2), iVar1 != 0)) {
      *(int *)(&DAT_00695eb0 + (1 - spell_id) * 4) =
           *(int *)(&DAT_00695eb0 + (1 - spell_id) * 4) + -2;
    }
    if (((flags == 0x8a) && (target_id == g_OverworldMapGrid)) &&
       ((spell_id == g_OverworldPlayerCoordX && (iVar1 = FUN_0040d949(spell_id,3,1), iVar1 != 0))))
    {
      DAT_006ff19c = DAT_006ff19c + 0xc;
    }
    if (((flags == 0x8b) && (target_id == g_OverworldMapGrid)) &&
       ((spell_id == g_OverworldPlayerCoordX && (iVar1 = FUN_0040d949(spell_id,3,1), iVar1 != 0))))
    {
      DAT_006ff19c = DAT_006ff19c + -0xc;
    }
    uVar2 = 0;
  }
  return uVar2;
}


