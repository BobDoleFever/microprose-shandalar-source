/*
 * Decompiled function: FUN_004a314e
 * Entry Point: 004a314e
 * Size: 1093 bytes
 */
#include "duel.h"


undefined4 FUN_004a314e(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x34) &&
       (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) &&
      ((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0)) &&
     (DAT_00690c48 != -1)) {
    DAT_0066642c = DAT_0066642c | *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  if ((((arg_3 == 0x77) &&
       (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) &&
      (((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0 &&
       ((DAT_00690c48 != -1 &&
        ((&DAT_006826e0)
         [*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
          (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] != '\x04')))))) &&
     (*(int *)(&DAT_004ff590 +
              *(int *)(&DAT_006826c4 +
                      *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 0x34) ==
      0x1a3)) {
    FUN_0046e571((int)(char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20],
                 *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20),2);
  }
  if ((DAT_00690c48 == arg_2) && (DAT_0068ecb0 == arg_1)) {
    if ((&DAT_006826e0)[arg_2 * 0x120 + arg_1 * 0x5b20] == '\x05') {
      if (((DAT_0068f230 == 0xcd) || (arg_3 == 199)) &&
         ((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_00681ec4)) {
        if (arg_3 == 0x7d) {
          DAT_0066642c = DAT_0066642c | 2;
        }
        if (((arg_3 == 0x7e) || (arg_3 == 199)) &&
           (FUN_0046e571((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                         *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20),2),
           *(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
          FUN_0046e571(arg_1,arg_2,2);
        }
      }
    }
    else if ((((&DAT_006826f8)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) &&
            ((arg_3 == 0x22 || (arg_3 == 199)))) {
      if ((&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1) {
        *(undefined4 *)
         (&DAT_006826fc +
         *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
         (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) = 0x8000000;
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
  }
  return 0;
}


