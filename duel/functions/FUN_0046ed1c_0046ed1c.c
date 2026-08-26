/*
 * Decompiled function: FUN_0046ed1c
 * Entry Point: 0046ed1c
 * Size: 785 bytes
 */
#include "duel.h"


void FUN_0046ed1c(int arg1,int arg2)

{
  int local_514;
  int local_510;
  int local_508;
  int aiStack_504 [320];
  
  local_510 = 0;
  for (local_508 = 0; local_508 < 2; local_508 = local_508 + 1) {
    for (local_514 = 0; local_514 < (int)(&DAT_00666408)[local_508]; local_514 = local_514 + 1) {
      if ((((*(int *)(&DAT_006826c4 + local_514 * 0x120 + local_508 * 0x5b20) != -1) &&
           (((&DAT_006826cc)[local_514 * 0x120 + local_508 * 0x5b20] & 2) != 0)) &&
          ((char)(&DAT_006826d2)[local_514 * 0x120 + local_508 * 0x5b20] == arg1)) &&
         ((*(int *)(&DAT_006826e8 + local_514 * 0x120 + local_508 * 0x5b20) == arg2 &&
          ((local_508 != arg1 || (local_514 != arg2)))))) {
        if (((&DAT_004ff594)
             [*(int *)(&DAT_006826c4 + local_514 * 0x120 + local_508 * 0x5b20) * 0x34] & 0x43) == 0)
        {
          aiStack_504[local_510 * 2] = local_508;
          aiStack_504[local_510 * 2 + 1] = local_514;
          local_510 = local_510 + 1;
        }
        else {
          (&DAT_006826d2)[local_514 * 0x120 + local_508 * 0x5b20] = 0xff;
          *(undefined4 *)(&DAT_006826e8 + local_514 * 0x120 + local_508 * 0x5b20) = 0xffffffff;
        }
      }
    }
  }
  while (local_510 != 0) {
    local_510 = local_510 + -1;
    FUN_0046e571(aiStack_504[local_510 * 2],aiStack_504[local_510 * 2 + 1],2);
  }
  *(undefined2 *)(&DAT_006826d0 + arg2 * 0x120 + arg1 * 0x5b20) = 0;
  *(undefined2 *)(&DAT_006826da + arg2 * 0x120 + arg1 * 0x5b20) =
       *(undefined2 *)(&DAT_006826d0 + arg2 * 0x120 + arg1 * 0x5b20);
  *(undefined2 *)(&DAT_006826d8 + arg2 * 0x120 + arg1 * 0x5b20) =
       *(undefined2 *)(&DAT_006826da + arg2 * 0x120 + arg1 * 0x5b20);
  (&DAT_006826de)[arg2 * 0x120 + arg1 * 0x5b20] = 0xff;
  return;
}


