/*
 * Decompiled function: FUN_0040dcca
 * Entry Point: 0040dcca
 * Size: 338 bytes
 */
#include "magic.h"


int FUN_0040dcca(int x,int y,uint width,int height)

{
  int iVar1;
  int iVar2;
  
  if (height == 0) {
    iVar1 = FUN_00473cc5((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20]);
    if (*(int *)(&DAT_006330d0 + iVar1 * 4) < 1) {
      iVar1 = 1;
    }
    else {
      iVar1 = FUN_00473cc5((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20]);
      iVar1 = FUN_0040d949(x,7,*(int *)(&DAT_006330d0 + iVar1 * 4));
    }
  }
  else {
    iVar1 = FUN_0040d949(x,width,height);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar2 = FUN_00473cc5((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20]);
      if (0 < *(int *)(&DAT_006330d0 + iVar2 * 4)) {
        iVar1 = FUN_00473cc5((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20]);
        iVar1 = FUN_0040d949(x,7,*(int *)(&DAT_006330d0 + iVar1 * 4) + height);
      }
    }
  }
  return iVar1;
}


