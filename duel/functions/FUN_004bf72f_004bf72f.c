/*
 * Decompiled function: FUN_004bf72f
 * Entry Point: 004bf72f
 * Size: 292 bytes
 */
#include "duel.h"


undefined4 FUN_004bf72f(int arg_1,int arg_2,int arg_3)

{
  if ((((*(int *)(&DAT_004ff590 + arg_3 * 0x34) == 0x2c) ||
       (*(int *)(&DAT_004ff590 + arg_3 * 0x34) == 0xea)) &&
      ((char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0)) &&
     (*(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) {
    (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006826d3)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120];
    *(undefined4 *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(undefined4 *)(&DAT_006826ec + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120);
  }
  return 0;
}


