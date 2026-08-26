/*
 * Decompiled function: FUN_0046c636
 * Entry Point: 0046c636
 * Size: 165 bytes
 */
#include "magic.h"


undefined4 FUN_0046c636(WPARAM arg_1,int y,int width,int height)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_1 == 0xffffffff) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_0046c4b5(arg_1,y);
    if (iVar2 != 0) {
      if ((*(int *)(iVar2 + 8) == width) && (*(int *)(iVar2 + 0xc) == height)) {
        return 1;
      }
      FUN_0046c6e5(arg_1,y);
    }
    iVar2 = FUN_0046c203(arg_1,y,width,height);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


