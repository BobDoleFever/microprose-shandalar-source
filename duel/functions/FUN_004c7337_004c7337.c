/*
 * Decompiled function: FUN_004c7337
 * Entry Point: 004c7337
 * Size: 123 bytes
 */
#include "duel.h"


undefined4 FUN_004c7337(int x,int y,int width,int height)

{
  uint arg_5;
  undefined4 uVar1;
  uint local_10;
  uint local_c;
  uint local_8;
  
  arg_5 = FUN_0048b81a(width,height,0x34,0xffffffff);
  FUN_00431f41(&local_8,&local_c);
  if (x == 1) {
    local_10 = local_8;
  }
  else {
    local_10 = local_c;
  }
  uVar1 = FUN_0048b2c9(x,y,width,height,arg_5,local_10);
  return uVar1;
}


