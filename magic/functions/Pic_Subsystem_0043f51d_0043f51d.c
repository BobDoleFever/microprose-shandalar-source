/*
 * Decompiled function: Pic_Subsystem_0043f51d
 * Entry Point: 0043f51d
 * Size: 1498 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043f51d(int spell_id,int target_id,int flags)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
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
    *(int *)(&DAT_006ff6a0 + spell_id * 0x20) = *(int *)(&DAT_006ff6a0 + spell_id * 0x20) + 2;
  }
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    uVar3 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar3,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052190c,s_THE_BRUTE_00521900);
      iVar4 = CardTarget_PromptTargetCreature(spell_id,spell_id,target_id);
      if (iVar4 == 0) {
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
      iVar4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar4 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar4,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar4 == 0) {
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
    if (((flags == 0x73) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
      bVar1 = (&g_CardSlot_Flags)
              [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20];
      cVar2 = (&DAT_006a5f50)
              [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20];
      iVar4 = FUN_0040dcca(spell_id,target_id,4,3);
      if (iVar4 == 0 || (cVar2 != '\x02' || (bVar1 & 2) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 99;
      }
    }
    else if (flags == 0x90) {
      Ai_GetOpponentPlayerScore(0);
      uVar3 = 0;
    }
    else {
      if (((flags == 0x6d) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) &&
         (Ai_Subsystem_004be192(spell_id,target_id,4,3), g_ActivePlayer != 1)) {
        DAT_00695df8 = 1;
        *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
      }
      if ((flags == 0x72) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) {
        *(undefined4 *)
         (&g_CardSlot_ConvertedManaCost +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) = 0;
        Card_GenericCreature_CanRegenerate
                  ((int)(char)(&g_CardSlot_Toughness)
                              [*(int *)(&g_CardSlot_SicknessState +
                                       target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                               *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20
                                       ) * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId +
                           *(int *)(&g_CardSlot_SicknessState +
                                   target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                           *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                           0x5b20));
      }
      if ((((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
             g_OverworldMapGrid) &&
           ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
            g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) &&
         ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
          (flags == 0x32)))) {
        g_ActivePalette = g_ActivePalette + 1;
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}


