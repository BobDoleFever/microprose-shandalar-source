/*
 * Decompiled function: FUN_0049b68d
 * Entry Point: 0049b68d
 * Size: 338 bytes
 */
#include "duel.h"


int FUN_0049b68d(int x,int y,uint width,int height)

{
  int iVar1;
  int iVar2;
  
  if (height == 0) {
    iVar1 = FUN_0048c367((&DAT_006826dd)[y * 0x120 + x * 0x5b20]);
    if (*(int *)(&DAT_00676150 + iVar1 * 4) < 1) {
      iVar1 = 1;
    }
    else {
      iVar1 = FUN_0048c367((&DAT_006826dd)[y * 0x120 + x * 0x5b20]);
      iVar1 = FUN_0049b309(x,7,*(int *)(&DAT_00676150 + iVar1 * 4));
    }
  }
  else {
    iVar1 = FUN_0049b309(x,width,height);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar2 = FUN_0048c367((&DAT_006826dd)[y * 0x120 + x * 0x5b20]);
      if (0 < *(int *)(&DAT_00676150 + iVar2 * 4)) {
        iVar1 = FUN_0048c367((&DAT_006826dd)[y * 0x120 + x * 0x5b20]);
        iVar1 = FUN_0049b309(x,7,*(int *)(&DAT_00676150 + iVar1 * 4) + height);
      }
    }
  }
  return iVar1;
}


