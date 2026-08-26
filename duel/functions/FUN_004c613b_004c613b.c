/*
 * Decompiled function: FUN_004c613b
 * Entry Point: 004c613b
 * Size: 306 bytes
 */
#include "duel.h"


void FUN_004c613b(int arg_1,undefined4 arg_2,int arg_3)

{
  if (arg_3 != 0x74) {
    if ((((arg_3 == 0x32) && (DAT_0068ecb0 == arg_1)) &&
        ((&DAT_004ff595)
         [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] == '\0'))
       && (((byte)*(undefined4 *)(&DAT_006826cc + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) &
           0x22) == 2)) {
      DAT_0066642c = DAT_0066642c + 1;
    }
    if (((arg_3 == 0x34) && (DAT_0068ecb0 == arg_1)) &&
       (((&DAT_004ff595)
         [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] == '\0' &&
        (((byte)*(undefined4 *)(&DAT_006826cc + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) & 0x22
         ) == 2)))) {
      DAT_0066642c = DAT_0066642c | 0x40;
    }
  }
  return;
}


