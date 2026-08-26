/*
 * Decompiled function: FUN_0049f327
 * Entry Point: 0049f327
 * Size: 93 bytes
 */
#include "duel.h"


void FUN_0049f327(HANDLE arg_1,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4)

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


