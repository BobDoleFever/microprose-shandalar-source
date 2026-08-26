/*
 * Decompiled function: FUN_10006020
 * Entry Point: 10006020
 * Size: 189 bytes
 */
#include "magvid.h"


void __cdecl FUN_10006020(int arg_1)

{
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((arg_1 != 0) && (*(int *)(arg_1 + 8) != 0)) {
    local_18 = *(int **)(arg_1 + 8);
    if (*local_18 == 0) {
      local_24 = 0;
      local_28 = 0;
      local_20 = 0x140;
      local_1c = 0;
    }
    else {
      thunk_FUN_1000b5e0((void *)*local_18,&local_28);
    }
    local_14 = local_28;
    local_c = local_20;
    local_8 = local_1c;
    local_10 = local_24;
    SetWindowPos(*(HWND *)(arg_1 + 0x10),(HWND)0x0,*(int *)(arg_1 + 0x58) + local_28,
                 *(int *)(arg_1 + 0x5c) + local_24,local_20 - local_28,local_1c - local_24,0x16);
  }
  return;
}


