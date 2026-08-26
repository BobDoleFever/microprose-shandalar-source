/*
 * Decompiled function: Card_ErgRaiders_ClearTurnAttack
 * Entry Point: 004de492
 * Size: 939 bytes
 */
#include "magic.h"


undefined4 Card_ErgRaiders_ClearTurnAttack(int arg_1,int arg_2,int arg_3)

{
  int arg_3_00;
  int local_8;
  
  if ((((arg_3 == 0x6e) &&
       (*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
        == DAT_006ff2e0)) &&
      ((char)(&g_CardSlot_DamageReceived)
             [g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] == arg_1)) &&
     ((*(int *)(&g_CardSlot_TypeFlags +
               g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == arg_2 &&
      (*(int *)(&g_CardSlot_ConvertedManaCost +
               g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) != 0)))) {
    (&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (undefined1)g_OverworldPlayerCoordX;
    *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) = g_OverworldMapGrid;
  }
  if (((g_PlayerManaPool == 0xd7) && (g_OverworldMapGrid == arg_2)) &&
     ((g_OverworldPlayerCoordX == arg_1 &&
      (((&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1 &&
       (DAT_006a4b5c == arg_1)))))) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x7e) {
      local_8 = *(int *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20)
      ;
      if (*(int *)(&g_CardSlot_OriginalCardId +
                  *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) != -1
         ) {
        arg_3_00 = FUN_00473179((int)(char)(&g_CardSlot_Toughness)
                                           [*(int *)(&g_CardSlot_TypeFlags +
                                                    arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                            (char)(&g_CardSlot_DamageReceived)
                                                  [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20],
                                *(int *)(&g_CardSlot_OriginalCardId +
                                        *(int *)(&g_CardSlot_TypeFlags +
                                                arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                        (char)(&g_CardSlot_DamageReceived)
                                              [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20),0x33,
                                0xffffffff);
        local_8 = FUN_0040a305(*(int *)(&g_CardSlot_ConvertedManaCost +
                                       *(int *)(&g_CardSlot_TypeFlags +
                                               arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                       (char)(&g_CardSlot_DamageReceived)
                                             [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20),0,arg_3_00);
      }
      (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] + local_8;
      (&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
    }
  }
  return 0;
}


