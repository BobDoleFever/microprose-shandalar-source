/*
 * Decompiled function: GetSndTime
 * Entry Point: 0043de88
 * Size: 65 bytes
 */
#include "duel.h"


undefined4 GetSndTime(undefined4 arg_1)

{
  undefined4 uVar1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_00694520)(arg_1);
  }
  return uVar1;
}


