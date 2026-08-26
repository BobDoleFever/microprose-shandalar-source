/*
 * Decompiled function: Minit_Subsystem_00464fcd
 * Entry Point: 00464fcd
 * Size: 408 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00464fcd(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x82) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    *(uint *)(&DAT_006a6038 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006a6038 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffc;
  }
  if ((((arg_3 == 0x84) && (g_OverworldMapGrid == arg_2)) &&
      ((g_OverworldPlayerCoordX == arg_1 &&
       ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0 &&
        (g_DefendingPlayer == arg_1)))))) && (DAT_0063edc0 == arg_1)) {
    *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    (&DAT_006a603c)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006a603c)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\t';
  }
  if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    (&DAT_006a603c)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006a603c)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\t';
  }
  return 0;
}


