/*
 * Decompiled function: Pic_Subsystem_00423ed6
 * Entry Point: 00423ed6
 * Size: 58 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00423ed6(void)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f410)();
  }
  return uVar1;
}


