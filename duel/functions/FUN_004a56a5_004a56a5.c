/*
 * Decompiled function: FUN_004a56a5
 * Entry Point: 004a56a5
 * Size: 457 bytes
 */
#include "duel.h"


undefined4 FUN_004a56a5(int arg_1,int arg_2,int arg_3)

{
  if ((arg_3 == 0x22) && (*(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    Mem_AllocOrFree_004af72b(*(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20));
    FUN_0046e571(arg_1,arg_2,1);
    *(uint *)(&DAT_006826fc +
             *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
             (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
         *(uint *)(&DAT_006826fc +
                  *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) | 0x1000000;
    FUN_0048b81a((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                 *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20),0x3c,0xffffffff);
    FUN_00451995();
  }
  if ((((arg_3 == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) &&
      (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) &&
     (((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0 && (DAT_00690c48 != -1)
      ))) {
    DAT_0066642c = *(undefined4 *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  return 0;
}


