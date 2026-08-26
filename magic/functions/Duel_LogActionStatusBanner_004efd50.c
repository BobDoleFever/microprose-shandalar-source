/*
 * Decompiled function: Duel_LogActionStatusBanner
 * Entry Point: 004efd50
 * Size: 1932 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Duel_LogActionStatusBanner
              (int spell_id,int target_id,int flags,uint arg_4,uint arg_5,char *str_6,
              undefined4 arg_7)

{
  int arg2;
  int iVar1;
  uint uVar2;
  uint local_210;
  int aiStack_200 [60];
  int local_110;
  int local_10c;
  int local_108;
  uint local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int aiStack_f4 [60];
  
  if ((g_ActivePlayer == 1) || ((g_IsAiThinking == 1 && (spell_id == g_CurrentTurnPhase)))) {
    local_108 = -1;
  }
  else {
    if (((byte)DAT_00680790 & 1) != 0) {
      flags = target_id;
    }
    if (((spell_id == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) {
      if ((arg_4 != 0) && (arg_4 != 0xff)) {
        g_OverworldWorldState = 0;
        local_104 = FUN_00474d4a();
        if (local_104 != 0xffffffff) {
          iVar1 = *(int *)(&DAT_006fecb8 + DAT_006a3f78 * 8);
          arg2 = *(int *)(&DAT_006fecbc + DAT_006a3f78 * 8);
          uVar2 = local_104 >> 0x10 & 0xff;
          if (uVar2 == 0x71) {
            strcpy(&g_OverworldWorldState,s_CASTING__0052ffc8);
            Ai_Subsystem_004b90de(iVar1,arg2);
          }
          if (uVar2 == 0x72) {
            strcpy(&g_OverworldWorldState,s_ACTIVATING__0052ffd4);
            Ai_Subsystem_004b90de(iVar1,arg2);
          }
          if (uVar2 == 0x7e) {
            strcpy(&g_OverworldWorldState,s_PROCESSING__0052ffe4);
            Ai_Subsystem_004b90de(iVar1,arg2);
          }
        }
        strcat(&g_OverworldWorldState,&DAT_0052fff4);
      }
      DAT_00627a88 = 0xffffffff;
      if (((arg_4 == 0) || (arg_4 == 0xff)) || (arg_4 == 0xfffffffe)) {
        local_210 = 0xffffffff;
      }
      else {
        local_210 = arg_4;
      }
      Ai_Subsystem_004af765
                (target_id,str_6,arg_7,local_210,arg_5,0xffffffff,0xffffffff,&DAT_0063ee8c,
                 &local_10c,0,0);
      if (local_10c != -1) {
        DAT_00633434 = 0;
      }
      strcpy(&g_OverworldGoldAmount,&DAT_0052fff8);
      _DAT_0063ee20 = local_10c;
    }
    else {
      local_110 = 0;
      for (local_fc = 0; local_fc < 2; local_fc = local_fc + 1) {
        if ((flags == -1) || (local_fc == flags)) {
          for (local_100 = 0; local_100 < (int)(&g_PlayerActiveCardCount)[local_fc];
              local_100 = local_100 + 1) {
            if (((((arg_4 != 0xfffffffe) &&
                  (*(int *)(&g_CardSlot_CardId + local_100 * 0x120 + local_fc * 0x5b20) != -1)) &&
                 ((((&g_CardSlot_Flags)[local_100 * 0x120 + local_fc * 0x5b20] & 2) != 0 ||
                  ((spell_id == g_CurrentTurnPhase && (DAT_006fedc0 != 0)))))) &&
                (((int)arg_4 < 1 ||
                 ((arg_4 & (byte)(&g_MasterCardColorTable)
                                 [*(int *)(&g_CardSlot_CardId +
                                          local_100 * 0x120 + local_fc * 0x5b20) * 0x34]) != 0))))
               && (((arg_5 == 1 || (arg_5 == 0)) ||
                   ((arg_5 & (int)(char)(&DAT_006a5f4c)[local_100 * 0x120 + local_fc * 0x5b20]) != 0
                   )))) {
              aiStack_f4[local_110] = local_fc;
              aiStack_200[local_110] = local_100;
              local_110 = local_110 + 1;
            }
          }
          if (((int)arg_4 < 1) && ((arg_5 == 1 || (arg_5 == 0)))) {
            aiStack_f4[local_110] = local_fc;
            aiStack_200[local_110] = -1;
            local_110 = local_110 + 1;
          }
        }
      }
      if (local_110 == 0) {
        local_108 = -1;
      }
      else if (spell_id == g_CurrentTurnPhase) {
        do {
          while( true ) {
            do {
              do {
                local_110 = FUN_0040a1d2(local_110);
                _DAT_0063ee20 = aiStack_f4[local_110];
                if (DAT_006fedc0 == 0) goto LAB_004f024d;
                DAT_0063ee8c = 0;
                iVar1 = FUN_0040a1d2(0x20);
                if ((iVar1 == 0) || (DAT_0063ee10 != 0)) {
                  DAT_00627a84 = 0xffffffff;
                  DAT_00627a88 = 0xffffffff;
                  DAT_0063ee8c = 0xfffffffe;
                  return -1;
                }
              } while (g_CurrentTurnPhase != _DAT_0063ee20);
              local_f8 = *(int *)(&g_CardSlot_CardId +
                                 _DAT_0063ee20 * 0x5b20 + aiStack_200[local_110] * 0x120);
            } while (((((&g_MasterCardColorTable)[local_f8 * 0x34] & 1) != 0) &&
                     (((&g_CardSlot_Flags)[_DAT_0063ee20 * 0x5b20 + aiStack_200[local_110] * 0x120]
                      & 2) != 0)) ||
                    ((((&g_MasterCardColorTable)[local_f8 * 0x34] & 2) != 0 &&
                     (((&g_CardSlot_Flags)[_DAT_0063ee20 * 0x5b20 + aiStack_200[local_110] * 0x120]
                      & 4) != 0))));
            if ((g_ScWillyScore < 0x15) || (0x1d < g_ScWillyScore)) break;
            if ((((&g_MasterCardColorTable)[local_f8 * 0x34] & 2) != 0) &&
               (((&g_CardSlot_Flags)[_DAT_0063ee20 * 0x5b20 + aiStack_200[local_110] * 0x120] & 2)
                != 0)) goto LAB_004f024d;
          }
        } while ((((&g_MasterCardColorTable)[local_f8 * 0x34] & 0x4b) == 0) ||
                (((&g_CardSlot_Flags)[_DAT_0063ee20 * 0x5b20 + aiStack_200[local_110] * 0x120] & 2)
                 != 0));
LAB_004f024d:
        local_108 = aiStack_200[local_110];
      }
      else {
        if (g_IsAiThinking == 1) {
          g_AiDecisionScore = FUN_0040a1d2(local_110);
          DAT_006fefa8 = CONCAT31((int3)((aiStack_f4[g_AiDecisionScore] == 0) - 1 >> 8),
                                  (char)aiStack_200[g_AiDecisionScore]) & 0x1ff | 0x4000;
          Ai_EvaluateCreaturePower();
        }
        else {
          Ai_CalcCardAdvantage();
          if (g_AiDecisionScore == 99) {
            g_AiDecisionScore = FUN_0040a1d2(local_110);
          }
        }
        _DAT_0063ee20 = aiStack_f4[g_AiDecisionScore];
        local_108 = aiStack_200[g_AiDecisionScore];
      }
    }
  }
  return local_108;
}


