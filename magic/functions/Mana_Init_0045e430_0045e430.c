/*
 * Decompiled function: Mana_Init_0045e430
 * Entry Point: 0045e430
 * Size: 1569 bytes
 */
#include "magic.h"


undefined4 Mana_Init_0045e430(int x,int y,int width,int height)

{
  undefined4 uVar1;
  int iVar2;
  int local_78;
  char local_74 [100];
  int local_10;
  int local_c;
  int local_8;
  
  if (width == 0x73) {
    if (((((&DAT_006a5f3e)[y * 0x120 + x * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] &
         2) == 0)) && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if ((width == 0x6d) && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      local_8 = Card_GetCounters(x,y);
      if ((DAT_006ff4ac == 0) && (iVar2 = FUN_0040d949(x,7,local_8 + 3), iVar2 != 0)) {
        strcpy(&g_OverworldWorldState,s_Tap_to_get_mana__005244e4);
        strcat(&g_OverworldWorldState,s_Charge_battery__add_counter___005244f8);
        strcat(&g_OverworldWorldState,s_Cancel__00524518);
        if ((g_ScWillyScore == 0x1f) && (1 - x == g_DefendingPlayer)) {
          local_10 = 1;
        }
        else {
          local_10 = 0;
        }
        local_c = Ai_Subsystem_004cc56d(x,x,y,-1,-1,&g_OverworldWorldState,local_10);
      }
      else {
        local_c = 0;
      }
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = 0;
      if (local_c == 0) {
        FUN_0040d875(x,height,1);
        local_8 = Card_GetCounters(x,y);
        if (local_8 != 0) {
          if (((x == 1) || (g_IsAiThinking == 1)) || (DAT_006fedc0 != 0)) {
            if (g_IsAiThinking == 1) {
              local_78 = FUN_0040a1d2(local_8 + 1);
              g_AiDecisionScore = local_78;
              Ai_EvaluateCreaturePower();
            }
            else {
              Ai_CalcCardAdvantage();
              local_78 = g_AiDecisionScore;
            }
          }
          else {
            sprintf(local_74,s__s_How_many_counters_do_you_wish_00524524,
                    *(undefined4 *)
                     (&DAT_006b3074 +
                     *(int *)(&g_MasterCardTypeTable +
                             *(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34) * 0x98),
                    local_8);
            local_78 = Ai_Subsystem_004cc8de(x,local_74,0);
          }
          if (local_78 == -1) {
            g_ActivePlayer = 1;
          }
          else {
            if (local_8 < local_78) {
              local_78 = local_8;
            }
            FUN_0040d901(x,height,local_78);
            Card_RemoveCounters(x,y,local_78);
          }
        }
        if (g_ActivePlayer == 1) {
          FUN_0040d8b7(x,height,1);
        }
        else {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = 0;
          *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
          DAT_006ff2d4 = height;
        }
      }
      else if (local_c == 1) {
        *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
        Ai_CalcManaRequirement_004ba890(x,0,2);
        if (g_ActivePlayer == 1) {
          *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) & 0xffffffef;
        }
        if (g_ActivePlayer != 1) {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = 1;
          DAT_006ff2d4 = -1;
        }
      }
      else if (local_c == 2) {
        g_ActivePlayer = 1;
      }
    }
    if ((width == 0x72) && (*(int *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) == 1))
    {
      Card_IncrementCounter(g_DialogPromptHwnd,g_DuelArenaHwnd);
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_SicknessState + y * 0x120 + x * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + y * 0x120 + x * 0x5b20) * 0x5b20) = 0;
    }
    if (((width == 0x7f) && (g_OverworldMapGrid == y)) &&
       ((g_OverworldPlayerCoordX == x && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)
        ))) {
      FUN_0040d7e9(x,height,1);
      iVar2 = Card_GetCounters(x,y);
      FUN_0040d7e9(x,height,iVar2);
    }
    if (((width == 0x8f) && (*(int *)(&DAT_0063eea4 + x * 0x20) != 0)) &&
       (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      g_ActivePalette = g_ActivePalette | 1;
    }
    if ((width == 199) && (g_ActivePlayerPriority == x)) {
      iVar2 = Card_GetCounters(x,y);
      g_SpellStackDepth = g_SpellStackDepth + iVar2 * 0xc;
    }
    uVar1 = 0;
  }
  return uVar1;
}


