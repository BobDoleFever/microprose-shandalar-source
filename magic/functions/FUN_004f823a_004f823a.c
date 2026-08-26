/*
 * Decompiled function: FUN_004f823a
 * Entry Point: 004f823a
 * Size: 91 bytes
 */
#include "magic.h"


void FUN_004f823a(int arg1,int arg2)

{
  int local_8;
  
  for (local_8 = 0; local_8 < arg2; local_8 = local_8 + 1) {
    FUN_0046f5d1(arg1);
    if (arg1 != 0) {
      DAT_00627a14 = 0;
    }
  }
  (&DAT_006b3008)[arg1] = arg2;
  return;
}


