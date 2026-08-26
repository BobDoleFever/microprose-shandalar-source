/*
 * Decompiled function: FUN_0044a267
 * Entry Point: 0044a267
 * Size: 93 bytes
 */
#include "duel.h"


void FUN_0044a267(int x,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4)

{
  if (x != 0) {
    FUN_00471395((HANDLE)x);
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


