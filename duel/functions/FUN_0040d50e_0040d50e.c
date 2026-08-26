/*
 * Decompiled function: FUN_0040d50e
 * Entry Point: 0040d50e
 * Size: 154 bytes
 */
#include "duel.h"


undefined4 FUN_0040d50e(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x22) || (arg_3 == 199)) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  if (((arg_3 == 0x34) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0066642c = DAT_0066642c | 0x20000;
  }
  return 0;
}


