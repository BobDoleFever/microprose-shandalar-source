/*
 * Decompiled function: thunk_FUN_10013e46
 * Entry Point: 10001609
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10013e46(void)

{
  int iStack_8;
  
  for (iStack_8 = 0; iStack_8 < DAT_10158728; iStack_8 = iStack_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_101cf5f0 + iStack_8 * 0x18));
  }
  DAT_10158728 = 0;
  return;
}


