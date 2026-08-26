/*
 * Decompiled function: FUN_0040f9b7
 * Entry Point: 0040f9b7
 * Size: 130 bytes
 */
#include "magic.h"


int FUN_0040f9b7(byte arg_1)

{
  int local_c;
  int local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < 0x80; local_c = local_c + 1) {
    if (((&DAT_0067be01)[local_c * 100] != '\0') &&
       ((*(int *)(&DAT_0067be00 + local_c * 100) >> 8) + -1 == 1 << (arg_1 & 0x1f))) {
      local_8 = local_8 + 1;
    }
  }
  return local_8;
}


