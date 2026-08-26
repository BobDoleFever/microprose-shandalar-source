/*
 * Decompiled function: StopSnd
 * Entry Point: 0043db70
 * Size: 65 bytes
 */
#include "duel.h"


undefined4 StopSnd(undefined4 sound_id)

{
  undefined4 uVar1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_006944ec)(sound_id);
  }
  return uVar1;
}


