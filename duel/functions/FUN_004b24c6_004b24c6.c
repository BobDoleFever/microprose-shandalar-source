/*
 * Decompiled function: FUN_004b24c6
 * Entry Point: 004b24c6
 * Size: 245 bytes
 */
#include "duel.h"


void FUN_004b24c6(HWND hwnd,HWND param_2)

{
  int iVar1;
  HWND pHVar2;
  int local_1c [2];
  LONG local_14;
  LPARAM local_10;
  int local_c;
  LONG local_8;
  
  local_14 = GetWindowLongA(hwnd,4);
  local_8 = GetWindowLongA(hwnd,0);
  SendMessageA(param_2,0x401,(WPARAM)local_1c,0);
  iVar1 = FUN_004994f8(DAT_00618ab0,local_1c,(undefined4 *)0x0,&local_10,(undefined4 *)0x0);
  if (iVar1 != 0) {
    for (local_c = 0; local_c < local_14; local_c = local_c + 1) {
      pHVar2 = (HWND)FUN_004864b1(*(HWND *)(local_8 + local_c * 4));
      if (pHVar2 == param_2) {
        SendMessageA(*(HWND *)(local_8 + local_c * 4),0x401,(WPARAM)local_1c,0);
        SendMessageA(DAT_00618ab0,0x406,(WPARAM)local_1c,local_10);
        FUN_004b24c6(hwnd,*(HWND *)(local_8 + local_c * 4));
      }
    }
  }
  return;
}


