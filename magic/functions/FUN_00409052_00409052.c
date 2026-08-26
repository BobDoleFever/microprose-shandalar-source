/*
 * Decompiled function: FUN_00409052
 * Entry Point: 00409052
 * Size: 164 bytes
 */
#include "magic.h"


void FUN_00409052(void)

{
  int local_8;
  
  if (DAT_00538308 != (HMENU)0x0) {
    DestroyMenu(DAT_00538308);
  }
  DAT_00538308 = (HMENU)0x0;
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00538310 + local_8 * 4) != 0) {
      FUN_004f4548(*(HANDLE *)(&DAT_00538310 + local_8 * 4));
      *(undefined4 *)(&DAT_00538310 + local_8 * 4) = 0;
    }
  }
  if (DAT_0053830c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0053830c);
  }
  DAT_0053830c = (HGDIOBJ)0x0;
  return;
}


