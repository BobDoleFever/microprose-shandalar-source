/*
 * Decompiled function: Pic_Subsystem_0042f690
 * Entry Point: 0042f690
 * Size: 249 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042f690(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b3000 + (7 - arg_1) * 4) - (&DAT_006b3018)[arg_1]) * 0x18;
    }
    if (((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) && (arg_3 == 0x7c)) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 0x40) !=
        0)) {
      Mem_AllocOrFree_0041df33(g_OverworldPlayerCoordX,1,arg_1,arg_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


