/*
 * Decompiled function: FUN_00435551
 * Entry Point: 00435551
 * Size: 152 bytes
 */
#include "duel.h"


undefined4 FUN_00435551(uint *x,int y,int width,int height)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  for (local_10 = 0; local_10 < y; local_10 = local_10 + 1) {
    local_c = 0;
    local_18 = *x;
    for (; local_c < width * 3; local_c = local_c + 3) {
      uVar1 = *(uint *)(local_c + 3 + (int)x);
      uVar2 = FUN_004351b5(local_18);
      *(undefined4 *)(local_c + (int)x) = uVar2;
      local_18 = uVar1;
    }
    x = (uint *)((int)x + height + width * 3);
  }
  return 0;
}


