/*
 * Decompiled function: Pic_Subsystem_00423e4c
 * Entry Point: 00423e4c
 * Size: 69 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00423e4c(undefined4 value,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f408)(value,arg2);
  }
  return uVar1;
}


