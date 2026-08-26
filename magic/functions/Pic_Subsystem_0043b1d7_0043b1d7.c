/*
 * Decompiled function: Pic_Subsystem_0043b1d7
 * Entry Point: 0043b1d7
 * Size: 77 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043b1d7(int arg_1,int arg_2,int arg_3)

{
  if (((&g_MasterCardColorTable)[arg_3 * 0x34] & 2) != 0) {
    FUN_0041db67(arg_1,arg_2,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
  }
  return 0;
}


