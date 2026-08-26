/*
 * Decompiled function: FUN_0047c734
 * Entry Point: 0047c734
 * Size: 118 bytes
 */
#include "magic.h"


void FUN_0047c734(void)

{
  if (DAT_00539518 != (HMENU)0x0) {
    DestroyMenu(DAT_00539518);
  }
  DAT_00539518 = (HMENU)0x0;
  if (DAT_00539514 != (HANDLE)0x0) {
    FUN_004f4548(DAT_00539514);
  }
  DAT_00539514 = (HANDLE)0x0;
  if (DAT_00539510 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539510);
  }
  DAT_00539510 = (HGDIOBJ)0x0;
  return;
}


