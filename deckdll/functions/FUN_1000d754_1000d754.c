/*
 * Decompiled function: FUN_1000d754
 * Entry Point: 1000d754
 * Size: 97 bytes
 */
#include "deckdll.h"


int32_t FUN_1000d754(int arg_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_101cf920 <= local_8) {
      return 0xffffffff;
    }
    if ((&DAT_1016a620)[local_8 * 4] == arg_1) break;
    local_8 = local_8 + 1;
  }
  return *(int32_t *)(&DAT_1016a624 + local_8 * 0x10);
}


