/*
 * Decompiled function: Card_Doppelganger_SyncAbilities
 * Entry Point: 004d2f6c
 * Size: 322 bytes
 */
#include "magic.h"


undefined4 Card_Doppelganger_SyncAbilities(int arg1,int arg2)

{
  if ((((*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20
                 ) == DAT_006ff2e0) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == arg2)) &&
      ((char)(&g_CardSlot_Toughness)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20]
       == arg1)) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TypeFlags +
                        g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_DamageReceived)
                      [g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] * 0x5b20) *
        0x34] & 0x40) != 0)) {
    *(undefined4 *)
     (&g_CardSlot_ConvertedManaCost + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
         = 0;
  }
  return 0;
}


