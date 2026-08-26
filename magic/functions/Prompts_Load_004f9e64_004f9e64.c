/*
 * Decompiled function: Prompts_Load_004f9e64
 * Entry Point: 004f9e64
 * Size: 1471 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004f9e64(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
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
  int local_14;
  int local_10;
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
    FUN_00403250((int *)(-(uint)(DAT_0063ee88 == 0) & 0x6b2d68),0,spell_id,2,2,0x200,2,0,0,uVar1,
                 arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if ((g_ActivePlayerPriority == spell_id) &&
       ((g_OverworldPlayerCoordY == 0 || (iVar2 = FUN_0040d949(spell_id,7,2), iVar2 == 0)))) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      local_c = 0;
      local_8 = 0;
      while (((local_c < g_TurnCounter && (local_8 == 0)) && (g_ActivePlayer != 1))) {
        Pic_Subsystem_00424500(s_prompts_txt_005304fc,s_WINTER_BLAST_005304ec);
        sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,local_c + 1,g_TurnCounter);
        arg_20 = &local_14;
        uVar1 = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar2 = -1;
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
        iVar2 = Action_ValidateTarget_00405802
                          (spell_id,2,1 - spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,
                           uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
        if (iVar2 == 0) {
          if (local_10 == -1) {
            g_ActivePlayer = 1;
          }
          else {
            local_8 = 1;
          }
        }
        else {
          *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) =
               *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) | 0x300000;
          Ai_Subsystem_004cc9c5(0,0x20);
          *(int *)(&g_CardSlot_CombatTarget +
                  target_id * 0x120 +
                  spell_id * 0x5b20 +
                  (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
               local_14;
          *(int *)(&g_CardSlot_AttachedAura +
                  target_id * 0x120 +
                  spell_id * 0x5b20 +
                  (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
               local_10;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
               (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
        }
        local_c = local_c + 1;
      }
      for (local_c = 0;
          local_c < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
          local_c = local_c + 1) {
        *(uint *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_AttachedAura +
                         target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x120 +
                 *(int *)(&g_CardSlot_CombatTarget +
                         target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_AttachedAura +
                              target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget +
                              target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x5b20) &
             0xffcfffff;
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
    }
    if (flags == 0x71) {
      for (local_c = 0;
          local_c < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
          local_c = local_c + 1) {
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar2 = -1;
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
        iVar2 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget +
                                   target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                           *(int *)(&g_CardSlot_AttachedAura +
                                   target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),(char *)0x0,
                           spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,uVar8,uVar9,
                           uVar10,uVar11);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          FUN_00415d48(*(int *)(&g_CardSlot_CombatTarget +
                               target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                       *(int *)(&g_CardSlot_AttachedAura +
                               target_id * 0x120 + spell_id * 0x5b20 + local_c * 8));
          uVar3 = FUN_00473179(*(int *)(&g_CardSlot_CombatTarget +
                                       target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                               *(int *)(&g_CardSlot_AttachedAura +
                                       target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),0x34,
                               0xffffffff);
          if ((uVar3 & 0x20) != 0) {
            FUN_0041db67(*(int *)(&g_CardSlot_CombatTarget +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),2,spell_id,
                         target_id);
          }
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


