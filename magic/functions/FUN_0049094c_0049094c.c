/*
 * Decompiled function: FUN_0049094c
 * Entry Point: 0049094c
 * Size: 84 bytes
 */
#include "magic.h"


int FUN_0049094c(void)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 1;
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    if ((DAT_0067bdb4 & 1 << ((byte)local_8 & 0x1f)) != 0) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}


