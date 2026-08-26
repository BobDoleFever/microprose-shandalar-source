/*
 * Decompiled function: FUN_0040a5de
 * Entry Point: 0040a5de
 * Size: 327 bytes
 */
#include "magic.h"


void FUN_0040a5de(void)

{
  int arg_9;
  int arg_10;
  undefined4 local_8;
  
  FUN_0050dce0((int *)g_DisplaySurfaceScreen,(int)DAT_00522458 / 2 - 0x50,
               (int)DAT_0052245c / 3 + -0x3c,0xa0,0x78,(int *)g_DisplaySurfaceBackBuffer,0,0);
  for (local_8 = 3; local_8 < 9; local_8 = local_8 + 1) {
    arg_9 = (int)(DAT_00522458 * local_8 + ((int)(DAT_00522458 * local_8) >> 0x1f & 7U)) >> 3;
    arg_10 = (int)(DAT_0052245c * local_8 + ((int)(DAT_0052245c * local_8) >> 0x1f & 7U)) >> 3;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0xa0,0x78,(int *)g_DisplaySurfaceScreen
                       ,(int)DAT_00522458 / 2 - arg_9 / 2,
                       (((int)DAT_0052245c / 3) * (8 - local_8) +
                       ((int)DAT_0052245c / 2) * (local_8 + -2)) / 6 - arg_10 / 2,arg_9,arg_10);
  }
  FUN_0050dce0((int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c,
               (int *)g_DisplaySurfaceBackBuffer,0,0);
  FUN_0040a3e1();
  return;
}


