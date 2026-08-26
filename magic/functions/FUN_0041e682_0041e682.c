/*
 * Decompiled function: FUN_0041e682
 * Entry Point: 0041e682
 * Size: 566 bytes
 */
#include "magic.h"


undefined4 FUN_0041e682(int arg1,int arg2)

{
  bool bVar1;
  undefined4 uVar2;
  DWORD arg_5;
  uint arg_4;
  int iVar3;
  int iVar4;
  int iVar5;
  uint arg_2;
  int local_8;
  
  if (arg2 == 0) {
    local_8 = DAT_00676d78;
  }
  else {
    local_8 = DAT_00676d7c;
  }
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x10) + *(int *)(arg1 + 0x18) < DAT_007039cc)) {
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
    arg_5 = Ai_Util_004c3bc4(0x30);
    arg_4 = Ai_Util_004c3bc4((*(short *)(local_8 + 4) * 0x30) / (int)*(short *)(local_8 + 6));
    iVar3 = Ai_Util_004c3bc4(0x20);
    arg_2 = iVar3 - (int)arg_4 / 2;
    iVar3 = Ai_Util_004c3bc4(0x106);
    iVar3 = iVar3 - (int)arg_5 / 2;
    if (arg2 == 2) {
      iVar4 = Ai_Util_004c3bc4(4);
      iVar5 = Ai_Util_004c3bc4(8);
      FUN_0050dce0((int *)PTR_DAT_005174e4,arg_2,iVar3,arg_4,arg_5,(int *)g_DisplaySurfaceBackBuffer
                   ,arg_2,iVar3);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,arg_2 + iVar4,iVar3 + iVar4,arg_4 - iVar5,
                        arg_5 - iVar5,local_8);
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2,iVar3,arg_4,arg_5,
                   (int *)g_DisplaySurfaceScreen,arg_2,iVar3);
      if (*(int *)(arg1 + 0x28) != 0) {
        (**(code **)(arg1 + 0x28))(arg1);
      }
    }
    else {
      Sprite_DrawScaled((int *)PTR_DAT_00519c20,arg_2,iVar3,arg_4,arg_5,local_8);
    }
    uVar2 = 1;
  }
  return uVar2;
}


