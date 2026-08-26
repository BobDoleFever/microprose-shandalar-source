/*
 * Decompiled function: InitSndTrack
 * Entry Point: 0043da45
 * Size: 60 bytes
 */
#include "duel.h"


undefined4 InitSndTrack(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3)

{
  undefined4 uVar1;
  
  if (DAT_004f79a4 == 0) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_006944d8)(arg_1,arg_2,arg_3);
  }
  return uVar1;
}


