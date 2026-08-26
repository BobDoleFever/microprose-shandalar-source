/*
 * Decompiled function: Minit_Subsystem_00457d5b
 * Entry Point: 00457d5b
 * Size: 268 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00457d5b(int arg_1,int arg_2,int arg_3)

{
  int local_8;
  
  if ((arg_3 == 0x1f) &&
     ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)))) {
    if (((&DAT_006a5f3d)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) {
      local_8 = g_ActivePlayerPriority;
    }
    else {
      local_8 = g_CurrentTurnPhase;
    }
    if ((g_DefendingPlayer == local_8) && (4 < (int)(&DAT_006b3008)[g_DefendingPlayer])) {
      g_ActivePalette = g_ActivePalette | 1;
      while (4 < (int)(&DAT_006b3008)[g_DefendingPlayer]) {
        Prompts_Load_0046fa40(g_DefendingPlayer,0,0);
      }
    }
  }
  return 0;
}


