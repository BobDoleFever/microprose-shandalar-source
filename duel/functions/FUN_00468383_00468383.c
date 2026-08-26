/*
 * Decompiled function: FUN_00468383
 * Entry Point: 00468383
 * Size: 461 bytes
 */
#include "duel.h"


int FUN_00468383(int arg_1)

{
  int iVar1;
  int iVar2;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) {
    iVar1 = Action_ValidateTarget_0041e2a2
                      (arg_1,arg_1,arg_1,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                       &DAT_006679f0,0,&local_1c);
    if (iVar1 == 0) {
      local_20 = -1;
    }
    else {
      local_20 = local_18;
    }
  }
  else {
    local_20 = -1;
    local_14 = 0x7fff;
    for (local_10 = 0; local_10 < (int)(&DAT_00666408)[arg_1]; local_10 = local_10 + 1) {
      local_c = *(int *)(&DAT_006826c4 + local_10 * 0x120 + arg_1 * 0x5b20);
      if ((((local_c != -1) && (((&DAT_006826cc)[local_10 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) &&
          (((&DAT_004ff594)[local_c * 0x34] & 2) != 0)) &&
         ((&DAT_006826e0)[local_10 * 0x120 + arg_1 * 0x5b20] != '\x03')) {
        iVar1 = FUN_0048b81a(arg_1,local_10,0x32,0xffffffff);
        iVar2 = FUN_0048b81a(arg_1,local_10,0x33,0xffffffff);
        local_8 = (iVar1 + 2) * (iVar2 + 2);
        if (local_8 < local_14) {
          local_20 = local_10;
          local_14 = local_8;
        }
      }
    }
  }
  if ((local_20 != -1) && (DAT_0066aaf4 != 1)) {
    FUN_0048d00c(0xf);
  }
  return local_20;
}


