/*
 * Decompiled function: FUN_0045f7f1
 * Entry Point: 0045f7f1
 * Size: 84 bytes
 */
#include "duel.h"


undefined4 FUN_0045f7f1(int arg_1,int arg_2,int arg_3)

{
  if ((&DAT_004ff595)[arg_3 * 0x34] == '\x02') {
    *(uint *)(&DAT_006826fc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826fc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x8000000;
  }
  return 1;
}


