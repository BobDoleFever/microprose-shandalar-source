/*
 * Decompiled function: FUN_0049b277
 * Entry Point: 0049b277
 * Size: 74 bytes
 */
#include "duel.h"


undefined4 FUN_0049b277(int arg_1,int arg_2,int arg_3)

{
  *(int *)(&DAT_0068f2e0 + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&DAT_0068f2e0 + arg_2 * 4 + arg_1 * 0x20) - arg_3;
  *(int *)(&DAT_0068f2fc + arg_1 * 0x20) = *(int *)(&DAT_0068f2fc + arg_1 * 0x20) - arg_3;
  return *(undefined4 *)(&DAT_0068f2e0 + arg_2 * 4 + arg_1 * 0x20);
}


