/*
 * Decompiled function: FUN_004a63d8
 * Entry Point: 004a63d8
 * Size: 519 bytes
 */
#include "duel.h"


undefined4 FUN_004a63d8(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  if ((((DAT_0068f230 == 0xd7) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) &&
     (arg_1 == DAT_00681ec4)) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      iVar1 = FUN_004d7d5e(0x44);
      if (*(int *)(&DAT_006826c0 + arg_2 * 0x120 + arg_1 * 0x5b20) == iVar1) {
        local_8 = 0;
        for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
          for (local_c = 0; local_c < (int)(&DAT_00666408)[local_10]; local_c = local_c + 1) {
            if (((*(int *)(&DAT_006826c4 + local_c * 0x120 + local_10 * 0x5b20) == DAT_0068f104) &&
                ((&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
                 (&DAT_006826d3)[local_c * 0x120 + local_10 * 0x5b20])) &&
               (*(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) ==
                *(int *)(&DAT_006826ec + local_c * 0x120 + local_10 * 0x5b20))) {
              local_8 = local_8 + *(int *)(&DAT_006826e4 + local_c * 0x120 + local_10 * 0x5b20);
            }
          }
        }
        iVar1 = *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
        if (local_8 <= *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20)) {
          iVar1 = local_8;
        }
        (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + iVar1;
      }
      FUN_0046e571(arg_1,arg_2,4);
    }
  }
  return 0;
}


