/*
 * Decompiled function: FUN_00469450
 * Entry Point: 00469450
 * Size: 203 bytes
 */
#include "duel.h"


int FUN_00469450(int arg1,int arg2)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_c = arg2;
  local_10 = 0;
  DAT_0066642c = -1;
  while ((local_c < 500 && (local_10 == 0))) {
    iVar1 = *(int *)(&DAT_006669f0 + local_c * 4 + arg1 * 2000);
    if ((iVar1 != -1) &&
       (*(int *)(&DAT_00618ad4 + *(int *)(&DAT_004ff590 + iVar1 * 0x34) * 0x98) == 7)) {
      local_10 = *(int *)(&DAT_00618ad8 + *(int *)(&DAT_004ff590 + iVar1 * 0x34) * 0x98);
      DAT_0066642c = iVar1;
    }
    local_c = local_c + 1;
  }
  return local_10;
}


