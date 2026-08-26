/*
 * Decompiled function: Minit_Subsystem_0045d8dc
 * Entry Point: 0045d8dc
 * Size: 1225 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045d8dc(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) ||
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0)) {
      if (((byte)g_PlayerHandCardCount & 4) == 0) {
        uVar1 = 0;
      }
      else if ((g_ScWillyScore == 0x1a) || (g_ScWillyScore == 0x19)) {
        iVar2 = FUN_0040d949(spell_id,7,1);
        if (iVar2 == 0) {
          uVar1 = 0;
        }
        else {
          iVar2 = FUN_00403250((int *)0x0,2,spell_id,1 - spell_id,1 - spell_id,0x200,2,0,0,0,0,0,
                               0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,2,8);
          if (iVar2 == 0) {
            uVar1 = 0;
          }
          else {
            uVar1 = 99;
          }
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if ((((flags == 0x6d) && (iVar2 = FUN_0040d949(spell_id,7,1), iVar2 != 0)) &&
        (((byte)g_PlayerHandCardCount & 4) != 0)) &&
       ((g_ScWillyScore == 0x1a || (g_ScWillyScore == 0x19)))) {
      Ai_CalcManaRequirement_004ba890(spell_id,0,1);
      Pic_Subsystem_00424500(s_prompts_txt_005244b8,s_FORCEFIELD_005244ac);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,spell_id,spell_id,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,
                         0xffffffff,0x20,0,0,&g_OverworldGoldAmount,1,&local_c);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else if ((((&g_MasterCardColorTable)
                 [*(int *)(&g_CardSlot_CardId +
                          *(int *)(&g_CardSlot_TypeFlags + local_c * 0x5b20 + local_8 * 0x120) *
                          0x120 + (char)(&g_CardSlot_DamageReceived)
                                        [local_c * 0x5b20 + local_8 * 0x120] * 0x5b20) * 0x34] & 2)
                != 0) &&
              (((&DAT_006a5f3d)
                [*(int *)(&g_CardSlot_TypeFlags + local_c * 0x5b20 + local_8 * 0x120) * 0x120 +
                 (char)(&g_CardSlot_DamageReceived)[local_c * 0x5b20 + local_8 * 0x120] * 0x5b20] &
               2) == 0)) {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x72) {
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,(byte)spell_id,(byte)spell_id,0x200,0,0,0,0,0,0,
                         DAT_006ff2e0,-1,0xffffffff,0xffffffff,0,0,0);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else if (*(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) *
                       0x5b20 + *(int *)(&g_CardSlot_AttachedAura +
                                        target_id * 0x120 + spell_id * 0x5b20) * 0x120) != 0) {
        *(undefined4 *)
         (&g_CardSlot_ConvertedManaCost +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


