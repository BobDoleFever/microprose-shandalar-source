/*
 * Decompiled function: Player_Init_0046709c
 * Entry Point: 0046709c
 * Size: 718 bytes
 */
#include "magic.h"


undefined4 Player_Init_0046709c(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_94;
  int local_90;
  undefined4 local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c [30];
  
  if (flags == 0x73) {
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
  else {
    if (flags == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_005247a0,s_GLASSES_OF_URZA_00524790);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_90);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_90;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8c
        ;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_94 = 0;
      local_88 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      if (((g_IsAiThinking != 1) && (spell_id == 0)) && (DAT_006fedc0 == 0)) {
        for (local_84 = 0; local_84 < (int)(&g_PlayerActiveCardCount)[local_88];
            local_84 = local_84 + 1) {
          local_80 = *(int *)(&g_CardSlot_CardId + local_88 * 0x5b20 + local_84 * 0x120);
          if ((local_80 != -1) &&
             (((&g_CardSlot_Flags)[local_88 * 0x5b20 + local_84 * 0x120] & 2) == 0)) {
            local_7c[local_94] = local_80;
            local_94 = local_94 + 1;
          }
        }
        Pic_Load_004509e8(0,(int)local_7c,local_94,s_Target_Player_s_Hand_005247b4,0);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


