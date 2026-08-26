/*
 * Decompiled function: SetPitch
 * Entry Point: 0043dc26
 * Size: 69 bytes
 */
#include "duel.h"


undefined4 SetPitch(undefined4 value,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_006944f8)(value,arg2);
  }
  return uVar1;
}


