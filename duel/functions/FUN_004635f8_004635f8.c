/*
 * Decompiled function: FUN_004635f8
 * Entry Point: 004635f8
 * Size: 161 bytes
 */
#include "duel.h"


undefined4 FUN_004635f8(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0066642c = DAT_0066642c | 2;
  }
  if (((((arg_3 == 4) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) || (arg_3 == 199)) &&
     ((int)(&DAT_00681ea8)[arg_1] < (int)(&DAT_00681ea8)[1 - arg_1])) {
    FUN_004bf853(arg_1,arg_2);
  }
  return 0;
}


