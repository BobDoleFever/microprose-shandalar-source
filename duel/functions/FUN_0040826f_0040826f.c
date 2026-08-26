/*
 * Decompiled function: FUN_0040826f
 * Entry Point: 0040826f
 * Size: 299 bytes
 */
#include "duel.h"


int FUN_0040826f(int x,int y,uint width,int height)

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
      if ((width == 0xffffffff) || ((width & (byte)(&DAT_004ff594)[iVar1 * 0x34]) != 0)) {
        local_8 = Mem_AllocOrFree_004d9810((int)(char)(&DAT_004ff598)[iVar1 * 0x34]);
        local_8 = local_8 + (char)(&DAT_004ff597)[iVar1 * 0x34] * 2;
        if (*(int *)(&DAT_0068ef6c + x * 0x20) < local_8) {
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


