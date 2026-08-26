/*
 * Decompiled function: FUN_0049d0dc
 * Entry Point: 0049d0dc
 * Size: 93 bytes
 */
#include "duel.h"


void FUN_0049d0dc(HANDLE arg_1,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4)

{
  if (arg_1 != (HANDLE)0x0) {
    FUN_00471395(arg_1);
  }
  if (arg_2 != (HGDIOBJ)0x0) {
    DeleteObject(arg_2);
  }
  if (arg_3 != (HGDIOBJ)0x0) {
    DeleteObject(arg_3);
  }
  if (arg_4 != (HGDIOBJ)0x0) {
    DeleteObject(arg_4);
  }
  return;
}


