/*
 * Decompiled function: FUN_0040c421
 * Entry Point: 0040c421
 * Size: 68 bytes
 */
#include "magic.h"


void FUN_0040c421(undefined4 arg_1,int y,int width,int height)

{
  if (height != 0) {
    FUN_0040c3cc(arg_1,y,width + 1,0);
  }
  FUN_0040c3cc(arg_1,y,width,height);
  return;
}


