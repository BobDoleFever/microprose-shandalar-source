/*
 * Decompiled function: Card_Leviathan_AttackTrigger
 * Entry Point: 004defc2
 * Size: 136 bytes
 */
#include "magic.h"


undefined4 Card_Leviathan_AttackTrigger(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 2) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    g_ActivePalette = g_ActivePalette | 2;
  }
  if ((((arg_3 == 4) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) ||
     (arg_3 == 199)) {
    Mem_AllocOrFree_0041df33(arg_1,1,arg_1,arg_2);
  }
  return 0;
}


