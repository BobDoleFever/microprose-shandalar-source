/*
 * Decompiled function: Minit_Subsystem_0045a789
 * Entry Point: 0045a789
 * Size: 156 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045a789(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x22) || (arg_3 == 199)) && (g_OverworldMapGrid == arg_2)) &&
     (g_OverworldPlayerCoordX == arg_1)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  if (((arg_3 == 0x34) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    g_ActivePalette = g_ActivePalette | 0x20000;
  }
  return 0;
}


