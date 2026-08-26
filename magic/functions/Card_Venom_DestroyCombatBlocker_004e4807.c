/*
 * Decompiled function: Card_Venom_DestroyCombatBlocker
 * Entry Point: 004e4807
 * Size: 1959 bytes
 */
#include "magic.h"


undefined4 Card_Venom_DestroyCombatBlocker(int spell_id,int target_id,int flags)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  int iVar4;
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
  int local_18;
  int local_10;
  
  if (((flags == 0x3c) &&
      (*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) != -1)) &&
     ((&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] != -1)) {
    (&DAT_006a604f)
    [*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
     (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] =
         (&DAT_006a604f)
         [*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
          (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] | 0x3f;
  }
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    uVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052efac,s_VENOM_0052efa4);
      iVar3 = CardTarget_PromptTargetCreature(spell_id,spell_id,target_id);
      if (iVar3 == 0) {
        g_ActivePlayer = 1;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      iVar4 = -1;
      iVar3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar3 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar3,iVar4,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar3 == 0) {
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
    if (flags == 0x1a) {
      iVar3 = 1 - (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120];
      if (((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] == g_DefendingPlayer
          ) && (((&g_CardSlot_Flags)
                 [*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) *
                  0x120 + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                          0x5b20] & 0x44) != 0)) {
        if ((&g_CardSlot_ColorMask)
            [*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
             (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] == -1) {
          local_18 = *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120);
        }
        else {
          local_18 = (int)(char)(&g_CardSlot_ColorMask)
                                [*(int *)(&g_CardSlot_OriginalCardId +
                                         spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                                 (char)(&g_CardSlot_Toughness)
                                       [spell_id * 0x5b20 + target_id * 0x120] * 0x5b20];
        }
        for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[iVar3];
            local_10 = local_10 + 1) {
          if ((((char)(&g_CardSlot_ColorMask)[iVar3 * 0x5b20 + local_10 * 0x120] == local_18) &&
              ((&DAT_0051aebd)
               [*(int *)(&g_CardSlot_CardId + iVar3 * 0x5b20 + local_10 * 0x120) * 0x34] != '\0'))
             && (((&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + iVar3 * 0x5b20 + local_10 * 0x120) * 0x34] & 2) !=
                 0)) {
            FUN_00410cc0(spell_id,target_id,DAT_006a48e4,iVar3,local_10);
          }
        }
      }
      if (((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] != g_DefendingPlayer
          ) && ((&g_CardSlot_ColorMask)
                [*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) *
                 0x120 + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                         0x5b20] != -1)) {
        cVar1 = (&g_CardSlot_ColorMask)
                [iVar3 * 0x5b20 +
                 (char)(&g_CardSlot_ColorMask)
                       [*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] * 0x120];
        if (cVar1 == -1) {
          FUN_00410cc0(spell_id,target_id,DAT_006a48e4,iVar3,
                       (int)(char)(&g_CardSlot_ColorMask)
                                  [*(int *)(&g_CardSlot_OriginalCardId +
                                           spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                                   (char)(&g_CardSlot_Toughness)
                                         [spell_id * 0x5b20 + target_id * 0x120] * 0x5b20]);
        }
        else {
          for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[iVar3];
              local_10 = local_10 + 1) {
            iVar4 = FUN_00471c32(iVar3,local_10);
            if ((iVar4 != 0) &&
               ((&g_CardSlot_ColorMask)[iVar3 * 0x5b20 + local_10 * 0x120] == cVar1)) {
              FUN_00410cc0(spell_id,target_id,DAT_006a48e4,iVar3,local_10);
            }
          }
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


