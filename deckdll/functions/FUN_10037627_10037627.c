/*
 * Decompiled function: FUN_10037627
 * Entry Point: 10037627
 * Size: 528 bytes
 */
#include "deckdll.h"


void FUN_10037627(HWND hwnd,HWND param_2)

{
  WPARAM WVar1;
  LRESULT LVar2;
  int val_3;
  uint32_t uval_4;
  HWND pHVar5;
  LRESULT lParam;
  UINT UVar6;
  HWND pHVar7;
  WPARAM local_20;
  WPARAM local_1c;
  uint8_t *local_c;
  int local_8;
  
  WVar1 = SendMessageA(hwnd,0x188,0,0);
  LVar2 = SendMessageA(hwnd,0x199,WVar1,0);
  SendMessageA(hwnd,0x184,0,0);
  SendMessageA(param_2,0x184,0,0);
  UpdateWindow(hwnd);
  UpdateWindow(param_2);
  local_20 = 0xffffffff;
  local_c = &DAT_10176ab0;
  for (local_8 = 0; local_8 < DAT_10175ee0; local_8 = local_8 + 1) {
    val_3 = thunk_FUN_10016b40(local_8);
    if (val_3 != 0) {
      WVar1 = SendMessageA(hwnd,0x180,0,*(LPARAM *)(local_c + 4));
      SendMessageA(hwnd,0x19a,WVar1,local_8);
      if (local_8 == LVar2) {
        local_20 = WVar1;
      }
    }
    local_c = local_c + 0x98;
  }
  if (local_20 == 0xffffffff) {
    local_20 = 0;
  }
  SendMessageA(hwnd,0x186,local_20,0);
  pHVar7 = hwnd;
  uval_4 = GetDlgCtrlID(hwnd);
  uval_4 = uval_4 & 0xffff | 0x10000;
  UVar6 = 0x111;
  pHVar5 = GetParent(hwnd);
  SendMessageA(pHVar5,UVar6,uval_4,(LPARAM)pHVar7);
  UpdateWindow(hwnd);
  LVar2 = SendMessageA(hwnd,0x18b,0,0);
  for (local_1c = 0; (int)local_1c < LVar2; local_1c = local_1c + 1) {
    lParam = SendMessageA(hwnd,0x199,local_1c,0);
    SendMessageA(param_2,0x180,0,lParam);
  }
  SendMessageA(param_2,0x186,0,0);
  pHVar7 = param_2;
  uval_4 = GetDlgCtrlID(param_2);
  uval_4 = uval_4 & 0xffff | 0x10000;
  UVar6 = 0x111;
  pHVar5 = GetParent(param_2);
  SendMessageA(pHVar5,UVar6,uval_4,(LPARAM)pHVar7);
  return;
}


