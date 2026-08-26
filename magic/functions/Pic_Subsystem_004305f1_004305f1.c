/*
 * Decompiled function: Pic_Subsystem_004305f1
 * Entry Point: 004305f1
 * Size: 283 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_004305f1(int arg_1,int arg_2,int arg_3)

{
  if ((((((&g_MasterCardColorTable)[arg_3 * 0x34] & 4) != 0) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20))) &&
      ((&g_CardSlot_Toughness)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] ==
       (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20])) &&
     ((*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) != 0x29 &&
      ((g_OverworldPlayerCoordX != arg_1 || (g_OverworldMapGrid != arg_2)))))) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}


