/*
 * Decompiled function: FUN_004a5def
 * Entry Point: 004a5def
 * Size: 699 bytes
 */
#include "duel.h"


undefined4 FUN_004a5def(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) &&
      (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) &&
     ((((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0 &&
       (DAT_00690c48 != -1)) && (*(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1))))
  {
    DAT_0066642c = *(uint *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(uint *)(&DAT_006826f8 +
             *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
             (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
         *(uint *)(&DAT_006826f8 +
                  *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) | 0x40;
  }
  if (((DAT_0068f230 == 0xc9) || (arg_3 == 199)) &&
     ((DAT_00690c48 == arg_2 &&
      (((DAT_0068ecb0 == arg_1 && (DAT_00666458 == arg_1)) && (arg_1 == DAT_00681ec4)))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      Mem_AllocOrFree_004af72b(*(int *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20));
      *(undefined4 *)(&DAT_006826c8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      *(uint *)(&DAT_006826fc +
               *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
           *(uint *)(&DAT_006826fc +
                    *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) | 0x1000000;
      FUN_0048b81a((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                   *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20),0x3c,0xffffffff);
      FUN_00451995();
      FUN_0046e571(arg_1,arg_2,1);
    }
  }
  return 0;
}


