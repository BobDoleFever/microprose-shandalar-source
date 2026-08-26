/*
 * Decompiled function: FUN_0040d7e9
 * Entry Point: 0040d7e9
 * Size: 66 bytes
 */
#include "magic.h"


undefined4 FUN_0040d7e9(int arg_1,int arg_2,int arg_3)

{
  *(int *)(&DAT_0063edd0 + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&DAT_0063edd0 + arg_2 * 4 + arg_1 * 0x20) + arg_3;
  *(int *)(&DAT_0063edec + arg_1 * 0x20) = *(int *)(&DAT_0063edec + arg_1 * 0x20) + arg_3;
  return *(undefined4 *)(&DAT_0063edd0 + arg_2 * 4 + arg_1 * 0x20);
}


