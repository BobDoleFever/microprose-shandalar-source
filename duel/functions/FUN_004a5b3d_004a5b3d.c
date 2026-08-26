/*
 * Decompiled function: FUN_004a5b3d
 * Entry Point: 004a5b3d
 * Size: 139 bytes
 */
#include "duel.h"


undefined4 FUN_004a5b3d(int arg1,int arg2)

{
  int iVar1;
  
  if ((arg1 == DAT_00666458) && (((&DAT_006826cd)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) == 0)) {
    *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) | 0x8000;
    iVar1 = FUN_0048ad82(arg1,arg2);
    if (iVar1 != 0) {
      DAT_006826b0 = 1;
    }
  }
  return 0;
}


