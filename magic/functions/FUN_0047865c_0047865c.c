/*
 * Decompiled function: FUN_0047865c
 * Entry Point: 0047865c
 * Size: 151 bytes
 */
#include "magic.h"


undefined * FUN_0047865c(int arg1,int arg2)

{
  undefined *local_c;
  int local_8;
  
  local_c = (undefined *)0x0;
  if (arg1 == -1) {
    local_c = (undefined *)0x0;
  }
  else {
    local_8 = 0;
    while ((local_8 < DAT_00680778 && (local_c == (undefined *)0x0))) {
      if (((&DAT_006fefc0)[local_8 * 6] == arg1) && ((&DAT_006fefc4)[local_8 * 6] == arg2)) {
        local_c = &DAT_006fefb0 + local_8 * 0x18;
      }
      local_8 = local_8 + 1;
    }
  }
  return local_c;
}


