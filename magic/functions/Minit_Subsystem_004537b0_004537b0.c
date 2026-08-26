/*
 * Decompiled function: Minit_Subsystem_004537b0
 * Entry Point: 004537b0
 * Size: 1200 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004537b0(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    local_14 = (uint)(((byte)g_PlayerHandCardCount & 4) != 0);
    if (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0) {
      local_14 = 0;
    }
    if (((local_14 != 0) && (((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0)) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0)) {
      local_14 = 0;
    }
    if (local_14 != 0) {
      local_14 = FUN_00403250((int *)0x0,1,spell_id,2,2,0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,
                              0xffffffff,0xffffffff,0,0,0);
    }
    if (local_14 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 99;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if ((flags == 0x6d) && (((byte)g_PlayerHandCardCount & 4) != 0)) {
      if (DAT_006ff4ac == 0) {
        local_8 = 0;
        while (local_8 == 0) {
          Pic_Subsystem_00424500(s_prompts_txt_00523f74,s_OASIS_00523f6c);
          iVar2 = Action_ValidateTarget_00405802
                            (spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,0xffffffff,0,
                             0,0,&g_OverworldGoldAmount,1,&local_10);
          if (iVar2 == 0) {
            g_ActivePlayer = 1;
            local_8 = 1;
          }
          else if (*(int *)(&g_CardSlot_OriginalCardId + local_10 * 0x5b20 + local_c * 0x120) == -1)
          {
            if (g_IsAiThinking != 1) {
              Ai_Util_004cc42d(s_Illegal_target__damage_type___00523f80);
              Sleep(2000);
              Ai_Util_004cc42d(&DAT_00523fa0);
            }
          }
          else {
            local_8 = 1;
            *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
            *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
            (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
            *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
          }
        }
      }
      else {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        g_ActivePlayer = 1;
      }
    }
    if ((flags == 0x72) && ((&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] != '\0')
       ) {
      local_10 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_c = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      iVar2 = Rules_ParseFilter_0040360b
                        (local_10,local_c,(char *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1
                         ,0xffffffff,0xffffffff,0,0,0);
      if (iVar2 != 0) {
        if (*(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) < 1) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) =
               *(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) + -1;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if ((flags == 0x3b) &&
       (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      *(int *)(&DAT_00695eb8 + spell_id * 4) = *(int *)(&DAT_00695eb8 + spell_id * 4) + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


