/*
 * Decompiled function: Ai_CalcManaRequirement_004ba890
 * Entry Point: 004ba890
 * Size: 4252 bytes
 */
#include "magic.h"


/* WARNING: Heritage AFTER dead removal. Example location: r0x006b2d58 : 0x004bb0c4 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int Ai_CalcManaRequirement_004ba890(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_d8;
  int aiStack_d4 [8];
  int local_b4;
  int aiStack_b0 [8];
  int local_90;
  int local_8c;
  int local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  int local_74;
  int local_70;
  uint local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50 [7];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((g_PlayerHandCardCount._1_1_ & 4) == 0) {
    (&DAT_006b2d40)[arg_2] = (&DAT_006b2d40)[arg_2] + arg_3;
    local_10 = 0;
    for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
      local_50[local_1c] = 0;
    }
    iVar1 = FUN_0040d949(arg_1,6,1);
    local_24 = FUN_0040d949(arg_1,7,1);
    local_24 = iVar1 - local_24;
    local_8 = 1;
    if ((((DAT_00627864 == 0) && (arg_1 != 1)) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) {
      local_c = 0;
      local_28 = 0;
      local_2c = 0;
      local_34 = 0;
      local_54 = 0;
    }
    else {
      local_54 = 1;
      local_34 = 1;
      local_2c = 1;
      if (((arg_1 == 1) || (g_IsAiThinking == 1)) || (DAT_006fedc0 != 0)) {
        local_28 = 1;
        local_c = 1;
      }
      else {
        local_c = 0;
        local_28 = 0;
      }
    }
    iVar1 = g_OverworldPlayerCoordY;
    if (arg_1 == g_ActivePlayerPriority) {
      for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
        if ((&DAT_006b2d40)[local_1c] == -1) {
          local_64 = FUN_0040d949(arg_1,local_1c,1);
          if (g_IsAiThinking == 1) {
            iVar1 = FUN_0040a1d2(3);
            if ((iVar1 == 0) || (local_64 < 2)) {
              local_60 = local_64;
            }
            else {
              local_60 = FUN_0040a1d2(local_64 + -1);
              local_60 = local_60 + 1;
            }
            g_AiDecisionScore = local_60;
            Ai_EvaluateCreaturePower();
          }
          else {
            Ai_CalcCardAdvantage();
            if (g_AiDecisionScore == 99) {
              g_AiDecisionScore = 0;
            }
            local_60 = g_AiDecisionScore;
          }
        }
      }
      if (g_OverworldPlayerCoordY == -1) {
        g_OverworldPlayerCoordY = local_60;
        iVar1 = g_OverworldPlayerCoordY;
      }
      else {
        iVar1 = local_60;
        if (g_OverworldPlayerCoordY <= local_60) {
          iVar1 = g_OverworldPlayerCoordY;
        }
      }
    }
    g_OverworldPlayerCoordY = iVar1;
    g_TurnCounter = 0;
    if (g_OverworldPlayerCoordY == 0) {
      for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
        if ((&DAT_006b2d40)[local_1c] == -1) {
          (&DAT_006b2d40)[local_1c] = 0;
        }
      }
    }
    local_58 = 0;
    for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
      if ((&DAT_006b2d40)[local_1c] == -1) {
        local_58 = 1;
      }
    }
    if ((local_8 != 0) &&
       (iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY), iVar1 == 0))
    {
      Ai_Subsystem_004bb9f3(arg_1,local_50,&local_10,local_24);
      Ai_Subsystem_004b584e();
    }
    if (((local_54 != 0) &&
        (iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY), iVar1 == 0))
       && (local_58 != 0)) {
      Ai_Subsystem_004bbb99
                (arg_1,local_50,&local_10,local_24,&g_TurnCounter,g_OverworldPlayerCoordY);
      Ai_Subsystem_004b584e();
    }
    if ((local_34 != 0) &&
       (iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY), iVar1 == 0))
    {
      Ai_Subsystem_004bbd93
                (arg_1,local_50,&local_10,local_24,&g_TurnCounter,g_OverworldPlayerCoordY);
      Ai_Subsystem_004b584e();
    }
    if ((local_2c != 0) &&
       (iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY), iVar1 == 0))
    {
      iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (iVar1 == 0) {
        Ai_Subsystem_004bc72e(arg_1,local_50,&local_10,0x1e,local_c);
      }
      iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (iVar1 == 0) {
        Ai_Subsystem_004bc72e(arg_1,local_50,&local_10,0x1c,local_c);
      }
    }
    if ((local_28 != 0) &&
       (iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY), iVar1 == 0))
    {
      iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (iVar1 == 0) {
        Ai_Subsystem_004bc72e(arg_1,local_50,&local_10,0x14,local_c);
      }
      iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (iVar1 == 0) {
        Ai_Subsystem_004bc72e(arg_1,local_50,&local_10,4,local_c);
      }
      iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (iVar1 == 0) {
        Ai_Subsystem_004bc72e(arg_1,local_50,&local_10,0x1a,local_c);
      }
      iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (iVar1 == 0) {
        Ai_Subsystem_004bc72e(arg_1,local_50,&local_10,0x18,local_c);
      }
      iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (iVar1 == 0) {
        Ai_Subsystem_004bc72e(arg_1,local_50,&local_10,0x10,local_c);
      }
      iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (iVar1 == 0) {
        Ai_Subsystem_004bc72e(arg_1,local_50,&local_10,0,local_c);
      }
    }
    if (((arg_1 == 1) || (g_IsAiThinking == 1)) || (DAT_006fedc0 != 0)) {
      iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if ((iVar1 == 0) && (local_58 == 0)) {
        g_ActivePlayer = 1;
      }
    }
    else {
      iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (iVar1 == 0) {
        local_5c = 0;
        while ((local_5c == 0 &&
               (iVar1 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY),
               iVar1 == 0))) {
          local_68 = 1;
          for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
            if (0 < (&DAT_006b2d40)[local_1c]) {
              local_68 = 0;
            }
          }
          Ai_Subsystem_004bc029
                    (&g_OverworldWorldState,&DAT_006b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
          local_30 = Duel_LogActionStatusBanner
                               (arg_1,arg_1,arg_1,0,0,&g_OverworldWorldState,
                                (-(uint)(local_68 == 0) & 0xfffffffe) + 3);
          if ((_DAT_0063ee20 == -1) && ((local_30 == -1 || (local_30 == -2)))) {
            if (DAT_0063ee8c == -2) {
              if ((DAT_00627a84 == -1) && (DAT_00627a88 == -1)) {
                if (local_30 == -1) {
                  g_ActivePlayer = 1;
                }
                local_5c = 1;
              }
              else if (local_68 != 0) {
                local_5c = 1;
              }
            }
            else if (((DAT_0063ee8c == -3) && (DAT_00627858 == arg_1)) &&
                    (DAT_00633430 != 0xffffffff)) {
              if ((0 < *(int *)(&DAT_0063ee90 + DAT_00633430 * 4 + arg_1 * 0x20)) &&
                 (((((&DAT_006b2d40)[DAT_00633430] != 0 || (DAT_006b2d40 != 0)) ||
                   (DAT_006b2d58 != 0)) && ((DAT_00633430 != 6 || (DAT_006b2d58 != 0)))))) {
                if ((&DAT_006b2d40)[DAT_00633430] == 0) {
                  if (DAT_006b2d58 == 0) {
                    local_6c = 0;
                  }
                  else {
                    local_6c = 6;
                  }
                }
                else {
                  local_6c = DAT_00633430;
                }
                local_70 = Ai_Subsystem_004bd459
                                     (0x6b2d40,local_6c,(int)(&DAT_0063ee90 + arg_1 * 0x20),
                                      DAT_00633430,DAT_00627864,g_OverworldPlayerCoordY,
                                      g_TurnCounter);
                Ai_Subsystem_004bd3e9
                          (0x6b2d40,local_6c,local_70,&g_TurnCounter,g_OverworldPlayerCoordY,arg_1,
                           DAT_00633430,(int)local_50,&local_10);
                Ai_Subsystem_004b584e();
              }
              if (0 < (&DAT_006b2d40)[DAT_00633430]) {
                local_78 = 0;
                local_20 = 0;
                while ((local_20 < 10 &&
                       (*(int *)(&DAT_00627a20 + local_20 * 4 + arg_1 * 0x2c) != -1))) {
                  local_80 = (uint)*(ushort *)(&DAT_00627a20 + local_20 * 4 + arg_1 * 0x2c);
                  iVar1 = local_20 * 4;
                  if (DAT_00633430 == local_80) {
                    local_84._0_1_ = (byte)(*(uint *)(&DAT_00627a20 + iVar1 + arg_1 * 0x2c) >> 0x10)
                    ;
                    local_78 = local_78 | 1 << ((byte)local_84 & 0x1f);
                  }
                  local_20 = local_20 + 1;
                  local_84 = *(uint *)(&DAT_00627a20 + iVar1 + arg_1 * 0x2c) >> 0x10;
                }
                local_7c = 0;
                for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
                  if ((&DAT_006b2d40)[local_1c] != 0) {
                    local_7c = local_7c | 1 << ((byte)local_1c & 0x1f);
                  }
                }
                local_78 = local_78 & local_7c;
                if (local_78 != 0) {
                  local_74 = 0;
                  for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
                    if ((local_78 & 1 << ((byte)local_1c & 0x1f)) != 0) {
                      local_74 = local_74 + 1;
                    }
                  }
                  if (local_74 == 1) {
                    local_88 = FUN_00473cc5((byte)local_78);
                  }
                  else {
                    local_88 = Ai_Subsystem_004cc93d
                                         (arg_1,s_Which_color_to_use_that_choice_a_0052d5d0,1,
                                          DAT_00633430,local_78);
                  }
                  local_8c = Ai_Subsystem_004bd459
                                       (0x6b2d40,local_88,(int)(&DAT_0063ee90 + arg_1 * 0x20),
                                        DAT_00633430,DAT_00627864,g_OverworldPlayerCoordY,
                                        g_TurnCounter);
                  Ai_Subsystem_004bd3e9
                            (0x6b2d40,local_88,local_8c,&g_TurnCounter,g_OverworldPlayerCoordY,arg_1
                             ,DAT_00633430,(int)local_50,&local_10);
                  Ai_Subsystem_004b584e();
                }
              }
            }
          }
          else if ((((_DAT_0063ee20 == -1) || (local_30 != -1)) &&
                   (local_14 = *(int *)(&g_CardSlot_CardId + local_30 * 0x120 + arg_1 * 0x5b20),
                   ((&DAT_0051aed1)[local_14 * 0x34] & 0x10) != 0)) &&
                  ((((&g_MasterCardColorTable)[local_14 * 0x34] & 0x20) != 0 ||
                   (((((&g_CardSlot_Flags)[local_30 * 0x120 + arg_1 * 0x5b20] & 2) != 0 &&
                     (((&g_CardSlot_Flags)[local_30 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) &&
                    ((((&DAT_006a5f3e)[local_30 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
                     (((&g_MasterCardColorTable)
                       [*(int *)(&g_CardSlot_CardId + local_30 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2
                      ) == 0)))))))) {
            for (local_d8 = 0; local_d8 < 8; local_d8 = local_d8 + 1) {
              aiStack_d4[local_d8] = *(int *)(&DAT_0063ee90 + local_d8 * 4 + arg_1 * 0x20);
            }
            local_b4 = g_TurnCounter;
            g_TurnCounter = 0;
            local_90 = g_OverworldPlayerCoordY;
            g_OverworldPlayerCoordY = -1;
            for (local_d8 = 0; local_d8 < 7; local_d8 = local_d8 + 1) {
              aiStack_b0[local_d8] = (&DAT_006b2d40)[local_d8];
              (&DAT_006b2d40)[local_d8] = 0;
            }
            if (((&g_CardSlot_Flags)[local_30 * 0x120 + arg_1 * 0x5b20] & 2) == 0) {
              FUN_0046fe86(arg_1,local_30);
              Ai_Subsystem_004cc9c5(0,0xff);
            }
            else if ((((&g_MasterCardColorTable)[local_14 * 0x34] & 1) != 0) ||
                    (iVar1 = Magic_TriggerCardEvent(arg_1,local_30,0x73,1 - arg_1,0xffffffff),
                    iVar1 != 0)) {
              Magic_CombatPhase(arg_1,local_30,0x72,arg_1,0);
              DAT_006ff4ac = 1;
              DAT_006ff2d4 = 0xffffffff;
              local_18 = *(uint *)(&g_CardSlot_Flags + local_30 * 0x120 + arg_1 * 0x5b20) & 0x10;
              Magic_TriggerCardEvent(arg_1,local_30,0x6d,1 - arg_1,0xffffffff);
              DAT_006ff4ac = 0;
              if (g_ActivePlayer == 1) {
                g_ActivePlayer = 0;
                Magic_DiscardToHandSize();
              }
              else {
                if ((local_18 == 0) &&
                   (((&g_CardSlot_Flags)[local_30 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
                  FUN_00473e69(arg_1,local_30,0x81);
                }
                if (g_IsAiThinking != 1) {
                  Magic_UpkeepPhase(0x12);
                }
                Magic_EndTurnPhase();
                Ai_Subsystem_004cc9c5(0,0xff);
              }
            }
            g_TurnCounter = local_b4;
            g_OverworldPlayerCoordY = local_90;
            for (local_d8 = 0; local_d8 < 7; local_d8 = local_d8 + 1) {
              (&DAT_006b2d40)[local_d8] = aiStack_b0[local_d8];
            }
            for (local_d8 = 0; local_d8 < 8; local_d8 = local_d8 + 1) {
              *(int *)(&DAT_0063ee90 + local_d8 * 4 + arg_1 * 0x20) =
                   *(int *)(&DAT_0063ee90 + local_d8 * 4 + arg_1 * 0x20) - aiStack_d4[local_d8];
            }
            iVar1 = FUN_0040d949(arg_1,6,1);
            local_24 = FUN_0040d949(arg_1,7,1);
            local_24 = iVar1 - local_24;
            Ai_Subsystem_004bb9f3(arg_1,local_50,&local_10,local_24);
            Ai_Subsystem_004bbb99
                      (arg_1,local_50,&local_10,local_24,&g_TurnCounter,g_OverworldPlayerCoordY);
            Ai_Subsystem_004bbd93
                      (arg_1,local_50,&local_10,local_24,&g_TurnCounter,g_OverworldPlayerCoordY);
            for (local_d8 = 0; local_d8 < 8; local_d8 = local_d8 + 1) {
              *(int *)(&DAT_0063ee90 + local_d8 * 4 + arg_1 * 0x20) =
                   *(int *)(&DAT_0063ee90 + local_d8 * 4 + arg_1 * 0x20) + aiStack_d4[local_d8];
            }
            Ai_Subsystem_004b584e();
          }
        }
      }
    }
  }
  if (g_ActivePlayer == 1) {
    Ai_Subsystem_004bd682((int)local_50);
    for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
      FUN_0040d875(arg_1,local_1c,local_50[local_1c]);
      local_50[local_1c] = 0;
    }
    local_10 = 0;
    g_TurnCounter = 0;
  }
  for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
    (&DAT_006b2d40)[local_1c] = 0;
  }
  g_OverworldPlayerCoordY = -1;
  return local_10;
}


