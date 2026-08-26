/*
 * Decompiled function: FUN_004212f0
 * Entry Point: 004212f0
 * Size: 479 bytes
 */
#include "magic.h"


undefined4 FUN_004212f0(int arg1,int arg2)

{
  int arg_6;
  int arg_2;
  int arg_3;
  uint arg_4;
  DWORD arg_5;
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
    arg_6 = *(int *)(&DAT_00538a88 + arg2 * 4 + (*(int *)(arg1 + 0x2c) + -1) * 0x10);
    arg_2 = *(int *)(arg1 + 0x10);
    arg_3 = *(int *)(arg1 + 0x14);
    arg_4 = *(uint *)(arg1 + 0x18);
    arg_5 = *(DWORD *)(arg1 + 0x1c);
    if (arg2 == 2) {
      Sprite_DrawScaled((int *)g_DisplaySurfaceWork,0,arg_3 + 0x80,arg_4,arg_5,
                        *(int *)(&DAT_00538a8c + (*(int *)(arg1 + 0x2c) + -1) * 0x10));
      Sprite_DrawScaled((int *)g_DisplaySurfaceWork,2,arg_3 + 0x82,arg_4 - 4,arg_5 - 4,arg_6);
      FUN_0050dce0((int *)g_DisplaySurfaceWork,0,arg_3 + 0x80,arg_4,arg_5,
                   (int *)g_DisplaySurfaceScreen,arg_2,arg_3);
      if (*(int *)(arg1 + 0x28) != 0) {
        (**(code **)(arg1 + 0x28))(arg1);
      }
    }
    else {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,arg_5,arg_6);
    }
    uVar2 = 1;
  }
  return uVar2;
}


