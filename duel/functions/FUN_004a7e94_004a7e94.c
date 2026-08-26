/*
 * Decompiled function: FUN_004a7e94
 * Entry Point: 004a7e94
 * Size: 208 bytes
 */
#include "duel.h"


undefined4 FUN_004a7e94(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      FUN_00461047(arg_1,arg_2);
    }
    if (arg_3 == 0x71) {
      iVar2 = FUN_004612b0(arg_1,arg_2,0x71,4);
      if (iVar2 != 0) {
        Mem_AllocOrFree_004afd1c(arg_1,2,arg_1,arg_2);
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


