/*
 * Decompiled function: FUN_004099bb
 * Entry Point: 004099bb
 * Size: 228 bytes
 */
#include "duel.h"


undefined4 FUN_004099bb(int arg_1,int arg_2,int arg_3)

{
  DAT_0068f220 = 1;
  DAT_0068f0f4 = 0xffffffff;
  if (((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
      (((&DAT_004ff594)[arg_3 * 0x34] & 1) != 0)) && (((&DAT_004ff5a9)[arg_3 * 0x34] & 0x10) != 0))
  {
    FUN_0048c907(arg_1,arg_2,0x6d,1 - arg_1,0xffffffff);
    if (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0) {
      FUN_0048c50b(arg_1,arg_2,0x81);
    }
  }
  DAT_0068f220 = 0;
  return 0;
}


