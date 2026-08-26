/*
 * Decompiled function: Pic_Subsystem_00424165
 * Entry Point: 00424165
 * Size: 73 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00424165(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f438)(arg_1,arg_2,arg_3);
  }
  return uVar1;
}


