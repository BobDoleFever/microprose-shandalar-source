/*
 * Decompiled function: FUN_00479b25
 * Entry Point: 00479b25
 * Size: 96 bytes
 */
#include "duel.h"


void FUN_00479b25(int arg_1,int arg_2,int arg_3)

{
  if (arg_3 == 0) {
    *(uint *)(&DAT_006826f8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826f8 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffdffff;
  }
  else {
    *(uint *)(&DAT_006826f8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826f8 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x20000;
  }
  return;
}


