/*
 * Decompiled function: FUN_0041e486
 * Entry Point: 0041e486
 * Size: 508 bytes
 */
#include "magic.h"


undefined4 FUN_0041e486(int arg1,int arg2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
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
      iVar3 = Ai_Util_004c3bc4(4);
      iVar4 = Ai_Util_004c3bc4(8);
      FUN_0050dce0((int *)PTR_DAT_005174e4,*(uint *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                   *(uint *)(arg1 + 0x18),*(DWORD *)(arg1 + 0x1c),(int *)g_DisplaySurfaceBackBuffer,
                   *(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14));
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(arg1 + 0x10) + iVar3,
                        *(int *)(arg1 + 0x14) + iVar3,*(int *)(arg1 + 0x18) - iVar4,
                        *(int *)(arg1 + 0x1c) - iVar4,*(int *)(arg1 + 0x4c));
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,*(uint *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                   *(uint *)(arg1 + 0x18),*(DWORD *)(arg1 + 0x1c),(int *)g_DisplaySurfaceScreen,
                   *(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14));
      if (*(int *)(arg1 + 0x28) != 0) {
        (**(code **)(arg1 + 0x28))(arg1);
      }
    }
    else {
      Sprite_DrawScaled((int *)PTR_DAT_00519c20,*(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                        *(int *)(arg1 + 0x18),*(int *)(arg1 + 0x1c),*(int *)(arg1 + 0x44 + arg2 * 4)
                       );
    }
    uVar2 = 1;
  }
  return uVar2;
}


