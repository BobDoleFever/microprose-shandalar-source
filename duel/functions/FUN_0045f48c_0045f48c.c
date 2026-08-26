/*
 * Decompiled function: FUN_0045f48c
 * Entry Point: 0045f48c
 * Size: 344 bytes
 */
#include "duel.h"


undefined4 FUN_0045f48c(int arg_1,int arg_2,int arg_3)

{
  int local_8;
  
  if (((((DAT_0068f230 == 0xd3) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) &&
      ((arg_1 == DAT_00681ec4 && (arg_1 == DAT_00666458)))) &&
     ((arg_1 == DAT_0068ecb0 &&
      (((&DAT_004ff594)
        [*(int *)(&DAT_006826c4 + DAT_0068edd0 * 0x120 + DAT_00666754 * 0x5b20) * 0x34] & 4) != 0)))
     ) {
    if (arg_3 == 0x7d) {
      if (arg_1 == DAT_00676510) {
        DAT_0066642c = DAT_0066642c | 1;
      }
      else {
        local_8 = 0;
        while ((local_8 < 500 && (*(int *)(&DAT_006669f0 + local_8 * 4 + arg_1 * 2000) != -1))) {
          local_8 = local_8 + 1;
        }
        if (((int)(&DAT_0068ee78)[arg_1] < 8) && (5 < local_8)) {
          DAT_0066642c = DAT_0066642c | 2;
        }
        else {
          DAT_0066642c = DAT_0066642c | 1;
        }
      }
    }
    if (arg_3 == 0x7e) {
      FUN_00487ce1(arg_1);
    }
  }
  return 0;
}


