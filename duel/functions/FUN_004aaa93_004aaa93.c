/*
 * Decompiled function: FUN_004aaa93
 * Entry Point: 004aaa93
 * Size: 209 bytes
 */
#include "duel.h"


void FUN_004aaa93(int x,int y,int width,undefined1 arg_4)

{
  int local_8;
  
  for (local_8 = 1; local_8 < 6; local_8 = local_8 + 1) {
    if ((char)(&DAT_006827bf)[y * 0x120 + x * 0x5b20 + local_8] == width) {
      (&DAT_006827bf)[y * 0x120 + x * 0x5b20 + local_8] = arg_4;
    }
  }
  if ((&DAT_006827bf)[width + x * 0x5b20 + y * 0x120] == '\0') {
    (&DAT_006827bf)[width + x * 0x5b20 + y * 0x120] = arg_4;
  }
  return;
}


