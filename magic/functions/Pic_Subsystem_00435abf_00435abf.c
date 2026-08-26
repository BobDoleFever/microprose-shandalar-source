/*
 * Decompiled function: Pic_Subsystem_00435abf
 * Entry Point: 00435abf
 * Size: 2625 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00435abf(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  int arg_15;
  undefined4 arg_15_00;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  
  if (flags == 1) {
    *(int *)(&DAT_006ff6a4 + spell_id * 0x20) = *(int *)(&DAT_006ff6a4 + spell_id * 0x20) + 1;
  }
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uVar1 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    uVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
      *(undefined4 *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = 0;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
           *(undefined4 *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120);
      Pic_Subsystem_00424500(s_prompts_txt_00521568,s_HOLY_ARMOR_0052155c);
      iVar2 = CardTarget_PromptTargetCreature(spell_id,spell_id,target_id);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
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
    if (((flags == 0x33) &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
         g_OverworldMapGrid &&
        (((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] ==
          g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))))) {
      g_ActivePalette = g_ActivePalette + 2;
    }
    if (flags == 0x73) {
      uVar1 = FUN_0040dcca(spell_id,target_id,5,1);
    }
    else if (flags == 0x90) {
      if (spell_id == g_DefendingPlayer) {
        iVar2 = FUN_00473cc5((&DAT_006a5f4d)[spell_id * 0x5b20 + target_id * 0x120]);
        if (*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) {
          Ai_CalcLifeAdvantage(0);
        }
        else {
          DAT_0062785c = 1;
        }
      }
      else {
        DAT_0062785c = 1;
      }
      DAT_006fefa8 = (int)(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] << 8
                     | *(uint *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120)
      ;
      uVar1 = 0;
    }
    else {
      if ((flags == 0x6d) && (iVar2 = FUN_0040dcca(spell_id,target_id,5,1), iVar2 != 0)) {
        if (spell_id == g_DefendingPlayer) {
          iVar2 = FUN_00473cc5((&DAT_006a5f4d)[spell_id * 0x5b20 + target_id * 0x120]);
          if (*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) {
            Ai_CalcManaRequirement_004ba890(spell_id,5,-1);
          }
          else {
            g_TurnCounter = Ai_Subsystem_004be192(spell_id,target_id,5,1);
          }
          if (g_TurnCounter < 1) {
            g_ActivePlayer = 1;
          }
          else {
            *(int *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = g_TurnCounter
            ;
          }
        }
        else {
          iVar2 = FUN_00473cc5((&DAT_006a5f4d)[spell_id * 0x5b20 + target_id * 0x120]);
          if (*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) {
            Ai_CalcManaRequirement_004ba890(spell_id,5,1);
          }
          else {
            Ai_Subsystem_004be192(spell_id,target_id,5,1);
          }
          *(undefined4 *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = 1;
        }
        if (g_ActivePlayer == 1) {
          *(undefined4 *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = 0;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) =
               (int)(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120];
          *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) =
               *(undefined4 *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120);
          (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
          if (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)
          {
            *(uint *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) |
                 0x80000;
          }
        }
      }
      if (flags == 0x72) {
        if (*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) *
                    0x120 + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                            0x5b20) == -1) {
          g_ActivePlayer = 1;
        }
        else {
          (&g_CardSlot_TurnPlayed)
          [*(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
           *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20] = 0;
          *(uint *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                   0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) *
                           0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                       0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120
                                       ) * 0x5b20) +
               (*(uint *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) & 0xff) *
               0x100;
          if (((&DAT_006a5f56)
               [*(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120
                + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20] &
              8) != 0) {
            *(uint *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                     0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120)
                             * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost +
                          *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120
                                  ) * 0x120 +
                          *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) *
                          0x5b20) & 0xfff7ffff;
            iVar2 = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,
                                 (int)(char)(&g_CardSlot_Toughness)
                                            [spell_id * 0x5b20 + target_id * 0x120],
                                 *(int *)(&g_CardSlot_OriginalCardId +
                                         spell_id * 0x5b20 + target_id * 0x120));
            if (iVar2 != -1) {
              *(short *)(&DAT_006a5f4a + iVar2 * 0x120 + spell_id * 0x5b20) =
                   (short)*(undefined4 *)
                           (&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120);
              *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + spell_id * 0x5b20) =
                   *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + spell_id * 0x5b20) |
                   0x80000;
            }
          }
        }
      }
      if (flags == 199) {
        if (spell_id == g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_0063ee44 + spell_id * 0x20) * 0xc;
        }
        else {
          g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_0063ee44 + spell_id * 0x20) * -0xc;
        }
      }
      if ((flags == 0x22) || (flags == 199)) {
        *(undefined4 *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = 0;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


