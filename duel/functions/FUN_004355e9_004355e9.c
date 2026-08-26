/*
 * Decompiled function: FUN_004355e9
 * Entry Point: 004355e9
 * Size: 230 bytes
 */
#include "duel.h"


undefined4 FUN_004355e9(uint *x,int y,int width,int height)

{
  undefined1 uVar1;
  uint arg_1;
  uint local_20;
  int local_18;
  int local_14;
  uint *local_10;
  int local_8;
  
  local_10 = x;
  for (local_18 = 0; local_18 < y; local_18 = local_18 + 1) {
    local_8 = 0;
    local_14 = 0;
    local_20 = *x;
    for (; local_14 < width * 3; local_14 = local_14 + 3) {
      arg_1 = local_20 & 0xffffff;
      local_20 = *(uint *)(local_14 + 3 + (int)x);
      uVar1 = FUN_00435343(arg_1);
      *(undefined1 *)(local_8 + (int)local_10) = uVar1;
      if (*(uint *)(&DAT_005162d0 + (uint)*(byte *)(local_8 + (int)local_10) * 4) != arg_1) {
        *(undefined4 *)(&DAT_005162d0 + (uint)*(byte *)(local_8 + (int)local_10) * 4) = 0;
      }
      local_8 = local_8 + 1;
    }
    x = (uint *)((int)x + height + width * 3);
    local_10 = (uint *)((int)local_10 + height + width);
  }
  return 0;
}


