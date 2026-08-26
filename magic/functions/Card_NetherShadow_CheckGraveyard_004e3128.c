/*
 * Decompiled function: Card_NetherShadow_CheckGraveyard
 * Entry Point: 004e3128
 * Size: 93 bytes
 */
#include "magic.h"


undefined4 Card_NetherShadow_CheckGraveyard(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x77) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    (&DAT_006a5f50)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] = 4;
  }
  return 0;
}


