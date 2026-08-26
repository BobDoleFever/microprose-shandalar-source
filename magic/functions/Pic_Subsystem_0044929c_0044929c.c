/*
 * Decompiled function: Pic_Subsystem_0044929c
 * Entry Point: 0044929c
 * Size: 164 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044929c(int arg1,int arg2)

{
  int local_8;
  
  if ((g_IsAiThinking != 1) && (((&g_MasterCardColorTable)[arg2 * 0x34] & 2) != 0)) {
    Magic_UpkeepPhase(0x17);
  }
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return;
    }
    if (*(int *)(&DAT_006b1590 + local_8 * 4 + arg1 * 2000) == -1) break;
    local_8 = local_8 + 1;
  }
  *(int *)(&DAT_006b1590 + local_8 * 4 + arg1 * 2000) = arg2;
  return;
}


