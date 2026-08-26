/*
 * Decompiled function: FUN_0046f116
 * Entry Point: 0046f116
 * Size: 121 bytes
 */
#include "duel.h"


void FUN_0046f116(int arg1,int arg2)

{
  int local_8;
  
  for (local_8 = arg2; local_8 < 499; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_0068f370 + local_8 * 4 + arg1 * 2000) =
         *(undefined4 *)(&DAT_0068f374 + local_8 * 4 + arg1 * 2000);
  }
  *(undefined4 *)(&DAT_0068fb3c + arg1 * 2000) = 0xffffffff;
  return;
}


