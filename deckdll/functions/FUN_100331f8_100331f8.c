/*
 * Decompiled function: FUN_100331f8
 * Entry Point: 100331f8
 * Size: 65 bytes
 */
#include "deckdll.h"


int32_t FUN_100331f8(HWND hwnd)

{
  int val_1;
  
  val_1 = thunk_FUN_1003336e(hwnd);
  if (val_1 != 0) {
    DAT_1013f198 = SetWindowLongA(hwnd,-4,0x10001343);
  }
  return 1;
}


