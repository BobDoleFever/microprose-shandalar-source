/*
 * Decompiled function: FUN_0040ae70
 * Entry Point: 0040ae70
 * Size: 407 bytes
 */
#include "magic.h"


undefined4 FUN_0040ae70(int arg1,int arg2)

{
  bool bVar1;
  undefined4 uVar2;
  int local_28;
  
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
    if (arg2 == 0) {
      local_28 = 0;
    }
    else if (arg2 == 1) {
      local_28 = 1;
    }
    else if (arg2 == 2) {
      local_28 = 2;
    }
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,DAT_00517210,DAT_00517214,DAT_00517218,
                      DAT_0051721c,(&DAT_00641890)[local_28 + DAT_0051722c * 3]);
    if ((arg2 == 2) && (*(int *)(arg1 + 0x28) != 0)) {
      (**(code **)(arg1 + 0x28))(arg1);
    }
    uVar2 = 1;
  }
  return uVar2;
}


