/*
 * Decompiled function: FUN_0047ec8c
 * Entry Point: 0047ec8c
 * Size: 412 bytes
 */
#include "duel.h"


void FUN_0047ec8c(int *arg_1,int *arg_2,int *arg_3,int arg_4,int arg_5,undefined4 arg_6,int arg_7)

{
  int *piVar1;
  int *piVar2;
  int local_20;
  int local_1c;
  int *local_c;
  int local_8;
  
  for (local_8 = 0; piVar1 = arg_1, local_8 < arg_5; local_8 = local_8 + 1) {
    piVar2 = arg_1 + arg_4 + -1;
    local_c = arg_3 + arg_7 * 2;
    for (; arg_1 < piVar2; arg_1 = arg_1 + 1) {
      local_1c = arg_1[1] * 0xb504;
      local_20 = arg_1[1] * 0xb504;
      if (*arg_2 != 0) {
        local_1c = local_1c + *arg_2 * 0xb504;
        local_20 = local_20 + *arg_2 * -0xb504;
      }
      *local_c = local_1c >> 0x10;
      local_c[arg_7] = local_20 >> 0x10;
      arg_2 = arg_2 + 1;
      local_c = local_c + arg_7 * 2;
    }
    *arg_3 = *arg_2 * 0xb504 + *piVar1 * 0xb504 >> 0x10;
    arg_3[arg_7] = *arg_2 * -0xb504 + *piVar1 * 0xb504 >> 0x10;
    arg_3 = arg_3 + 1;
    arg_1 = arg_1 + 1;
    arg_2 = arg_2 + 1;
  }
  return;
}


