/*
 * Decompiled function: FUN_0040c761
 * Entry Point: 0040c761
 * Size: 95 bytes
 */
#include "magic.h"


uint FUN_0040c761(int arg1,int arg2)

{
  uint uVar1;
  
  if ((0x3f < arg1) || (arg1 < 0)) {
    arg1 = 0;
  }
  if ((0x3f < arg2) || (arg2 < 0)) {
    arg2 = 0;
  }
  uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg1,arg2);
  return uVar1 & 0xf;
}


