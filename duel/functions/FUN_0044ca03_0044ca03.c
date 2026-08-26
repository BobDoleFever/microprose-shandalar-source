/*
 * Decompiled function: FUN_0044ca03
 * Entry Point: 0044ca03
 * Size: 77 bytes
 */
#include "duel.h"


void FUN_0044ca03(byte arg_1)

{
  undefined1 local_8 [4];
  
  local_8[0] = 0xc1;
  if ((arg_1 & 0xc0) == 0xc0) {
    FID_conflict___fwrite_lk(local_8,1,1,DAT_00694434);
  }
  FID_conflict___fwrite_lk(&arg_1,1,1,DAT_00694434);
  return;
}


