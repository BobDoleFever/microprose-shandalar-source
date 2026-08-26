/*
 * Decompiled function: FUN_0045f5e4
 * Entry Point: 0045f5e4
 * Size: 168 bytes
 */
#include "duel.h"


undefined4 FUN_0045f5e4(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x6c) &&
      (((&DAT_004ff594)
        [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] & 0x40) != 0
      )) && (arg_1 != DAT_0068ecb0)) {
    *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
    *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
  }
  return 0;
}


