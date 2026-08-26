/*
 * Decompiled function: Card_SetCounters
 * Entry Point: 004e6913
 * Size: 101 bytes
 */
#include "magic.h"


void Card_SetCounters(int arg_1,int arg_2,int arg_3)

{
  if (0xff < arg_3) {
    arg_3 = 0xff;
  }
  *(uint *)(&DAT_006a5f7c + arg_2 * 0x120 + arg_1 * 0x5b20) =
       CONCAT31((int3)((uint)*(undefined4 *)(&DAT_006a5f7c + arg_2 * 0x120 + arg_1 * 0x5b20) >> 8),
                (undefined1)arg_3);
  return;
}


