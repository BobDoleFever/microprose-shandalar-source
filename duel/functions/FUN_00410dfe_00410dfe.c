/*
 * Decompiled function: FUN_00410dfe
 * Entry Point: 00410dfe
 * Size: 395 bytes
 */
#include "duel.h"


undefined4 FUN_00410dfe(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    DAT_0068f2d4 = DAT_0068f2d4 + ((&DAT_00681ea8)[arg_1] - (&DAT_00681ea8)[1 - arg_1]) * 0x18;
  }
  if (((arg_3 == 2) || (arg_3 == 3)) &&
     ((DAT_00690c48 == arg_2 &&
      ((DAT_0068ecb0 == arg_1 && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)))))
     ) {
    DAT_0066642c = DAT_0066642c | 2;
  }
  if (((((arg_3 == 4) || (arg_3 == 5)) || (arg_3 == 199)) &&
      ((DAT_00690c48 == arg_2 && (DAT_0068ecb0 == arg_1)))) &&
     (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    Mem_AllocOrFree_004afd1c(DAT_00666458,1,arg_1,arg_2);
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  if (arg_3 == 0x22) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}


