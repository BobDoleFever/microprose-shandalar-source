/*
 * Decompiled function: Minit_Subsystem_0045d1f0
 * Entry Point: 0045d1f0
 * Size: 1618 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045d1f0(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  undefined4 uVar16;
  uint uVar17;
  undefined4 uVar18;
  undefined1 *arg_18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 arg_19;
  int *arg_20;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    uVar20 = 0;
    uVar19 = 0;
    uVar18 = 0;
    uVar16 = 0xffffffff;
    uVar14 = 0xffffffff;
    uVar12 = 0xffffffff;
    uVar10 = 0xffffffff;
    uVar8 = 0;
    uVar6 = 0;
    uVar1 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    FUN_00403250((int *)(-(uint)(DAT_0063ee88 == 0) & 0x6b2d68),0,spell_id,2,2,0x200,1,0,0,uVar1,
                 uVar6,uVar8,uVar10,uVar12,uVar14,uVar16,uVar18,uVar19,uVar20);
    if (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (flags == 0x90) {
    Ai_CalcLifeAdvantage(0);
    uVar1 = 0;
  }
  else {
    if (flags == 0x6d) {
      if (spell_id == g_ActivePlayerPriority) {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
      *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      uVar1 = g_OverworldPlayerCoordY;
      arg_19 = 0;
      uVar20 = 0;
      uVar19 = 0;
      uVar18 = 0xffffffff;
      uVar16 = 0xffffffff;
      uVar14 = 0xffffffff;
      uVar12 = 0xffffffff;
      uVar10 = 0;
      uVar8 = 0;
      uVar6 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      FUN_00403250(&g_OverworldPlayerCoordY,0,spell_id,2,2,0x200,1,0,0,uVar6,uVar8,uVar10,uVar12,
                   uVar14,uVar16,uVar18,uVar19,uVar20,arg_19);
      DAT_006b2d40 = 0xffffffff;
      Ai_CalcManaRequirement_004ba890(spell_id,0,0);
      g_OverworldPlayerCoordY = uVar1;
      if (g_ActivePlayer != 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        local_c = 0;
        local_8 = 0;
        while (((local_c < g_TurnCounter && (local_8 == 0)) && (g_ActivePlayer != 1))) {
          Pic_Subsystem_00424500(s_prompts_txt_005244a0,s_CANDLEABRA_OF_TAWNOS_00524488);
          sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,local_c + 1,g_TurnCounter);
          arg_20 = &local_14;
          uVar1 = 1;
          arg_18 = &g_OverworldGoldAmount;
          uVar17 = 0;
          uVar15 = 0;
          uVar13 = 0;
          uVar11 = 0xffffffff;
          uVar9 = 0xffffffff;
          iVar7 = -1;
          iVar5 = -1;
          uVar4 = 0;
          uVar3 = 0;
          uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
          iVar5 = Action_ValidateTarget_00405802
                            (spell_id,2,spell_id,0x200,1,0,0,uVar2,uVar3,uVar4,iVar5,iVar7,uVar9,
                             uVar11,uVar13,uVar15,uVar17,arg_18,uVar1,arg_20);
          if (iVar5 == 0) {
            if (local_10 == -1) {
              (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
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
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0xffffffef;
      }
    }
    if (flags == 0x72) {
      for (local_c = 0;
          local_c < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
          local_c = local_c + 1) {
        local_14 = *(int *)(&g_CardSlot_CombatTarget +
                           target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
        local_10 = *(int *)(&g_CardSlot_AttachedAura +
                           target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
        uVar17 = 0;
        uVar15 = 0;
        uVar13 = 0;
        uVar11 = 0xffffffff;
        uVar9 = 0xffffffff;
        iVar7 = -1;
        iVar5 = -1;
        uVar4 = 0;
        uVar3 = 0;
        uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
        iVar5 = Rules_ParseFilter_0040360b
                          (local_14,local_10,(char *)0x0,spell_id,2,2,0x200,1,0,0,uVar2,uVar3,uVar4,
                           iVar5,iVar7,uVar9,uVar11,uVar13,uVar15,uVar17);
        if (iVar5 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          Magic_TriggerCardEvent(local_14,local_10,1,0xffffffff,0xffffffff);
          *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) =
               *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) & 0xffffffef;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


