/*
 * Decompiled function: Duel_ScrollRightButton_Handler
 * Entry Point: 004ef740
 * Size: 265 bytes
 */
#include "magic.h"


void Duel_ScrollRightButton_Handler(HWND hwnd,LPARAM arg_2,byte arg_3)

{
  int iVar1;
  int local_1c;
  int local_18;
  LONG local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_14 = GetWindowLongA(hwnd,4);
  local_c = GetWindowLongA(hwnd,0);
  for (local_10 = 0; local_10 < local_14; local_10 = local_10 + 1) {
    iVar1 = FUN_0046bc92(*(HWND *)(local_c + local_10 * 4));
    if (iVar1 == 0) {
      SendMessageA(*(HWND *)(local_c + local_10 * 4),0x401,(WPARAM)&local_1c,0);
      local_8 = Ai_Subsystem_004b613b(local_1c,local_18);
      if ((((((local_8 & 1) != 0) && ((arg_3 & 1) != 0)) ||
           (((local_8 & 2) != 0 && ((arg_3 & 2) != 0)))) ||
          (((local_8 & 4) != 0 && ((arg_3 & 4) != 0)))) ||
         (((local_8 & 0x40) != 0 && ((arg_3 & 8) != 0)))) {
        SendMessageA(hwnd,0x402,*(WPARAM *)(local_c + local_10 * 4),arg_2);
      }
    }
  }
  return;
}


