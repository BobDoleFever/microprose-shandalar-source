/*
 * Decompiled function: FUN_0040c889
 * Entry Point: 0040c889
 * Size: 113 bytes
 */
#include "magic.h"


void FUN_0040c889(uint arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  
  if ((((arg_2 < 0x40) && (-1 < arg_2)) && (arg_3 < 0x40)) && (-1 < arg_3)) {
    uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg_2,arg_3);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,arg_2,arg_3,uVar1 & ~arg_1);
  }
  return;
}


