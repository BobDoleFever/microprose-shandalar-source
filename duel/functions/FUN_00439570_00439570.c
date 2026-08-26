/*
 * Decompiled function: FUN_00439570
 * Entry Point: 00439570
 * Size: 102 bytes
 */
#include "duel.h"


void FUN_00439570(int arg_1)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_004f71c0 + local_8 * 8) =
         *(undefined4 *)(&DAT_004f71c0 + local_8 * 8 + arg_1 * 0x280);
    (&DAT_004f71c4)[local_8 * 2] = (&DAT_004f71c4)[arg_1 * 0xa0 + local_8 * 2];
  }
  return;
}


