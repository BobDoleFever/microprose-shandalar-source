/*
 * Decompiled function: FUN_00446de2
 * Entry Point: 00446de2
 * Size: 78 bytes
 */
#include "duel.h"


undefined4 FUN_00446de2(int arg1,int arg2)

{
  undefined4 uVar1;
  
  if ((arg1 == 0) || (arg1 == 1)) {
    if ((arg2 < 0) || (0x50 < arg2)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


