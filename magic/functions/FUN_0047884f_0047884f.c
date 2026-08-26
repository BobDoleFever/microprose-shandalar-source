/*
 * Decompiled function: FUN_0047884f
 * Entry Point: 0047884f
 * Size: 135 bytes
 */
#include "magic.h"


undefined4 FUN_0047884f(WPARAM arg_1,int y,int width,int height)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_1 == 0xffffffff) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_004786f3(arg_1,y,width,height);
    if (iVar2 == 0) {
      FUN_004788e0(arg_1,y);
      iVar2 = FUN_00478370(arg_1,y,width,height);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


