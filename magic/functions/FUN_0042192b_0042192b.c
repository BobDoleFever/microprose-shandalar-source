/*
 * Decompiled function: FUN_0042192b
 * Entry Point: 0042192b
 * Size: 182 bytes
 */
#include "magic.h"


undefined4 FUN_0042192b(int arg_1)

{
  int iVar1;
  int iVar2;
  int arg_6;
  
  arg_6 = DAT_00538ac4;
  iVar1 = *(int *)(arg_1 + 0x70);
  iVar2 = *(int *)(arg_1 + 0x14);
  Surface_FillRect((int *)g_DisplaySurfaceScreen,*(int *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14),
                   *(int *)(arg_1 + 0x18),*(int *)(arg_1 + 0x1c),0);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(arg_1 + 0x10),
                    (iVar2 + iVar1 / 2) - *(int *)(arg_1 + 0x70) / 2,*(int *)(arg_1 + 0x18),
                    ((int)*(short *)(arg_6 + 6) * *(int *)(arg_1 + 0x18)) / *(int *)(arg_1 + 8),
                    arg_6);
  return 0;
}


