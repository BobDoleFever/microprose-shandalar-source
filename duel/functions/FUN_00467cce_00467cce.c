/*
 * Decompiled function: FUN_00467cce
 * Entry Point: 00467cce
 * Size: 151 bytes
 */
#include "duel.h"


undefined4 FUN_00467cce(int arg1,byte arg2)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if ((int)(&DAT_00666408)[arg1] <= local_8) {
      return 0;
    }
    iVar1 = FUN_0048a33f(arg1,local_8);
    if ((iVar1 != 0) &&
       ((arg2 & (&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_8 * 0x120 + arg1 * 0x5b20) * 0x34])
        != 0)) break;
    local_8 = local_8 + 1;
  }
  return 1;
}


