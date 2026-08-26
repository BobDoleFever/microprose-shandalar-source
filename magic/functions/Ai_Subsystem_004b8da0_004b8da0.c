/*
 * Decompiled function: Ai_Subsystem_004b8da0
 * Entry Point: 004b8da0
 * Size: 93 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b8da0(int x,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4)

{
  if (x != 0) {
    FUN_004f4548((HANDLE)x);
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


