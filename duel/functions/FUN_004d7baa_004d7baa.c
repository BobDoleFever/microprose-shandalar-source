/*
 * Decompiled function: FUN_004d7baa
 * Entry Point: 004d7baa
 * Size: 118 bytes
 */
#include "duel.h"


void FUN_004d7baa(int arg1,undefined4 arg2)

{
  int local_8;
  
  for (local_8 = 499; 0 < local_8; local_8 = local_8 + -1) {
    *(undefined4 *)(&DAT_006669f0 + local_8 * 4 + arg1 * 2000) =
         *(undefined4 *)(&DAT_006669ec + local_8 * 4 + arg1 * 2000);
  }
  *(undefined4 *)(&DAT_006669f0 + arg1 * 2000) = arg2;
  return;
}


