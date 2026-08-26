/*
 * Decompiled function: FUN_004a9754
 * Entry Point: 004a9754
 * Size: 139 bytes
 */
#include "duel.h"


undefined4 FUN_004a9754(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((arg_3 == 0x32) &&
       (((&DAT_006826cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] & 4) != 0)) {
      DAT_0066642c = DAT_0066642c + 2;
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


