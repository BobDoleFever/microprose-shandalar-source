/*
 * Decompiled function: Adventure_DestroyConfirmMenu
 * Entry Point: 004ecf94
 * Size: 81 bytes
 */
#include "magic.h"


void Adventure_DestroyConfirmMenu(void)

{
  if (DAT_005659f8 != (HMENU)0x0) {
    DestroyMenu(DAT_005659f8);
  }
  if (DAT_005659e0 != (HMENU)0x0) {
    DestroyMenu(DAT_005659e0);
  }
  DAT_005659f8 = (HMENU)0x0;
  DAT_005659e0 = (HMENU)0x0;
  return;
}


