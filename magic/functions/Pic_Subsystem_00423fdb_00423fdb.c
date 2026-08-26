/*
 * Decompiled function: Pic_Subsystem_00423fdb
 * Entry Point: 00423fdb
 * Size: 69 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00423fdb(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f41c)(arg1,arg2);
  }
  return uVar1;
}


