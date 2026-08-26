/*
 * Decompiled function: FUN_00447a88
 * Entry Point: 00447a88
 * Size: 100 bytes
 */
#include "duel.h"


uint FUN_00447a88(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  uint local_8;
  
  iVar1 = FUN_00446de2(arg1,arg2);
  if (iVar1 == 0) {
    uVar2 = FUN_004478fb(arg1,arg2);
    local_8 = (uint)((uVar2 & 0x1000) != 0);
  }
  else {
    local_8 = 0xffffffff;
  }
  return local_8;
}


