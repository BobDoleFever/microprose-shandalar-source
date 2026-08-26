/*
 * Decompiled function: FUN_004d7ecb
 * Entry Point: 004d7ecb
 * Size: 141 bytes
 */
#include "duel.h"


int FUN_004d7ecb(void)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < 0x80; local_8 = local_8 + 1) {
    if ((((*(uint *)(&DAT_005ef9d0 + local_8 * 100) & 0xff01) == 1) &&
        (1 < *(int *)(&DAT_005ef9c0 + local_8 * 100))) &&
       (*(int *)(&DAT_005ef9c0 + local_8 * 100) < 4)) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}


