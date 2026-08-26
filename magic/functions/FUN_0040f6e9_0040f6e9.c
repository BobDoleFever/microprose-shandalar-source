/*
 * Decompiled function: FUN_0040f6e9
 * Entry Point: 0040f6e9
 * Size: 164 bytes
 */
#include "magic.h"


int FUN_0040f6e9(void)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    if ((DAT_0067bdb4 & 1 << ((byte)local_c & 0x1f)) == 0) {
      local_8 = local_8 + 1;
    }
  }
  local_10 = FUN_0040a1d2(local_8);
  local_c = 1;
  while ((local_c < 6 && (local_10 != 0))) {
    if ((DAT_0067bdb4 & 1 << ((byte)local_c & 0x1f)) == 0) {
      local_10 = local_10 + -1;
    }
    local_c = local_c + 1;
  }
  return local_c;
}


