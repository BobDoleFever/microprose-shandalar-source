/*
 * Decompiled function: FUN_0049e5d3
 * Entry Point: 0049e5d3
 * Size: 137 bytes
 */
#include "duel.h"


undefined4 FUN_0049e5d3(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_10;
  int local_8;
  
  local_10 = 0;
  local_8 = arg_3 + -1;
  while( true ) {
    while( true ) {
      if (local_8 < local_10) {
        return 0;
      }
      iVar1 = (local_8 + local_10) / 2;
      if (arg_1 <= *(int *)(arg_2 + iVar1 * 4)) break;
      local_10 = iVar1 + 1;
    }
    if (*(int *)(arg_2 + iVar1 * 4) <= arg_1) break;
    local_8 = iVar1 + -1;
  }
  return 1;
}


