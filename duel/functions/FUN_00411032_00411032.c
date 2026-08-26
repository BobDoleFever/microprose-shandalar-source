/*
 * Decompiled function: FUN_00411032
 * Entry Point: 00411032
 * Size: 170 bytes
 */
#include "duel.h"


undefined4 FUN_00411032(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 +
                   (*(int *)(&DAT_0068ee70 + (5 - arg_1) * 4) - *(int *)(&DAT_0068ee80 + arg_1 * 4))
                   * 0xc;
  }
  if (((arg_3 == 0x32) && (((&DAT_006826cc)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] & 4) != 0)
      ) && (DAT_00666458 == DAT_0068ecb0)) {
    DAT_0066642c = DAT_0066642c + -1;
  }
  return 0;
}


