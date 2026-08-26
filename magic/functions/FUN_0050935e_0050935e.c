/*
 * Decompiled function: FUN_0050935e
 * Entry Point: 0050935e
 * Size: 441 bytes
 */
#include "magic.h"


undefined4 FUN_0050935e(int arg1,int arg2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint arg_4;
  int iVar4;
  uint arg_2;
  int *local_c;
  
  iVar4 = DAT_0061e108;
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
      local_c = (int *)g_DisplaySurfaceBackBuffer;
    }
    else {
      local_c = (int *)g_DisplaySurfaceScreen;
    }
    iVar3 = Ai_Util_004c3ba3((int)*(short *)(DAT_0061e108 + 4));
    arg_4 = iVar3 / 2;
    iVar4 = Ai_Util_004c3ba3((int)*(short *)(iVar4 + 6));
    arg_2 = DAT_00522458 / 2 - (int)arg_4 / 2;
    iVar3 = Ai_Util_004c3ba3(0x112);
    iVar3 = iVar3 / 2;
    Sprite_DrawScaled(local_c,arg_2,iVar3,arg_4,iVar4 / 2,(&DAT_0061e108)[arg2]);
    if (arg2 == 2) {
      Adventure_Audio_PlayEffectAtVolume(0x12,100,100,0);
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2,iVar3,arg_4,iVar4 / 2,
                   (int *)g_DisplaySurfaceScreen,arg_2,iVar3);
      DAT_00626600 = 1;
    }
    uVar2 = 1;
  }
  return uVar2;
}


