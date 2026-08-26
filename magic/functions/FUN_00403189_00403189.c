/*
 * Decompiled function: FUN_00403189
 * Entry Point: 00403189
 * Size: 185 bytes
 */
#include "magic.h"


bool FUN_00403189(HWND hwnd,int arg2)

{
  LONG LVar1;
  size_t sVar2;
  bool bVar3;
  int local_10;
  char *local_8;
  
  if (hwnd == (HWND)0x0) {
    bVar3 = false;
  }
  else {
    local_8 = (char *)GetWindowLongA(hwnd,4);
    LVar1 = GetWindowLongA(hwnd,8);
    if (LVar1 + -1 < arg2) {
      bVar3 = false;
    }
    else {
      for (local_10 = 0; local_10 < arg2; local_10 = local_10 + 1) {
        sVar2 = strlen(local_8);
        local_8 = local_8 + sVar2 + 1;
      }
      bVar3 = *local_8 != '_';
    }
  }
  return bVar3;
}


