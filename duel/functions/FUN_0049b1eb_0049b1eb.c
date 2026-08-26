/*
 * Decompiled function: FUN_0049b1eb
 * Entry Point: 0049b1eb
 * Size: 74 bytes
 */
#include "duel.h"


undefined4 FUN_0049b1eb(int arg_1,int arg_2,int arg_3)

{
  *(int *)(&DAT_0068ed10 + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&DAT_0068ed10 + arg_2 * 4 + arg_1 * 0x20) - arg_3;
  *(int *)(&DAT_0068ed2c + arg_1 * 0x20) = *(int *)(&DAT_0068ed2c + arg_1 * 0x20) - arg_3;
  return *(undefined4 *)(&DAT_0068ed10 + arg_2 * 4 + arg_1 * 0x20);
}


