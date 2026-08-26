/*
 * Decompiled function: Card_BronzeTablets_AnteSwap
 * Entry Point: 004d212c
 * Size: 1247 bytes
 */
#include "magic.h"


void Card_BronzeTablets_AnteSwap(int arg_1,int arg_2,int arg_3)

{
  int arg_4;
  undefined4 uVar1;
  int iVar2;
  int local_10;
  
  if (arg_3 != 0x73) {
    if (arg_3 == 0x6d) {
      *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) = 1 - arg_1;
      uVar1 = Ai_Subsystem_004cc56d
                        (*(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20),arg_1,
                         arg_2,-1,-1,s_Swap_cards__Lose_10_life__Conced_0052e924,0);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = uVar1;
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      arg_4 = *(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20);
      iVar2 = *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      if (iVar2 == 0) {
        *(uint *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) ^
             0x1000;
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0xf);
        }
        Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,3);
        if (arg_1 == g_CurrentTurnPhase) {
          Pic_Subsystem_0045200d
                    (*(uint *)(&g_CardSlot_CardId +
                              *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) *
                              0x120 + *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20
                                              ) * 0x5b20));
        }
        else {
          Pic_Subsystem_00451e40
                    (*(uint *)(&g_CardSlot_CardId +
                              *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) *
                              0x120 + *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20
                                              ) * 0x5b20));
        }
        *(undefined4 *)
         (&g_CardSlot_CardId +
         *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) = 0xffffffff;
        local_10 = 0;
        do {
          do {
            iVar2 = FUN_0040a1d2((&g_PlayerActiveCardCount)[arg_4]);
          } while (*(int *)(&g_CardSlot_CardId + iVar2 * 0x120 + arg_4 * 0x5b20) == -1);
        } while ((((&g_CardSlot_Flags)[iVar2 * 0x120 + arg_4 * 0x5b20] & 2) != 0) &&
                (local_10 = local_10 + 1, local_10 < 999));
        if (local_10 < 999) {
          Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,arg_4,iVar2,s_randomly_chooses____0052e950,0);
          *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg_4 * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg_4 * 0x5b20) ^ 0x1000;
          Pic_Subsystem_0044913a(arg_4,iVar2);
          if (arg_1 == g_CurrentTurnPhase) {
            Pic_Subsystem_00451e40(*(uint *)(&g_CardSlot_CardId + iVar2 * 0x120 + arg_4 * 0x5b20));
          }
          else {
            Pic_Subsystem_0045200d(*(uint *)(&g_CardSlot_CardId + iVar2 * 0x120 + arg_4 * 0x5b20));
          }
          *(undefined4 *)(&g_CardSlot_CardId + iVar2 * 0x120 + arg_4 * 0x5b20) = 0xffffffff;
        }
      }
      else if (iVar2 == 1) {
        (&g_PlayerCreatureCount)[arg_4] = (&g_PlayerCreatureCount)[arg_4] + -10;
        Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
      }
      else if (iVar2 == 2) {
        (&g_PlayerCreatureCount)[arg_4] = 0xffffff9d;
        Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
      }
    }
  }
  return;
}


