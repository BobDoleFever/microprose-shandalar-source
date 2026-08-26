/*
 * Decompiled function: Pic_Subsystem_00424065
 * Entry Point: 00424065
 * Size: 66 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00424065(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_0067f428)(arg1,arg2);
  }
  return uVar1;
}


