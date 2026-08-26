/*
 * Decompiled function: FUN_0049f384
 * Entry Point: 0049f384
 * Size: 340 bytes
 */
#include "duel.h"


void FUN_0049f384(HWND hwnd)

{
  UINT UVar1;
  
  IsDlgButtonChecked(hwnd,0x456);
  UVar1 = IsDlgButtonChecked(hwnd,0x45a);
  if ((UVar1 == 0) && (UVar1 = IsDlgButtonChecked(hwnd,0x45b), UVar1 == 0)) {
    IsDlgButtonChecked(hwnd,0x45b);
  }
  IsDlgButtonChecked(hwnd,0x46a);
  return;
}


