/*
 * Decompiled function: FUN_0049aed0
 * Entry Point: 0049aed0
 * Size: 66 bytes
 */
#include "duel.h"


undefined4 FUN_0049aed0(int arg_1,int arg_2,int arg_3)

{
  *(int *)(&DAT_0068ef50 + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&DAT_0068ef50 + arg_2 * 4 + arg_1 * 0x20) + arg_3;
  *(int *)(&DAT_0068ef6c + arg_1 * 0x20) = *(int *)(&DAT_0068ef6c + arg_1 * 0x20) + arg_3;
  return *(undefined4 *)(&DAT_0068ef50 + arg_2 * 4 + arg_1 * 0x20);
}


