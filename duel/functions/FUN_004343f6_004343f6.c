/*
 * Decompiled function: FUN_004343f6
 * Entry Point: 004343f6
 * Size: 70 bytes
 */
#include "duel.h"


undefined4 FUN_004343f6(int *arg1,int *arg2)

{
  undefined4 uVar1;
  
  if (*arg2 < *arg1) {
    uVar1 = 1;
  }
  else if (*arg1 < *arg2) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


