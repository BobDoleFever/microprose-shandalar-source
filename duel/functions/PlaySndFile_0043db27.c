/*
 * Decompiled function: PlaySndFile
 * Entry Point: 0043db27
 * Size: 73 bytes
 */
#include "duel.h"


undefined4 PlaySndFile(undefined4 filename,undefined4 loop_flag,undefined4 out_handle)

{
  undefined4 uVar1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_006944e8)(filename,loop_flag,out_handle);
  }
  return uVar1;
}


