/*
 * Decompiled function: FUN_0040cb4f
 * Entry Point: 0040cb4f
 * Size: 110 bytes
 */
#include "magic.h"


uint FUN_0040cb4f(int arg_1,int arg_2,char arg_3)

{
  uint uVar1;
  
  if ((arg_1 < 0x40) && (-1 < arg_1)) {
    if ((arg_2 < 0x40) && (-1 < arg_2)) {
      uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg_1,arg_2 + 0x40);
      uVar1 = uVar1 & 1 << (arg_3 - 1U & 0x1f);
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


