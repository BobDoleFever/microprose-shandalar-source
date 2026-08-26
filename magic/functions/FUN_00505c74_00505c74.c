/*
 * Decompiled function: FUN_00505c74
 * Entry Point: 00505c74
 * Size: 172 bytes
 */
#include "magic.h"


undefined4 FUN_00505c74(void)

{
  if ((DAT_00627a88 != -1) && (g_IsAiThinking != 1)) {
    if ((g_ScWillyScore < DAT_00627a88) || (DAT_00627a84 != g_DefendingPlayer)) {
      return 1;
    }
    if ((g_PlayerManaPool != -1) && (g_ScWillyScore == DAT_00627a88)) {
      return 1;
    }
    if ((DAT_00627a88 < g_ScWillyScore) && (DAT_00627a84 == g_DefendingPlayer)) {
      DAT_00627a88 = -1;
    }
  }
  return 0;
}


