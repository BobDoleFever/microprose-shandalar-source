/*
 * Decompiled function: Pic_Subsystem_00423f55
 * Entry Point: 00423f55
 * Size: 69 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00423f55(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f418)(arg1,arg2);
  }
  return uVar1;
}


