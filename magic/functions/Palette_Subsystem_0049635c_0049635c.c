/*
 * Decompiled function: Palette_Subsystem_0049635c
 * Entry Point: 0049635c
 * Size: 134 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_0049635c(HWND arg_1,uint y,HWND arg_3,undefined4 arg_4)

{
  undefined4 uVar1;
  
  if (y == 0x30f) {
    uVar1 = FUN_004f5d1a(arg_1,0x30f,arg_3,arg_4);
  }
  else if ((y < 0x310) || (0x311 < y)) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_004f5d1a(arg_1,y,arg_3,arg_4);
  }
  return uVar1;
}


