/*
 * Decompiled function: Pic_Subsystem_00423bf4
 * Entry Point: 00423bf4
 * Size: 69 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00423bf4(undefined4 sound_id,undefined4 flags)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f3e4)(sound_id,flags);
  }
  return uVar1;
}


