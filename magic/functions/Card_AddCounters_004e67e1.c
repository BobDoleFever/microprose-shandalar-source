/*
 * Decompiled function: Card_AddCounters
 * Entry Point: 004e67e1
 * Size: 186 bytes
 */
#include "magic.h"


void Card_AddCounters(int arg_1,int arg_2,int arg_3)

{
  if (((&DAT_006a5f7c)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1) &&
     (*(uint *)(&DAT_006a5f7c + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(int *)(&DAT_006a5f7c + arg_1 * 0x5b20 + arg_2 * 0x120) + arg_3 & 0xffU |
           *(uint *)(&DAT_006a5f7c + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xffffff00,
     g_IsAiThinking != 1)) {
    Magic_UpkeepPhase(0x1b);
  }
  return;
}


