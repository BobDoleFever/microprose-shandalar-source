/*
 * Decompiled function: Palette_RemapBitmapRGB
 * Entry Point: 004946f0
 * Size: 93 bytes
 */
#include "magic.h"


undefined4 Palette_RemapBitmapRGB(uint *x,int y,int width,int height)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint arg_1;
  undefined4 local_4;
  
  iVar2 = width * 3;
  if (0 < y) {
    local_4 = y;
    do {
      iVar4 = 0;
      arg_1 = *x;
      if (0 < iVar2) {
        do {
          uVar1 = *(uint *)(iVar4 + 3 + (int)x);
          iVar5 = iVar4 + 3;
          uVar3 = Color_FindNearestRGB(arg_1);
          *(undefined4 *)(iVar4 + (int)x) = uVar3;
          iVar4 = iVar5;
          arg_1 = uVar1;
        } while (iVar5 < iVar2);
      }
      x = (uint *)((int)x + height + iVar2);
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return 0;
}


