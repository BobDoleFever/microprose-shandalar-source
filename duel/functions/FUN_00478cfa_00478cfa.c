/*
 * Decompiled function: FUN_00478cfa
 * Entry Point: 00478cfa
 * Size: 78 bytes
 */
#include "duel.h"


undefined4 FUN_00478cfa(int arg1,uint arg2)

{
  undefined4 uVar1;
  
  if ((arg1 == 0) && ((arg2 & 0x100) != 0)) {
    uVar1 = 1;
  }
  else if ((arg1 == 0) || ((arg2 & 0x100) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


