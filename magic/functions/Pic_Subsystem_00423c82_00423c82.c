/*
 * Decompiled function: Pic_Subsystem_00423c82
 * Entry Point: 00423c82
 * Size: 65 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00423c82(undefined4 sound_id)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f3ec)(sound_id);
  }
  return uVar1;
}


