/*
 * Decompiled function: FUN_1000e6cc
 * Entry Point: 1000e6cc
 * Size: 114 bytes
 */
#include "deckdll.h"


int32_t FUN_1000e6cc(void)

{
  int32_t uval_1;
  int local_c;
  int local_8;
  
  if (DAT_10041570 == 0) {
    local_c = -0xff;
    for (local_8 = 0; local_8 < 0x200; local_8 = local_8 + 1) {
      *(int *)(&DAT_10204010 + local_8 * 4) = local_c * local_c;
      local_c = local_c + 1;
    }
    DAT_10041570 = 1;
    uval_1 = 1;
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}


