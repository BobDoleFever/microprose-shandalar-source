/*
 * Decompiled function: Prompts_Load_004f72b0
 * Entry Point: 004f72b0
 * Size: 936 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004f72b0(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_110;
  int local_108;
  char local_104 [252];
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (flags == 0x71) {
      Pic_Subsystem_00424500(s_prompts_txt_00530338,s_BALANCE_00530330);
      strcpy(local_104,&g_OverworldGoldAmount);
      do {
        strcpy(&g_OverworldGoldAmount,local_104);
        local_110 = 0;
        local_108 = 0;
        local_8 = 0;
        while( true ) {
          iVar2 = DAT_006808bc;
          if (DAT_006808bc <= g_PlayerActiveCardCount) {
            iVar2 = g_PlayerActiveCardCount;
          }
          if (iVar2 <= local_8) break;
          iVar2 = FUN_00471c32(0,local_8);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + local_8 * 0x120) * 0x34] & 1)
              != 0)) {
            local_108 = local_108 + 1;
          }
          iVar2 = FUN_00471c32(1,local_8);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)[*(int *)(&DAT_006aba54 + local_8 * 0x120) * 0x34] & 1) != 0
             )) {
            local_110 = local_110 + 1;
          }
          local_8 = local_8 + 1;
        }
        if (local_110 < local_108) {
          CardTarget_HasValidPermanentTarget(0);
        }
        else if (local_108 < local_110) {
          CardTarget_HasValidPermanentTarget(1);
        }
        Ai_Subsystem_004cc9c5(0,0xff);
      } while (local_110 != local_108);
      do {
        if (DAT_006b300c < DAT_006b3008) {
          Prompts_Load_0046fa40(0,0,0);
        }
        if (DAT_006b3008 < DAT_006b300c) {
          Prompts_Load_0046fa40(1,0,0);
        }
      } while (DAT_006b3008 != DAT_006b300c);
      do {
        local_110 = 0;
        local_108 = 0;
        local_8 = 0;
        while( true ) {
          iVar2 = DAT_006808bc;
          if (DAT_006808bc <= g_PlayerActiveCardCount) {
            iVar2 = g_PlayerActiveCardCount;
          }
          if (iVar2 <= local_8) break;
          iVar2 = FUN_00471c32(0,local_8);
          if (((iVar2 != 0) &&
              (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + local_8 * 0x120) * 0x34] & 2
               ) != 0)) && ((&DAT_006a5f50)[local_8 * 0x120] != '\x03')) {
            local_108 = local_108 + 1;
          }
          iVar2 = FUN_00471c32(1,local_8);
          if (((iVar2 != 0) &&
              (((&g_MasterCardColorTable)[*(int *)(&DAT_006aba54 + local_8 * 0x120) * 0x34] & 2) !=
               0)) && ((&DAT_006a5f50)[local_8 * 0x120] != '\x03')) {
            local_110 = local_110 + 1;
          }
          local_8 = local_8 + 1;
        }
        strcpy(&g_OverworldGoldAmount,&DAT_0069f84a);
        if (local_110 < local_108) {
          iVar2 = CardTarget_HasValidCreatureTarget(0);
          Pic_Subsystem_0044867e(0,iVar2,3);
        }
        if (local_108 < local_110) {
          iVar2 = CardTarget_HasValidCreatureTarget(1);
          Pic_Subsystem_0044867e(1,iVar2,3);
        }
        Ai_Subsystem_004cc9c5(0,0xff);
      } while (local_110 != local_108);
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


