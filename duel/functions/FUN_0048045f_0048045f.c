/*
 * Decompiled function: FUN_0048045f
 * Entry Point: 0048045f
 * Size: 82 bytes
 */
#include "duel.h"


undefined4 * FUN_0048045f(int arg_1)

{
  undefined4 *local_8;
  
  local_8 = _malloc(arg_1 + 8);
  if (((uint)local_8 & 7) == 0) {
    local_8[1] = 0;
    local_8 = local_8 + 2;
  }
  else {
    *local_8 = 0xffffffff;
    local_8 = local_8 + 1;
  }
  return local_8;
}


