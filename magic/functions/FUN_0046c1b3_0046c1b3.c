/*
 * Decompiled function: FUN_0046c1b3
 * Entry Point: 0046c1b3
 * Size: 80 bytes
 */
#include "magic.h"


void FUN_0046c1b3(int arg_1)

{
  if ((arg_1 != -1) && (*(int *)(&DAT_00696a20 + arg_1 * 0x10) != 0)) {
    DeleteObject(*(HGDIOBJ *)(&DAT_00696a20 + arg_1 * 0x10));
    *(undefined4 *)(&DAT_00696a20 + arg_1 * 0x10) = 0;
  }
  return;
}


