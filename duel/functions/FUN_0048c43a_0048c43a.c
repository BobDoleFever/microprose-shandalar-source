/*
 * Decompiled function: FUN_0048c43a
 * Entry Point: 0048c43a
 * Size: 209 bytes
 */
#include "duel.h"


int FUN_0048c43a(int arg_1)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_10 = 0;
  for (local_c = 0; local_c < (int)(&DAT_00666408)[arg_1]; local_c = local_c + 1) {
    iVar1 = *(int *)(&DAT_006826c4 + local_c * 0x120 + arg_1 * 0x5b20);
    if ((((iVar1 != -1) && (((&DAT_006826cc)[local_c * 0x120 + arg_1 * 0x5b20] & 2) == 0)) &&
        (((&DAT_004ff594)[iVar1 * 0x34] & 1) != 0)) && ((&DAT_004ff596)[iVar1 * 0x34] != '\0')) {
      local_10 = local_10 + 1;
    }
  }
  return local_10;
}


