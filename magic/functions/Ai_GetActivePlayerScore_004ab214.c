/*
 * Decompiled function: Ai_GetActivePlayerScore
 * Entry Point: 004ab214
 * Size: 119 bytes
 */
#include "magic.h"


void Ai_GetActivePlayerScore(void)

{
  int local_8;
  
  DAT_00701008 = 0;
  DAT_0054be44 = 0;
  DAT_0063ee70 = 0xffffffff;
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    (&DAT_005524c8)[local_8] = 99;
  }
  Ai_RestoreGameState();
  if (g_IsAiThinking != 1) {
    DAT_006808a8 = 0xffffffff;
  }
  return;
}


