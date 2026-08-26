/*
 * Decompiled function: Pic_Subsystem_00432f70
 * Entry Point: 00432f70
 * Size: 231 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00432f70(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_0063ee4c + g_ActivePlayerPriority * 0x20) -
           *(int *)(&DAT_0063ee4c + g_CurrentTurnPhase * 0x20)) * 0x18;
    }
    if (((arg_3 == 0x81) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 1) != 0)
        ) && (DAT_006ff2d4 != -1)) {
      Mem_AllocOrFree_0041df33(g_OverworldPlayerCoordX,1,arg_1,arg_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


