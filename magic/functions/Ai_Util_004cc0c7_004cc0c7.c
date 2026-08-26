/*
 * Decompiled function: Ai_Util_004cc0c7
 * Entry Point: 004cc0c7
 * Size: 48 bytes
 */
#include "magic.h"


int Ai_Util_004cc0c7(int arg1,int arg2)

{
  return (int)*(short *)(&g_CardSlot_Counters + arg2 * 0x120 + arg1 * 0x5b20);
}


