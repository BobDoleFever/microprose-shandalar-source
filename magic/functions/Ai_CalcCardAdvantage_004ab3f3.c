/*
 * Decompiled function: Ai_CalcCardAdvantage
 * Entry Point: 004ab3f3
 * Size: 108 bytes
 */
#include "magic.h"


void Ai_CalcCardAdvantage(void)

{
  DAT_006fefa8 = *(undefined4 *)(&DAT_0054f838 + DAT_0054be44 * 4);
  g_AiDecisionScore = (&DAT_005520c8)[DAT_0054be44];
  if ((&DAT_005520c8)[DAT_0054be44] != 99) {
    DAT_0054be44 = DAT_0054be44 + 1;
  }
  DAT_0052ce1c = 0;
  return;
}


