/*
 * Decompiled function: FUN_004f3b2c
 * Entry Point: 004f3b2c
 * Size: 51 bytes
 */
#include "magic.h"


void FUN_004f3b2c(HDC hdc,HGDIOBJ arg2)

{
  if (hdc != (HDC)0x0) {
    DeleteDC(hdc);
  }
  if (arg2 != (HGDIOBJ)0x0) {
    DeleteObject(arg2);
  }
  return;
}


