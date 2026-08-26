/*
 * Decompiled function: FUN_0040c3cc
 * Entry Point: 0040c3cc
 * Size: 85 bytes
 */
#include "magic.h"


void FUN_0040c3cc(char *arg_1,int y,int width,undefined4 arg_4)

{
  int iVar1;
  
  iVar1 = FUN_0040c465(arg_1);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x14) = 0;
  FUN_0040c1ad(arg_1,y - iVar1 / 2,width,arg_4);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x14) = 1;
  return;
}


