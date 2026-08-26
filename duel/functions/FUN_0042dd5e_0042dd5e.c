/*
 * Decompiled function: FUN_0042dd5e
 * Entry Point: 0042dd5e
 * Size: 426 bytes
 */
#include "duel.h"


undefined4 FUN_0042dd5e(int arg1,int arg2)

{
  uint uVar1;
  undefined4 local_8;
  
  if ((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006826ce)[arg2 * 0x120 + arg1 * 0x5b20] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) == 0))))
  {
    FUN_0048d878(arg1,arg2,0x72,arg1,0);
    DAT_0068f220 = 1;
    DAT_0068f0f4 = 0xffffffff;
    uVar1 = *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20);
    FUN_0048c907(arg1,arg2,0x6d,1 - arg1,0xffffffff);
    DAT_0068f220 = 0;
    if (DAT_00681ea4 == 1) {
      DAT_00681ea4 = 0;
      FUN_0048e251();
      local_8 = 0;
    }
    else {
      if (((uVar1 & 0x10) == 0) && (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) {
        FUN_0048c50b(arg1,arg2,0x81);
      }
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x12);
      }
      FUN_0048dd43();
      local_8 = 1;
    }
  }
  else {
    local_8 = 0;
  }
  return local_8;
}


