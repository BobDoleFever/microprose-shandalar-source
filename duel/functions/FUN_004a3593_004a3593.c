/*
 * Decompiled function: FUN_004a3593
 * Entry Point: 004a3593
 * Size: 341 bytes
 */
#include "duel.h"


undefined4 FUN_004a3593(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x34) &&
       (*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) == DAT_00690c48)) &&
      ((char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] == DAT_0068ecb0)) &&
     (DAT_00690c48 != -1)) {
    DAT_0066642c = DAT_0066642c & ~*(uint *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120);
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    if ((&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1) {
      *(undefined4 *)
       (&DAT_006826fc +
       *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
       (char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20) = 0x8000000;
    }
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}


