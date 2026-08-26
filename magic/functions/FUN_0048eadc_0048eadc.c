/*
 * Decompiled function: FUN_0048eadc
 * Entry Point: 0048eadc
 * Size: 396 bytes
 */
#include "magic.h"


undefined4 FUN_0048eadc(int arg1,int arg2)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    if (arg2 == 2) {
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,1,1,*(int *)(arg1 + 0x18) + -2,
                        *(int *)(arg1 + 0x1c) + -2,iRam00676b98);
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,*(int *)(arg1 + 0x18) + 1,
                   *(int *)(arg1 + 0x1c) + 1,(int *)g_DisplaySurfaceScreen,*(int *)(arg1 + 0x10),
                   *(int *)(arg1 + 0x14));
      if (*(int *)(arg1 + 0x28) != 0) {
        (**(code **)(arg1 + 0x28))(arg1);
      }
    }
    else {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                        *(int *)(arg1 + 0x18),*(int *)(arg1 + 0x1c),(&DAT_00676b90)[arg2]);
    }
    uVar2 = 1;
  }
  return uVar2;
}


