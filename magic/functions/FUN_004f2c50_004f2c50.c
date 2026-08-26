/*
 * Decompiled function: FUN_004f2c50
 * Entry Point: 004f2c50
 * Size: 140 bytes
 */
#include "magic.h"


undefined4 FUN_004f2c50(HWND arg_1,int y,int width,int height)

{
  uint *arg_3;
  
  if (y == 0) {
    return 0;
  }
  arg_3 = (uint *)FUN_004f27c0(0,y,width,height);
  Palette_DitherBitmapRGB
            (DAT_0052a1b8,DAT_0052a1bc,arg_3,height,width,
             (DAT_00530068 - (width * 3) % DAT_00530068) % DAT_00530068);
  FUN_0050ec20(arg_1,arg_3,0,0,width,height);
  if (*(uint **)(y + 0x1ac) != arg_3) {
    free(arg_3);
  }
  return 1;
}


