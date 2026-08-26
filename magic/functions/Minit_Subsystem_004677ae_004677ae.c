/*
 * Decompiled function: Minit_Subsystem_004677ae
 * Entry Point: 004677ae
 * Size: 203 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004677ae(int arg_1,int arg_2,int arg_3)

{
  int arg_3_00;
  uint arg_2_00;
  
  if ((((arg_3 == 0x7f) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) &&
     ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)))) {
    arg_3_00 = FUN_0041d9d2(arg_1,arg_2,4);
    arg_2_00 = FUN_0041d9d2(arg_1,arg_2,5);
    FUN_0040d72b(arg_1,arg_2_00,arg_3_00);
  }
  return 0;
}


