/*
 * Decompiled function: FUN_0045133c
 * Entry Point: 0045133c
 * Size: 95 bytes
 */
#include "duel.h"


INT_PTR FUN_0045133c(int arg_1,undefined4 arg_2,INT_PTR arg_3)

{
  if (DAT_0066aaf4 != 1) {
    if (DAT_0068eed8 == 0) {
      arg_3 = Mem_AllocOrFree_0049f6d5(arg_1,arg_2,arg_3);
    }
    else {
      arg_3 = FUN_00442e3c(arg_1,arg_2,arg_3);
    }
  }
  return arg_3;
}


