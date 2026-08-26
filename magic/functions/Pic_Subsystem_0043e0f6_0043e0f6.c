/*
 * Decompiled function: Pic_Subsystem_0043e0f6
 * Entry Point: 0043e0f6
 * Size: 1697 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043e0f6(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int local_2a8;
  int local_2a4;
  int local_2a0;
  int local_29c;
  int local_298;
  int local_294;
  int local_290;
  int local_28c;
  int aiStack_288 [160];
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
    }
    if (arg_3 == 0x73) {
      if (((g_ScWillyScore == 4) &&
          (((&g_CardSlot_ConvertedManaCost)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0)) &&
         (g_DefendingPlayer == DAT_0063edc0)) {
        *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x101;
        DAT_006a4920 = DAT_006a4920 | 3;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if (((arg_3 == 4) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (arg_3 == 0x86) {
        if (g_IsAiThinking == 1) {
          return 0;
        }
        for (local_290 = 0; local_290 < 2; local_290 = local_290 + 1) {
          local_294 = 0;
          for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_290];
              local_8 = local_8 + 1) {
            if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_290 * 0x5b20) != -1) &&
                (((&g_CardSlot_Flags)[local_8 * 0x120 + local_290 * 0x5b20] & 2) != 0)) &&
               ((((&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_290 * 0x5b20) * 0x34] &
                 0x43) != 0 &&
                (iVar4 = local_8 * 0x120, uVar2 = SpellChain_ProcessTriggerEvent(arg_1,arg_2),
                (*(uint *)(&g_CardSlot_Abilities2 + iVar4 + local_290 * 0x5b20) & uVar2) == 0)))) {
              aiStack_288[local_294 + local_290 * 0x50] = local_8;
              local_294 = local_294 + 1;
            }
          }
          if (g_CurrentTurnPhase == local_290) {
            local_2a8 = local_294;
          }
          else {
            local_2a4 = local_294;
          }
        }
        if (g_DefendingPlayer == g_CurrentTurnPhase) {
          if (local_2a8 < 1) {
            g_ActivePlayer = 1;
          }
          else {
            iVar4 = FUN_0040a1d2(local_2a8);
            local_298 = aiStack_288[iVar4 + g_CurrentTurnPhase * 0x50];
            local_28c = 0;
            local_29c = 0;
            local_294 = FUN_0040a1d2(local_2a4);
            while ((local_28c == 0 && (local_29c < local_2a4))) {
              local_2a0 = aiStack_288[local_294 + g_ActivePlayerPriority * 0x50];
              if (((&g_MasterCardColorTable)
                   [*(int *)(&g_CardSlot_CardId +
                            g_ActivePlayerPriority * 0x5b20 + local_2a0 * 0x120) * 0x34] &
                  (&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + local_298 * 0x120 + g_CurrentTurnPhase * 0x5b20) *
                   0x34]) == 0) {
                local_294 = (local_294 + 1) % local_2a4;
                local_29c = local_29c + 1;
              }
              else {
                local_28c = 1;
              }
            }
            if (local_28c != 1) {
              g_ActivePlayer = 1;
            }
          }
        }
        else if (local_2a4 < 1) {
          g_ActivePlayer = 1;
        }
        else {
          iVar4 = FUN_0040a1d2(local_2a4);
          local_2a0 = aiStack_288[iVar4 + g_ActivePlayerPriority * 0x50];
          local_28c = 0;
          local_29c = 0;
          local_294 = FUN_0040a1d2(local_2a8);
          while ((local_28c == 0 && (local_29c < local_2a8))) {
            local_298 = aiStack_288[local_294 + g_CurrentTurnPhase * 0x50];
            if (((&g_MasterCardColorTable)
                 [*(int *)(&g_CardSlot_CardId + g_ActivePlayerPriority * 0x5b20 + local_2a0 * 0x120)
                  * 0x34] &
                (&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + local_298 * 0x120 + g_CurrentTurnPhase * 0x5b20) *
                 0x34]) == 0) {
              local_294 = (local_294 + 1) % local_2a8;
              local_29c = local_29c + 1;
            }
            else {
              local_28c = 1;
            }
          }
          if (local_28c != 1) {
            g_ActivePlayer = 1;
          }
        }
        if ((local_28c == 1) && (g_ActivePlayer != 1)) {
          strcpy(&g_OverworldWorldState,s_is_swapping_005218b0);
          pcVar3 = (char *)Ai_Subsystem_004b8e4d(g_CurrentTurnPhase,local_298);
          strcat(&g_OverworldWorldState,pcVar3);
          strcat(&g_OverworldWorldState,s_for_005218c0);
          pcVar3 = (char *)Ai_Subsystem_004b8e4d(g_ActivePlayerPriority,local_2a0);
          strcat(&g_OverworldWorldState,pcVar3);
          Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&g_OverworldWorldState,0);
          Pic_Subsystem_0042ce63(g_CurrentTurnPhase,local_298,g_ActivePlayerPriority,local_2a0);
        }
        if (g_ActivePlayer != 1) {
          Magic_UpkeepPhase(0x2a);
        }
      }
      if (arg_3 == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffe;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


