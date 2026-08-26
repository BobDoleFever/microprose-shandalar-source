/*
 * Decompiled function: FUN_0040a36f
 * Entry Point: 0040a36f
 * Size: 114 bytes
 */
#include "magic.h"


int FUN_0040a36f(int arg1,int arg2)

{
  undefined4 local_8;
  
  if (arg1 < 0) {
    arg1 = -arg1;
  }
  if (arg2 < 0) {
    arg2 = -arg2;
  }
  if (arg2 < arg1) {
    local_8 = arg1 * 2 + arg2;
  }
  else {
    local_8 = arg2 * 2 + arg1;
  }
  if (local_8 < 0) {
    local_8 = 0x7ffe;
  }
  return local_8;
}


