/*
 * Decompiled function: Card_HealingSalve_DamagePrevention
 * Entry Point: 004dde51
 * Size: 169 bytes
 */
#include "magic.h"


undefined4 Card_HealingSalve_DamagePrevention(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x6c) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20
                 ) * 0x34] & 0x40) != 0)) && (g_OverworldPlayerCoordX != arg_1)) {
    *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
    *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
  }
  return 0;
}


