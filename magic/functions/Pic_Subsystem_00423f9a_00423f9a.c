/*
 * Decompiled function: Pic_Subsystem_00423f9a
 * Entry Point: 00423f9a
 * Size: 65 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00423f9a(undefined4 arg_1)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f420)(arg_1);
  }
  return uVar1;
}


