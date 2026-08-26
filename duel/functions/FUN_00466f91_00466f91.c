/*
 * Decompiled function: FUN_00466f91
 * Entry Point: 00466f91
 * Size: 287 bytes
 */
#include "duel.h"


bool FUN_00466f91(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  
  if (arg_3 == 0x73) {
    bVar1 = (*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0;
  }
  else {
    if ((arg_3 == 0x6d) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      FUN_0049b2c1(arg_1,4,1);
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_0068f0f4 = 4;
    }
    if ((((arg_3 == 0x7f) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
       ((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
      FUN_0049b1a9(arg_1,4,1);
    }
    bVar1 = false;
  }
  return bVar1;
}


