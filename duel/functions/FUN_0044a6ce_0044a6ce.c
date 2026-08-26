/*
 * Decompiled function: FUN_0044a6ce
 * Entry Point: 0044a6ce
 * Size: 118 bytes
 */
#include "duel.h"


void FUN_0044a6ce(void)

{
  if (DAT_00516b48 != (HMENU)0x0) {
    DestroyMenu(DAT_00516b48);
  }
  DAT_00516b48 = (HMENU)0x0;
  if (DAT_00516b50 != (HANDLE)0x0) {
    FUN_00471395(DAT_00516b50);
  }
  DAT_00516b50 = (HANDLE)0x0;
  if (DAT_00516b4c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00516b4c);
  }
  DAT_00516b4c = (HGDIOBJ)0x0;
  return;
}


