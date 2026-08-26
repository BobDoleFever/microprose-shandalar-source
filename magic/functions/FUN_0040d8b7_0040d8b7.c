/*
 * Decompiled function: FUN_0040d8b7
 * Entry Point: 0040d8b7
 * Size: 74 bytes
 */
#include "magic.h"


undefined4 FUN_0040d8b7(int arg_1,int arg_2,int arg_3)

{
  *(int *)(&DAT_0063ee90 + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&DAT_0063ee90 + arg_2 * 4 + arg_1 * 0x20) - arg_3;
  *(int *)(&DAT_0063eeac + arg_1 * 0x20) = *(int *)(&DAT_0063eeac + arg_1 * 0x20) - arg_3;
  return *(undefined4 *)(&DAT_0063ee90 + arg_2 * 4 + arg_1 * 0x20);
}


