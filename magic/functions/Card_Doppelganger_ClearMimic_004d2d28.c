/*
 * Decompiled function: Card_Doppelganger_ClearMimic
 * Entry Point: 004d2d28
 * Size: 258 bytes
 */
#include "magic.h"


undefined4 Card_Doppelganger_ClearMimic(int arg1,int arg2)

{
  if ((((*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20
                 ) == DAT_006ff2e0) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == arg2)) &&
      ((char)(&g_CardSlot_Toughness)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20]
       == arg1)) &&
     (*(int *)(&g_MasterCardTypeTable +
              *(int *)(&g_CardSlot_CardId +
                      g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) * 0x34) ==
      0x197)) {
    *(undefined4 *)
     (&g_CardSlot_ConvertedManaCost + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
         = 0;
  }
  return 0;
}


