/*
 * Decompiled function: FUN_00464774
 * Entry Point: 00464774
 * Size: 315 bytes
 */
#include "duel.h"


undefined4 FUN_00464774(int arg_1,int arg_2,int arg_3)

{
  if ((DAT_00690c48 == arg_2) && (arg_1 == DAT_0068ecb0)) {
    *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffcffff;
  }
  if (arg_3 == 199) {
    FUN_0046e571(arg_1,arg_2,1);
  }
  if ((((DAT_0068f230 == 0xcd) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) &&
     (arg_1 == DAT_00681ec4)) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      FUN_0046e571(arg_1,arg_2,1);
    }
  }
  if (((arg_3 == 0x8a) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0069340c = DAT_0069340c + -0x3c;
  }
  if (((arg_3 == 0x8b) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0069340c = DAT_0069340c + 0x3c;
  }
  return 0;
}


