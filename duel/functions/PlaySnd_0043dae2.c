/*
 * Decompiled function: PlaySnd
 * Entry Point: 0043dae2
 * Size: 69 bytes
 */
#include "duel.h"


undefined4 PlaySnd(undefined4 sound_id,undefined4 flags)

{
  undefined4 uVar1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_006944e4)(sound_id,flags);
  }
  return uVar1;
}


