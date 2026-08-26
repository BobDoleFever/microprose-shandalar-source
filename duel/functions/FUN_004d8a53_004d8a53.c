/*
 * Decompiled function: FUN_004d8a53
 * Entry Point: 004d8a53
 * Size: 411 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d8a53(int arg_1)

{
  int iVar1;
  int local_114;
  int local_110 [32];
  int local_90;
  int local_8c [32];
  int local_c;
  int local_8;
  
  local_90 = 0;
  for (local_114 = 0; local_114 < 0x20; local_114 = local_114 + 1) {
    local_110[local_114] = 1;
  }
  local_8c[0] = arg_1 + -1;
  local_8 = local_8c[0];
  _memset(&DAT_005edd10,0,0x80);
  do {
    iVar1 = local_90;
    local_90 = local_90 + 1;
    if (local_110[iVar1] == 0) {
      local_c = *(int *)(&DAT_005ddac4 + local_8 * 8);
    }
    else {
      local_c = *(int *)(&DAT_005ddac0 + local_8 * 8);
    }
    local_8 = local_c - _DAT_005ddab8;
    local_8c[local_90] = local_c - _DAT_005ddab8;
    if (local_8 < 0) {
      *(int *)(&DAT_005edd10 + local_90 * 4) = *(int *)(&DAT_005edd10 + local_90 * 4) + 1;
      local_110[local_90] = 1;
      local_90 = local_90 + -1;
      local_110[local_90] = local_110[local_90] + -1;
      local_8 = local_8c[local_90];
      while ((-1 < local_110[0] && (local_110[local_90] < 0))) {
        local_110[local_90] = 1;
        local_90 = local_90 + -1;
        local_110[local_90] = local_110[local_90] + -1;
        local_8 = local_8c[local_90];
      }
    }
  } while (-1 < local_110[0]);
  return 0;
}


