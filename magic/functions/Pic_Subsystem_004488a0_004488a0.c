/*
 * Decompiled function: Pic_Subsystem_004488a0
 * Entry Point: 004488a0
 * Size: 191 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_004488a0(void)

{
  if ((DAT_00695f18 != 0) && (DAT_0052211c == 0)) {
    DAT_0052211c = 1;
    g_PlayerHandCardCount = g_PlayerHandCardCount | 0x200;
    FUN_00475c8a(-2,g_ScWillyScore,s_Use_Regeneration_Effects_005221cc,0x70);
    g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffffdff;
    FUN_00476205(g_DefendingPlayer,0xd6,s_Graveyard_order_005221e8,0);
    FUN_00476205(g_DefendingPlayer,0xd5,s_Card_s__to_Graveyard_005221f8,0);
    DAT_00695f18 = 0;
    DAT_0052211c = 0;
    Ai_Subsystem_004cc9c5(0,0xff);
  }
  return 0;
}


