/*
 * Decompiled function: FUN_0042b213
 * Entry Point: 0042b213
 * Size: 139 bytes
 */
#include "duel.h"


undefined4 FUN_0042b213(int arg1,int arg2)

{
  DAT_0068f220 = 1;
  DAT_0068f0f4 = 0xffffffff;
  FUN_0048c907(arg1,arg2,0x6d,1 - arg1,0xffffffff);
  if (((&DAT_006826cc)[arg1 * 0x5b20 + arg2 * 0x120] & 0x10) != 0) {
    FUN_0048c50b(arg1,arg2,0x81);
  }
  DAT_0068f220 = 0;
  return DAT_0068f0f4;
}


