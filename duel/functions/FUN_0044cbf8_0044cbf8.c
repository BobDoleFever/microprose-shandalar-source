/*
 * Decompiled function: FUN_0044cbf8
 * Entry Point: 0044cbf8
 * Size: 118 bytes
 */
#include "duel.h"


void FUN_0044cbf8(void)

{
  if (DAT_00516b78 != (HMENU)0x0) {
    DestroyMenu(DAT_00516b78);
  }
  DAT_00516b78 = (HMENU)0x0;
  if (DAT_00516b58 != (HANDLE)0x0) {
    FUN_00471395(DAT_00516b58);
  }
  if (DAT_00516b74 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00516b74);
  }
  DAT_00516b58 = (HANDLE)0x0;
  DAT_00516b74 = (HGDIOBJ)0x0;
  return;
}


