/*
 * Decompiled function: FUN_0046801f
 * Entry Point: 0046801f
 * Size: 120 bytes
 */
#include "duel.h"


void FUN_0046801f(int arg_1,int arg_2,int arg_3)

{
  *(uint *)(&DAT_0068270c + arg_2 * 0x120 + arg_1 * 0x5b20) =
       *(int *)(&DAT_0068270c + arg_2 * 0x120 + arg_1 * 0x5b20) - arg_3 & 0xffU |
       *(uint *)(&DAT_0068270c + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffffff00;
  return;
}


