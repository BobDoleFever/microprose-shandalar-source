/*
 * Decompiled function: FUN_004687a3
 * Entry Point: 004687a3
 * Size: 142 bytes
 */
#include "duel.h"


undefined4 FUN_004687a3(int arg_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  iVar1 = Action_ValidateTarget_0041e2a2
                    (arg_1,arg_1,arg_1,0x200,1,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                     &DAT_006679f0,0,&local_c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if (DAT_0066aaf4 != 1) {
      FUN_0048d00c(0xf);
    }
    FUN_0046e571(local_c,local_8,3);
    uVar2 = 1;
  }
  return uVar2;
}


