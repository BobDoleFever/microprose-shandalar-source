/*
 * Decompiled function: thunk_FUN_10006020
 * Entry Point: 10001361
 * Size: 5 bytes
 */
#include "magvid.h"


void __cdecl thunk_FUN_10006020(int arg_1)

{
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int *piStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if ((arg_1 != 0) && (*(int *)(arg_1 + 8) != 0)) {
    piStack_18 = *(int **)(arg_1 + 8);
    if (*piStack_18 == 0) {
      iStack_24 = 0;
      iStack_28 = 0;
      iStack_20 = 0x140;
      iStack_1c = 0;
    }
    else {
      thunk_FUN_1000b5e0((void *)*piStack_18,&iStack_28);
    }
    iStack_14 = iStack_28;
    iStack_c = iStack_20;
    iStack_8 = iStack_1c;
    iStack_10 = iStack_24;
    SetWindowPos(*(HWND *)(arg_1 + 0x10),(HWND)0x0,*(int *)(arg_1 + 0x58) + iStack_28,
                 *(int *)(arg_1 + 0x5c) + iStack_24,iStack_20 - iStack_28,iStack_1c - iStack_24,0x16
                );
  }
  return;
}


