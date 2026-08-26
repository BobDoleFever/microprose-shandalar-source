/*
 * Decompiled function: Pic_Subsystem_0044e2e7
 * Entry Point: 0044e2e7
 * Size: 577 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0044e2e7(int x,int y,int width,int height)

{
  int iVar1;
  int iVar2;
  int arg2;
  int iVar3;
  uint uVar4;
  int local_34;
  int local_30;
  int local_2c;
  int local_24;
  int local_20;
  int local_1c;
  int local_8;
  
  local_1c = x;
  local_20 = y;
  local_34 = 0;
  FUN_0050dce0((int *)g_DisplaySurfaceWork,0,0,0x40,0x80,(int *)g_DisplaySurfaceWork,0x40,0);
  FUN_0040c81c(0x20,x,y);
  do {
    iVar1 = FUN_0040a36f(width - local_1c,height - local_20);
    local_30 = -1;
    local_2c = 0x7fff;
    for (local_24 = 1; local_24 < 9; local_24 = local_24 + 1) {
      iVar2 = *(int *)(&DAT_00522378 + local_24 * 4) + local_1c;
      arg2 = *(int *)(&DAT_005223e0 + local_24 * 4) + local_20;
      iVar3 = FUN_0040c761(iVar2,arg2);
      if ((iVar3 != 0) && (local_8 = FUN_0040a36f(width - iVar2,height - arg2), local_8 < iVar1)) {
        if ((iVar3 == 2) || (iVar3 == 0xb)) {
          local_8 = local_8 + 1;
        }
        if ((iVar3 == 4) || (iVar3 == 5)) {
          local_8 = local_8 + 4;
        }
        uVar4 = FUN_0040c7c0(iVar2,arg2);
        if (((uVar4 & 0x20) != 0) && (0 < local_34)) {
          local_8 = local_8 + -4;
        }
        if (local_8 < local_2c) {
          local_2c = local_8;
          local_30 = local_24;
        }
      }
    }
    if (local_30 == -1) {
      FUN_0050dce0((int *)g_DisplaySurfaceWork,0x40,0,0x40,0x80,(int *)g_DisplaySurfaceWork,0,0);
      return 0;
    }
    iVar1 = *(int *)(&DAT_00522378 + local_30 * 4) + local_1c;
    iVar2 = *(int *)(&DAT_005223e0 + local_30 * 4) + local_20;
    uVar4 = FUN_0040c7c0(iVar1,iVar2);
    FUN_0040ca43(local_1c,local_20,local_30);
    if (((uVar4 & 0x20) != 0) && (0 < local_34)) {
      return 1;
    }
    local_34 = local_34 + 1;
    local_20 = iVar2;
    local_1c = iVar1;
  } while ((iVar1 != width) || (iVar2 != height));
  return 1;
}


