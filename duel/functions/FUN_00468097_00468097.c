/*
 * Decompiled function: FUN_00468097
 * Entry Point: 00468097
 * Size: 101 bytes
 */
#include "duel.h"


void FUN_00468097(int arg_1,int arg_2,int arg_3)

{
  if (0xff < arg_3) {
    arg_3 = 0xff;
  }
  *(uint *)(&DAT_0068270c + arg_2 * 0x120 + arg_1 * 0x5b20) =
       CONCAT31((int3)((uint)*(undefined4 *)(&DAT_0068270c + arg_2 * 0x120 + arg_1 * 0x5b20) >> 8),
                (undefined1)arg_3);
  return;
}


