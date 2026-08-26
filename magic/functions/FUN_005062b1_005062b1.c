/*
 * Decompiled function: FUN_005062b1
 * Entry Point: 005062b1
 * Size: 220 bytes
 */
#include "magic.h"


undefined4 FUN_005062b1(void)

{
  bool bVar1;
  undefined4 local_8;
  
  if ((g_PlayerCreatureCount < 1) || (DAT_006a4a04 < 1)) {
    bVar1 = true;
  }
  else if ((DAT_00696870 < 10) && (DAT_00696874 < 10)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if (g_IsAiThinking == 1) {
      if (9 < DAT_00696870) {
        g_PlayerCreatureCount = 0;
      }
      if (9 < DAT_00696874) {
        DAT_006a4a04 = 0;
      }
      local_8 = 0;
    }
    else {
      Ai_Subsystem_004cc9c5(0,0xff);
      local_8 = 1;
    }
  }
  else {
    local_8 = 0;
  }
  return local_8;
}


