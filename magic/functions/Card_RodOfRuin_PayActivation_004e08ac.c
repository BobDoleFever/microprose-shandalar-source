/*
 * Decompiled function: Card_RodOfRuin_PayActivation
 * Entry Point: 004e08ac
 * Size: 175 bytes
 */
#include "magic.h"


undefined4 Card_RodOfRuin_PayActivation(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 2) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    g_ActivePalette = g_ActivePalette | 2;
  }
  if (((arg_3 == 4) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    iVar1 = CardTarget_HasValidPlayerOrCreatureTarget(arg_1);
    if (iVar1 == 0) {
      *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
      Mem_AllocOrFree_0041df33(arg_1,2,arg_1,arg_2);
    }
  }
  return 0;
}


