/*
 * Decompiled function: Pic_Subsystem_0042ae1d
 * Entry Point: 0042ae1d
 * Size: 2008 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042ae1d(int spell_id,int target_id,int flags)

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
  int local_10;
  undefined4 local_c;
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
    uVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052126c,s_ANIMATE_ARTIFACT_00521258);
      arg_20 = &local_10;
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
                        (spell_id,2,2,0x200,0x40,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9
                         ,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,0x40,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7
                         ,uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        if (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                              0x5b20) * 0x34] & 0x42) == 0x40) {
          local_8 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId +
                                         *(int *)(&g_CardSlot_OriginalCardId +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                         (char)(&g_CardSlot_Toughness)
                                               [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20));
          if (local_8 != -1) {
            (&g_MasterCardColorTable)[local_8 * 0x34] = 0x42;
            *(short *)(&DAT_0051aec4 + local_8 * 0x34) =
                 (short)(char)(&DAT_0051aec0)
                              [*(int *)(&g_CardSlot_CardId +
                                       *(int *)(&g_CardSlot_OriginalCardId +
                                               target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                       (char)(&g_CardSlot_Toughness)
                                             [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) *
                               0x34];
            *(undefined2 *)(&DAT_0051aec2 + local_8 * 0x34) =
                 *(undefined2 *)(&DAT_0051aec4 + local_8 * 0x34);
            *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = local_8;
            *(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) = local_8;
            *(uint *)(&g_CardSlot_Abilities2 +
                     *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                             0x5b20) =
                 *(uint *)(&g_CardSlot_Abilities2 +
                          *(int *)(&g_CardSlot_OriginalCardId +
                                  target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                          (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) | 0x1000000;
          }
        }
        else {
          *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)
                (&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x77) && (g_OverworldMapGrid == target_id)) &&
       ((g_OverworldPlayerCoordX == spell_id &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) != -1)))) {
      (&g_MasterCardColorTable)
      [*(int *)(&g_CardSlot_CardId +
               *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) *
       0x34] = (&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) * 0x34] &
               0xfd;
    }
    if (((flags == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_OverworldMapGrid &&
        ((((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
           g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)) &&
         (iVar5 = FUN_00471c32(spell_id,target_id), iVar5 != 0)))))) {
      g_ActivePalette =
           *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
      *(uint *)(&g_CardSlot_Abilities1 +
               *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) | 0x40;
    }
    uVar1 = 0;
  }
  return uVar1;
}


