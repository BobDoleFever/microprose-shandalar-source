/*
 * Decompiled function: FUN_004a3f89
 * Entry Point: 004a3f89
 * Size: 251 bytes
 */
#include "duel.h"


undefined4 FUN_004a3f89(int arg_1,int arg_2,int arg_3)

{
  if ((((DAT_0068f230 == 0xcc) || (arg_3 == 199)) && (DAT_00690c48 == arg_2)) &&
     (DAT_0068ecb0 == arg_1)) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      if ((&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1) {
        FUN_0046e571((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                     *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20),2);
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
  }
  return 0;
}


