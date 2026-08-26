/*
 * Decompiled function: FUN_0041240a
 * Entry Point: 0041240a
 * Size: 425 bytes
 */
#include "duel.h"


undefined4 FUN_0041240a(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 +
                   (*(int *)(&DAT_0068ef6c + DAT_00676504 * 0x20) -
                   *(int *)(&DAT_0068ef6c + DAT_00676510 * 0x20)) * 0xc;
  }
  if (((((DAT_0068f230 == 0xdb) || (DAT_0068f230 == 0xd3)) &&
       ((arg_2 == DAT_00690c48 && ((arg_1 == DAT_0068ecb0 && (DAT_00681ec4 == DAT_00666458)))))) &&
      (*(int *)(&DAT_006826c4 + DAT_0068edd0 * 0x120 + DAT_00666754 * 0x5b20) != -1)) &&
     ((((&DAT_004ff594)
        [*(int *)(&DAT_006826c4 + DAT_0068edd0 * 0x120 + DAT_00666754 * 0x5b20) * 0x34] & 1) != 0 &&
      ((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0 ||
       (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] & 2) != 0)
       ))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      Mem_AllocOrFree_004afd1c(DAT_00666754,2,arg_1,arg_2);
    }
  }
  return 0;
}


