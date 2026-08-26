/*
 * Decompiled function: Card_AlabasterPotion_HealOrPrevent
 * Entry Point: 004ddcf4
 * Size: 349 bytes
 */
#include "magic.h"


undefined4 Card_AlabasterPotion_HealOrPrevent(int arg_1,int arg_2,int arg_3)

{
  int local_8;
  
  if (((((g_PlayerManaPool == 0xd3) && (g_OverworldMapGrid == arg_2)) &&
       (g_OverworldPlayerCoordX == arg_1)) &&
      ((DAT_006a4b5c == arg_1 && (g_DefendingPlayer == arg_1)))) &&
     ((g_OverworldPlayerCoordX == arg_1 &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) * 0x34] & 4) !=
       0)))) {
    if (arg_3 == 0x7d) {
      if (g_CurrentTurnPhase == arg_1) {
        g_ActivePalette = g_ActivePalette | 1;
      }
      else {
        local_8 = 0;
        while ((local_8 < 500 && (*(int *)(&DAT_0069e730 + local_8 * 4 + arg_1 * 2000) != -1))) {
          local_8 = local_8 + 1;
        }
        if (((int)(&DAT_006b3008)[arg_1] < 8) && (5 < local_8)) {
          g_ActivePalette = g_ActivePalette | 2;
        }
        else {
          g_ActivePalette = g_ActivePalette | 1;
        }
      }
    }
    if (arg_3 == 0x7e) {
      FUN_0046f5d1(arg_1);
    }
  }
  return 0;
}


