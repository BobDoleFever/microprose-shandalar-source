/*
 * Decompiled function: FUN_00469825
 * Entry Point: 00469825
 * Size: 424 bytes
 */
#include "duel.h"


int FUN_00469825(int arg_1,int arg_2,int arg_3)

{
  int local_514;
  int local_50c;
  int local_508;
  int local_504 [320];
  
  local_514 = FUN_004699cd(arg_1,arg_2,(int)local_504);
  local_508 = 0;
  for (; (local_508 < arg_3 && (local_514 != 0)); local_514 = local_514 + -1) {
    local_50c = FUN_00439892(local_514);
    FUN_004a7b83(local_504[local_50c * 2],local_504[local_50c * 2 + 1]);
    if ((*(int *)(&DAT_00618ad8 +
                 *(int *)(&DAT_004ff590 +
                         *(int *)(&DAT_006826c4 +
                                 local_504[local_50c * 2] * 0x5b20 +
                                 local_504[local_50c * 2 + 1] * 0x120) * 0x34) * 0x98) == 0x58) ||
       (*(int *)(&DAT_00618ad8 +
                *(int *)(&DAT_004ff590 +
                        *(int *)(&DAT_006826c4 +
                                local_504[local_50c * 2] * 0x5b20 +
                                local_504[local_50c * 2 + 1] * 0x120) * 0x34) * 0x98) == 0x57)) {
      FUN_004a2b00(arg_1,arg_2,DAT_006664e8,local_504[local_50c * 2],local_504[local_50c * 2 + 1]);
    }
    for (; local_50c < local_514; local_50c = local_50c + 1) {
      local_504[local_50c * 2] = local_504[local_50c * 2 + 2];
      local_504[local_50c * 2 + 1] = local_504[local_50c * 2 + 3];
    }
    local_508 = local_508 + 1;
  }
  return local_508;
}


