/*
 * Decompiled function: FUN_0041a782
 * Entry Point: 0041a782
 * Size: 1594 bytes
 */
#include "magic.h"


undefined4 FUN_0041a782(int arg_1,int arg_2,int arg_3)

{
  int arg_2_00;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_18;
  int local_14;
  int local_8;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (DAT_006b2d3c == -1) {
      uVar2 = 0;
    }
    else if ((g_ActivePlayerPriority == arg_1) && (iVar1 = FUN_0040d949(arg_1,7,2), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      iVar1 = Rules_ParseFilter_0040360b
                        (DAT_006b2d3c,DAT_006b2d2c,(char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,
                         0xffffffff,0xffffffff,2,0,0);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 99;
      }
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if (DAT_006b2d3c == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_006b2d3c;
        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_006b2d2c;
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             g_TurnCounter;
      }
    }
    if (arg_3 == 0x71) {
      iVar1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),
                         (char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,2,0,0);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        iVar1 = *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20);
        arg_2_00 = *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20);
        if (iVar1 == g_CurrentTurnPhase) {
          Magic_CombatPhase(arg_1,arg_2,0x7e,0,0);
          local_8 = Ai_CalcManaRequirement_004ba890
                              (iVar1,0,*(int *)(&g_CardSlot_ConvertedManaCost +
                                               arg_2 * 0x120 + arg_1 * 0x5b20));
          Magic_DiscardToHandSize();
          g_ActivePlayer = 0;
        }
        else {
          iVar3 = FUN_0040d949(iVar1,7,1);
          if (iVar3 == 0) {
            local_8 = 0;
          }
          else {
            local_8 = Ai_CalcManaRequirement_004ba890
                                (iVar1,0,*(int *)(&g_CardSlot_ConvertedManaCost +
                                                 arg_2 * 0x120 + arg_1 * 0x5b20));
          }
        }
        if (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)) {
          local_14 = 0;
          while ((local_14 < 7 &&
                 (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)
                 ))) {
            for (; (0 < *(int *)(&DAT_0063ee90 + local_14 * 4 + iVar1 * 0x20) &&
                   (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost +
                                      arg_2 * 0x120 + arg_1 * 0x5b20))); local_8 = local_8 + 1) {
              *(int *)(&DAT_0063ee90 + local_14 * 4 + iVar1 * 0x20) =
                   *(int *)(&DAT_0063ee90 + local_14 * 4 + iVar1 * 0x20) + -1;
              *(int *)(&DAT_0063eeac + iVar1 * 0x20) = *(int *)(&DAT_0063eeac + iVar1 * 0x20) + -1;
            }
            local_14 = local_14 + 1;
          }
          local_18 = 0;
          while ((local_18 < (int)(&g_PlayerActiveCardCount)[iVar1] &&
                 (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)
                 ))) {
            iVar3 = FUN_00471c32(iVar1,local_18);
            if (((iVar3 != 0) &&
                ((((&g_MasterCardColorTable)
                   [*(int *)(&g_CardSlot_CardId + local_18 * 0x120 + iVar1 * 0x5b20) * 0x34] & 1) !=
                  0 && (((&g_CardSlot_Flags)[local_18 * 0x120 + iVar1 * 0x5b20] & 0x10) == 0)))) &&
               ((((&DAT_006a5f3e)[local_18 * 0x120 + iVar1 * 0x5b20] & 3) == 0 ||
                (((&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + local_18 * 0x120 + iVar1 * 0x5b20) * 0x34] & 2) ==
                 0)))) {
              Ai_Subsystem_004bd23f(iVar1,local_18);
              local_14 = 0;
              while ((local_14 < 7 &&
                     (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost +
                                        arg_2 * 0x120 + arg_1 * 0x5b20)))) {
                for (; (0 < *(int *)(&DAT_0063ee90 + local_14 * 4 + iVar1 * 0x20) &&
                       (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost +
                                          arg_2 * 0x120 + arg_1 * 0x5b20))); local_8 = local_8 + 1)
                {
                  *(int *)(&DAT_0063ee90 + local_14 * 4 + iVar1 * 0x20) =
                       *(int *)(&DAT_0063ee90 + local_14 * 4 + iVar1 * 0x20) + -1;
                  *(int *)(&DAT_0063eeac + iVar1 * 0x20) =
                       *(int *)(&DAT_0063eeac + iVar1 * 0x20) + -1;
                }
                local_14 = local_14 + 1;
              }
            }
            local_18 = local_18 + 1;
          }
        }
        if (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)) {
          Pic_Subsystem_0044867e(iVar1,arg_2_00,1);
        }
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


