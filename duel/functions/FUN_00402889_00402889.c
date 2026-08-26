/*
 * Decompiled function: FUN_00402889
 * Entry Point: 00402889
 * Size: 91 bytes
 */
#include "duel.h"


void FUN_00402889(int arg1,int arg2)

{
  int local_8;
  
  for (local_8 = 0; local_8 < arg2; local_8 = local_8 + 1) {
    FUN_00487ce1(arg1);
    if (arg1 != 0) {
      DAT_006668f8 = 0;
    }
  }
  (&DAT_0068ee78)[arg1] = arg2;
  return;
}


