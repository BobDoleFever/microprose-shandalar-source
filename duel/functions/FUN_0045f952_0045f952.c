/*
 * Decompiled function: FUN_0045f952
 * Entry Point: 0045f952
 * Size: 414 bytes
 */
#include "duel.h"


undefined4 FUN_0045f952(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 199) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
     ((arg_1 == DAT_00666458 &&
      ((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x30044) == 0)))) {
    if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) {
      FUN_0045102d(arg_1,arg_1,arg_2,-1,-1,s_Erg_Raiders_take_2_life__004f8b24,0);
    }
    Mem_AllocOrFree_004afd1c(arg_1,2,arg_1,arg_2);
  }
  if (((DAT_0068f230 == 0xcd) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 &&
      (((arg_1 == DAT_00666458 && (arg_1 == DAT_00681ec4)) &&
       ((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x30044) == 0)))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) {
        FUN_0045102d(arg_1,arg_1,arg_2,-1,-1,s_Erg_Raiders_take_2_life__004f8b40,0);
      }
      Mem_AllocOrFree_004afd1c(arg_1,2,arg_1,arg_2);
    }
  }
  return 0;
}


