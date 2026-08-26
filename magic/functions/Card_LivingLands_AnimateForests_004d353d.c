/*
 * Decompiled function: Card_LivingLands_AnimateForests
 * Entry Point: 004d353d
 * Size: 528 bytes
 */
#include "magic.h"


undefined4 Card_LivingLands_AnimateForests(int arg_1,int arg_2,int arg_3)

{
  if (((((arg_3 == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20
                 ) == DAT_006ff2e0)) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == -1)) &&
      (((char)(&g_CardSlot_DamageReceived)
              [g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] == arg_1 &&
       (*(int *)(&g_CardSlot_TypeFlags +
                g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == arg_2)))) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost +
              g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) != 0)) {
    (&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (undefined1)g_OverworldPlayerCoordX;
    *(int *)(&g_CardSlot_TypeFlags + arg_1 * 0x5b20 + arg_2 * 0x120) = g_OverworldMapGrid;
  }
  if (((g_PlayerManaPool == 0xd7) && (arg_2 == g_OverworldMapGrid)) &&
     ((arg_1 == g_OverworldPlayerCoordX &&
      (((&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1 &&
       (arg_1 == DAT_006a4b5c)))))) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x7e) {
      (&DAT_00696870)[(char)(&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120]] =
           (&DAT_00696870)[(char)(&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120]] + 2;
      (&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120] = 0xff;
      FUN_005062b1();
    }
  }
  return 0;
}


