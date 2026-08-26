/*
 * Decompiled function: Pic_Subsystem_00423c39
 * Entry Point: 00423c39
 * Size: 73 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00423c39(undefined4 filename,undefined4 loop_flag,undefined4 out_handle)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f3e8)(filename,loop_flag,out_handle);
  }
  return uVar1;
}


