/*
 * Decompiled function: thunk_FUN_10037837
 * Entry Point: 10001730
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10037837(HWND hwnd,HWND param_2)

{
  LRESULT LVar1;
  int val_2;
  uint32_t uval_3;
  HWND hWnd;
  UINT Msg;
  HWND lParam;
  int32_t uStack_14;
  int32_t uStack_10;
  int32_t uStack_c;
  
  uStack_14 = SendMessageA(hwnd,0x188,0,0);
  uStack_c = SendMessageA(hwnd,0x18b,0,0);
  uStack_10 = 0;
  while ((int)uStack_10 < uStack_c) {
    LVar1 = SendMessageA(hwnd,0x199,uStack_10,0);
    val_2 = thunk_FUN_10016b40(LVar1);
    if (val_2 == 0) {
      SendMessageA(hwnd,0x182,uStack_10,0);
      SendMessageA(param_2,0x182,uStack_10,0);
      uStack_c = uStack_c + -1;
      if ((int)uStack_10 < (int)uStack_14) {
        uStack_14 = uStack_14 - 1;
      }
      else if (uStack_10 == uStack_14) {
        uStack_14 = 0;
      }
    }
    else {
      uStack_10 = uStack_10 + 1;
    }
  }
  LVar1 = SendMessageA(hwnd,0x18b,0,0);
  if (LVar1 != 0) {
    SendMessageA(hwnd,0x186,uStack_14,0);
    SendMessageA(param_2,0x186,uStack_14,0);
    lParam = hwnd;
    uval_3 = GetDlgCtrlID(hwnd);
    uval_3 = uval_3 & 0xffff | 0x10000;
    Msg = 0x111;
    hWnd = GetParent(hwnd);
    SendMessageA(hWnd,Msg,uval_3,(LPARAM)lParam);
  }
  return;
}


