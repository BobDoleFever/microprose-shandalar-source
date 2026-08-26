/*
 * Decompiled function: Card_LordOfAtlantis_IslandwalkTrigger
 * Entry Point: 004e1e6c
 * Size: 161 bytes
 */
#include "magic.h"


undefined4 Card_LordOfAtlantis_IslandwalkTrigger(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 2) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    g_ActivePalette = g_ActivePalette | 2;
  }
  if (((((arg_3 == 4) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) ||
      (arg_3 == 199)) &&
     ((int)(&g_PlayerCreatureCount)[arg_1] < (int)(&g_PlayerCreatureCount)[1 - arg_1])) {
    Pic_Subsystem_0042ca53(arg_1,arg_2);
  }
  return 0;
}


