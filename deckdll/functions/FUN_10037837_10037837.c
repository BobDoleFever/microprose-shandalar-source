/*
 * Decompiled function: FUN_10037837
 * Entry Point: 10037837
 * Size: 339 bytes
 */
#include "deckdll.h"


void FUN_10037837(HWND hwnd,HWND param_2)

{
  LRESULT LVar1;
  int val_2;
  uint32_t uval_3;
  HWND hWnd;
  UINT Msg;
  HWND lParam;
  int32_t local_14;
  int32_t local_10;
  int32_t local_c;
  
  local_14 = SendMessageA(hwnd,0x188,0,0);
  local_c = SendMessageA(hwnd,0x18b,0,0);
  local_10 = 0;
  while ((int)local_10 < local_c) {
    LVar1 = SendMessageA(hwnd,0x199,local_10,0);
    val_2 = thunk_FUN_10016b40(LVar1);
    if (val_2 == 0) {
      SendMessageA(hwnd,0x182,local_10,0);
      SendMessageA(param_2,0x182,local_10,0);
      local_c = local_c + -1;
      if ((int)local_10 < (int)local_14) {
        local_14 = local_14 - 1;
      }
      else if (local_10 == local_14) {
        local_14 = 0;
      }
    }
    else {
      local_10 = local_10 + 1;
    }
  }
  LVar1 = SendMessageA(hwnd,0x18b,0,0);
  if (LVar1 != 0) {
    SendMessageA(hwnd,0x186,local_14,0);
    SendMessageA(param_2,0x186,local_14,0);
    lParam = hwnd;
    uval_3 = GetDlgCtrlID(hwnd);
    uval_3 = uval_3 & 0xffff | 0x10000;
    Msg = 0x111;
    hWnd = GetParent(hwnd);
    SendMessageA(hWnd,Msg,uval_3,(LPARAM)lParam);
  }
  return;
}


