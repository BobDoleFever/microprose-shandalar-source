/*
 * Decompiled function: FUN_004392f3
 * Entry Point: 004392f3
 * Size: 165 bytes
 */
#include "duel.h"


undefined4 FUN_004392f3(WPARAM arg_1,int y,int width,int height)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_1 == 0xffffffff) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_00439172(arg_1,y);
    if (iVar2 != 0) {
      if ((*(int *)(iVar2 + 8) == width) && (*(int *)(iVar2 + 0xc) == height)) {
        return 1;
      }
      FUN_004393a2(arg_1,y);
    }
    iVar2 = FUN_00438ec2(arg_1,y,width,height);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


