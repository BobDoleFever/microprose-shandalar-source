/*
 * Decompiled function: FUN_00431f41
 * Entry Point: 00431f41
 * Size: 155 bytes
 */
#include "duel.h"


void FUN_00431f41(uint *arg1,uint *arg2)

{
  int local_10;
  uint local_c;
  uint local_8;
  
  local_c = 0;
  local_8 = 0;
  for (local_10 = 1; local_10 < 6; local_10 = local_10 + 1) {
    if (0 < *(int *)(&DAT_0068ef70 + local_10 * 4)) {
      local_8 = local_8 | 1 << ((char)local_10 - 1U & 0x1f);
    }
    if (0 < *(int *)(&DAT_0068ef50 + local_10 * 4)) {
      local_c = local_c | 1 << ((char)local_10 - 1U & 0x1f);
    }
  }
  if (arg1 != (uint *)0x0) {
    *arg1 = local_8;
  }
  if (arg2 != (uint *)0x0) {
    *arg2 = local_c;
  }
  return;
}


