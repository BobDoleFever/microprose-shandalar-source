/*
 * Decompiled function: FUN_1003724f
 * Entry Point: 1003724f
 * Size: 118 bytes
 */
#include "deckdll.h"


int FUN_1003724f(int arg_1)

{
  int local_c;
  int local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < DAT_101cf920; local_c = local_c + 1) {
    if (((&DAT_1016a620)[local_c * 4] == arg_1) &&
       ((*(uint32_t *)(&DAT_1016a62c + local_c * 0x10) & 1 << (DAT_10162904 & 0x1f)) == 0)) {
      local_8 = local_8 + 1;
    }
  }
  return local_8;
}


