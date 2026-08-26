/*
 * Decompiled function: Card_FrozenShade_ClearBoost
 * Entry Point: 004d6391
 * Size: 111 bytes
 */
#include "magic.h"


undefined4 Card_FrozenShade_ClearBoost(int arg1,int arg2)

{
  if ((arg1 == g_OverworldPlayerCoordX) &&
     ((&DAT_0051aebd)
      [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
       * 0x34] == '\x04')) {
    Pic_Subsystem_0044867e(arg1,arg2,1);
  }
  return 0;
}


