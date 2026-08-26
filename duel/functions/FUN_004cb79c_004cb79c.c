/*
 * Decompiled function: FUN_004cb79c
 * Entry Point: 004cb79c
 * Size: 856 bytes
 */
#include "duel.h"


undefined4 FUN_004cb79c(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      DAT_0068f2d4 = DAT_0068f2d4 +
                     (*(int *)(&DAT_0068ede8 + (1 - arg_1) * 0x20) -
                     *(int *)(&DAT_0068ede8 + arg_1 * 0x20));
    }
    if (arg_3 == 0x82) {
      cVar1 = (&DAT_006826dd)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120];
      bVar2 = FUN_004af7bb(arg_1,arg_2,2);
      if (((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) &&
         (((&DAT_004ff594)
           [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 2) != 0
         )) {
        *(uint *)(&DAT_006827c8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) =
             *(uint *)(&DAT_006827c8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) & 0xfffffffc;
      }
    }
    if (((arg_3 == 0x84) &&
        (((&DAT_006826cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] & 0x10) != 0)) &&
       ((DAT_00666458 == DAT_0068ecb0 &&
        ((DAT_00666458 == DAT_00681eb4 &&
         (((&DAT_004ff594)
           [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 2) != 0
         )))))) {
      cVar1 = (&DAT_006826dd)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120];
      bVar2 = FUN_004af7bb(arg_1,arg_2,2);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
        *(uint *)(&DAT_006827d4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) =
             *(uint *)(&DAT_006827d4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) | 0x10;
        (&DAT_006827cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] =
             (&DAT_006827cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] + '\x04';
      }
    }
    if (arg_3 == 0x6c) {
      cVar1 = (&DAT_006826dd)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120];
      bVar2 = FUN_004af7bb(arg_1,arg_2,2);
      if (((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) &&
         (((&DAT_004ff594)
           [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 2) != 0
         )) {
        (&DAT_006827cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] =
             (&DAT_006827cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] + '\x04';
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}


