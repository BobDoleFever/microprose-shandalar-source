/*
 * Decompiled function: FUN_004a467d
 * Entry Point: 004a467d
 * Size: 1748 bytes
 */
#include "duel.h"


undefined4 FUN_004a467d(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((&DAT_006826f9)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x40) != 0) {
    if (((*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) == DAT_00690c48) &&
        ((char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] == DAT_0068ecb0)) &&
       (DAT_00690c48 != -1)) {
      if (arg_3 == 0x34) {
        DAT_0066642c = DAT_0066642c | *(uint *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120);
      }
      if (arg_3 == 0x32) {
        DAT_0066642c = DAT_0066642c +
                       (int)*(short *)(&DAT_006826d8 + arg_1 * 0x5b20 + arg_2 * 0x120);
      }
    }
    if (((arg_2 == DAT_00690c48) && (arg_1 == DAT_0068ecb0)) &&
       ((arg_3 == 0x22 &&
        ((*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) != -1 &&
         (((&DAT_006826cc)
           [*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
            (char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20] & 0x40) != 0)))))) {
      (&DAT_006826e0)[arg_1 * 0x5b20 + arg_2 * 0x120] = 5;
    }
  }
  if (((&DAT_006826f9)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0) {
    if (((((arg_3 == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) &&
         (*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) == DAT_00690c48)) &&
        (((char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] == DAT_0068ecb0 &&
         (DAT_00690c48 != -1)))) &&
       (*(int *)(&DAT_006826c4 +
                *(int *)(&DAT_006826ec + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                (char)(&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20) != -1)) {
      iVar1 = FUN_004af74c(arg_1,arg_2,
                           *(int *)(&DAT_006826e4 +
                                   *(int *)(&DAT_006826ec + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120
                                   + (char)(&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20)
                          );
      DAT_0066642c = iVar1 - 1;
    }
    if (((arg_3 == 0x77) && ((char)(&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120] == DAT_0068ecb0))
       && (*(int *)(&DAT_006826ec + arg_1 * 0x5b20 + arg_2 * 0x120) == DAT_00690c48)) {
      *(uint *)(&DAT_006826fc +
               *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
               (char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20) =
           *(uint *)(&DAT_006826fc +
                    *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                    (char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20) | 0x1000000;
      FUN_0046e571(arg_1,arg_2,1);
    }
  }
  if (((&DAT_006826fa)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x40) != 0) {
    if ((arg_3 == 0x6a) && (arg_1 == DAT_00666458)) {
      FUN_0046e571(arg_1,arg_2,2);
      *(undefined4 *)(&DAT_006663e8 + arg_1 * 4) = 0;
    }
    if ((arg_3 == 0x79) &&
       ((*(uint *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) &
        *(uint *)(&DAT_006826fc + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120)) == 0)) {
      DAT_0066642c = DAT_0066642c + 1;
    }
  }
  if (((&DAT_006826f9)[arg_1 * 0x5b20 + arg_2 * 0x120] & 1) != 0) {
    if ((arg_3 == 0x6a) && (DAT_0068f0f8 == -1)) {
      DAT_0068f0f8 = arg_1;
    }
    if ((arg_3 == 0x22) && (DAT_00690318 == 0)) {
      DAT_00690318 = 1 << ((byte)arg_1 & 0x1f);
      *(uint *)(&DAT_006826f8 + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint *)(&DAT_006826f8 + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xffffffdf;
    }
  }
  if ((arg_2 == DAT_00690c48) && (arg_1 == DAT_0068ecb0)) {
    if ((&DAT_006826e0)[arg_1 * 0x5b20 + arg_2 * 0x120] == '\x05') {
      if (((DAT_0068f230 == 0xcd) || (arg_3 == 199)) &&
         ((char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] == DAT_00681ec4)) {
        if (arg_3 == 0x7d) {
          DAT_0066642c = DAT_0066642c | 2;
        }
        if (((arg_3 == 0x7e) || (arg_3 == 199)) &&
           (FUN_0046e571((int)(char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120],
                         *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120),2),
           *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) != -1)) {
          FUN_0046e571(arg_1,arg_2,2);
        }
      }
    }
    else if ((((&DAT_006826f8)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x20) == 0) &&
            ((arg_3 == 0x22 || (arg_3 == 199)))) {
      FUN_0046e571(arg_1,arg_2,1);
    }
  }
  return 0;
}


