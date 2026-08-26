/*
 * Decompiled function: FUN_004217ea
 * Entry Point: 004217ea
 * Size: 321 bytes
 */
#include "magic.h"


undefined4 FUN_004217ea(int arg_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int arg_6;
  int iVar4;
  int iVar5;
  
  arg_6 = DAT_00538ac4;
  Pic_Subsystem_0044b84b();
  iVar4 = *(int *)(arg_1 + 0x14) + *(int *)(arg_1 + 0x70) / 2;
  if (iVar4 <= DAT_0067bda8) {
    iVar4 = DAT_0067bda8;
  }
  iVar5 = (*(int *)(arg_1 + 0x14) + *(int *)(arg_1 + 0x1c)) - *(int *)(arg_1 + 0x70) / 2;
  if (iVar4 <= iVar5) {
    iVar5 = iVar4;
  }
  iVar4 = *(int *)(arg_1 + 0x14);
  iVar1 = *(int *)(arg_1 + 0x70);
  iVar2 = *(int *)(arg_1 + 0x1c);
  iVar3 = *(int *)(arg_1 + 0x70);
  Surface_FillRect((int *)g_DisplaySurfaceScreen,*(int *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14),
                   *(int *)(arg_1 + 0x18),*(int *)(arg_1 + 0x1c),0);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(arg_1 + 0x10),
                    iVar5 - *(int *)(arg_1 + 0x70) / 2,*(int *)(arg_1 + 0x18),
                    ((int)*(short *)(arg_6 + 6) * *(int *)(arg_1 + 0x18)) / *(int *)(arg_1 + 8),
                    arg_6);
  FUN_00422b04((((iVar5 - iVar4) - iVar1 / 2) * 0x11) / (iVar2 - iVar3));
  DAT_00538a28 = *(undefined4 *)(arg_1 + 0x2c);
  return *(undefined4 *)(arg_1 + 0x2c);
}


