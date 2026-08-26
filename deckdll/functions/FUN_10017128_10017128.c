/*
 * Decompiled function: FUN_10017128
 * Entry Point: 10017128
 * Size: 106 bytes
 */
#include "deckdll.h"


int32_t FUN_10017128(int arg_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_101cf920 <= local_8) {
      return 0;
    }
    if (((&DAT_1016a620)[local_8 * 4] == arg_1) && (*(int *)(&DAT_1016a628 + local_8 * 0x10) == 1))
    break;
    local_8 = local_8 + 1;
  }
  return 1;
}


