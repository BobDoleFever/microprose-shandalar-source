/*
 * Decompiled function: FUN_004729bc
 * Entry Point: 004729bc
 * Size: 131 bytes
 */
#include "duel.h"


int FUN_004729bc(int arg1,int arg2)

{
  BOOL BVar1;
  int local_c;
  int local_8;
  
  local_8 = -1;
  if ((arg1 == 0) || (arg2 == 0)) {
    local_8 = -1;
  }
  else {
    local_c = 0;
    while ((local_c < arg2 && (local_8 == -1))) {
      BVar1 = IsWindowVisible(*(HWND *)(arg1 + local_c * 4));
      if (BVar1 != 0) {
        local_8 = local_c;
      }
      local_c = local_c + 1;
    }
  }
  return local_8;
}


