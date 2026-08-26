/*
 * Decompiled function: FUN_00434fa1
 * Entry Point: 00434fa1
 * Size: 172 bytes
 */
#include "duel.h"


int FUN_00434fa1(int *arg_1)

{
  int iVar1;
  int local_c;
  int local_8;
  
  local_8 = 0;
  if (*arg_1 == 0) {
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      if (arg_1[local_c + 2] != 0) {
        iVar1 = FUN_00434fa1((int *)arg_1[local_c + 2]);
        local_8 = local_8 + iVar1;
      }
    }
    if (arg_1[10] != 0) {
      FUN_004db150(arg_1[10]);
    }
    FUN_004db150(arg_1);
  }
  else {
    FUN_004db150(arg_1);
    local_8 = 1;
  }
  return local_8;
}


