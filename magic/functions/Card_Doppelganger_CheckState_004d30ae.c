/*
 * Decompiled function: Card_Doppelganger_CheckState
 * Entry Point: 004d30ae
 * Size: 150 bytes
 */
#include "magic.h"


undefined4 Card_Doppelganger_CheckState(int arg_1,int arg_2,int arg_3)

{
  Card_Doppelganger_SyncAbilities(arg_1,arg_2);
  if ((((arg_3 == 0x78) && (DAT_006b2d5c == arg_2)) && (DAT_007006c8 == arg_1)) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
        * 0x34] & 0x40) != 0)) {
    g_ActivePalette = 1;
  }
  return 0;
}


