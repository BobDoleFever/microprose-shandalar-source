/*
 * Decompiled function: FUN_004fdc20
 * Entry Point: 004fdc20
 * Size: 299 bytes
 */
#include "magic.h"


int FUN_004fdc20(int x,int y,uint width,int height)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  local_14 = -99;
  local_10 = -1;
  if (y == -1) {
    local_10 = -1;
  }
  else {
    for (local_18 = 0; (*(int *)(height + local_18 * 4) != -1 && (local_18 < 0x50));
        local_18 = local_18 + 1) {
      iVar1 = *(int *)(height + local_18 * 4);
      if ((width == 0xffffffff) || ((width & (byte)(&g_MasterCardColorTable)[iVar1 * 0x34]) != 0)) {
        local_8 = abs((int)(char)(&DAT_0051aec0)[iVar1 * 0x34]);
        local_8 = local_8 + (char)(&DAT_0051aebf)[iVar1 * 0x34] * 2;
        if (*(int *)(&DAT_0063ee4c + x * 0x20) < local_8) {
          local_8 = -local_8;
        }
        if (local_8 == 0) {
          local_8 = 99;
        }
        iVar1 = Pic_Subsystem_00452551(iVar1);
        local_8 = local_8 + iVar1 * 2;
        if (local_14 < local_8) {
          local_10 = local_18;
          local_14 = local_8;
        }
      }
    }
  }
  return local_10;
}


