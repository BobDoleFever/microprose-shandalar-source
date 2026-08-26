/*
 * Decompiled function: FUN_004d7acc
 * Entry Point: 004d7acc
 * Size: 97 bytes
 */
#include "duel.h"


void FUN_004d7acc(int arg1,int arg2)

{
  int local_8;
  
  while (local_8 = arg2 + 1, local_8 < 500) {
    *(undefined4 *)(&DAT_006669ec + local_8 * 4 + arg1 * 2000) =
         *(undefined4 *)(&DAT_006669f0 + local_8 * 4 + arg1 * 2000);
    arg2 = local_8;
  }
  return;
}


