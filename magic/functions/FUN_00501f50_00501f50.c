/*
 * Decompiled function: FUN_00501f50
 * Entry Point: 00501f50
 * Size: 15607 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00501f50(uint arg_1)

{
  int iVar1;
  uint uVar2;
  uint local_7d0;
  char local_7c8 [100];
  int local_764;
  int local_760;
  int local_75c;
  int local_758 [80];
  int local_618;
  int local_614;
  int local_610;
  int local_60c [100];
  int local_47c [100];
  int local_2ec;
  int local_2e8;
  int local_2e4;
  int local_2e0;
  int local_2dc;
  int local_2d8;
  int local_2d4;
  int local_2d0;
  int local_2cc;
  int local_2c8;
  int local_2c4;
  int local_2c0;
  short local_2bc;
  int local_2b8;
  int local_2b4;
  int local_2b0;
  int local_2ac;
  undefined4 local_2a8;
  int local_2a4;
  int local_2a0;
  int local_29c;
  short asStack_298 [160];
  int local_158;
  int local_154;
  int local_150;
  undefined4 auStack_14c [16];
  uint local_10c;
  char local_108 [256];
  int local_8;
  
  local_2b8 = 1 - arg_1;
  g_DefendingPlayer = arg_1;
  DAT_006808a8 = -1;
  if (arg_1 == g_CurrentTurnPhase) {
    DAT_00680788 = DAT_00680788 + 1;
  }
  for (local_2ac = 0; local_2ac < 0x50; local_2ac = local_2ac + 1) {
    (&DAT_00700ec1)[local_2ac * 2 + local_2b8 * 0xa0] = 0;
    (&DAT_00700ec0)[local_2ac * 2 + local_2b8 * 0xa0] =
         (&DAT_00700ec1)[local_2ac * 2 + local_2b8 * 0xa0];
    (&DAT_00700ec1)[local_2ac * 2 + arg_1 * 0xa0] =
         (&DAT_00700ec0)[local_2ac * 2 + local_2b8 * 0xa0];
    (&DAT_00700ec0)[local_2ac * 2 + arg_1 * 0xa0] = (&DAT_00700ec1)[local_2ac * 2 + arg_1 * 0xa0];
  }
  Pic_Subsystem_00451a82();
  FUN_00476510();
  for (local_2ac = 0; local_2ac < 0x26; local_2ac = local_2ac + 1) {
    *(uint *)(&DAT_00696740 + local_2ac * 4) = *(uint *)(&DAT_00696740 + local_2ac * 4) & 1;
    *(uint *)(&DAT_006967d8 + local_2ac * 4) = *(uint *)(&DAT_006967d8 + local_2ac * 4) & 1;
  }
  FUN_0040a1ff();
  FUN_00472fae();
  Mem_AllocOrFree_00474d1e();
  Magic_UntapTurnPhase();
  if ((-1 < g_IsAiThinking) && (DAT_0068a648 == 0)) goto LAB_00502276;
  for (local_2a0 = 0; local_2a0 < 2; local_2a0 = local_2a0 + 1) {
    for (local_2ac = 0; local_2ac < 0x50; local_2ac = local_2ac + 1) {
      if (*(int *)(&g_CardSlot_CardId + local_2a0 * 0x5b20 + local_2ac * 0x120) != -1) {
        (&g_PlayerActiveCardCount)[local_2a0] = local_2ac;
      }
    }
  }
  Ai_Subsystem_004cc9c5(0,0xff);
  iVar1 = g_IsAiThinking;
  local_8 = g_IsAiThinking;
  g_IsAiThinking = 0;
  if ((iVar1 == -1) || (iVar1 == -2)) goto LAB_00502f23;
  if (iVar1 == -10) {
    DAT_00627a84 = g_DefendingPlayer;
    DAT_00627a88 = g_ScWillyScore;
    if (g_ScWillyScore == 0x22) {
      DAT_00627a88 = 0x20;
    }
    if (g_ScWillyScore == 0) goto LAB_00502276;
    if (g_ScWillyScore == 1) goto LAB_00502384;
    if (g_ScWillyScore == 4) goto LAB_00502be5;
    if (g_ScWillyScore != 10) {
      if (g_ScWillyScore == 0x14) goto LAB_00502f23;
      if (g_ScWillyScore == 0x1f) goto LAB_00504ca9;
      if (g_ScWillyScore == 0x22) goto LAB_00505053;
      goto LAB_00502276;
    }
  }
  else {
LAB_00502276:
    if (g_IsAiThinking != 1) {
      Pic_Subsystem_0044edf5(0);
    }
    if ((g_PlayerHandCardCount & 0x8000) != 0) {
      g_PlayerHandCardCount = g_PlayerHandCardCount & 0xffff7fff;
      Magic_ScanCards(0x22);
      return;
    }
    Ai_ResetEvaluationState();
    g_ScWillyScore = 0;
    Magic_CheckTurnTriggers(arg_1,0);
    Magic_ScanCards(0x6a);
    if ((g_PlayerHandCardCount & 0x8000) != 0) {
      g_PlayerHandCardCount = g_PlayerHandCardCount & 0xffff7fff;
      Magic_ScanCards(0x22);
      return;
    }
    DAT_0069f700 = '\0';
    DAT_006a5f20 = 0;
    g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffffe00;
    Ai_Subsystem_004cc9c5(0,0xff);
    for (local_2ac = 0; local_2ac < (&g_PlayerActiveCardCount)[arg_1]; local_2ac = local_2ac + 1) {
      *(uint *)(&g_CardSlot_Flags + local_2ac * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + local_2ac * 0x120 + arg_1 * 0x5b20) & 0xfffc7bf3;
    }
LAB_00502384:
    local_2c0 = Ai_Subsystem_004cbcd9(0xe9);
    if ((local_2c0 == -1) ||
       (iVar1 = FUN_00403250((int *)0x0,0,arg_1,2,2,0x200,0,0,0,0,0,0,local_2c0,0xffffffff,
                             0xffffffff,0xffffffff,0,0,0), iVar1 == 0)) {
      g_ScWillyScore = 1;
      Magic_CheckTurnTriggers(arg_1,1);
      DAT_007006d0 = 0;
      DAT_0063ee1c = 0;
      DAT_00627860 = 1;
      Ai_Util_004cb2d0(arg_1);
      _DAT_006ff198 = 0;
      for (local_2ec = 0; local_2ec < (&g_PlayerActiveCardCount)[arg_1]; local_2ec = local_2ec + 1)
      {
        iVar1 = FUN_00471c32(arg_1,local_2ec);
        if ((iVar1 != 0) && (((&g_CardSlot_Flags)[local_2ec * 0x120 + arg_1 * 0x5b20] & 0x10) != 0))
        {
          *(undefined4 *)(&DAT_006a6038 + local_2ec * 0x120 + arg_1 * 0x5b20) = 3;
          FUN_00473e69(arg_1,local_2ec,0x82);
        }
      }
      local_2e0 = 0;
      while (local_2e0 == 0) {
        local_614 = 0;
        local_2e8 = 0;
        for (local_2e4 = 0; local_2e4 < 2; local_2e4 = local_2e4 + 1) {
          for (local_2ec = 0; local_2ec < (&g_PlayerActiveCardCount)[local_2e4];
              local_2ec = local_2ec + 1) {
            if (((&g_CardSlot_Flags)[local_2ec * 0x120 + local_2e4 * 0x5b20] & 2) != 0) {
              g_OverworldPlayerCoordX = local_2e4;
              g_OverworldMapGrid = local_2ec;
              g_ActivePalette = 0;
              Magic_ScanCards(0x7d);
              local_610 = g_ActivePalette;
              if (g_ActivePalette == 1) {
                local_47c[local_614 * 2] = local_2e4;
                local_47c[local_614 * 2 + 1] = local_2ec;
                local_614 = local_614 + 1;
              }
              else if (g_ActivePalette == 2) {
                local_60c[local_2e8 * 2] = local_2e4;
                local_60c[local_2e8 * 2 + 1] = local_2ec;
                local_2e8 = local_2e8 + 1;
              }
            }
          }
        }
        if (((arg_1 == 1) || (g_IsAiThinking == 1)) || (DAT_006fedc0 != 0)) {
          local_2e0 = 1;
          if (((arg_1 == 1) && (g_IsAiThinking != 1)) && (iVar1 = FUN_00505d20(1), iVar1 != 0)) {
            local_2e0 = 0;
          }
        }
        else if (((local_2e8 == 0) || (local_2e8 == 1)) &&
                ((local_614 == 0 && (iVar1 = FUN_00505d20(1), iVar1 == 0)))) {
          local_2e0 = 1;
        }
        if (local_2e0 == 0) {
          Mem_AllocOrFree_00475c61();
          if ((((arg_1 == 0) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) &&
             ((0 < local_2e8 || (0 < local_614)))) {
            strcpy(&g_OverworldWorldState,s_Untap_effects__00531114);
            local_2dc = Duel_LogActionStatusBanner(0,-1,0,0xff,0,&g_OverworldWorldState,2);
          }
          else {
            strcpy(&g_OverworldWorldState,s_Paused__Untap_phase_00531124);
            local_2dc = Duel_LogActionStatusBanner
                                  (g_CurrentTurnPhase,g_CurrentTurnPhase,g_CurrentTurnPhase,0xff,0,
                                   &g_OverworldWorldState,2);
            DAT_007006d0 = 1;
          }
          if (DAT_0063ee8c != -3) {
            if (DAT_0063ee8c == -2) {
              local_2e0 = 1;
            }
            else if ((DAT_0063ee8c == 0) && (local_2dc != -1)) {
              iVar1 = FUN_0050638d((int)local_60c,local_2e8,_DAT_0063ee20,local_2dc);
              if ((iVar1 == 0) &&
                 (iVar1 = FUN_0050638d((int)local_47c,local_614,_DAT_0063ee20,local_2dc), iVar1 == 0
                 )) {
                iVar1 = FUN_005063f6(_DAT_0063ee20,local_2dc);
                if (iVar1 != 0) {
                  FUN_005064e9(_DAT_0063ee20,local_2dc);
                }
              }
              else {
                g_OverworldPlayerCoordX = _DAT_0063ee20;
                g_OverworldMapGrid = local_2dc;
                Magic_ScanCards(0x7e);
              }
            }
          }
        }
      }
      if (local_2e8 != 0) {
        local_2e0 = 0;
        while (local_2e0 == 0) {
          local_2e8 = 0;
          local_2e4 = 0;
          while ((local_2e4 < 2 && (local_2e8 == 0))) {
            local_2ec = 0;
            while ((local_2ec < (&g_PlayerActiveCardCount)[local_2e4] && (local_2e8 == 0))) {
              if (((&g_CardSlot_Flags)[local_2ec * 0x120 + local_2e4 * 0x5b20] & 2) != 0) {
                g_OverworldPlayerCoordX = local_2e4;
                g_OverworldMapGrid = local_2ec;
                g_ActivePalette = 0;
                Magic_ScanCards(0x7d);
                local_610 = g_ActivePalette;
                if (g_ActivePalette == 2) {
                  local_60c[local_2e8 * 2] = local_2e4;
                  local_60c[local_2e8 * 2 + 1] = local_2ec;
                  local_2e8 = local_2e8 + 1;
                }
              }
              local_2ec = local_2ec + 1;
            }
            local_2e4 = local_2e4 + 1;
          }
          if (local_2e8 == 0) {
            local_2e0 = 1;
          }
          else {
            g_OverworldPlayerCoordX = local_60c[0];
            g_OverworldMapGrid = local_60c[1];
            Magic_ScanCards(0x7e);
          }
        }
      }
      for (local_2ec = 0; local_2ec < (&g_PlayerActiveCardCount)[arg_1]; local_2ec = local_2ec + 1)
      {
        if ((((&DAT_006a6038)[local_2ec * 0x120 + arg_1 * 0x5b20] & 1) != 0) &&
           (((&DAT_006a6038)[local_2ec * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
          *(uint *)(&g_CardSlot_Flags + local_2ec * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + local_2ec * 0x120 + arg_1 * 0x5b20) & 0xffffffef;
          Magic_TriggerCardEvent(arg_1,local_2ec,0x83,1 - arg_1,0xffffffff);
        }
      }
      for (local_2ec = 0; local_2ec < (&g_PlayerActiveCardCount)[arg_1]; local_2ec = local_2ec + 1)
      {
        iVar1 = FUN_00471c32(arg_1,local_2ec);
        if (iVar1 != 0) {
          *(undefined4 *)(&DAT_006a6038 + local_2ec * 0x120 + arg_1 * 0x5b20) = 0;
        }
      }
      Ai_Subsystem_004cc9c5(0,0xff);
      local_150 = DAT_007006d0;
      if (DAT_007006d0 == 0) {
        FUN_00505ea7(1);
      }
      FUN_00506102();
      iVar1 = FUN_005062b1();
      if (iVar1 != 0) {
        return;
      }
    }
LAB_00502be5:
    DAT_006ff550 = 0;
    DAT_007006d0 = 0;
    DAT_00627860 = 0;
    if ((DAT_00627a88 == -1) || ((DAT_00627a88 == 4 && (arg_1 == DAT_00627a84)))) {
      DAT_0063ee1c = 0;
    }
    else {
      DAT_0063ee1c = 1;
    }
    g_ScWillyScore = 2;
    Magic_CheckTurnTriggers(arg_1,2);
    FUN_0047624f(arg_1,0xc9,s_Begin_Upkeep_00531138,0);
    DAT_00627860 = 1;
    g_ScWillyScore = 4;
    FUN_00476a80();
    FUN_00475c8a(-1,g_ScWillyScore,s_Upkeep_Phase_00531148,4);
    DAT_00627860 = 0;
    FUN_0047624f(arg_1,0xcb,s_End_Upkeep_00531158,0);
    DAT_0063ee1c = 0;
    DAT_0068a67c = 1;
    Pic_Subsystem_004475a4(arg_1);
    DAT_0068a67c = 0;
    DAT_006ff550 = 0;
    FUN_00506102();
    iVar1 = FUN_005062b1();
    if (iVar1 != 0) {
      return;
    }
  }
  if ((DAT_006a4b58 == 0) || (DAT_006a4b58 = 0, DAT_006a2858 == 0)) {
    g_ScWillyScore = 10;
    Magic_CheckTurnTriggers(arg_1,10);
    DAT_007006d0 = 0;
    DAT_00627860 = 0;
    if ((DAT_00627a88 == -1) || ((DAT_00627a88 == 10 && (arg_1 == DAT_00627a84)))) {
      DAT_0063ee1c = 0;
    }
    else {
      DAT_0063ee1c = 1;
    }
    FUN_0047624f(arg_1,0xce,s_Draw_Phase_00531164,1);
    g_ActivePalette = 1;
    Magic_ScanCards(10);
    local_8 = g_ActivePalette;
    if (0 < g_ActivePalette) {
      if (arg_1 == g_CurrentTurnPhase) {
        for (local_2ac = 0; local_2ac < local_8; local_2ac = local_2ac + 1) {
          local_2b4 = Pic_Subsystem_00451291(arg_1,DAT_006a3f74);
          if (local_2b4 != -1) {
            *(uint *)(&g_CardSlot_Flags + local_2b4 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags + local_2b4 * 0x120 + arg_1 * 0x5b20) | 2;
          }
        }
        Ai_Subsystem_004cc9c5(0,0x30);
      }
      else {
        for (local_2ac = 0; local_2ac < local_8; local_2ac = local_2ac + 1) {
          FUN_0046f5d1(arg_1);
        }
      }
    }
    DAT_00627860 = 1;
    DAT_007006d0 = 0;
    FUN_00475c8a(-1,g_ScWillyScore,s_Draw_Phase_00531170,g_ScWillyScore);
    DAT_00627860 = 0;
    local_150 = DAT_007006d0;
    DAT_0063ee1c = 0;
    Ai_Util_004cb2d0(arg_1);
    FUN_00506102();
    iVar1 = FUN_005062b1();
    if (iVar1 != 0) {
      return;
    }
  }
LAB_00502f23:
  DAT_006a5f20 = 0;
  g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffffe00;
  g_ScWillyScore = 0x14;
  Magic_CheckTurnTriggers(arg_1,0x14);
  DAT_007006d0 = 0;
  DAT_00627860 = 0;
  if (g_IsAiThinking != 1) {
    DAT_0063ee1c = 0;
  }
LAB_00502f7e:
  do {
    if (arg_1 != g_CurrentTurnPhase) {
      Ai_Subsystem_004cc9c5(0,0xff);
      FUN_00472f0c(1,((g_ScWillyScore < 0x1e) - 1 & 0xffffffd3) + 0x5a);
      DAT_006a2840 = 0;
    }
LAB_00502fc3:
    DAT_00627860 = 1;
    DAT_006fe3f8 = 0;
    if (arg_1 != g_CurrentTurnPhase) {
      Ai_GetActivePlayerScore();
      DAT_006b253c = 0;
      DAT_006b2538 = 0;
      DAT_006a2844 = 0;
      g_SpellStackDepth = 0;
      if (((g_IsAiThinking != 1) && ((g_PlayerHandCardCount & 0x40) == 0)) && (DAT_0069f700 != '\0')
         ) {
        Pic_Subsystem_0045275a(&DAT_0069f700);
        g_PlayerHandCardCount = g_PlayerHandCardCount | 0x40;
        DAT_0069f700 = '\0';
      }
    }
LAB_00503056:
    local_154 = 0;
    local_2a8 = 6;
    while (((DAT_00701008 = 0, arg_1 == g_CurrentTurnPhase || (g_IsAiThinking == 1)) ||
           ((_DAT_006ff190 & 2) == 0))) {
      DAT_0067bdb0 = 0;
      if ((g_IsAiThinking != 1) && (DAT_0069f700 != '\0')) {
        Pic_Subsystem_0045275a(&DAT_0069f700);
      }
      if (arg_1 == g_CurrentTurnPhase) {
        if (g_ActivePlayer == 1) {
          Engine_ReportFatalError(s_Cancel_error_0053117c);
          g_ActivePlayer = 0;
        }
        do {
          while( true ) {
            g_PlayerHandCardCount = g_PlayerHandCardCount | 0x80;
            g_OverworldWorldState = 0;
            if (g_ScWillyScore < 0x15) break;
            if (0x1d < g_ScWillyScore) {
              strcpy(&g_OverworldWorldState,s_Main_phase__after_combat___cast_s_005311c4);
              if ((g_PlayerHandCardCount & 1) == 0) {
                strcat(&g_OverworldWorldState,s___play_land_005311ec);
              }
              strcat(&g_OverworldWorldState,&DAT_005311f8);
              goto LAB_005032a2;
            }
            if (arg_1 == g_CurrentTurnPhase) {
              iVar1 = FUN_00472616(arg_1);
              if ((iVar1 != 0) || (iVar1 = FUN_00505e3f(0x15), iVar1 != 0)) goto LAB_00503236;
              g_ScWillyScore = 0x1e;
            }
            else {
              iVar1 = FUN_00472a0a(arg_1);
              if (iVar1 != 0) {
LAB_00503236:
                if (DAT_006fe444 == 2) {
                  strcpy(&g_OverworldWorldState,
                         s_Choose_attackers__005311fc + ((arg_1 == g_DefendingPlayer) - 1 & 0x14));
                }
                else {
                  strcpy(&g_OverworldWorldState,
                         s_Combat_phase__Choose_attackers__00531224 +
                         ((arg_1 == g_DefendingPlayer) - 1 & 0x20));
                }
                goto LAB_005032a2;
              }
              g_ScWillyScore = 0x1e;
            }
          }
          strcpy(&g_OverworldWorldState,s_Main_phase__before_combat___cast_0053118c);
          if ((g_PlayerHandCardCount & 1) == 0) {
            strcat(&g_OverworldWorldState,s___play_land_005311b4);
          }
          strcat(&g_OverworldWorldState,&DAT_005311c0);
LAB_005032a2:
          do {
            Mem_AllocOrFree_00475c61();
            iVar1 = FUN_00505c74();
            if ((iVar1 == 0) || ((g_ScWillyScore == 0x15 && (DAT_00626810 != 0)))) {
              local_2dc = Duel_LogActionStatusBanner(arg_1,arg_1,arg_1,0,0,&g_OverworldWorldState,2)
              ;
            }
            else {
              DAT_0063ee8c = -2;
              local_2dc = -1;
            }
            if (local_2dc == -2) {
              local_2dc = -1;
            }
          } while (((g_ScWillyScore == 0x15) && (local_2dc < 0)) &&
                  (FUN_00472905(arg_1), DAT_00626810 != 0));
          if ((DAT_0063ee8c == -2) && (g_IsAiThinking != 1)) {
            if (g_ScWillyScore < 0x18) {
              if (DAT_00627a88 < 0x19) {
                DAT_0063ee1c = 0;
              }
              else {
                DAT_0063ee1c = 1;
              }
            }
            if (g_ScWillyScore < 0x16) {
              if (DAT_00627a88 < 0x17) {
                DAT_0063ee1c = 0;
              }
              else {
                DAT_0063ee1c = 1;
              }
            }
          }
          g_PlayerHandCardCount = g_PlayerHandCardCount & 0xffffff7f;
          if ((DAT_0063ee8c != -2) || ((DAT_00627a84 != 0xffffffff && (DAT_00627a88 == -1))))
          goto LAB_00503702;
          iVar1 = Ai_Util_004cb2d0(arg_1);
          if (iVar1 == 0) {
            if (0x14 < g_ScWillyScore) {
              if (0x1d < g_ScWillyScore) goto LAB_00504c88;
              if ((arg_1 == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
                g_OverworldWorldState = 0;
              }
              if ((DAT_006a5f20 < 1) && (iVar1 = FUN_00472905(arg_1), iVar1 != 0))
              goto LAB_00504287;
              local_154 = 1;
              goto LAB_00504287;
            }
            Magic_ScanCards(0x89);
            FUN_00506102();
            iVar1 = FUN_005062b1();
            if (iVar1 != 0) {
              return;
            }
            Magic_CheckTurnTriggers(arg_1,g_ScWillyScore);
            if ((((DAT_006a5f20 == 0) &&
                 ((iVar1 = FUN_00472616(arg_1), iVar1 == 0 || (iVar1 = FUN_00505c74(), iVar1 != 0)))
                 ) && ((DAT_00627a84 != g_CurrentTurnPhase || (DAT_00627a88 != 0x15)))) &&
               (((&DAT_00696794)[arg_1 * 0x98] & 1) == 0)) goto LAB_00504287;
            g_ScWillyScore = 0x15;
            if (((g_DefendingPlayer == g_CurrentTurnPhase) && (DAT_00627a84 == g_CurrentTurnPhase))
               && (DAT_00627a88 == 0x15)) {
              *(uint *)(&DAT_00696794 + g_CurrentTurnPhase * 0x98) =
                   *(uint *)(&DAT_00696794 + g_CurrentTurnPhase * 0x98) | 2;
              *(uint *)(&DAT_00696798 + g_CurrentTurnPhase * 0x98) =
                   *(uint *)(&DAT_00696798 + g_CurrentTurnPhase * 0x98) | 2;
              *(uint *)(&DAT_006967a0 + g_CurrentTurnPhase * 0x98) =
                   *(uint *)(&DAT_006967a0 + g_CurrentTurnPhase * 0x98) | 2;
            }
            iVar1 = FUN_00505c74();
            if (((iVar1 != 0) && (DAT_006a5f20 == 0)) && (iVar1 = FUN_00472905(arg_1), iVar1 != 0))
            goto LAB_00504287;
            Magic_CheckTurnTriggers(arg_1,g_ScWillyScore);
            if (arg_1 != g_CurrentTurnPhase) goto LAB_0050427a;
            if (g_IsAiThinking == 1) goto LAB_0050427a;
            if (DAT_006fe444 == 2) {
              strcpy(&g_OverworldWorldState,s_Choose_attackers__00531284);
              goto LAB_0050427a;
            }
            strcpy(&g_OverworldWorldState,s_Combat_phase__choose_attackers__00531264);
            goto LAB_0050427a;
          }
        } while( true );
      }
      Mem_AllocOrFree_00475c61();
      DAT_0067bdb0 = 2;
      local_2dc = Palette_Subsystem_004a99a0(arg_1);
      if (local_2dc == -1) {
        if (g_IsAiThinking != 1) {
          FUN_00475c8a(0,g_ScWillyScore,s_Main_Phase_00531298,g_ScWillyScore);
        }
        if (g_ScWillyScore == 0x14) {
          g_ScWillyScore = 0x15;
        }
        else {
          g_ScWillyScore = 0x1e;
        }
        Magic_CheckTurnTriggers(arg_1,g_ScWillyScore);
        FUN_00506102();
        iVar1 = FUN_005062b1();
        if (iVar1 != 0) {
          return;
        }
        local_154 = 1;
      }
LAB_00503702:
      DAT_0067bdb0 = 3;
      local_2a8 = 0;
      if (local_2dc != -1) {
        local_158 = *(int *)(&g_CardSlot_CardId + local_2dc * 0x120 + arg_1 * 0x5b20);
        if (((&g_CardSlot_Flags)[local_2dc * 0x120 + arg_1 * 0x5b20] & 0x12) == 0) {
          if ((((&g_MasterCardColorTable)[local_158 * 0x34] & 1) == 0) ||
             ((g_PlayerHandCardCount & 1) == 0)) {
            if (g_ScWillyScore != 0x15) {
              g_TurnCounter = 0;
              DAT_006b2d3c = 0xffffffff;
              iVar1 = FUN_0046ff50(arg_1,local_2dc,0);
              if (iVar1 != 0) {
                if (arg_1 != g_CurrentTurnPhase) goto LAB_00503847;
                if (g_ScWillyScore == 0x15) goto LAB_00503847;
                if (((&g_MasterCardColorTable)[local_158 * 0x34] & 1) != 0) goto LAB_00503847;
                FUN_00472f0c(4,0x1e);
                goto LAB_00503847;
              }
            }
          }
          else if (g_IsAiThinking == 1) {
            local_154 = 1;
          }
        }
        else {
          if (((g_ScWillyScore < 0x15) || (0x1d < g_ScWillyScore)) || (arg_1 != g_CurrentTurnPhase))
          {
            g_OverworldPlayerCoordY = 0xffffffff;
            DAT_006fefa8 = 0xffffffff;
            if (((((&DAT_0051aed0)[local_158 * 0x34] & 3) == 0) ||
                (((&g_CardSlot_Flags)[local_2dc * 0x120 + arg_1 * 0x5b20] & 0x24) != 0)) &&
               (((&DAT_0051aed1)[local_158 * 0x34] & 0x10) == 0)) goto LAB_00503f2d;
            iVar1 = Magic_TriggerCardEvent(arg_1,local_2dc,0x73,local_2b8,0xffffffff);
            if (iVar1 == 0) goto LAB_00503f2d;
            if ((arg_1 != g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
              DAT_00627a84 = g_DefendingPlayer;
              DAT_00627a88 = g_ScWillyScore;
            }
            if (g_IsAiThinking != 1) {
              g_ActivePlayer = -1;
            }
            local_618 = FUN_0047103b(arg_1,local_2dc);
            g_OverworldPlayerCoordY = 0xffffffff;
            if (local_618 == 0) goto LAB_00503e94;
            if (g_IsAiThinking == 1) goto LAB_00503dee;
            if (arg_1 != g_CurrentTurnPhase) goto LAB_00503dee;
            if (g_ScWillyScore == 0x15) goto LAB_00503dee;
            if (((&DAT_0051aed1)
                 [*(int *)(&g_CardSlot_CardId + local_2dc * 0x120 + arg_1 * 0x5b20) * 0x34] & 0x10)
                != 0) goto LAB_00503dee;
            FUN_00472f0c(7,0xf);
            goto LAB_00503dee;
          }
          if ((((arg_1 == g_CurrentTurnPhase) &&
               (((&g_MasterCardColorTable)[local_158 * 0x34] & 2) != 0)) &&
              ((*(uint *)(&g_CardSlot_Flags + local_2dc * 0x120 + arg_1 * 0x5b20) & 0x10014) == 0))
             && ((-1 < DAT_006a5f20 && (iVar1 = FUN_004726c5(arg_1,local_2dc), iVar1 != 0)))) {
            Magic_PayManaCost();
            strcpy(local_108,&g_OverworldWorldState);
            DAT_00695f08 = arg_1;
            DAT_006b2e14 = local_2dc;
            DAT_0068a65c = 0;
            FUN_0047624f(arg_1,0xdc,s_Pay_for_attacker_00531374,1);
            strcpy(&g_OverworldWorldState,local_108);
            Magic_TapCardForMana();
            if (DAT_0068a65c == 0) {
              (&g_CardSlot_ColorMask)[local_2dc * 0x120 + arg_1 * 0x5b20] = 0xff;
              iVar1 = DAT_006a5f20;
              DAT_006a5f20 = DAT_006a5f20 + 1;
              if (iVar1 == 0) {
                FUN_00506102();
                iVar1 = FUN_005062b1();
                if (iVar1 != 0) {
                  return;
                }
                Magic_CheckTurnTriggers(arg_1,g_ScWillyScore);
              }
              uVar2 = FUN_00473179(arg_1,local_2dc,0x34,0xffffffff);
              if ((((uVar2 & 0x200040) != 0) && (1 < DAT_006a5f20)) && (DAT_00627864 == 0)) {
                strcpy(&g_OverworldWorldState,s_Band_with_other_attacker__00531388);
                iVar1 = Action_ValidateTarget_00405802
                                  (arg_1,arg_1,arg_1,0x200,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0
                                   ,2,0,&g_OverworldWorldState,2,&local_2d4);
                if (iVar1 != 0) {
                  local_2a4 = local_2d0;
                  if ((&g_CardSlot_ColorMask)[local_2d0 * 0x120 + arg_1 * 0x5b20] == -1) {
                    local_2a4._0_1_ = (undefined1)local_2d0;
                    (&g_CardSlot_ColorMask)[local_2d0 * 0x120 + arg_1 * 0x5b20] =
                         (undefined1)local_2a4;
                    (&g_CardSlot_ColorMask)[local_2dc * 0x120 + arg_1 * 0x5b20] =
                         (undefined1)local_2a4;
                  }
                  else {
                    (&g_CardSlot_ColorMask)[local_2dc * 0x120 + arg_1 * 0x5b20] =
                         (&g_CardSlot_ColorMask)[local_2d0 * 0x120 + arg_1 * 0x5b20];
                  }
                }
              }
              *(uint *)(&g_CardSlot_Flags + local_2dc * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&g_CardSlot_Flags + local_2dc * 0x120 + arg_1 * 0x5b20) | 4;
              local_2a8 = 2;
            }
            else if (g_IsAiThinking != 1) {
              Ai_Util_004cc42d(s_Illegal_attacker__005313a4);
              Sleep(2000);
              Ai_Util_004cc42d(&DAT_005313b8);
            }
          }
        }
      }
LAB_00504268:
      while( true ) {
        if (DAT_006fe3f0 != 0) {
          return;
        }
LAB_0050427a:
        if (local_154 == 0) break;
LAB_00504287:
        DAT_0067bdb0 = 4;
        DAT_0068a67c = 1;
        Pic_Subsystem_004475a4(arg_1);
        if ((arg_1 != g_CurrentTurnPhase) &&
           (((g_IsAiThinking != 1 || (DAT_006808a8 != 1)) && (g_ScWillyScore == 0x1e))))
        goto LAB_00504c88;
        if (arg_1 == g_CurrentTurnPhase) goto LAB_0050471d;
        if (0x1d < g_ScWillyScore) goto LAB_0050471d;
        Magic_ScanCards(0x89);
        iVar1 = Ai_Subsystem_004c5fc9(arg_1);
        if (iVar1 == 0) goto LAB_0050471d;
        if (g_DefendingPlayer == 1) {
          DAT_00627a88 = -1;
          DAT_00627a84 = 0xffffffff;
        }
        DAT_00695f08 = arg_1;
        for (DAT_006b2e14 = 0; DAT_006b2e14 < (&g_PlayerActiveCardCount)[arg_1];
            DAT_006b2e14 = DAT_006b2e14 + 1) {
          if ((*(int *)(&g_CardSlot_CardId + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) != -1) &&
             (((byte)*(undefined4 *)
                      (&g_CardSlot_Flags + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) & 6) == 6))
          {
            Magic_PayManaCost();
            strcpy(local_108,&g_OverworldWorldState);
            DAT_0068a65c = 0;
            FUN_0047624f(arg_1,0xdc,s_Pay_for_attacker_005313bc,1);
            strcpy(&g_OverworldWorldState,local_108);
            Magic_TapCardForMana();
            if ((DAT_0068a65c != 0) &&
               (*(uint *)(&g_CardSlot_Flags + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) =
                     *(uint *)(&g_CardSlot_Flags + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) &
                     0xfffffffb,
               (&g_CardSlot_ColorMask)[DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20] != -1)) {
              local_760 = 0;
              for (local_75c = 0; local_75c < (&g_PlayerActiveCardCount)[arg_1];
                  local_75c = local_75c + 1) {
                if ((local_75c != DAT_006b2e14) &&
                   ((&g_CardSlot_ColorMask)[local_75c * 0x120 + arg_1 * 0x5b20] ==
                    (&g_CardSlot_ColorMask)[DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20])) {
                  local_758[local_760] = local_75c;
                  local_760 = local_760 + 1;
                }
              }
              if (local_760 == 1) {
                (&g_CardSlot_ColorMask)[arg_1 * 0x5b20 + local_758[0] * 0x120] = 0xff;
              }
              else {
                for (local_75c = 0; local_75c < local_760; local_75c = local_75c + 1) {
                  (&g_CardSlot_ColorMask)[arg_1 * 0x5b20 + local_758[local_75c] * 0x120] =
                       (undefined1)local_758[0];
                }
              }
            }
          }
        }
        FUN_00506102();
        iVar1 = FUN_005062b1();
        if (iVar1 != 0) {
          return;
        }
        Magic_CheckTurnTriggers(arg_1,g_ScWillyScore);
        Magic_ScanCards(0x15);
        Magic_CheckTurnTriggers(arg_1,g_ScWillyScore);
        g_ScWillyScore = 0x16;
        Magic_CheckTurnTriggers(arg_1,0x16);
        do {
          if (g_IsAiThinking != 1) {
            Ai_Subsystem_004cc9c5(0,0xff);
            FUN_00472f0c(8,0x1e);
          }
LAB_00504651:
          if (DAT_006808a8 == 8) {
            Ai_GetActivePlayerScore();
            DAT_006b253c = 0;
            DAT_006b2538 = 0;
            DAT_006a2844 = 0;
            g_SpellStackDepth = 0;
          }
          DAT_00627860 = 1;
          local_29c = FUN_00475c8a(-2,g_ScWillyScore,s_Assign_Attackers_005313d0,0x16);
          DAT_00627860 = 0;
        } while (local_29c != 0);
        g_ScWillyScore = 0x17;
        Magic_CheckTurnTriggers(arg_1,0x17);
        FUN_0047624f(1 - arg_1,0xda,s_Choose_Defenders_005313e4,0);
        FUN_00471d16(arg_1);
        DAT_006a5f20 = 1;
LAB_0050471d:
        if ((arg_1 == g_CurrentTurnPhase) && (g_ScWillyScore < 0x1e)) {
          iVar1 = FUN_00505c74();
          if ((iVar1 != 0) && ((DAT_006a5f20 == 0 && (iVar1 = FUN_00505e3f(0x15), iVar1 == 0))))
          goto LAB_00504b66;
          Magic_ScanCards(0x15);
          if ((g_IsAiThinking == 1) && (g_ScWillyScore < 0x15)) {
            Ai_Subsystem_004c5fc9(arg_1);
          }
          iVar1 = FUN_00472905(arg_1);
          if (iVar1 != 0) {
            if (arg_1 != g_CurrentTurnPhase) goto LAB_00504b66;
            iVar1 = FUN_00505e3f(0x15);
            if (iVar1 == 0) goto LAB_00504b66;
          }
          if (DAT_006a5f20 == 0) {
            DAT_006a5f20 = 1;
            FUN_00506102();
            iVar1 = FUN_005062b1();
            if (iVar1 != 0) {
              return;
            }
            Magic_CheckTurnTriggers(arg_1,g_ScWillyScore);
          }
          FUN_0047624f(arg_1,0xd9,s_Choose_Attackers_005313f8,0);
          goto LAB_00504826;
        }
LAB_00504970:
        Magic_ScanCards(0x1a);
        FUN_004767ee(arg_1);
        if (((0 < DAT_006a5f20) ||
            ((arg_1 == g_CurrentTurnPhase && (iVar1 = FUN_00505e3f(0x18), iVar1 != 0)))) &&
           ((g_PlayerHandCardCount & 8) == 0)) goto LAB_005049db;
        if ((arg_1 == g_CurrentTurnPhase) && (g_IsAiThinking == 1)) goto LAB_005049db;
LAB_00504b66:
        if ((arg_1 == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
          if (g_ScWillyScore < 0x1e) {
            if (DAT_006a4a04 <= DAT_006b3004 / 2) {
              Pic_Subsystem_0045275a(s__Ouch__that_hurt___00531454);
            }
            DAT_006a5f20 = 0;
            g_ScWillyScore = 0x1e;
            Magic_CheckTurnTriggers(arg_1,0x1e);
            iVar1 = FUN_00505c74();
            if (iVar1 == 0) goto LAB_00502fc3;
          }
          else if (g_PlayerCreatureCount <= DAT_006a4a04 / 2) {
            Pic_Subsystem_0045275a(s__Give_up__you_re_doomed___00531468);
          }
        }
        if ((arg_1 != g_CurrentTurnPhase) && (g_ScWillyScore != 0x1e)) {
          g_ScWillyScore = 0x1e;
          Magic_CheckTurnTriggers(arg_1,0x1e);
          if (g_IsAiThinking != 1) {
            g_PlayerHandCardCount = g_PlayerHandCardCount | 0x100;
            goto LAB_00502f7e;
          }
          if ((DAT_006808a8 == 1) || (DAT_006808a8 == 2)) goto LAB_00503056;
        }
LAB_00504c88:
        DAT_0067bdb0 = 5;
        FUN_00506102();
        iVar1 = FUN_005062b1();
        if (iVar1 != 0) {
          return;
        }
LAB_00504ca9:
        local_2d8 = Ai_Subsystem_004cbcd9(0x8c);
        if ((local_2d8 != -1) &&
           (iVar1 = FUN_00403250((int *)0x0,0,arg_1,arg_1,arg_1,0x200,0,0,0,0,0,0,local_2d8,
                                 0xffffffff,0xffffffff,0xffffffff,0,0,0), iVar1 != 0))
        goto LAB_00505053;
        local_764 = 0;
        DAT_007006d0 = 0;
        if (g_IsAiThinking != 1) {
          if ((DAT_00627a88 == -1) || ((DAT_00627a88 == 0x1f && (arg_1 == DAT_00627a84)))) {
            DAT_0063ee1c = 0;
          }
          else {
            DAT_0063ee1c = 1;
          }
        }
LAB_00504d79:
        DAT_00627860 = 0;
        if ((g_IsAiThinking != 1) && (arg_1 == g_CurrentTurnPhase)) {
          Ai_Subsystem_004cc9c5(0,0xff);
          FUN_00472f0c(3,0x1e);
        }
LAB_00504daf:
        if (DAT_006808a8 == 3) {
          Ai_GetActivePlayerScore();
          DAT_006b253c = 0;
          DAT_006b2538 = 0;
          DAT_006a2844 = 0;
          g_SpellStackDepth = 0;
        }
        g_ScWillyScore = 0x1f;
        Magic_CheckTurnTriggers(arg_1,0x1f);
        DAT_00627860 = 1;
        if (arg_1 == g_CurrentTurnPhase) {
          local_7d0 = 0xffffffff;
        }
        else {
          local_7d0 = arg_1;
        }
        local_29c = FUN_00475c8a(local_7d0,g_ScWillyScore,s_Discard_Phase_00531484,0x1f);
        DAT_00627860 = 0;
        if (local_29c != 0) goto LAB_00504d79;
        if (g_IsAiThinking == 1) {
          if (arg_1 != g_CurrentTurnPhase) goto LAB_00504ea5;
        }
        else {
          DAT_0063ee1c = 0;
LAB_00504ea5:
          if ((g_PlayerHandCardCount & 0x800 << ((byte)arg_1 & 0x1f)) == 0) {
            if (arg_1 == g_CurrentTurnPhase) {
              local_2c8 = 0;
            }
            else {
              local_2c8 = DAT_00627a14;
            }
            for (local_2ac = 0; local_2ac < (&g_PlayerActiveCardCount)[arg_1];
                local_2ac = local_2ac + 1) {
              if ((*(int *)(&g_CardSlot_CardId + local_2ac * 0x120 + arg_1 * 0x5b20) != -1) &&
                 (((&g_CardSlot_Flags)[local_2ac * 0x120 + arg_1 * 0x5b20] & 2) == 0)) {
                local_2c8 = local_2c8 + 1;
              }
            }
            g_ActivePalette = 0;
            Magic_ScanCards(0x1f);
            local_764 = 0;
            while ((g_ActivePalette == 0 && (7 < local_2c8))) {
              Prompts_Load_0046fa40(arg_1,0,1);
              local_2c8 = local_2c8 + -1;
              if ((arg_1 == g_ActivePlayerPriority) && (g_IsAiThinking == 1)) {
                g_SpellStackDepth = g_SpellStackDepth + -0x18;
              }
              if (((arg_1 == 0) && (g_IsAiThinking == 0)) && (DAT_006fedc0 == 0)) {
                local_764 = 1;
              }
            }
          }
        }
        if (local_764 != 0) {
          FUN_00506029(s_Paused__Discard_phase_00531494);
          local_150 = 1;
          local_764 = 0;
        }
        FUN_00506102();
        iVar1 = FUN_005062b1();
        if (iVar1 != 0) {
          return;
        }
LAB_00505053:
        if (g_IsAiThinking != 1) {
          g_ScWillyScore = 0x22;
          Magic_CheckTurnTriggers(arg_1,0x22);
          DAT_007006d0 = 0;
          DAT_00627860 = 0;
          if (g_IsAiThinking != 1) {
            if ((DAT_00627a88 == -1) || ((DAT_00627a88 == 0x20 && (arg_1 == DAT_00627a84)))) {
              DAT_0063ee1c = 0;
            }
            else {
              DAT_0063ee1c = 1;
            }
          }
        }
        local_2ac = 0;
        while( true ) {
          iVar1 = DAT_006808bc;
          if (DAT_006808bc <= g_PlayerActiveCardCount) {
            iVar1 = g_PlayerActiveCardCount;
          }
          if (iVar1 <= local_2ac) break;
          if ((*(int *)(&g_CardSlot_CardId + local_2ac * 0x120 + arg_1 * 0x5b20) != -1) &&
             (((&g_CardSlot_Flags)[local_2ac * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
            *(undefined2 *)(&g_CardSlot_Power + local_2ac * 0x120 + arg_1 * 0x5b20) = 0;
            Magic_TriggerCardEvent(arg_1,local_2ac,0x22,local_2b8,0xffffffff);
          }
          if ((*(int *)(&g_CardSlot_CardId + local_2b8 * 0x5b20 + local_2ac * 0x120) != -1) &&
             (((&g_CardSlot_Flags)[local_2b8 * 0x5b20 + local_2ac * 0x120] & 2) != 0)) {
            *(undefined2 *)(&g_CardSlot_Power + local_2b8 * 0x5b20 + local_2ac * 0x120) = 0;
            Magic_TriggerCardEvent(local_2b8,local_2ac,0x22,arg_1,0xffffffff);
          }
          local_2ac = local_2ac + 1;
        }
        if (DAT_0068a64c != -1) {
          (**(code **)(&DAT_0051aec8 + DAT_0068a64c * 0x34))(0,0x4e,0x22);
        }
        FUN_00476205(arg_1,0xcd,s_End_of_Turn_005314ac,0);
        Pic_Subsystem_004488a0();
        if (g_IsAiThinking != 1) {
          DAT_0063ee1c = 0;
        }
        Pic_Subsystem_004475a4(arg_1);
        Ai_Subsystem_004cc9c5(0,0xff);
        local_2bc = 0;
        for (local_2ac = 0; local_2ac < 0x50; local_2ac = local_2ac + 1) {
          if (*(int *)(&g_CardSlot_CardId + local_2ac * 0x120 + arg_1 * 0x5b20) != -1) {
            *(uint *)(&g_CardSlot_Flags + local_2ac * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags + local_2ac * 0x120 + arg_1 * 0x5b20) & 0xffff7db2;
            (&g_CardSlot_ColorMask)[local_2ac * 0x120 + arg_1 * 0x5b20] = 0xff;
            *(undefined2 *)(&g_CardSlot_Power + local_2ac * 0x120 + arg_1 * 0x5b20) = 0;
          }
          if (*(int *)(&g_CardSlot_CardId + local_2b8 * 0x5b20 + local_2ac * 0x120) != -1) {
            *(uint *)(&g_CardSlot_Flags + local_2b8 * 0x5b20 + local_2ac * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + local_2b8 * 0x5b20 + local_2ac * 0x120) & 0xffff7db2;
            (&g_CardSlot_ColorMask)[local_2b8 * 0x5b20 + local_2ac * 0x120] = 0xff;
            *(undefined2 *)(&g_CardSlot_Power + local_2b8 * 0x5b20 + local_2ac * 0x120) = 0;
          }
          if (g_MasterCardCount <= *(int *)(&g_CardSlot_CardId + local_2ac * 0x120 + arg_1 * 0x5b20)
             ) {
            asStack_298[local_2bc] =
                 (short)*(undefined4 *)(&g_CardSlot_CardId + local_2ac * 0x120 + arg_1 * 0x5b20);
            local_2bc = local_2bc + 1;
          }
          if (g_MasterCardCount <=
              *(int *)(&g_CardSlot_CardId + local_2b8 * 0x5b20 + local_2ac * 0x120)) {
            asStack_298[local_2bc] =
                 (short)*(undefined4 *)(&g_CardSlot_CardId + local_2b8 * 0x5b20 + local_2ac * 0x120)
            ;
            local_2bc = local_2bc + 1;
          }
        }
        for (local_2ac = g_MasterCardCount; local_2ac < g_MasterCardCount + 0x10;
            local_2ac = local_2ac + 1) {
          if (*(int *)(&g_MasterCardTypeTable + local_2ac * 0x34) != -1) {
            local_2b0 = local_2bc + -1;
            local_2cc = 0;
            while ((-1 < local_2b0 && (local_2cc == 0))) {
              if (asStack_298[local_2b0] == local_2ac) {
                local_2cc = 1;
              }
              local_2b0 = local_2b0 + -1;
            }
            local_2b0 = 0;
            while( true ) {
              iVar1 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
              if ((&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
                  (&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
                iVar1 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
              }
              if (iVar1 <= local_2b0) break;
              if (((*(int *)(&g_CardSlot_CardId + local_2b0 * 0x120 + g_CurrentTurnPhase * 0x5b20)
                    != -1) &&
                  (((&g_CardSlot_Flags)[local_2b0 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0))
                 && (*(int *)(&g_CardSlot_Controller +
                             local_2b0 * 0x120 + g_CurrentTurnPhase * 0x5b20) == local_2ac)) {
                local_2cc = 1;
              }
              if (((*(int *)(&g_CardSlot_CardId +
                            local_2b0 * 0x120 + g_ActivePlayerPriority * 0x5b20) != -1) &&
                  (((&g_CardSlot_Flags)[local_2b0 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2) !=
                   0)) && (*(int *)(&g_CardSlot_Controller +
                                   local_2b0 * 0x120 + g_ActivePlayerPriority * 0x5b20) == local_2ac
                          )) {
                local_2cc = 1;
              }
              local_2b0 = local_2b0 + 1;
            }
            if (local_2cc == 0) {
              *(undefined4 *)(&g_MasterCardTypeTable + local_2ac * 0x34) = 0xffffffff;
            }
          }
        }
        if (g_IsAiThinking != 1) goto LAB_00505c28;
        local_2a0 = 1 - arg_1;
        for (local_2ac = 0; local_2ac < 8; local_2ac = local_2ac + 1) {
          auStack_14c[local_2ac + local_2a0 * 8] =
               *(undefined4 *)(&DAT_0063edd0 + local_2ac * 4 + local_2a0 * 0x20);
          *(undefined4 *)(&DAT_0063edd0 + local_2ac * 4 + local_2a0 * 0x20) =
               *(undefined4 *)(&DAT_0063ee30 + local_2ac * 4 + local_2a0 * 0x20);
        }
        Magic_ScanCards(199);
        for (local_2ac = 0; local_2ac < (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
            local_2ac = local_2ac + 1) {
          if (*(int *)(&g_CardSlot_CardId + g_ActivePlayerPriority * 0x5b20 + local_2ac * 0x120) !=
              -1) {
            (**(code **)(&DAT_0051aec8 +
                        *(int *)(&g_CardSlot_CardId +
                                g_ActivePlayerPriority * 0x5b20 + local_2ac * 0x120) * 0x34))
                      (g_ActivePlayerPriority,local_2ac,0x38);
          }
        }
        Pic_Subsystem_004475a4(arg_1);
        Pic_Subsystem_004488a0();
        for (local_2a0 = 0; local_2a0 < 2; local_2a0 = local_2a0 + 1) {
          for (local_2ac = 0; local_2ac < 8; local_2ac = local_2ac + 1) {
            *(undefined4 *)(&DAT_0063edd0 + local_2ac * 4 + local_2a0 * 0x20) =
                 auStack_14c[local_2ac + local_2a0 * 8];
          }
        }
        FUN_00472fae();
        local_8 = Ai_SimulateCombatRound(g_ActivePlayerPriority);
        local_8 = g_SpellStackDepth + local_8;
        if (0 < DAT_006a4a04) {
          DAT_00680790 = DAT_00680790 | 4;
        }
        if (DAT_0067b9a4 != 0) {
          Ai_ChooseBlockers(0,local_8);
        }
        if ((DAT_0069f6d8 < local_8) && (DAT_00701008 == 0)) {
          DAT_0069f6d8 = local_8;
          Ai_ScoreBoardPosition();
          local_10c = DAT_00680790;
          local_2c4 = DAT_006b1580;
        }
        if (DAT_006a2840 == 999) {
          DAT_006a2840 = -1;
        }
        DAT_006a2838 = 0;
        local_154 = 0;
        DAT_00701008 = 0;
        iVar1 = Timer_GetElapsedFraction();
        if (((DAT_006fe40c / 2 < iVar1) &&
            (((DAT_0067f380 * 5 + 5) * 5 <= DAT_006b1580 ||
             (uVar2 = DAT_00680790 & 4, iVar1 = Timer_GetElapsedFraction(),
             (int)((-(uint)(uVar2 == 0) & 0x96) + 0x32) < iVar1)))) &&
           ((DAT_0067b9a4 == 0 || (0x32 < DAT_006b1580)))) {
          sprintf(local_7c8,s_phase___3d_num_tries___4d_mtime___005314b8,DAT_006498f0,DAT_006b1580,
                  DAT_006fe40c / 2,DAT_00677340);
          OutputDebugStringA(local_7c8);
          if (DAT_0067b9a4 != 0) {
            Ai_ChooseBlockers(1,DAT_0069f6d8);
          }
          DAT_0067bdb0 = 0xffffffff;
          g_IsAiThinking = 0;
          DAT_006a2840 = -1;
          DAT_00680790 = local_10c;
        }
        DAT_006b1580 = DAT_006b1580 + 1;
        _DAT_00627a0c = 0;
        if (DAT_006808a8 == 1) {
          if ((g_PlayerHandCardCount & 0x100) == 0) {
            g_ScWillyScore = 0x14;
          }
          else {
            g_ScWillyScore = 0x1e;
          }
          goto LAB_00502fc3;
        }
        if (DAT_006808a8 == 2) {
          g_ScWillyScore = 0x1a;
          while( true ) {
            if (DAT_006808a8 == 2) {
              Ai_GetActivePlayerScore();
              DAT_006b253c = 0;
              DAT_006b2538 = 0;
              DAT_006a2844 = 0;
              g_SpellStackDepth = 0;
            }
            g_ScWillyScore = 0x18;
            Magic_CheckTurnTriggers(arg_1,0x18);
            DAT_00627860 = 1;
            local_29c = FUN_00475c8a(-2,g_ScWillyScore,s_Assign_Blockers_00531434,0x18);
            DAT_00627860 = 0;
            if (local_29c == 0) break;
LAB_005049db:
            if (g_IsAiThinking != 1) {
              Ai_Subsystem_004cc9c5(0,0xff);
              FUN_00472f0c(2,0x1e);
            }
          }
          Ai_EvalAttackCandidate_004c864d(arg_1);
          g_PlayerHandCardCount = g_PlayerHandCardCount | 8;
LAB_00504ac9:
          DAT_0068a67c = 1;
          if (DAT_006808a8 == 5) {
            Ai_GetActivePlayerScore();
            DAT_006b253c = 0;
            DAT_006b2538 = 0;
            DAT_006a2844 = 0;
            g_SpellStackDepth = 0;
            DAT_0068a67c = 3;
          }
          FUN_00476205(arg_1,0xcc,s_End_of_Combat_00531444,0);
          Ai_Subsystem_004c9f88(arg_1);
          FUN_00472fae();
          Ai_Subsystem_004cc9c5(0,0xff);
          FUN_00506102();
          iVar1 = FUN_005062b1();
          if (iVar1 != 0) {
            return;
          }
          goto LAB_00504b66;
        }
        if (DAT_006808a8 == 3) goto LAB_00504daf;
        if (DAT_006808a8 != 4) {
          if (DAT_006808a8 == 5) {
            g_ScWillyScore = 0x1a;
            goto LAB_00504ac9;
          }
          if (DAT_006808a8 != 6) goto LAB_00505bca;
          g_ScWillyScore = 0x1a;
          while( true ) {
            if (DAT_006808a8 == 6) {
              Ai_GetActivePlayerScore();
              DAT_006b253c = 0;
              DAT_006b2538 = 0;
              DAT_006a2844 = 0;
              g_SpellStackDepth = 0;
            }
            g_ScWillyScore = 0x15;
            Magic_CheckTurnTriggers(arg_1,0x15);
            g_ScWillyScore = 0x16;
            Magic_CheckTurnTriggers(arg_1,0x16);
            Ai_Subsystem_004cc9c5(0,0xff);
            DAT_00627860 = 1;
            local_29c = FUN_00475c8a(-2,g_ScWillyScore,s_Assign_Attackers_0053140c,0x16);
            DAT_00627860 = 0;
            if (local_29c == 0) break;
LAB_00504826:
            if (g_IsAiThinking != 1) {
              Ai_Subsystem_004cc9c5(0,0xff);
              FUN_00472f0c(6,0x1e);
            }
          }
          g_ScWillyScore = 0x17;
          Magic_CheckTurnTriggers(arg_1,0x17);
          FUN_00476205(arg_1,0xda,s_Choose_Defenders_00531420,0);
          Ai_Subsystem_004c4210(arg_1);
          Ai_Subsystem_004c7aa8(arg_1);
          Magic_CheckTurnTriggers(arg_1,g_ScWillyScore);
          goto LAB_00504970;
        }
        if ((g_PlayerHandCardCount & 8) == 0) {
          g_ScWillyScore = 0x14;
        }
        else {
          g_ScWillyScore = 0x1e;
        }
        local_154 = 0;
LAB_00503847:
        if (DAT_006808a8 == 4) {
          Ai_GetActivePlayerScore();
          DAT_006b253c = 0;
          DAT_006b2538 = 0;
          DAT_006a2844 = 0;
          g_SpellStackDepth = 0;
        }
        iVar1 = FUN_0046ff50(arg_1,local_2dc,1);
        if (iVar1 != 0) {
          local_158 = *(int *)(&g_CardSlot_CardId + local_2dc * 0x120 + arg_1 * 0x5b20);
          iVar1 = FUN_00470b36(arg_1,local_2dc);
          if (iVar1 != 0) {
            local_2a8 = 6;
            if (((&g_MasterCardColorTable)[local_158 * 0x34] & 1) != 0) {
              if (arg_1 == g_CurrentTurnPhase) {
                DAT_006fe40c = 0;
              }
              g_PlayerHandCardCount = g_PlayerHandCardCount | 1;
            }
            if (((&g_MasterCardColorTable)[local_158 * 0x34] & 2) != 0) {
              *(uint *)(&g_CardSlot_Flags + local_2dc * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&g_CardSlot_Flags + local_2dc * 0x120 + arg_1 * 0x5b20) | 0x400;
            }
            if (g_IsAiThinking != 1) {
              if (arg_1 == g_CurrentTurnPhase) {
                if ((short)(*(ushort *)(&DAT_0051aec2 + local_158 * 0x34) & 0xbfff) < 4) {
                  iVar1 = FUN_0040a1d2(3);
                  if ((iVar1 == 0) && (iVar1 = Pic_Subsystem_00452551(local_158), 2 < iVar1)) {
                    strcpy(&DAT_0069f700,s__Where_d_you_get_that_card___005312b8);
                  }
                  iVar1 = FUN_0040a1d2(3);
                  if (((iVar1 == 0) && (((&g_MasterCardColorTable)[local_158 * 0x34] & 0x30) != 0))
                     && (0 < DAT_006a4a04)) {
                    strcpy(&DAT_0069f700,s__I_knew_that_was_coming___005312d8);
                  }
                }
                else {
                  strcpy(&DAT_0069f700,s__Oooh__I_m_scared___005312a4);
                }
              }
              else if ((short)(*(ushort *)(&DAT_0051aec2 + local_158 * 0x34) & 0xbfff) < 4) {
                iVar1 = FUN_0040a1d2(3);
                if ((iVar1 == 0) &&
                   ((((&g_MasterCardColorTable)[local_158 * 0x34] & 0x30) != 0 ||
                    (iVar1 = Pic_Subsystem_00452551(local_158), 2 < iVar1)))) {
                  strcpy(&DAT_0069f700,s__Didn_t_expect_that__did_ya___00531310);
                }
                iVar1 = abs((int)(char)(&DAT_0051aec0)[local_158 * 0x34]);
                if (3 < iVar1 + (char)(&DAT_0051aebf)[local_158 * 0x34]) {
                  strcpy(&DAT_0069f700,s__Deal_with_this__rat_boy___00531330);
                }
                if (((int)(char)(&g_CardSlot_Toughness)[local_2dc * 0x120 + arg_1 * 0x5b20] ==
                     g_CurrentTurnPhase) &&
                   (*(int *)(&g_CardSlot_OriginalCardId + local_2dc * 0x120 + arg_1 * 0x5b20) != -1)
                   ) {
                  strcpy(&DAT_0069f700,s__Gotcha___0053134c);
                }
                if (((&DAT_0051aec0)[local_158 * 0x34] == -1) && (2 < g_TurnCounter)) {
                  strcpy(&DAT_0069f700,s__I_just_love_doing_that___00531358);
                }
              }
              else {
                strcpy(&DAT_0069f700,s__Take_that__troll_face___005312f4);
              }
            }
          }
        }
        if (((arg_1 != g_CurrentTurnPhase) && (g_IsAiThinking != 1)) && (DAT_00633434 == 0))
        goto LAB_00502f7e;
        if ((g_IsAiThinking == 1) && (DAT_006808a8 == 4)) {
          local_154 = 1;
        }
      }
    }
    _DAT_006ff190 = 0;
  } while( true );
LAB_00505bca:
  if (DAT_006808a8 != 7) {
    if (DAT_006808a8 != 8) {
LAB_00505c28:
      local_150 = 0;
      FUN_00505ea7(0x20);
      FUN_00506102();
      iVar1 = FUN_005062b1();
      if (iVar1 != 0) {
        return;
      }
      FUN_00505c74();
      Magic_UpkeepPhase(5);
      return;
    }
    g_ScWillyScore = 0x1a;
    goto LAB_00504651;
  }
  if ((g_PlayerHandCardCount & 8) == 0) {
    g_ScWillyScore = 0x14;
  }
  else {
    g_ScWillyScore = 0x1e;
  }
  local_154 = 0;
LAB_00503dee:
  local_158 = *(int *)(&g_CardSlot_CardId + local_2dc * 0x120 + arg_1 * 0x5b20);
  if (DAT_006808a8 == 7) {
    Ai_GetActivePlayerScore();
    DAT_006b253c = 0;
    DAT_006b2538 = 0;
    DAT_006a2844 = 0;
    g_SpellStackDepth = 0;
  }
  if (g_ActivePlayer != 1) {
    FUN_00471971(arg_1,local_2dc);
  }
  if ((g_IsAiThinking == 1) && (DAT_006808a8 == 7)) {
    local_154 = 1;
  }
LAB_00503e94:
  if (g_ActivePlayer == 1) {
    if (arg_1 != g_CurrentTurnPhase) {
      DAT_00701008 = 1;
      local_154 = 1;
    }
    g_ActivePlayer = 0;
  }
  else {
    g_ActivePlayer = 0;
    if (((arg_1 != g_CurrentTurnPhase) && (g_IsAiThinking != 1)) && (DAT_00633434 == 0))
    goto LAB_00502f7e;
    if (g_IsAiThinking != 1) {
      Ai_Subsystem_004cc3f8(arg_1,local_2dc,3,2);
    }
LAB_00503f2d:
    g_TurnCounter = 0;
  }
  goto LAB_00504268;
}


