/*
 * Decompiled function: FUN_00417d49
 * Entry Point: 00417d49
 * Size: 408 bytes
 */
#include "duel.h"


undefined4 FUN_00417d49(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x82) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    *(uint *)(&DAT_006827c8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006827c8 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffc;
  }
  if ((((arg_3 == 0x84) && (DAT_00690c48 == arg_2)) &&
      ((DAT_0068ecb0 == arg_1 &&
       ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0 && (DAT_00666458 == arg_1))))
      )) && (DAT_00681eb4 == arg_1)) {
    *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    (&DAT_006827cc)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827cc)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\t';
  }
  if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    (&DAT_006827cc)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827cc)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\t';
  }
  return 0;
}


