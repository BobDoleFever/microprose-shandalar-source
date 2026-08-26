/*
 * Decompiled function: FUN_00438e72
 * Entry Point: 00438e72
 * Size: 80 bytes
 */
#include "duel.h"


void FUN_00438e72(int arg_1)

{
  if ((arg_1 != -1) && (*(int *)(&DAT_0060d5b0 + arg_1 * 0x10) != 0)) {
    DeleteObject(*(HGDIOBJ *)(&DAT_0060d5b0 + arg_1 * 0x10));
    *(undefined4 *)(&DAT_0060d5b0 + arg_1 * 0x10) = 0;
  }
  return;
}


