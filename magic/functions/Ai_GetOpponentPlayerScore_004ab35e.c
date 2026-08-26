/*
 * Decompiled function: Ai_GetOpponentPlayerScore
 * Entry Point: 004ab35e
 * Size: 75 bytes
 */
#include "magic.h"


undefined4 Ai_GetOpponentPlayerScore(int arg_1)

{
  if ((g_IsAiThinking != 1) &&
     (DAT_006fefa8 = *(uint *)(&DAT_0054f838 + (arg_1 + DAT_0054be44) * 4),
     DAT_006fefa8 != 0xffffffff)) {
    DAT_006fefa8 = DAT_006fefa8 & 0xfff;
  }
  return 0;
}


