/*
 * Decompiled function: FUN_0040a95d
 * Entry Point: 0040a95d
 * Size: 404 bytes
 */
#include "magic.h"


void FUN_0040a95d(char *arg_1)

{
  int arg_3;
  int arg_9;
  int arg_10;
  int iVar1;
  int arg_9_00;
  int arg_10_00;
  undefined4 local_18;
  
  arg_3 = DAT_0052245c + -0x118;
  FUN_00510b70(1,0,arg_3,arg_1,(short *)0x0);
  arg_9 = Ai_Util_004c3ba3(0x100);
  arg_10 = Ai_Util_004c3ba3(0x8c);
  iVar1 = Ai_Util_004c3ba3(0x5e);
  for (local_18 = 2; local_18 < 9; local_18 = local_18 + 1) {
    arg_9_00 = (int)(local_18 * arg_9 + (local_18 * arg_9 >> 0x1f & 7U)) >> 3;
    arg_10_00 = (int)(local_18 * arg_10 + (local_18 * arg_10 >> 0x1f & 7U)) >> 3;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,arg_3,0x200,0x118,
                       (int *)g_DisplaySurfaceScreen,DAT_00522458 / 2 - arg_9_00 / 2,
                       iVar1 - arg_10_00 / 2,arg_9_00,arg_10_00);
  }
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,arg_3,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,DAT_00522458 / 2 - arg_9 / 2,
                     iVar1 - arg_10 / 2,arg_9,arg_10);
  FUN_0050b9d5(g_DisplaySurfaceScreen);
  return;
}


