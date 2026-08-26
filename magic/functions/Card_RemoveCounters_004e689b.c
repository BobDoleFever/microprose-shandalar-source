/*
 * Decompiled function: Card_RemoveCounters
 * Entry Point: 004e689b
 * Size: 120 bytes
 */
#include "magic.h"


void Card_RemoveCounters(int arg_1,int arg_2,int arg_3)

{
  *(uint *)(&DAT_006a5f7c + arg_2 * 0x120 + arg_1 * 0x5b20) =
       *(int *)(&DAT_006a5f7c + arg_2 * 0x120 + arg_1 * 0x5b20) - arg_3 & 0xffU |
       *(uint *)(&DAT_006a5f7c + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffffff00;
  return;
}


