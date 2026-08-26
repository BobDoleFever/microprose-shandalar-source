/*
 * Decompiled function: Card_TitaniasSong_ClearFlags
 * Entry Point: 004d3fa1
 * Size: 248 bytes
 */
#include "magic.h"


undefined4 Card_TitaniasSong_ClearFlags(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x21) && (g_ScWillyScore == 0x1a)) &&
      (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0)) &&
     (((char)(&g_CardSlot_Toughness)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20]
       == arg_1 &&
      (*(int *)(&g_CardSlot_OriginalCardId +
               g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == -1)))) {
    (&g_CardSlot_Toughness)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] =
         (undefined1)arg_1;
    *(int *)(&g_CardSlot_OriginalCardId +
            g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) = arg_2;
  }
  return 0;
}


