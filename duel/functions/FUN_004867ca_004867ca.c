/*
 * Decompiled function: FUN_004867ca
 * Entry Point: 004867ca
 * Size: 151 bytes
 */
#include "duel.h"


undefined * FUN_004867ca(int arg1,int arg2)

{
  undefined *local_c;
  int local_8;
  
  local_c = (undefined *)0x0;
  if (arg1 == -1) {
    local_c = (undefined *)0x0;
  }
  else {
    local_8 = 0;
    while ((local_8 < DAT_005f76d4 && (local_c == (undefined *)0x0))) {
      if (((&DAT_00664880)[local_8 * 6] == arg1) && ((&DAT_00664884)[local_8 * 6] == arg2)) {
        local_c = &DAT_00664870 + local_8 * 0x18;
      }
      local_8 = local_8 + 1;
    }
  }
  return local_c;
}


