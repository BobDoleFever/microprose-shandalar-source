/*
 * Decompiled function: FUN_00414ac1
 * Entry Point: 00414ac1
 * Size: 723 bytes
 */
#include "magic.h"


undefined4 FUN_00414ac1(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (DAT_006b2d3c == -1) {
      uVar2 = 0;
    }
    else {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           g_TurnCounter;
      if ((((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20) * 0x34] &
           0x18) == 0) ||
         (iVar1 = Rules_ParseFilter_0040360b
                            (DAT_006b2d3c,DAT_006b2d2c,(char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,
                             0xffffffff,0xffffffff,2,0,0), iVar1 == 0)) {
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
      }
    }
    if (arg_3 == 0x71) {
      iVar1 = Pic_Subsystem_00451291
                        (arg_1,*(int *)(&g_CardSlot_CardId +
                                       *(int *)(&g_CardSlot_AttachedAura +
                                               arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                       *(int *)(&g_CardSlot_CombatTarget +
                                               arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20));
      if (iVar1 != -1) {
        (&DAT_006a5f4d)[iVar1 * 0x120 + arg_1 * 0x5b20] = 0x10;
        *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg_1 * 0x5b20) | 8;
        g_TurnCounter =
             *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
        g_PlayerHandCardCount = g_PlayerHandCardCount | 0x400;
        Pic_Subsystem_0042ac1f(arg_1,iVar1);
        g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffffbff;
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


