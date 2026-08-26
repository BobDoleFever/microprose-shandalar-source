/*
 * Decompiled function: FUN_004a4084
 * Entry Point: 004a4084
 * Size: 461 bytes
 */
#include "duel.h"


undefined4 FUN_004a4084(int arg_1,int arg_2,int arg_3)

{
  if ((((DAT_0068f230 == 0xcc) || (arg_3 == 199)) && (arg_2 == DAT_00690c48)) &&
     (arg_1 == DAT_0068ecb0)) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      if ((&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1) {
        Mem_AllocOrFree_004afd1c(arg_1,5,arg_1,arg_2);
      }
      if ((*(int *)(&DAT_006826c4 +
                   *(int *)(&DAT_006826ec + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                   (char)(&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20) != -1) &&
         (((&DAT_006826cc)
           [*(int *)(&DAT_006826ec + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
            (char)(&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20] & 2) != 0)) {
        FUN_0046e571((int)(char)(&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120],
                     *(int *)(&DAT_006826ec + arg_1 * 0x5b20 + arg_2 * 0x120),1);
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
  }
  return 0;
}


