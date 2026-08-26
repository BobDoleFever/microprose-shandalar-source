/*
 * Decompiled function: Pic_Subsystem_0043070c
 * Entry Point: 0043070c
 * Size: 2036 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043070c(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 arg_11;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  int iVar5;
  undefined4 arg_15;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  int local_10;
  
  bVar1 = false;
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11 = 0;
    uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    uVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uVar2,arg_11,arg_12_00,arg_13_00,
                         arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005213f0,s_EROSION_005213e8);
      iVar3 = CardTarget_PromptTargetPermanent(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint)(iVar3 == 0);
      if (g_ActivePlayer != 1) {
        if (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) ==
            g_CurrentTurnPhase) {
          iVar3 = FUN_00473cc5((&DAT_0051aebe)
                               [*(int *)(&g_CardSlot_CardId +
                                        *(int *)(&g_CardSlot_AttachedAura +
                                                spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                                        *(int *)(&g_CardSlot_CombatTarget +
                                                spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) *
                                0x34]);
          g_SpellStackDepth =
               g_SpellStackDepth +
               *(int *)(&DAT_0063ee30 + iVar3 * 4 + g_CurrentTurnPhase * 0x20) * -4 + 0x20;
        }
        if (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) ==
            g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + -0x60;
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      iVar5 = -1;
      iVar3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      uVar4 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar3 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,uVar4,arg_12,arg_13,iVar3,iVar5,arg_16
                         ,arg_17,arg_18,arg_19,arg_20);
      if (iVar3 == 0) {
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
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == DAT_0063edc0)) &&
          ((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] == g_DefendingPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[spell_id * 0x5b20 + target_id * 0x120] & 1) == 0))
      {
        *(uint *)(&g_CardSlot_SpecialState + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_SpecialState + spell_id * 0x5b20 + target_id * 0x120) | 0x101;
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
        *(uint *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (flags == 0x86) {
        iVar3 = 1;
        uVar4 = FUN_00473cc5((&DAT_006a5f4c)
                             [*(int *)(&g_CardSlot_OriginalCardId +
                                      spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                              (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                              0x5b20]);
        iVar3 = FUN_0040d949((int)(char)(&g_CardSlot_Toughness)
                                        [spell_id * 0x5b20 + target_id * 0x120],uVar4,iVar3);
        iVar5 = FUN_0040d949((int)(char)(&g_CardSlot_Toughness)
                                        [spell_id * 0x5b20 + target_id * 0x120],7,1);
        if (iVar3 == 1) {
          if ((iVar5 < 4) &&
             (10 < (int)(&g_PlayerCreatureCount)
                        [(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120]])) {
            local_10 = 2;
          }
          else {
            local_10 = 1;
          }
        }
        else if ((iVar5 < 3) &&
                (0xf < (int)(&g_PlayerCreatureCount)
                            [(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120]]))
        {
          local_10 = 2;
        }
        else {
          local_10 = 0;
        }
        while (!bVar1) {
          iVar3 = Ai_Subsystem_004cc56d
                            ((int)(char)(&g_CardSlot_Toughness)
                                        [spell_id * 0x5b20 + target_id * 0x120],spell_id,target_id,
                             (int)(char)(&g_CardSlot_Toughness)
                                        [spell_id * 0x5b20 + target_id * 0x120],
                             *(int *)(&g_CardSlot_OriginalCardId +
                                     spell_id * 0x5b20 + target_id * 0x120),
                             s_Destroy_enchanted_land__Pay_1_ma_005213fc,local_10);
          if (iVar3 == 0) {
            Pic_Subsystem_0044867e
                      ((int)(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120],
                       *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120),
                       2);
            bVar1 = true;
          }
          else if (iVar3 == 1) {
            iVar3 = FUN_0040d949((int)(char)(&g_CardSlot_Toughness)
                                            [spell_id * 0x5b20 + target_id * 0x120],7,1);
            if (iVar3 != 0) {
              *(uint *)(&g_CardSlot_Flags +
                       *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) =
                   *(uint *)(&g_CardSlot_Flags +
                            *(int *)(&g_CardSlot_OriginalCardId +
                                    spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                            (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                            0x5b20) | 0x40000;
              Ai_CalcManaRequirement_004ba890
                        ((int)(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120],0
                         ,1);
              if (g_ActivePlayer == 1) {
                g_ActivePlayer = 0;
              }
              else {
                bVar1 = true;
              }
            }
          }
          else if (iVar3 == 2) {
            (&g_PlayerCreatureCount)
            [(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120]] =
                 (&g_PlayerCreatureCount)
                 [(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120]] + -1;
            bVar1 = true;
          }
        }
      }
      if (flags == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) &
             0xfffffffe;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}


