/*
 * Decompiled function: IsSndLoaded
 * Entry Point: 0043e011
 * Size: 66 bytes
 */
#include "duel.h"


undefined4 IsSndLoaded(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_00694534)(arg1,arg2);
  }
  return uVar1;
}


