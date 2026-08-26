/*
 * Decompiled function: FUN_004354bb
 * Entry Point: 004354bb
 * Size: 150 bytes
 */
#include "duel.h"


int FUN_004354bb(int *arg1,int *arg2)

{
  int iVar1;
  int local_c;
  int local_8;
  
  local_8 = 0;
  if (*arg1 == 0) {
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      if (arg1[local_c + 2] != 0) {
        iVar1 = FUN_004354bb((int *)arg1[local_c + 2],arg2);
        local_8 = local_8 + iVar1;
        arg2 = arg2 + iVar1;
      }
    }
  }
  else {
    *arg2 = arg1[1];
    local_8 = 1;
  }
  return local_8;
}


