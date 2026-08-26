/*
 * Decompiled function: FUN_0048f375
 * Entry Point: 0048f375
 * Size: 430 bytes
 */
#include "magic.h"


undefined4 FUN_0048f375(int *arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int local_20;
  int local_1c;
  int local_8;
  
  if (arg_1[0x10] == 0) {
    local_20 = arg_1[6] + arg_1[0xe] / 2;
    local_8 = arg_1[8] - arg_1[0xe] / 2;
  }
  else {
    local_20 = arg_1[7] + arg_1[0xf] / 2;
    local_8 = arg_1[9] - arg_1[0xf] / 2;
  }
  if ((arg_2 < local_20) || (local_8 < arg_2)) {
    uVar1 = 0xffffffff;
  }
  else {
    arg_1[0x13] = arg_2;
    for (local_1c = 0; local_1c < arg_1[5]; local_1c = local_1c + 1) {
      Surface_PutLine((undefined4 *)(arg_1[4] * local_1c + arg_1[0xd]),*(int *)*arg_1,arg_1[4],
                      arg_1[2],arg_1[3]);
    }
    Sprite_DrawScaled((int *)*arg_1,arg_1[2] - arg_1[0xe] / 2,arg_1[3] - arg_1[0xf] / 2,arg_1[0xe],
                      arg_1[0xf],arg_1[arg_3 + 10]);
    if (*arg_1 != arg_1[1]) {
      FUN_0050dce0((int *)*arg_1,arg_1[2],arg_1[3],arg_1[4],arg_1[5],(int *)arg_1[1],arg_1[6],
                   arg_1[7]);
    }
    uVar1 = 0;
  }
  return uVar1;
}


