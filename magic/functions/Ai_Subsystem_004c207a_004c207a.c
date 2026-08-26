/*
 * Decompiled function: Ai_Subsystem_004c207a
 * Entry Point: 004c207a
 * Size: 497 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004c207a(int arg1,int arg2)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  int local_28;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < DAT_007039cc)) {
      bVar2 = false;
    }
    else if ((DAT_007039c8 < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < DAT_007039c8)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)g_DisplaySurfaceScreen;
    *(undefined4 *)g_DisplaySurfaceScreen = 0;
    iVar1 = *(int *)(&DAT_0052d8c4 + *(int *)(arg1 + 0x2c) * 0x54);
    if (arg2 == 0) {
      local_28 = 0;
    }
    else if (arg2 == 1) {
      local_28 = 1;
    }
    else if (arg2 == 2) {
      local_28 = 2;
    }
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(&DAT_0052d8a8)[iVar1 * 0x15],
                      *(int *)(&DAT_0052d8ac + iVar1 * 0x54),*(int *)(&DAT_0052d8b0 + iVar1 * 0x54),
                      *(int *)(&DAT_0052d8b4 + iVar1 * 0x54),(&DAT_00641890)[iVar1 * 3 + local_28]);
    *(undefined4 *)g_DisplaySurfaceScreen = uVar3;
    if ((arg2 == 2) && (*(int *)(arg1 + 0x28) != 0)) {
      (**(code **)(arg1 + 0x28))(arg1);
    }
    uVar3 = 1;
  }
  return uVar3;
}


