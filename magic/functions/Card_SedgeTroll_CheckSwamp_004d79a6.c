/*
 * Decompiled function: Card_SedgeTroll_CheckSwamp
 * Entry Point: 004d79a6
 * Size: 117 bytes
 */
#include "magic.h"


undefined4 Card_SedgeTroll_CheckSwamp(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if ((arg_2 == g_OverworldMapGrid) && (arg_1 == g_OverworldPlayerCoordX)) {
    iVar1 = FUN_0041d963(arg_1,arg_2,3);
    if (0 < *(int *)(&DAT_0063ee30 + iVar1 * 4 + arg_1 * 0x20)) {
      if (arg_3 == 0x32) {
        g_ActivePalette = g_ActivePalette + 1;
      }
      if (arg_3 == 0x33) {
        g_ActivePalette = g_ActivePalette + 2;
      }
    }
  }
  return 0;
}


