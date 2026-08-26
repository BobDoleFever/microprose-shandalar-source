/*
 * Decompiled function: FUN_00438636
 * Entry Point: 00438636
 * Size: 134 bytes
 */
#include "duel.h"


undefined4 FUN_00438636(HWND arg_1,uint y,HWND arg_3,undefined4 arg_4)

{
  undefined4 uVar1;
  
  if (y == 0x30f) {
    uVar1 = FUN_00472b60(arg_1,0x30f,arg_3,arg_4);
  }
  else if ((y < 0x310) || (0x311 < y)) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00472b60(arg_1,y,arg_3,arg_4);
  }
  return uVar1;
}


