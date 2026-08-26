/*
 * Decompiled function: FUN_004a60aa
 * Entry Point: 004a60aa
 * Size: 814 bytes
 */
#include "duel.h"


undefined4 FUN_004a60aa(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_c;
  int local_8;
  
  if ((((DAT_0068f230 == 0xd5) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) &&
     (arg_1 == DAT_00681ec4)) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      iVar1 = FUN_004d7d5e(0x200);
      if (*(int *)(&DAT_006826c0 + arg_1 * 0x5b20 + arg_2 * 0x120) == iVar1) {
        if ((DAT_0066aaf4 == 1) && (arg_1 == DAT_00676510)) {
          (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + 1;
        }
        else {
          (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + 2;
        }
      }
      iVar1 = FUN_004d7d5e(0xb5);
      if (*(int *)(&DAT_006826c0 + arg_1 * 0x5b20 + arg_2 * 0x120) == iVar1) {
        (&DAT_00681ea8)[(*(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x1000) >> 0xc]
             = (int)(&DAT_00681ea8)
                    [(*(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x1000) >> 0xc] /
               2;
      }
      iVar1 = FUN_004d7d5e(0x32);
      if (*(int *)(&DAT_006826c0 + arg_1 * 0x5b20 + arg_2 * 0x120) == iVar1) {
        Mem_AllocOrFree_004afd1c
                  ((int)(char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120],
                   *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120),arg_1,arg_2);
      }
      iVar1 = FUN_004d7d5e(0x109);
      if (*(int *)(&DAT_006826c0 + arg_1 * 0x5b20 + arg_2 * 0x120) == iVar1) {
        for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
          Mem_AllocOrFree_004afd1c
                    (local_8,*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120),arg_1,arg_2);
          for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
            iVar1 = FUN_0048a33f(local_8,local_c);
            if ((iVar1 != 0) &&
               (((&DAT_004ff594)
                 [*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0)) {
              FUN_004af950(local_8,local_c,*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120),
                           arg_1,arg_2);
            }
          }
        }
      }
      FUN_0046e571(arg_1,arg_2,4);
    }
  }
  return 0;
}


