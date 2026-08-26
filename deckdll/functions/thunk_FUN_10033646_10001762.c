/*
 * Decompiled function: thunk_FUN_10033646
 * Entry Point: 10001762
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10033646(int arg1,int arg2)

{
  BOOL BVar1;
  int iStack_c;
  int iStack_8;
  
  iStack_8 = -1;
  if ((arg1 == 0) || (arg2 == 0)) {
    iStack_8 = -1;
  }
  else {
    iStack_c = 0;
    while ((iStack_c < arg2 && (iStack_8 == -1))) {
      BVar1 = IsWindowVisible(*(HWND *)(arg1 + iStack_c * 4));
      if (BVar1 != 0) {
        iStack_8 = iStack_c;
      }
      iStack_c = iStack_c + 1;
    }
  }
  return iStack_8;
}


