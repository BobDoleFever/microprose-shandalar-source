/*
 * Decompiled function: FUN_004512d1
 * Entry Point: 004512d1
 * Size: 107 bytes
 */
#include "duel.h"


INT_PTR FUN_004512d1(int arg_1,undefined4 arg_2,INT_PTR arg_3,char *str_4,char *str_5,char *str_6)

{
  if (DAT_0066aaf4 != 1) {
    if (DAT_0068eed8 == 0) {
      arg_3 = Mem_AllocOrFree_0049f6d5(arg_1,arg_2,arg_3);
    }
    else {
      arg_3 = FUN_004428d2(arg_1,arg_2,arg_3,str_4,str_5,str_6);
    }
  }
  return arg_3;
}


