/*
 * Decompiled function: Card_ChaosLace_ModifyAttributes
 * Entry Point: 004d109a
 * Size: 3109 bytes
 */
#include "magic.h"


undefined4 Card_ChaosLace_ModifyAttributes(int arg_1,int arg_2,int arg_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *str_2;
  int local_10;
  
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    bVar1 = FUN_0040a1d2(5);
    *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 0x800 << (bVar1 & 0x1f);
  }
  if (arg_3 == 0x71) {
    *(uint *)(&g_CardSlot_Abilities2 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities2 + arg_2 * 0x120 + arg_1 * 0x5b20) |
         *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  if (arg_3 == 0x73) {
    iVar2 = FUN_0040d949(arg_1,5,2);
    if (iVar2 == 0) {
      iVar2 = FUN_0040d949(arg_1,7,1);
      if ((iVar2 == 0) || (((&DAT_006a5f61)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = FUN_0040d949(arg_1,7,1);
      iVar4 = FUN_0040d949(arg_1,5,2);
      *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffe;
      if ((iVar4 != 0) ||
         ((iVar2 != 0 && (((&DAT_006a5f61)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0)))) {
        if (iVar4 == 0) {
          strcpy(&g_OverworldWorldState,s__Add_random_power__0052e8b0);
        }
        else {
          strcpy(&g_OverworldWorldState,s_Add_random_power__0052e89c);
        }
        if ((iVar2 == 0) || (((&DAT_006a5f61)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) {
          strcat(&g_OverworldWorldState,s__Gain_first_strike__0052e8dc);
        }
        else {
          strcat(&g_OverworldWorldState,s_Gain_first_strike__0052e8c4);
        }
        strcat(&g_OverworldWorldState,s_Cancel__0052e8f4);
        if ((DAT_006a5f20 == 0) ||
           ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 8) == 0 &&
            ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) == 0 ||
             (((&DAT_006a5f3d)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) == 0)))))) {
          if (iVar4 == 0) {
            if ((iVar2 == 0) || (((&DAT_006a5f61)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) {
              local_10 = 2;
            }
            else {
              local_10 = 1;
            }
          }
          else {
            local_10 = 0;
          }
        }
        else if ((iVar2 == 0) || (((&DAT_006a5f61)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) {
          if (iVar4 == 0) {
            local_10 = 2;
          }
          else {
            local_10 = 0;
          }
        }
        else {
          local_10 = 1;
        }
        iVar2 = Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&g_OverworldWorldState,local_10);
        if (iVar2 == 0) {
          if ((iVar4 != 0) && (Ai_CalcManaRequirement_004ba890(arg_1,5,2), g_ActivePlayer != 1)) {
            *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
            *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
            (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
            if (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
              *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) |
                   0x80000;
            }
          }
        }
        else if (iVar2 == 1) {
          Ai_CalcManaRequirement_004ba890(arg_1,0,1);
          if (g_ActivePlayer != 1) {
            *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
            *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
            (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
            *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
          }
        }
        else if (iVar2 == 2) {
          g_ActivePlayer = 1;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) ==
          -1) {
        g_ActivePlayer = 1;
      }
      else if (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0) {
        uVar5 = FUN_0040a1d2(3);
        *(uint *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (uVar5 & 0xff);
        strcpy(&g_OverworldWorldState,s_Power_increased_by_0052e900);
        str_2 = _itoa(uVar5,&DAT_00565998,10);
        strcat(&g_OverworldWorldState,str_2);
        Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&g_OverworldWorldState,0);
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x2e);
        }
        if ((uVar5 != 0) &&
           (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
              *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 8) !=
            0)) {
          *(uint *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20)
               & 0xfff7ffff;
          iVar2 = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,g_DialogPromptHwnd,
                               g_DuelArenaHwnd);
          if (iVar2 != -1) {
            *(short *)(&DAT_006a5f48 + iVar2 * 0x120 + arg_1 * 0x5b20) = (short)uVar5;
            *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x80000
            ;
            *(undefined4 *)(&g_CardSlot_TargetSlot + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
          }
        }
      }
      else if (((&DAT_006a5f61)
                [*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 1)
               == 0) {
        *(uint *)(&g_CardSlot_TargetSlot +
                 *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint *)(&g_CardSlot_TargetSlot +
                      *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
             0x1ff800;
        *(uint *)(&g_CardSlot_TargetSlot +
                 *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint *)(&g_CardSlot_TargetSlot +
                      *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) |
             0x100;
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        iVar2 = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,g_DialogPromptHwnd,
                             g_DuelArenaHwnd);
        if (iVar2 != -1) {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + arg_1 * 0x5b20) = 0x100;
          *(undefined4 *)(&g_CardSlot_Abilities2 + iVar2 * 0x120 + arg_1 * 0x5b20) = 0;
          *(undefined4 *)(&g_CardSlot_TargetSlot + iVar2 * 0x120 + arg_1 * 0x5b20) = 2;
        }
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x2e);
        }
      }
    }
    if ((((arg_3 == 0x34) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX))
       && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0)) {
      g_ActivePalette =
           g_ActivePalette |
           *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x1ff800;
      uVar5 = g_ActivePalette;
      iVar2 = FUN_00473cc5((byte)((*(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20
                                            ) & 0x1ff800) >> 10));
      Card_RockHydra_UpdateStatsFromHeads(arg_1,arg_2,iVar2);
      g_ActivePalette = uVar5;
    }
    if (((arg_3 == 0x8c) && (arg_2 == g_OverworldMapGrid)) &&
       ((arg_1 == g_OverworldPlayerCoordX && (iVar2 = FUN_0040d949(arg_1,7,1), iVar2 != 0)))) {
      DAT_006ff1ac = DAT_006ff1ac | 0x100;
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffeff;
    }
    uVar3 = 0;
  }
  return uVar3;
}


