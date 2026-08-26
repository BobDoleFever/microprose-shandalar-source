/*
 * Decompiled function: FUN_0048acd3
 * Entry Point: 0048acd3
 * Size: 175 bytes
 */
#include "duel.h"


undefined4 FUN_0048acd3(int arg_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if ((int)(&DAT_00666408)[arg_1] <= local_8) {
      return 0;
    }
    if (((*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_8 * 0x120) != -1) &&
        (((&DAT_006826cc)[arg_1 * 0x5b20 + local_8 * 0x120] & 6) != 0)) &&
       (iVar1 = FUN_0048ad82(arg_1,local_8), iVar1 != 0)) break;
    local_8 = local_8 + 1;
  }
  return 1;
}


