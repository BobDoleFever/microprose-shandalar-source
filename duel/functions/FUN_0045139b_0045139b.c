/*
 * Decompiled function: FUN_0045139b
 * Entry Point: 0045139b
 * Size: 95 bytes
 */
#include "duel.h"


INT_PTR FUN_0045139b(int arg_1,undefined4 arg_2,INT_PTR arg_3)

{
  if (DAT_0066aaf4 != 1) {
    if (DAT_0068eed8 == 0) {
      arg_3 = Mem_AllocOrFree_0049f6e7(arg_1,arg_2,arg_3);
    }
    else {
      arg_3 = FUN_00443000(arg_1,arg_2,arg_3);
    }
  }
  return arg_3;
}


