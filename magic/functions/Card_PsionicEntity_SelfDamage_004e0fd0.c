/*
 * Decompiled function: Card_PsionicEntity_SelfDamage
 * Entry Point: 004e0fd0
 * Size: 382 bytes
 */
#include "magic.h"


undefined4 Card_PsionicEntity_SelfDamage(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x77) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20
                 ) * 0x34] & 2) != 0)) && (g_ActivePalette < 1)) {
    *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) +
         (short)*(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) +
         (short)*(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}


