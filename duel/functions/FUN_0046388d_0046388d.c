/*
 * Decompiled function: FUN_0046388d
 * Entry Point: 0046388d
 * Size: 433 bytes
 */
#include "duel.h"


bool FUN_0046388d(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  
  if (arg_3 == 0x73) {
    bVar1 = (*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0;
  }
  else {
    if ((arg_3 == 0x6d) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      FUN_0049b2c1(arg_1,3,1);
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_0068f0f4 = 3;
    }
    if ((((arg_3 == 0x7f) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
       ((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
      FUN_0049b1a9(arg_1,3,1);
    }
    if (((arg_3 == 0x8a) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c +
                     (int)(0x18 / (longlong)(*(int *)(&DAT_0068ef5c + arg_1 * 0x20) + 2));
    }
    if (((arg_3 == 0x8b) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c -
                     (int)(0x60 / (longlong)(*(int *)(&DAT_0068ef5c + arg_1 * 0x20) + 2));
    }
    bVar1 = false;
  }
  return bVar1;
}


