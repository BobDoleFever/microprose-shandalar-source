/*
 * Decompiled function: FUN_0041a52d
 * Entry Point: 0041a52d
 * Size: 203 bytes
 */
#include "duel.h"


undefined4 FUN_0041a52d(int arg_1,int arg_2,int arg_3)

{
  int arg_3_00;
  uint arg_2_00;
  
  if ((((arg_3 == 0x7f) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) &&
     ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0))
     )) {
    arg_3_00 = FUN_004af7bb(arg_1,arg_2,4);
    arg_2_00 = FUN_004af7bb(arg_1,arg_2,5);
    FUN_0049b0eb(arg_1,arg_2_00,arg_3_00);
  }
  return 0;
}


