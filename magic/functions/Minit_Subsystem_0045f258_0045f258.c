/*
 * Decompiled function: Minit_Subsystem_0045f258
 * Entry Point: 0045f258
 * Size: 371 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045f258(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  int arg_2_00;
  int arg_3_00;
  
  if (((arg_3 == 0x33) || (arg_3 == 0x32)) &&
     (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
    cVar1 = (&DAT_006a5f4c)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20];
    bVar2 = FUN_0041d9d2(arg_1,arg_2,4);
    if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
      g_ActivePalette = g_ActivePalette + 1;
    }
  }
  if (((arg_3 == 0x7c) && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
        * 0x34] & 1) != 0)) {
    cVar1 = (&DAT_006a5f4c)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20];
    bVar2 = FUN_0041d963(arg_1,arg_2,4);
    if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
      arg_3_00 = 1;
      arg_2_00 = FUN_0041d963(arg_1,arg_2,4);
      FUN_0040d875(g_OverworldPlayerCoordX,arg_2_00,arg_3_00);
    }
  }
  return 0;
}


