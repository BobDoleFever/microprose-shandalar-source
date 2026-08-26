/*
 * Decompiled function: Adventure_Audio_GetTrackStatus
 * Entry Point: 004ec65a
 * Size: 115 bytes
 */
#include "magic.h"


undefined4 Adventure_Audio_GetTrackStatus(undefined4 arg_1)

{
  undefined4 uVar1;
  
  switch(arg_1) {
  case 1:
    uVar1 = 4;
    break;
  case 2:
    uVar1 = 2;
    break;
  case 3:
    uVar1 = 3;
    break;
  case 4:
    uVar1 = 1;
    break;
  case 5:
    uVar1 = 0;
    break;
  case 6:
    uVar1 = 5;
    break;
  default:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


