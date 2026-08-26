/*
 * Decompiled function: FUN_00412b3d
 * Entry Point: 00412b3d
 * Size: 712 bytes
 */
#include "duel.h"


undefined4 FUN_00412b3d(int arg_1,int arg_2,int arg_3)

{
  int local_c;
  int local_8;
  
  if ((((arg_3 == 0x77) && ((&DAT_006826e0)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] != '\0'))
      && (((&DAT_004ff594)
           [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] & 1) != 0
         )) && ((&DAT_006826e0)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] != '\x04')) {
    if (DAT_0068ecb0 == 0) {
      *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
    }
    else {
      *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 0x100;
    }
  }
  if ((((DAT_0068f230 == 0xd5) && (arg_2 == DAT_00690c48)) &&
      ((arg_1 == DAT_0068ecb0 &&
       (((*(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffff) != 0 &&
        (DAT_00681ec4 == arg_1)))))) &&
     ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0))
     )) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        if ((&DAT_006826e4)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\0') {
          for (local_c = 0;
              local_c < (int)(*(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff);
              local_c = local_c + 1) {
            Mem_AllocOrFree_004afd1c(local_8,2,arg_1,arg_2);
          }
        }
        *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) >> 8;
      }
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
  }
  return 0;
}


