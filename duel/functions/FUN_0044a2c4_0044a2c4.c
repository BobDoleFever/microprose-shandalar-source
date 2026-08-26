/*
 * Decompiled function: FUN_0044a2c4
 * Entry Point: 0044a2c4
 * Size: 80 bytes
 */
#include "duel.h"


int FUN_0044a2c4(int arg1,int arg2)

{
  undefined4 local_8;
  
  if ((arg1 == 0) || (arg2 == 0)) {
    local_8 = 0;
  }
  else {
    local_8 = (arg1 - (arg2 + -1)) / arg2;
    if (local_8 < 1) {
      local_8 = 0;
    }
  }
  return local_8;
}


