/*
 * Decompiled function: Card_DamagePrevention_ReduceDamage
 * Entry Point: 004ddf4b
 * Size: 77 bytes
 */
#include "magic.h"


undefined4 Card_DamagePrevention_ReduceDamage(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x34) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) &&
     (arg_1 == g_DefendingPlayer)) {
    g_ActivePalette = g_ActivePalette & 0xffffffdf;
  }
  return 0;
}


