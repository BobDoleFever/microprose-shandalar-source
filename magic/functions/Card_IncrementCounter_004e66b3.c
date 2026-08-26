/*
 * Decompiled function: Card_IncrementCounter
 * Entry Point: 004e66b3
 * Size: 184 bytes
 */
#include "magic.h"


void Card_IncrementCounter(int arg1,int arg2)

{
  if (((&DAT_006a5f7c)[arg2 * 0x120 + arg1 * 0x5b20] != -1) &&
     (*(uint *)(&DAT_006a5f7c + arg2 * 0x120 + arg1 * 0x5b20) =
           *(int *)(&DAT_006a5f7c + arg2 * 0x120 + arg1 * 0x5b20) + 1U & 0xff |
           *(uint *)(&DAT_006a5f7c + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff00, g_IsAiThinking != 1
     )) {
    Magic_UpkeepPhase(0x1b);
  }
  return;
}


