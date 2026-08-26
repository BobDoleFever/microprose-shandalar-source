/*
 * Decompiled function: FUN_0040c274
 * Entry Point: 0040c274
 * Size: 59 bytes
 */
#include "magic.h"


void FUN_0040c274(undefined4 arg_1,int y,int width,undefined4 arg_4)

{
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x14) = 0;
  FUN_0040c1ad(arg_1,y,width,arg_4);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x14) = 1;
  return;
}


