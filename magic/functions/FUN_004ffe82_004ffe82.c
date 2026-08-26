/*
 * Decompiled function: FUN_004ffe82
 * Entry Point: 004ffe82
 * Size: 93 bytes
 */
#include "magic.h"


void FUN_004ffe82(HANDLE arg_1,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4)

{
  if (arg_1 != (HANDLE)0x0) {
    FUN_004f4548(arg_1);
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


