/*
 * Decompiled function: FUN_004ac030
 * Entry Point: 004ac030
 * Size: 636 bytes
 */
#include "duel.h"


uint FUN_004ac030(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int local_8;
  
  if (arg_3 == 0x74) {
    if (((&DAT_004ff594)[DAT_0066644c * 0x34] & 0x40) == 0) {
      uVar1 = 0;
    }
    else {
      FUN_0043071d(0);
      if (arg_1 == DAT_00676510) {
        uVar1 = DAT_00681eb0 & 0x20;
      }
      else if (((DAT_00681eb0 & 0x20) == 0) || (DAT_00666458 != DAT_00676510)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else {
    if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      if (local_8 == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) = local_8;
        (&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] = (undefined1)DAT_0068eef0;
      }
    }
    if (arg_3 == 0x71) {
      if (((*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) != -1) &&
          (((&DAT_006826cc)
            [*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
             (char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20] & 0x20) != 0)) &&
         (((&DAT_004ff594)
           [*(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                    (char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20) * 0x34] & 0x40)
          != 0)) {
        FUN_0046e571((int)(char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120],
                     *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120),2);
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


