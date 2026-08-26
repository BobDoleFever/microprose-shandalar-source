/*
 * Decompiled function: Ai_EvaluateCreaturePower
 * Entry Point: 004ab28b
 * Size: 211 bytes
 */
#include "magic.h"


void Ai_EvaluateCreaturePower(void)

{
  if (DAT_0054be44 < 0x100) {
    *(uint *)(&DAT_0054fc38 + DAT_0054be44 * 4) = DAT_006fefa8;
    *(undefined4 *)(&DAT_00553840 + DAT_0054be44 * 4) =
         *(undefined4 *)
          (&g_CardSlot_CardId +
          (DAT_006fefa8 & 0xff) * 0x120 + ((DAT_006fefa8 & 0x100) >> 8) * 0x5b20);
    *(undefined4 *)(&DAT_00553c40 + DAT_0054be44 * 4) = DAT_0052ce1c;
    (&DAT_005524c8)[DAT_0054be44] = g_AiDecisionScore;
    DAT_0054be44 = DAT_0054be44 + 1;
    if ((DAT_005524c8 == 99) || (DAT_005520c8 == 99)) {
      DAT_006fefa8 = 0xffffffff;
    }
  }
  else {
    g_ActivePlayer = 1;
  }
  DAT_0052ce1c = 0;
  return;
}


