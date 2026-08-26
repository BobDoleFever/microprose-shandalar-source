/*
 * Decompiled function: FUN_0040c8fa
 * Entry Point: 0040c8fa
 * Size: 95 bytes
 */
#include "magic.h"


undefined4 FUN_0040c8fa(int arg1,int arg2)

{
  undefined4 uVar1;
  
  if ((arg1 < 0x40) && (-1 < arg1)) {
    if ((arg2 < 0x40) && (-1 < arg2)) {
      uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg1 + 0x40,arg2);
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


