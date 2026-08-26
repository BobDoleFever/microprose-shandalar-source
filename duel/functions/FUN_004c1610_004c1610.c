/*
 * Decompiled function: FUN_004c1610
 * Entry Point: 004c1610
 * Size: 178 bytes
 */
#include "duel.h"


undefined4 FUN_004c1610(int arg_1,int arg_2,int arg_3)

{
  if (((*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48) &&
      ((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0)) &&
     (DAT_00690c48 != -1)) {
    (**(code **)(&DAT_004ff5a0 + arg_3 * 0x34))(arg_1,arg_2,0x79);
    if (DAT_00681ea4 == 1) {
      DAT_0066642c = DAT_0066642c + 1;
      DAT_00681ea4 = 0;
    }
  }
  return 0;
}


