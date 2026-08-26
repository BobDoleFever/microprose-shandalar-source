/*
 * Decompiled function: SetSndMarker
 * Entry Point: 0043ddfe
 * Size: 69 bytes
 */
#include "duel.h"


undefined4 SetSndMarker(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_00694514)(arg1,arg2);
  }
  return uVar1;
}


