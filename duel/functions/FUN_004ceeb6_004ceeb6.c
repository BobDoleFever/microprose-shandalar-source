/*
 * Decompiled function: FUN_004ceeb6
 * Entry Point: 004ceeb6
 * Size: 194 bytes
 */
#include "duel.h"


undefined4 FUN_004ceeb6(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 0x33) && (DAT_0068ecb0 == arg_1)) &&
        (((&DAT_006826cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] & 0x14) == 0)) &&
       ((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x20) == 0 &&
        (((&DAT_006826cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] & 2) != 0)))) {
      DAT_0066642c = DAT_0066642c + 2;
    }
    uVar1 = 0;
  }
  return uVar1;
}


