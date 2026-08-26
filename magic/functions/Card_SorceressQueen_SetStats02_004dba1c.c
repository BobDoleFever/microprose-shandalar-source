/*
 * Decompiled function: Card_SorceressQueen_SetStats02
 * Entry Point: 004dba1c
 * Size: 1471 bytes
 */
#include "magic.h"


undefined4 Card_SorceressQueen_SetStats02(int spell_id,int target_id,int flags)

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
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    uVar1 = 0;
    if ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0) {
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
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ebfc,s_SORCERESS_QUEEN_0052ebec);
      *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x100000;
      Ai_Subsystem_004cc9c5(0,0x20);
      arg_20 = &local_14;
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
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_14;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
      *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0xffefffff;
    }
    if (flags == 0x72) {
      local_14 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_10 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
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
                        (local_14,local_10,(char *)0x0,spell_id,2,2,0x200,2,0,0,uVar2,uVar3,uVar4,
                         iVar5,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
          for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8];
              local_c = local_c + 1) {
            if ((((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == DAT_006b3060
                  ) && (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
                ((char)(&g_CardSlot_Toughness)[local_c * 0x120 + local_8 * 0x5b20] == local_14)) &&
               (*(int *)(&g_CardSlot_OriginalCardId + local_c * 0x120 + local_8 * 0x5b20) ==
                local_10)) {
              *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + local_8 * 0x5b20) =
                   *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + local_8 * 0x5b20) &
                   0xfeffffff;
            }
          }
        }
        iVar5 = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006b3060,local_14,local_10);
        if (iVar5 != -1) {
          *(uint *)(&g_CardSlot_Abilities1 + iVar5 * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + iVar5 * 0x120 + spell_id * 0x5b20) | 0x1000000;
          *(ushort *)(&DAT_006a5f48 + iVar5 * 0x120 + spell_id * 0x5b20) =
               -(*(ushort *)
                  (&DAT_0051aec2 +
                  *(int *)(&g_CardSlot_CardId + local_14 * 0x5b20 + local_10 * 0x120) * 0x34) &
                0xbfff);
          *(ushort *)(&DAT_006a5f4a + iVar5 * 0x120 + spell_id * 0x5b20) =
               2 - (*(ushort *)
                     (&DAT_0051aec4 +
                     *(int *)(&g_CardSlot_CardId + local_14 * 0x5b20 + local_10 * 0x120) * 0x34) &
                   0xbfff);
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if (((flags == 0x8a) && (g_OverworldMapGrid == target_id)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      DAT_006ff19c = DAT_006ff19c + 0xc;
    }
    if (((flags == 0x8b) && (g_OverworldMapGrid == target_id)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      DAT_006ff19c = DAT_006ff19c + -0xc;
    }
    uVar1 = 0;
  }
  return uVar1;
}


