/*
 * Decompiled function: Minit_Subsystem_00458c07
 * Entry Point: 00458c07
 * Size: 104 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00458c07(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 2) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    CardQuery_ForEachPermanent(Minit_Subsystem_00458c6f,-1);
    if (g_ActivePalette == 0) {
      Pic_Subsystem_0044867e(arg_1,arg_2,4);
    }
  }
  return 0;
}


