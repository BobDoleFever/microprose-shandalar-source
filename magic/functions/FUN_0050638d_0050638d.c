/*
 * Decompiled function: FUN_0050638d
 * Entry Point: 0050638d
 * Size: 105 bytes
 */
#include "magic.h"


undefined4 FUN_0050638d(int x,int y,int width,int height)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < y; local_c = local_c + 1) {
    if ((*(int *)(x + local_c * 8) == width) && (*(int *)(x + 4 + local_c * 8) == height)) {
      local_8 = 1;
    }
  }
  return local_8;
}


