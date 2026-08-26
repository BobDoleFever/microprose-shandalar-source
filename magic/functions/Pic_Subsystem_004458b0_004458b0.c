/*
 * Decompiled function: Pic_Subsystem_004458b0
 * Entry Point: 004458b0
 * Size: 4135 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Pic_Subsystem_004458b0(int arg1,char *str_2)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int local_84;
  int local_7c;
  int local_78;
  byte local_74;
  int local_70;
  char local_68 [64];
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((int)(&g_PlayerCreatureCount)[g_CurrentTurnPhase] < 1) {
    *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) =
         *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) | 2;
  }
  local_18 = 0;
  if (((g_IsAiThinking != 1) && (g_DefendingPlayer == DAT_00627a84)) &&
     (DAT_00627a88 == g_ScWillyScore)) {
    DAT_0063ee1c = 0;
  }
  if (arg1 == 1) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_00505d20(g_ScWillyScore);
  }
  strcpy(local_68,str_2);
  uVar3 = g_PlayerHandCardCount;
  uVar2 = DAT_0063edc0;
  local_14 = arg1;
  DAT_0063edc0 = arg1;
  local_24 = arg1;
  DAT_0063ee10 = 1;
  DAT_0063edc8 = DAT_0063ee70 & 0x30;
  _DAT_0063eed8 = 0;
  DAT_00627a10 = DAT_00627a10 + 1;
  if (DAT_00627a10 < DAT_0063edc4) {
    DAT_0063edc4 = 0;
  }
  _DAT_00538bb4 = 2;
  _DAT_00538bb8 = 0x20;
  if (0x16 < g_ScWillyScore) {
    _DAT_00538bb4 = 4;
    _DAT_00538bb8 = 0x40;
  }
  if (g_ScWillyScore < 0x15) {
    _DAT_00538bb4 = 1;
    _DAT_00538bb8 = 0x10;
  }
  if (0x1d < g_ScWillyScore) {
    _DAT_00538bb4 = 8;
    _DAT_00538bb8 = 0xffffff80;
  }
  if (g_ScWillyScore == 0x1f) {
    _DAT_00538bb4 = 0xf;
    _DAT_00538bb8 = 0xfffffff0;
  }
  if ((g_ActivePlayerPriority == arg1) && (DAT_006fecc0 == g_CurrentTurnPhase)) {
    _DAT_00538bb4 = 0xf;
    _DAT_00538bb8 = 0xfffffff0;
  }
  if (((((g_IsAiThinking == 1) || (DAT_00633434 != 0)) ||
       ((g_PlayerManaPool != -1 && (g_ActivePlayerPriority == DAT_006a4b5c)))) ||
      (DAT_00695ec4 == 4)) ||
     ((g_ActivePlayerPriority == arg1 && ((g_PlayerHandCardCount & 0x200) != 0)))) {
    local_84 = Pic_Subsystem_004468dc(arg1);
    local_14 = _DAT_0063ee20;
  }
  else {
    local_84 = -1;
  }
  local_20 = 0;
  if ((local_84 != -1) &&
     (iVar4 = Pic_Subsystem_004485d6(local_14,local_84,0x7d,local_24), iVar4 == 2)) {
    FUN_00471aba(local_14,local_84,local_24);
    local_84 = -1;
    Ai_Subsystem_004cc9c5(0,0xff);
  }
  if (local_84 != -1) {
    _DAT_0063ee84 = *(int *)(&g_CardSlot_CardId + local_84 * 0x120 + local_14 * 0x5b20);
    local_1c = _DAT_0063ee84;
    if (((&g_CardSlot_Flags)[local_84 * 0x120 + local_14 * 0x5b20] & 2) == 0) {
      iVar4 = FUN_0046fe86(local_14,local_84);
      if (iVar4 != 0) {
        if ((&g_MasterCardColorTable)[local_1c * 0x34] == ' ') {
          DAT_0063edc8 = DAT_0063ee70 & 0x20;
        }
        local_20 = 1;
        Ai_Subsystem_004cc9c5(0,0xff);
        if ((g_IsAiThinking != 1) && (iVar4 = FUN_0040a1d2(3), iVar4 == 0)) {
          Pic_Subsystem_0045275a(s_Didn_t_expect_that__did_ya__00522120);
        }
      }
    }
    else {
      if (((*(int *)(&DAT_006a5f80 + local_84 * 0x120 + local_14 * 0x5b20) == g_PlayerManaPool) &&
          (DAT_00695f18 != (code *)0x0)) && (g_PlayerManaPool != -1)) {
        if (DAT_00695f18 != (code *)0x0) {
          (*DAT_00695f18)(local_14,local_84);
        }
      }
      else {
        Magic_TriggerCardEvent(local_14,local_84,0x73,1 - local_14,0xffffffff);
        iVar4 = FUN_0047103b(local_14,local_84);
        if (iVar4 != 0) {
          FUN_00471971(local_14,local_84);
        }
        g_ActivePlayer = 0;
      }
      local_20 = 1;
      Ai_Subsystem_004cc9c5(0,0xff);
    }
  }
  local_28 = 0;
  local_8 = 0;
  local_7c = -1;
  if ((g_IsAiThinking != 1) || ((g_PlayerManaPool != -1 && (g_CurrentTurnPhase == DAT_006a4b5c)))) {
    if ((g_CurrentTurnPhase == DAT_006a4b5c) && (g_PlayerManaPool != -1)) {
      for (local_24 = 0; local_24 < 2; local_24 = local_24 + 1) {
        for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[local_24];
            local_70 = local_70 + 1) {
          if ((((&g_CardSlot_Flags)[local_70 * 0x120 + local_24 * 0x5b20] & 2) != 0) &&
             (iVar4 = Pic_Subsystem_004485d6(local_24,local_70,0x7d,arg1), iVar4 != 0)) {
            if (iVar4 == 2) {
              local_7c = local_70;
              local_c = local_24;
              local_14 = local_24;
              local_8 = local_8 + 1;
            }
            else {
              local_74 = (byte)iVar4;
              local_28 = local_28 | 1 << (local_74 & 0x1f);
            }
          }
          if (((((DAT_0068a67c & 1) != 0) &&
               (*(int *)(&DAT_006a5f80 + local_70 * 0x120 + local_24 * 0x5b20) == g_PlayerManaPool))
              && (local_24 == DAT_006a4b5c)) && (g_PlayerManaPool != -1)) {
            local_28 = local_28 | 4;
            local_7c = local_70;
            local_c = local_24;
            local_14 = local_24;
            local_8 = local_8 + 1;
          }
        }
      }
    }
    if (local_7c == -1) {
      if (g_IsAiThinking == 1) goto LAB_00446898;
      if ((g_PlayerManaPool == 0xca) && (*(int *)(&DAT_00696750 + g_DefendingPlayer * 0x98) == 0)) {
        DAT_0068a67c = 0;
      }
      if ((g_PlayerManaPool == 0xce) && (*(int *)(&DAT_00696768 + g_DefendingPlayer * 0x98) == 0)) {
        DAT_0068a67c = 0;
      }
    }
    if (((local_7c != -1) || (local_28 != 0)) || (((DAT_0068a67c & 1) != 0 && (DAT_0063ee70 != 0))))
    {
      DAT_006a4920 = 0;
      DAT_0068a67c = 0;
      local_78 = 0;
      for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
          local_70 = local_70 + 1) {
        if (((*(int *)(&g_CardSlot_CardId + local_70 * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1)
            && (((((&g_CardSlot_SpecialState)[local_70 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 1)
                  != 0 || (((&g_CardSlot_SpecialState)
                            [local_70 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 0x10) != 0)) ||
                ((iVar4 = Magic_ResolveSpellStack(g_CurrentTurnPhase,local_70), iVar4 == 0 &&
                 (g_CurrentTurnPhase == DAT_0063edc0)))))) &&
           (((uVar5 = Pic_Subsystem_00446d52(g_CurrentTurnPhase,local_70), 1 < (int)uVar5 ||
             ((((DAT_006808b0 != 0 || (g_DefendingPlayer != g_CurrentTurnPhase)) &&
               ((uVar5 & 2) != 0)) || ((DAT_006a4920 & 2) != 0)))) &&
            (((g_CurrentTurnPhase != DAT_006a4b5c || (g_PlayerManaPool == -1)) ||
             ((uVar5 != 2 || ((DAT_006a4920 & 2) != 0)))))))) {
          if (((DAT_006a4920 & 2) == 0) && (uVar5 != 2)) {
            if (uVar5 == 2) {
              local_28 = local_28 | 4;
            }
            else {
              local_28 = local_28 | 2;
            }
          }
          else {
            local_7c = local_70;
            local_c = g_CurrentTurnPhase;
            local_8 = local_8 + 1;
          }
          DAT_006a4920 = DAT_006a4920 & 0xfffffffd;
        }
      }
      if (DAT_00695ec4 == 4) {
        for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[1 - g_CurrentTurnPhase];
            local_70 = local_70 + 1) {
          if (((*(int *)(&g_CardSlot_CardId + local_70 * 0x120 + (1 - g_CurrentTurnPhase) * 0x5b20)
                != -1) &&
              (((((&g_CardSlot_SpecialState)[local_70 * 0x120 + (1 - g_CurrentTurnPhase) * 0x5b20] &
                 1) != 0 ||
                (((&g_CardSlot_SpecialState)[local_70 * 0x120 + (1 - g_CurrentTurnPhase) * 0x5b20] &
                 0x10) != 0)) ||
               (iVar4 = Magic_ResolveSpellStack(1 - g_CurrentTurnPhase,local_70), iVar4 == 0)))) &&
             (iVar4 = Pic_Subsystem_00446d52(1 - g_CurrentTurnPhase,local_70),
             (DAT_006a4920 & 2) != 0)) {
            local_7c = local_70;
            local_c = 1 - g_CurrentTurnPhase;
            local_8 = local_8 + 1;
            DAT_006a4920 = DAT_006a4920 & 0xfffffffd;
            if (iVar4 == 2) {
              local_28 = local_28 | 4;
            }
            else {
              local_28 = local_28 | 2;
            }
            break;
          }
        }
      }
      if ((local_28 & 2) != 0) {
        local_18 = 1;
      }
    }
  }
  if (((local_18 != 0) || (local_10 != 0)) || (local_8 != 0)) {
    strcpy(&g_OverworldWorldState,s_Triggered_effects_____0052213c);
    if (((DAT_0063edc8 & 0x10) == 0) || (DAT_006b2d3c != -1)) {
      if ((DAT_0063edc8 & 0x20) != 0) {
        strcpy(&g_OverworldWorldState,s_Interrupts_____00522168);
      }
    }
    else {
      strcpy(&g_OverworldWorldState,s_Fast_Effects_____00522154);
    }
    if (g_PlayerManaPool != -1) {
      strcpy(&g_OverworldWorldState,s_Triggered_effects_____00522178);
    }
    strcat(&g_OverworldWorldState,local_68);
    if ((DAT_0063ee1c == 0) || ((local_28 & 2) != 0)) {
      if (((((local_10 == 0) && ((DAT_006808b0 == 0 || (g_PlayerManaPool != -1)))) &&
           ((local_18 == 0 || (g_PlayerManaPool == -1)))) &&
          ((DAT_00525850 == 0 || ((local_28 & 6) == 0)))) &&
         (((local_8 <= (int)(uint)((local_28 & 2) == 0) && ((local_28 & 4) == 0)) ||
          ((((local_78 == 0 && (iVar4 = FUN_00505c74(), iVar4 != 0)) || (g_PlayerManaPool == 0xd6))
           || ((local_7c != -1 && (DAT_00627a10 == DAT_0063edc4)))))))) {
        local_84 = local_7c;
        local_14 = local_c;
        _DAT_0063eed8 = 1;
      }
      else {
        DAT_007006d0 = 1;
        DAT_00627a84 = -1;
        DAT_0063edc4 = 0;
        bVar1 = false;
        while (!bVar1) {
          if (g_IsAiThinking == 1) {
            local_84 = local_7c;
            bVar1 = true;
            DAT_0063ee8c = -1;
          }
          else {
            local_84 = Duel_LogActionStatusBanner
                                 (g_CurrentTurnPhase,-1,g_CurrentTurnPhase,0xff,0,
                                  &g_OverworldWorldState,2);
            local_14 = _DAT_0063ee20;
            if (-1 < local_84) {
              *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) =
                   *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) | 2;
            }
          }
          if (DAT_0063ee8c == -3) {
            bVar1 = false;
          }
          else if (DAT_0063ee8c == -2) {
            bVar1 = true;
            local_84 = -1;
            DAT_00695f0c = DAT_00695f0c & 0xfffffffd;
            if (g_PlayerManaPool != -1) {
              DAT_00627a84 = g_DefendingPlayer;
              DAT_00627a88 = g_ScWillyScore;
              DAT_0063ee8c = 0;
            }
            if (local_8 != 0) {
              DAT_0063edc4 = DAT_00627a10;
              DAT_0063ee1c = 1;
              _DAT_0063eed8 = 1;
              DAT_00627a88 = -1;
              DAT_00627a84 = -1;
            }
          }
          else if (DAT_0063ee8c == 0) {
            if ((local_14 == -1) || (local_84 == -1)) {
              if ((local_14 != -1) && (local_84 == -1)) {
                bVar1 = false;
              }
            }
            else {
              bVar1 = true;
            }
          }
        }
      }
    }
    else {
      local_84 = local_7c;
      local_14 = local_c;
      if (local_7c != -1) {
        _DAT_0063eed8 = 1;
      }
    }
    g_OverworldWorldState = 0;
    if ((local_84 != -1) &&
       ((g_CurrentTurnPhase == local_14 ||
        (((((&g_CardSlot_Flags)[local_84 * 0x120 + local_14 * 0x5b20] & 2) != 0 &&
          (iVar4 = Pic_Subsystem_004485d6(local_14,local_84,0x7d,g_CurrentTurnPhase), iVar4 != 0))
         || (DAT_00695ec4 == 4)))))) {
      local_1c = *(int *)(&g_CardSlot_CardId + local_84 * 0x120 + local_14 * 0x5b20);
      iVar4 = Pic_Subsystem_00446d52(local_14,local_84);
      if (iVar4 == 0) {
        iVar4 = FUN_005063f6(local_14,local_84);
        if (iVar4 != 0) {
          FUN_005064e9(local_14,local_84);
        }
      }
      else {
        if (((&g_CardSlot_Flags)[local_84 * 0x120 + local_14 * 0x5b20] & 2) == 0) {
          FUN_0046fe86(local_14,local_84);
          if ((&g_MasterCardColorTable)[local_1c * 0x34] == ' ') {
            DAT_0063edc8 = DAT_0063ee70 & 0x20;
          }
          iVar4 = FUN_0040a1d2(3);
          if (iVar4 == 0) {
            Pic_Subsystem_0045275a(s_I_knew_that_was_coming__00522190);
          }
        }
        else {
          iVar4 = Pic_Subsystem_004485d6(local_14,local_84,0x7d,g_CurrentTurnPhase);
          if (iVar4 == 0) {
            if (((*(int *)(&DAT_006a5f80 + local_84 * 0x120 + local_14 * 0x5b20) == g_PlayerManaPool
                 ) && (DAT_00695f18 != (code *)0x0)) && (g_PlayerManaPool != -1)) {
              if (DAT_00695f18 != (code *)0x0) {
                (*DAT_00695f18)(local_14,local_84);
              }
            }
            else {
              iVar4 = FUN_0047103b(local_14,local_84);
              if (((iVar4 != 0) && (FUN_00471971(local_14,local_84), g_ActivePlayer != 1)) &&
                 (g_IsAiThinking != 1)) {
                Magic_UpkeepPhase(0x1c);
              }
              g_ActivePlayer = 0;
            }
          }
          else {
            FUN_00471aba(local_14,local_84,g_CurrentTurnPhase);
          }
        }
        Ai_Subsystem_004cc9c5(0,0xff);
        local_20 = local_20 | 2;
      }
      local_20 = local_20 | 2;
    }
    DAT_0068a67c = 1;
    _DAT_0063eed8 = 0;
  }
LAB_00446898:
  if (local_20 == 0) {
    DAT_0063edc8 = DAT_0063ee70 & 0x30;
  }
  DAT_0063ee10 = 0;
  DAT_0063edc0 = uVar2;
  g_PlayerHandCardCount = uVar3;
  DAT_00627a10 = DAT_00627a10 + -1;
  return local_20;
}


