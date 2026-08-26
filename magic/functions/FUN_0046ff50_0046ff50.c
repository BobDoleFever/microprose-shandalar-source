/*
 * Decompiled function: FUN_0046ff50
 * Entry Point: 0046ff50
 * Size: 2993 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0046ff50(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *str_2;
  undefined4 uVar6;
  int local_18;
  
  iVar5 = *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120);
  iVar3 = FUN_00473cc5((&DAT_0051aebe)[iVar5 * 0x34]);
  iVar2 = DAT_006b2d3c;
  iVar1 = DAT_006b2d2c;
  iVar4 = DAT_0068a708;
  if (arg_3 == 0) {
    iVar4 = FUN_00470ea3(arg_1,arg_1,arg_2);
    if (iVar4 == 0) {
      return 0;
    }
    DAT_006fefa8 = 0xffffffff;
    DAT_006fe3f4 = 0;
    g_OverworldPlayerCoordY = -1;
    if ((((&g_MasterCardColorTable)[iVar5 * 0x34] & 0x3c) != 0) &&
       (iVar4 = Magic_TriggerCardEvent(arg_1,arg_2,0x74,1 - arg_1,0xffffffff), iVar4 == 0)) {
      return 0;
    }
    iVar2 = DAT_006b2d3c;
    iVar1 = DAT_006b2d2c;
    iVar4 = DAT_0068a708;
    g_ActivePlayer = -1;
    DAT_006b2d3c = arg_1;
    DAT_006b2d2c = arg_2;
    DAT_0068a708 = iVar5;
    Magic_CombatPhase(arg_1,arg_2,0x71,arg_1,0);
    Ai_Subsystem_004bd4f0();
    if (DAT_006fe3f4 == 0) {
      if ((g_CurrentTurnPhase == arg_1) && (g_IsAiThinking != 1)) {
        if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 0x40) == 0) {
          (&DAT_006b2d40)[iVar3] = (int)(char)(&DAT_0051aebf)[iVar5 * 0x34];
          DAT_006b2d40 = DAT_006b2d40 + (char)(&DAT_0051aec0)[iVar5 * 0x34];
        }
        else {
          DAT_006b2d58 = (int)(char)(&DAT_0051aebf)[iVar5 * 0x34] +
                         (int)(char)(&DAT_0051aec0)[iVar5 * 0x34];
        }
        Ai_Subsystem_004be192(arg_1,arg_2,0,0);
      }
      else if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 0x40) == 0) {
        if ((&DAT_0051aebf)[iVar5 * 0x34] != '\0') {
          (&DAT_006b2d40)[iVar3] = (int)(char)(&DAT_0051aebf)[iVar5 * 0x34];
        }
        if ('\0' < (char)(&DAT_0051aec0)[iVar5 * 0x34]) {
          DAT_006b2d40 = (int)(char)(&DAT_0051aec0)[iVar5 * 0x34];
        }
        Ai_Subsystem_004be192(arg_1,arg_2,0,0);
        if ((&DAT_0051aec0)[iVar5 * 0x34] == -1) {
          if (g_CurrentTurnPhase == arg_1) {
            g_OverworldPlayerCoordY = FUN_0040d949(arg_1,7,1);
            Ai_CalcManaRequirement_004ba890(arg_1,0,-1);
          }
          else {
            if (g_IsAiThinking == 1) {
              iVar3 = FUN_0040a1d2(2);
              if (iVar3 == 0) {
                iVar3 = FUN_0040d949(arg_1,7,1);
                if (iVar3 == 0) {
                  iVar3 = FUN_0040d949(arg_1,7,1);
                  g_AiDecisionScore = FUN_0040a1d2(iVar3 + 1);
                  local_18 = g_AiDecisionScore;
                }
                else {
                  iVar3 = FUN_0040a1d2(iVar3);
                  g_AiDecisionScore = iVar3 + 1;
                  local_18 = g_AiDecisionScore;
                }
              }
              else if (iVar3 == 1) {
                local_18 = FUN_0040d949(arg_1,7,1);
                g_AiDecisionScore = local_18;
                if ((g_PlayerCreatureCount < local_18) && (iVar3 = FUN_0040a1d2(3), iVar3 == 0)) {
                  local_18 = g_PlayerCreatureCount;
                  g_AiDecisionScore = g_PlayerCreatureCount;
                }
                if ((g_OverworldPlayerCoordY != -1) && (g_OverworldPlayerCoordY < g_AiDecisionScore)
                   ) {
                  local_18 = g_OverworldPlayerCoordY;
                  g_AiDecisionScore = g_OverworldPlayerCoordY;
                }
              }
              Ai_EvaluateCreaturePower();
            }
            else {
              Ai_CalcCardAdvantage();
              local_18 = g_AiDecisionScore;
            }
            g_OverworldPlayerCoordY = local_18;
            Ai_CalcManaRequirement_004ba890(arg_1,0,-1);
          }
          if (g_TurnCounter == 0) {
            g_SpellStackDepth = g_SpellStackDepth + -100;
          }
        }
      }
      else {
        Ai_Subsystem_004be192
                  (arg_1,arg_2,6,
                   (int)(char)(&DAT_0051aebf)[iVar5 * 0x34] +
                   (int)(char)(&DAT_0051aec0)[iVar5 * 0x34]);
      }
    }
    g_OverworldPlayerCoordY = -1;
    if (iVar5 != -1) {
      DAT_0068a650 = arg_1;
      _DAT_006a3f70 = 1;
      (&DAT_006b3008)[arg_1] = (&DAT_006b3008)[arg_1] + -1;
      if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 2) != 0) {
        *(int *)(&DAT_006b3010 + arg_1 * 4) = *(int *)(&DAT_006b3010 + arg_1 * 4) + 1;
      }
      if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 0x40) != 0) {
        (&DAT_006b3018)[arg_1] = (&DAT_006b3018)[arg_1] + 1;
      }
      if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 4) != 0) {
        *(int *)(&DAT_006b3020 + arg_1 * 4) = *(int *)(&DAT_006b3020 + arg_1 * 4) + 1;
      }
      (&DAT_006a2828)[arg_1] =
           (&DAT_006a2828)[arg_1] | (uint)(byte)(&g_MasterCardColorTable)[iVar5 * 0x34];
      *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x20;
      g_PlayerHandCardCount = g_PlayerHandCardCount | 0x20;
      if ((g_CurrentTurnPhase == arg_1) || (g_IsAiThinking != 1)) {
        *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x30000;
      }
      else {
        *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10000;
      }
      DAT_0068a708 = iVar4;
      DAT_006b2d2c = iVar1;
      DAT_006b2d3c = iVar2;
      if (g_ActivePlayer == 1) {
        Ai_Util_004bd5af();
      }
      else {
        iVar4 = FUN_00473e69(arg_1,arg_2,0x6c);
        if (iVar4 != 0) {
          Engine_ReportFatalError(s_Illegal_cast_00525bcc);
          g_ActivePlayer = 1;
        }
        if (g_ActivePlayer == 1) {
          Ai_Subsystem_004bd5e3(arg_1);
        }
        Ai_Util_004bd5af();
        if (g_ActivePlayer != 1) {
          if (((g_IsAiThinking == 1) && (g_ActivePlayerPriority == arg_1)) &&
             ((&DAT_0051aec0)[iVar5 * 0x34] == -1)) {
            iVar5 = FUN_00473d98(arg_1);
            g_SpellStackDepth = g_SpellStackDepth + iVar5 * -0xc;
          }
          return 1;
        }
      }
    }
  }
  else {
    DAT_006b2d3c = arg_1;
    DAT_006b2d2c = arg_2;
    DAT_0068a708 = iVar5;
    if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 1) == 0) {
      Magic_MainTurnPhase(1);
    }
    if (((&g_MasterCardColorTable)[iVar5 * 0x34] != '\x01') &&
       (((&g_MasterCardColorTable)[iVar5 * 0x34] != ' ' ||
        (((&DAT_0051aed1)[iVar5 * 0x34] & 0x10) == 0)))) {
      strcpy(&g_OverworldWorldState,s_Trying_to_cast_00525bdc);
      Ai_Subsystem_004b90de(DAT_006b2d3c,DAT_006b2d2c);
      FUN_00475c8a(-2,g_ScWillyScore,&g_OverworldWorldState,0xd3);
    }
    if (*(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120) == -1) {
      g_ActivePlayer = 1;
    }
    g_PlayerHandCardCount = g_PlayerHandCardCount & 0xffffffdf;
    DAT_0068a708 = iVar4;
    DAT_006b2d2c = iVar1;
    DAT_006b2d3c = iVar2;
    *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) |
         CONCAT31((uint3)((arg_1 == 0) - 1 >> 8) & 0x4000,0x80);
    if (g_IsAiThinking != 1) {
      FUN_004755fd();
    }
    if (g_ActivePlayer != 1) {
      if (((g_CurrentTurnPhase != arg_1) && (g_IsAiThinking != 1)) &&
         (((&g_MasterCardColorTable)[iVar5 * 0x34] & 0x7e) != 0)) {
        strcpy(&g_OverworldWorldState,&DAT_00695e10);
        strcat(&g_OverworldWorldState,s_casts____00525bec);
        if ((&DAT_0051aec0)[iVar5 * 0x34] == -1) {
          strcat(&g_OverworldWorldState,s_X_is_00525bf8);
          str_2 = _itoa(g_TurnCounter,&DAT_00538df8,10);
          strcat(&g_OverworldWorldState,str_2);
          strcat(&g_OverworldWorldState,&DAT_00525c00);
        }
        if ((&g_CardSlot_TurnPlayed)[arg_1 * 0x5b20 + arg_2 * 0x120] == '\0') {
          Ai_Subsystem_004b574d(arg_1,arg_2,-1,-1,&g_OverworldWorldState,0);
        }
        else if ((&g_CardSlot_TurnPlayed)[arg_1 * 0x5b20 + arg_2 * 0x120] == '\x01') {
          Ai_Subsystem_004b574d
                    (arg_1,arg_2,*(int *)(&g_CardSlot_CombatTarget + arg_1 * 0x5b20 + arg_2 * 0x120)
                     ,*(int *)(&g_CardSlot_AttachedAura + arg_1 * 0x5b20 + arg_2 * 0x120),
                     &g_OverworldWorldState,0);
        }
        else {
          Ai_Subsystem_004b574d(arg_1,arg_2,-1,-1,&g_OverworldWorldState,0);
        }
        DAT_00627a84 = g_DefendingPlayer;
        DAT_00627a88 = g_ScWillyScore;
      }
      if (g_IsAiThinking != 1) {
        Ai_Subsystem_004cc3f8(arg_1,arg_2,2,1);
      }
    }
  }
  if (g_ActivePlayer == 1) {
    (&DAT_006b3008)[arg_1] = (&DAT_006b3008)[arg_1] + 1;
    if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 2) != 0) {
      *(int *)(&DAT_006b3010 + arg_1 * 4) = *(int *)(&DAT_006b3010 + arg_1 * 4) + -1;
    }
    if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 0x40) != 0) {
      (&DAT_006b3018)[arg_1] = (&DAT_006b3018)[arg_1] + -1;
    }
    if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 4) != 0) {
      *(int *)(&DAT_006b3020 + arg_1 * 4) = *(int *)(&DAT_006b3020 + arg_1 * 4) + -1;
    }
    *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xffffff5d;
    *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xfffcffff;
    if (g_CurrentTurnPhase != arg_1) {
      DAT_00701008 = 1;
    }
    g_ActivePlayer = 0;
    Magic_DiscardToHandSize();
    g_PlayerHandCardCount = g_PlayerHandCardCount & 0xffffffdf;
    uVar6 = 0;
  }
  else {
    FUN_00476482(arg_1,arg_2);
    uVar6 = 1;
  }
  return uVar6;
}


