/*
 * Decompiled function: FUN_00439172
 * Entry Point: 00439172
 * Size: 150 bytes
 */
#include "duel.h"


undefined * FUN_00439172(int arg1,int arg2)

{
  int local_c;
  undefined *local_8;
  
  local_8 = (undefined *)0x0;
  if (arg1 == -1) {
    local_8 = (undefined *)0x0;
  }
  else {
    local_c = 0;
    while ((local_c < DAT_00663df8 && (local_8 == (undefined *)0x0))) {
      if ((*(int *)(&DAT_00616a20 + local_c * 0x18) == arg1) &&
         (*(int *)(&DAT_00616a24 + local_c * 0x18) == arg2)) {
        local_8 = &DAT_00616a10 + local_c * 0x18;
      }
      local_c = local_c + 1;
    }
  }
  return local_8;
}


