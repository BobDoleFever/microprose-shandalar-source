/*
 * Decompiled function: Card_AliFromCairo_ResetState
 * Entry Point: 004d4d1f
 * Size: 596 bytes
 */
#include "magic.h"


undefined4 Card_AliFromCairo_ResetState(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x80) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) &&
      ((char)(&g_CardSlot_Toughness)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20]
       == arg_1)) &&
     ((*(int *)(&g_CardSlot_OriginalCardId +
               g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == arg_2 &&
      (0 < *(short *)(&g_CardSlot_Power + arg_2 * 0x120 + arg_1 * 0x5b20))))) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  if (((g_PlayerManaPool == 0xd7) && (arg_2 == g_OverworldMapGrid)) &&
     ((arg_1 == g_OverworldPlayerCoordX &&
      (0 < *(short *)(&g_CardSlot_Power + arg_2 * 0x120 + arg_1 * 0x5b20))))) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  if (((((g_PlayerManaPool == 0xcd) || (arg_3 == 199)) && (arg_2 == g_OverworldMapGrid)) &&
      ((arg_1 == g_OverworldPlayerCoordX &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)))) &&
     (DAT_006a4b5c == arg_1)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      Card_AddCounters(arg_1,arg_2,1);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
  }
  return 0;
}


