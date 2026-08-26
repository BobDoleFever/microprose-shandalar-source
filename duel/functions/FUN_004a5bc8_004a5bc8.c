/*
 * Decompiled function: FUN_004a5bc8
 * Entry Point: 004a5bc8
 * Size: 551 bytes
 */
#include "duel.h"


undefined4 FUN_004a5bc8(int arg_1,int arg_2,int arg_3)

{
  if ((arg_3 == 0x21) && ((DAT_0068f2c4 == 0x1a || (DAT_0068f2c4 == 0x19)))) {
    if (((&DAT_006826d2)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] ==
         (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20]) &&
       (*(int *)(&DAT_006826e8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) ==
        *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20))) {
      *(undefined4 *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) = 0;
    }
    if (((&DAT_006826d3)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] ==
         (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20]) &&
       (*(int *)(&DAT_006826ec + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) ==
        *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20))) {
      *(undefined4 *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) = 0;
    }
  }
  if ((((DAT_0068f230 == 0xcc) || (arg_3 == 199)) && (DAT_00690c48 == arg_2)) &&
     (DAT_0068ecb0 == arg_1)) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      FUN_0046e571(arg_1,arg_2,1);
    }
  }
  return 0;
}


