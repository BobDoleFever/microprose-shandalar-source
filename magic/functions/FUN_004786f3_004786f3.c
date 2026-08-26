/*
 * Decompiled function: FUN_004786f3
 * Entry Point: 004786f3
 * Size: 112 bytes
 */
#include "magic.h"


int FUN_004786f3(int x,int y,int width,int height)

{
  int local_8;
  
  if (x == -1) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_0047865c(x,y);
    if ((local_8 != 0) && ((*(int *)(local_8 + 8) != width || (*(int *)(local_8 + 0xc) != height))))
    {
      local_8 = 0;
    }
  }
  return local_8;
}


