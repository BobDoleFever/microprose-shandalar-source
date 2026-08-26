/*
 * Decompiled function: FUN_0040fbe2
 * Entry Point: 0040fbe2
 * Size: 184 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0040fbe2(void)

{
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < 0xc; local_c = local_c + 1) {
    if ((_DAT_0067f374 & 1 << ((byte)local_c & 0x1f)) == 0) {
      local_8 = local_8 + 1;
    }
  }
  if (local_8 == 0) {
    local_c = -1;
  }
  else {
    local_10 = FUN_0040a1d2(local_8);
    local_c = 0;
    while ((local_c < 0xc && (local_10 != 0))) {
      if ((_DAT_0067f374 & 1 << ((byte)local_c & 0x1f)) == 0) {
        local_10 = local_10 + -1;
      }
      local_c = local_c + 1;
    }
  }
  return local_c;
}


