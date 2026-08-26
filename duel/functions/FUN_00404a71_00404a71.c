/*
 * Decompiled function: FUN_00404a71
 * Entry Point: 00404a71
 * Size: 149 bytes
 */
#include "duel.h"


int FUN_00404a71(int arg1,int arg2)

{
  int local_c;
  int local_8;
  
  local_c = 1;
  for (local_8 = 0; local_8 < (int)(&DAT_00666408)[arg1]; local_8 = local_8 + 1) {
    if ((*(int *)(&DAT_006826c4 + local_8 * 0x120 + arg1 * 0x5b20) == arg2) &&
       (((&DAT_006826cc)[local_8 * 0x120 + arg1 * 0x5b20] & 2) == 0)) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}


