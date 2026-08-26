/*
 * Decompiled function: FUN_0041459d
 * Entry Point: 0041459d
 * Size: 519 bytes
 */
#include "magic.h"


undefined4 FUN_0041459d(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  if ((((g_PlayerManaPool == 0xd7) && (g_OverworldMapGrid == arg_2)) &&
      (arg_1 == g_OverworldPlayerCoordX)) && (arg_1 == DAT_006a4b5c)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x7e) {
      iVar1 = Pic_Subsystem_0045268f(0x44);
      if (*(int *)(&g_ActiveCardsInPlay + arg_2 * 0x120 + arg_1 * 0x5b20) == iVar1) {
        local_8 = 0;
        for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
          for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_10];
              local_c = local_c + 1) {
            if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_10 * 0x5b20) == DAT_006ff2e0
                 ) && ((&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
                       (&g_CardSlot_DamageReceived)[local_c * 0x120 + local_10 * 0x5b20])) &&
               (*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) ==
                *(int *)(&g_CardSlot_TypeFlags + local_c * 0x120 + local_10 * 0x5b20))) {
              local_8 = local_8 + *(int *)(&g_CardSlot_ConvertedManaCost +
                                          local_c * 0x120 + local_10 * 0x5b20);
            }
          }
        }
        iVar1 = *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
        if (local_8 <= *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)) {
          iVar1 = local_8;
        }
        (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] + iVar1;
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,4);
    }
  }
  return 0;
}


