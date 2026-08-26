/*
 * Decompiled function: FUN_0047097b
 * Entry Point: 0047097b
 * Size: 51 bytes
 */
#include "duel.h"


void FUN_0047097b(HDC hdc,HGDIOBJ arg2)

{
  if (hdc != (HDC)0x0) {
    DeleteDC(hdc);
  }
  if (arg2 != (HGDIOBJ)0x0) {
    DeleteObject(arg2);
  }
  return;
}


