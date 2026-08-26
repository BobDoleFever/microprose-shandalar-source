/*
 * Decompiled function: FUN_0040b143
 * Entry Point: 0040b143
 * Size: 389 bytes
 */
#include "magic.h"


undefined4 FUN_0040b143(int arg_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int arg_6;
  int iVar5;
  int iVar6;
  
  arg_6 = DAT_006498e4;
  iVar1 = *(int *)(arg_1 + 0x30);
  Pic_Subsystem_0044b84b();
  iVar5 = *(int *)(arg_1 + 0x14) + *(int *)(arg_1 + 0x70) / 2;
  if (iVar5 <= DAT_0067bda8) {
    iVar5 = DAT_0067bda8;
  }
  iVar6 = (*(int *)(arg_1 + 0x14) + *(int *)(arg_1 + 0x1c)) - *(int *)(arg_1 + 0x70) / 2;
  if (iVar5 <= iVar6) {
    iVar6 = iVar5;
  }
  iVar5 = *(int *)(arg_1 + 0x14);
  iVar2 = *(int *)(arg_1 + 0x70);
  iVar3 = *(int *)(arg_1 + 0x1c);
  iVar4 = *(int *)(arg_1 + 0x70);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14),
                    *(int *)(arg_1 + 0x18),*(int *)(arg_1 + 0x1c),DAT_00641878);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(arg_1 + 0x10),
                    iVar6 - *(int *)(arg_1 + 0x70) / 2,*(int *)(arg_1 + 0x18),
                    ((int)*(short *)(arg_6 + 6) * *(int *)(arg_1 + 0x18)) / *(int *)(arg_1 + 8),
                    arg_6);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,*(uint *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14),
               *(uint *)(arg_1 + 0x18),*(DWORD *)(arg_1 + 0x1c),(int *)g_DisplaySurfaceScreen,
               *(int *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14));
  Castle_Process_0040b7fa((((iVar6 - iVar5) - iVar2 / 2) * iVar1) / (iVar3 - iVar4));
  DAT_005384d0 = *(undefined4 *)(arg_1 + 0x2c);
  return *(undefined4 *)(arg_1 + 0x2c);
}


