/*
 * Decompiled function: FUN_0040d510
 * Entry Point: 0040d510
 * Size: 66 bytes
 */
#include "magic.h"


undefined4 FUN_0040d510(int arg_1,int arg_2,int arg_3)

{
  *(int *)(&DAT_0063ee30 + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&DAT_0063ee30 + arg_2 * 4 + arg_1 * 0x20) + arg_3;
  *(int *)(&DAT_0063ee4c + arg_1 * 0x20) = *(int *)(&DAT_0063ee4c + arg_1 * 0x20) + arg_3;
  return *(undefined4 *)(&DAT_0063ee30 + arg_2 * 4 + arg_1 * 0x20);
}


