/*
 * Decompiled function: FUN_0047f7d3
 * Entry Point: 0047f7d3
 * Size: 292 bytes
 */
#include "duel.h"


undefined4 * FUN_0047f7d3(undefined4 arg_1,int arg_2,int arg_3)

{
  int local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  if (arg_3 == 8) {
    local_8 = _malloc(0x42c);
  }
  else if (arg_3 == 0x18) {
    local_8 = _malloc(0x2c);
  }
  else {
    local_8 = _malloc(0x2c);
  }
  *local_8 = 0x28;
  local_8[1] = arg_1;
  local_8[2] = -arg_2;
  *(undefined2 *)(local_8 + 3) = 1;
  *(short *)((int)local_8 + 0xe) = (short)arg_3;
  local_8[4] = 0;
  local_8[5] = 0;
  local_8[6] = 0;
  local_8[7] = 0;
  if (arg_3 == 8) {
    local_8[8] = 0x100;
    local_8[9] = 0x100;
    local_c = local_8 + 10;
    for (local_10 = 0; local_10 < 0x100; local_10 = local_10 + 1) {
      *(short *)local_c = (short)local_10;
      local_c = (undefined4 *)((int)local_c + 2);
    }
  }
  else {
    local_8[8] = 0;
    local_8[9] = 0;
  }
  return local_8;
}


