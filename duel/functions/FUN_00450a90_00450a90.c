/*
 * Decompiled function: FUN_00450a90
 * Entry Point: 00450a90
 * Size: 131 bytes
 */
#include "duel.h"


undefined4 FUN_00450a90(int arg_1,int arg_2,int *arg_3)

{
  if (arg_3 != (int *)0x0) {
    *arg_3 = (int)(char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20];
    arg_3[1] = *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  return *(undefined4 *)(&DAT_00682704 + arg_2 * 0x120 + arg_1 * 0x5b20);
}


