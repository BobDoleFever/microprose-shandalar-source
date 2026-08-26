/*
 * Decompiled function: FUN_00454cdc
 * Entry Point: 00454cdc
 * Size: 528 bytes
 */
#include "duel.h"


undefined4 FUN_00454cdc(int arg_1,int arg_2,int arg_3)

{
  if (((((arg_3 == 0x6e) &&
        (*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104)) &&
       (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == -1)) &&
      (((char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1 &&
       (*(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2)))) &&
     (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)) {
    (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068ecb0;
    *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00690c48;
  }
  if (((DAT_0068f230 == 0xd7) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 &&
      (((&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1 && (arg_1 == DAT_00681ec4)))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      (&DAT_006668f0)[(char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20]] =
           (&DAT_006668f0)[(char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20]] + 2;
      (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
      FUN_0042afdb();
    }
  }
  return 0;
}


