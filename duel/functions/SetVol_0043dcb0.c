/*
 * Decompiled function: SetVol
 * Entry Point: 0043dcb0
 * Size: 69 bytes
 */
#include "duel.h"


undefined4 SetVol(undefined4 value,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_00694500)(value,arg2);
  }
  return uVar1;
}


