/*
 * Decompiled function: FUN_10018411
 * Entry Point: 10018411
 * Size: 136 bytes
 */
#include "deckdll.h"


int32_t FUN_10018411(int arg_1)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  do {
    if (6 < local_c) {
      return 0;
    }
    for (local_8 = 0; local_8 < 0x20; local_8 = local_8 + 1) {
      if (((*(uint32_t *)(&DAT_101cf7d8 + local_c * 4) & 1 << ((uint8_t)local_8 & 0x1f)) != 0) &&
         (local_c * 0x20 + local_8 + 1 == arg_1)) {
        return 1;
      }
    }
    local_c = local_c + 1;
  } while( true );
}


