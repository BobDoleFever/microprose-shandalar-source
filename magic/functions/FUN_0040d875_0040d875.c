/*
 * Decompiled function: FUN_0040d875
 * Entry Point: 0040d875
 * Size: 66 bytes
 */
#include "magic.h"


undefined4 FUN_0040d875(int arg_1,int arg_2,int arg_3)

{
  *(int *)(&DAT_0063ee90 + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&DAT_0063ee90 + arg_2 * 4 + arg_1 * 0x20) + arg_3;
  *(int *)(&DAT_0063eeac + arg_1 * 0x20) = *(int *)(&DAT_0063eeac + arg_1 * 0x20) + arg_3;
  return *(undefined4 *)(&DAT_0063ee90 + arg_2 * 4 + arg_1 * 0x20);
}


