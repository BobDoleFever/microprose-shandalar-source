/*
 * Decompiled function: Card_DecrementCounter
 * Entry Point: 004e676b
 * Size: 118 bytes
 */
#include "magic.h"


void Card_DecrementCounter(int arg1,int arg2)

{
  *(uint *)(&DAT_006a5f7c + arg2 * 0x120 + arg1 * 0x5b20) =
       *(int *)(&DAT_006a5f7c + arg2 * 0x120 + arg1 * 0x5b20) - 1U & 0xff |
       *(uint *)(&DAT_006a5f7c + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff00;
  return;
}


