/*
 * Decompiled function: FUN_0046c4b5
 * Entry Point: 0046c4b5
 * Size: 150 bytes
 */
#include "magic.h"


undefined * FUN_0046c4b5(int arg1,int arg2)

{
  int local_c;
  undefined *local_8;
  
  local_8 = (undefined *)0x0;
  if (arg1 == -1) {
    local_8 = (undefined *)0x0;
  }
  else {
    local_c = 0;
    while ((local_c < DAT_006fe404 && (local_8 == (undefined *)0x0))) {
      if ((*(int *)(&DAT_006a3f90 + local_c * 0x18) == arg1) &&
         (*(int *)(&DAT_006a3f94 + local_c * 0x18) == arg2)) {
        local_8 = &DAT_006a3f80 + local_c * 0x18;
      }
      local_c = local_c + 1;
    }
  }
  return local_8;
}


