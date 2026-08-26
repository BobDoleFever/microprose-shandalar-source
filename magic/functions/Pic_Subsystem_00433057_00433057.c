/*
 * Decompiled function: Pic_Subsystem_00433057
 * Entry Point: 00433057
 * Size: 475 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00433057(int arg_1,int arg_2,int arg_3)

{
  byte arg_1_00;
  undefined4 uVar1;
  int arg_2_00;
  int arg_3_00;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (arg_1 == g_OverworldPlayerCoordX)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x30;
    }
    if (((arg_3 == 0x81) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 1) != 0)
        ) && (DAT_006ff2d4 != -1)) {
      FUN_0040d875(g_OverworldPlayerCoordX,DAT_006ff2d4,1);
    }
    if (((arg_3 == 0x7f) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 1) != 0)
        ) && (((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] &
              0x10) == 0)) {
      arg_1_00 = (&DAT_006a5f4c)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      local_8 = 0;
      for (local_c = 0; local_c < 7; local_c = local_c + 1) {
        if (((int)(char)arg_1_00 & 1 << ((byte)local_c & 0x1f)) != 0) {
          local_8 = local_8 + 1;
        }
      }
      if (local_8 < 1) {
        arg_3_00 = 1;
        arg_2_00 = FUN_00473cc5(arg_1_00);
        FUN_0040d7e9(g_OverworldPlayerCoordX,arg_2_00,arg_3_00);
      }
      else {
        FUN_0040d59c(g_OverworldPlayerCoordX,(int)(char)arg_1_00,1);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


