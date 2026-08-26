/*
 * Decompiled function: FUN_004a7b83
 * Entry Point: 004a7b83
 * Size: 176 bytes
 */
#include "duel.h"


undefined4 FUN_004a7b83(int arg1,int arg2)

{
  if (((&DAT_006826cc)[arg1 * 0x5b20 + arg2 * 0x120] & 0x10) == 0) {
    *(uint *)(&DAT_006826cc + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint *)(&DAT_006826cc + arg1 * 0x5b20 + arg2 * 0x120) | 0x10;
    if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 1) != 0) {
      DAT_0068f0f4 = 0xffffffff;
    }
    FUN_0048c50b(arg1,arg2,0x81);
  }
  return 0;
}


