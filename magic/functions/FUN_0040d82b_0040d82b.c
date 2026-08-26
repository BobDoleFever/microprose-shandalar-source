/*
 * Decompiled function: FUN_0040d82b
 * Entry Point: 0040d82b
 * Size: 74 bytes
 */
#include "magic.h"


undefined4 FUN_0040d82b(int arg_1,int arg_2,int arg_3)

{
  *(int *)(&DAT_0063edd0 + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&DAT_0063edd0 + arg_2 * 4 + arg_1 * 0x20) - arg_3;
  *(int *)(&DAT_0063edec + arg_1 * 0x20) = *(int *)(&DAT_0063edec + arg_1 * 0x20) - arg_3;
  return *(undefined4 *)(&DAT_0063edd0 + arg_2 * 4 + arg_1 * 0x20);
}


