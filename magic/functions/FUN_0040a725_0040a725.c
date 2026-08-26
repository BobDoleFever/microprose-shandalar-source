/*
 * Decompiled function: FUN_0040a725
 * Entry Point: 0040a725
 * Size: 350 bytes
 */
#include "magic.h"


void FUN_0040a725(char *arg_1)

{
  int arg_9;
  int arg_10;
  undefined4 local_8;
  
  Mem_AllocOrFree_00510e20(1,arg_1);
  *(undefined4 *)g_DisplaySurfaceScreen = 1;
  FUN_0048a2a5(0,0,0x13f,199,0xff);
  *(undefined4 *)g_DisplaySurfaceScreen = 0;
  for (local_8 = 2; local_8 < 9; local_8 = local_8 + 1) {
    arg_9 = (int)(DAT_00522458 * local_8 + ((int)(DAT_00522458 * local_8) >> 0x1f & 7U)) >> 3;
    arg_10 = (int)(DAT_0052245c * local_8 + ((int)(DAT_0052245c * local_8) >> 0x1f & 7U)) >> 3;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x140,200,(int *)g_DisplaySurfaceScreen
                       ,(int)DAT_00522458 / 2 - arg_9 / 2,
                       (((int)DAT_0052245c / 3) * (8 - local_8) +
                       (local_8 + -2) * ((int)DAT_0052245c / 2)) / 6 - arg_10 / 2,arg_9,arg_10);
    FUN_00501736((int)((10 - local_8) + (10 - local_8 >> 0x1f & 3U)) >> 2);
  }
  FUN_0050dce0((int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c,
               (int *)g_DisplaySurfaceBackBuffer,0,0);
  return;
}


