/*
 * Decompiled function: FUN_00490c33
 * Entry Point: 00490c33
 * Size: 278 bytes
 */
#include "magic.h"


undefined4 FUN_00490c33(int arg1,int arg2)

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
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                      *(int *)(arg1 + 0x18),*(int *)(arg1 + 0x1c),*(int *)(&DAT_00676be0 + arg2 * 4)
                     );
    if ((arg2 == 2) && (*(int *)(arg1 + 0x28) != 0)) {
      (**(code **)(arg1 + 0x28))(arg1);
    }
    uVar2 = 1;
  }
  return uVar2;
}


