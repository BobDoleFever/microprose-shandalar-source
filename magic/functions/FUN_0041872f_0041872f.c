/*
 * Decompiled function: FUN_0041872f
 * Entry Point: 0041872f
 * Size: 86 bytes
 */
#include "magic.h"


undefined4 FUN_0041872f(int arg1,int arg2)

{
  if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
    FUN_0041db67(arg1,arg2,1,g_OverworldPlayerCoordX,g_OverworldMapGrid);
  }
  return 0;
}


