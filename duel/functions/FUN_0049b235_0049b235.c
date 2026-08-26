/*
 * Decompiled function: FUN_0049b235
 * Entry Point: 0049b235
 * Size: 66 bytes
 */
#include "duel.h"


undefined4 FUN_0049b235(int arg_1,int arg_2,int arg_3)

{
  *(int *)(&DAT_0068f2e0 + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&DAT_0068f2e0 + arg_2 * 4 + arg_1 * 0x20) + arg_3;
  *(int *)(&DAT_0068f2fc + arg_1 * 0x20) = *(int *)(&DAT_0068f2fc + arg_1 * 0x20) + arg_3;
  return *(undefined4 *)(&DAT_0068f2e0 + arg_2 * 4 + arg_1 * 0x20);
}


