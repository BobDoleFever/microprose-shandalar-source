/*
 * Decompiled function: FUN_00436a52
 * Entry Point: 00436a52
 * Size: 164 bytes
 */
#include "duel.h"


void FUN_00436a52(void)

{
  int local_8;
  
  if (DAT_00516700 != (HMENU)0x0) {
    DestroyMenu(DAT_00516700);
  }
  DAT_00516700 = (HMENU)0x0;
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00516708 + local_8 * 4) != 0) {
      FUN_00471395(*(HANDLE *)(&DAT_00516708 + local_8 * 4));
      *(undefined4 *)(&DAT_00516708 + local_8 * 4) = 0;
    }
  }
  if (DAT_00516704 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00516704);
  }
  DAT_00516704 = (HGDIOBJ)0x0;
  return;
}


