/*
 * Decompiled function: FUN_0040b2c8
 * Entry Point: 0040b2c8
 * Size: 250 bytes
 */
#include "magic.h"


undefined4 FUN_0040b2c8(int arg_1)

{
  int iVar1;
  int iVar2;
  int arg_6;
  
  arg_6 = DAT_006498e4;
  iVar1 = *(int *)(arg_1 + 0x70);
  iVar2 = *(int *)(arg_1 + 0x14);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14),
                    *(int *)(arg_1 + 0x18),*(int *)(arg_1 + 0x1c),DAT_00641878);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(arg_1 + 0x10),
                    (iVar2 + iVar1 / 2) - *(int *)(arg_1 + 0x70) / 2,*(int *)(arg_1 + 0x18),
                    ((int)*(short *)(arg_6 + 6) * *(int *)(arg_1 + 0x18)) / *(int *)(arg_1 + 8),
                    arg_6);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,*(uint *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14),
               *(uint *)(arg_1 + 0x18),*(DWORD *)(arg_1 + 0x1c),(int *)g_DisplaySurfaceScreen,
               *(int *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14));
  return 0;
}


