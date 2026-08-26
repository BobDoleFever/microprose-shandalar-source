/*
 * Decompiled function: FUN_1003798a
 * Entry Point: 1003798a
 * Size: 685 bytes
 */
#include "deckdll.h"


void FUN_1003798a(HWND hwnd,HWND param_2)

{
  int arg_1;
  bool flag_1;
  WPARAM WVar2;
  LRESULT LVar3;
  LRESULT LVar4;
  LRESULT LVar5;
  int val_6;
  uint32_t uval_7;
  HWND hWnd;
  WPARAM local_1f58;
  WPARAM local_1f4c;
  int local_1f44 [1992];
  int32_t uStackY_24;
  UINT Msg;
  HWND lParam;
  
  FUN_1003d810();
  uStackY_24 = 0x100379ad;
  WVar2 = SendMessageA(hwnd,0x188,0,0);
  uStackY_24 = 0x100379cb;
  LVar3 = SendMessageA(hwnd,0x199,WVar2,0);
  uStackY_24 = 0x100379e4;
  LVar4 = SendMessageA(hwnd,0x18b,0,0);
  memset(local_1f44,0,8000);
  for (local_1f4c = 0; (int)local_1f4c < LVar4; local_1f4c = local_1f4c + 1) {
    uStackY_24 = 0x10037a3f;
    LVar5 = SendMessageA(hwnd,0x199,local_1f4c,0);
    local_1f44[LVar5] = 1;
  }
  for (local_1f4c = 0; (int)local_1f4c < DAT_10175ee0; local_1f4c = local_1f4c + 1) {
    arg_1 = *(int *)(&DAT_10176ab0 + local_1f4c * 0x98);
    if (local_1f44[arg_1] == 0) {
      val_6 = thunk_FUN_10016b40(arg_1);
      if (val_6 != 0) {
        uStackY_24 = 0x10037aee;
        WVar2 = SendMessageA(hwnd,0x180,0,(&DAT_10176ab4)[local_1f4c * 0x26]);
        uStackY_24 = 0x10037b11;
        SendMessageA(hwnd,0x19a,WVar2,arg_1);
        uStackY_24 = 0x10037b2e;
        SendMessageA(param_2,0x181,WVar2,arg_1);
      }
    }
  }
  uStackY_24 = 0x10037b46;
  LVar4 = SendMessageA(hwnd,0x18b,0,0);
  local_1f58 = 0;
  local_1f4c = 0;
  flag_1 = false;
  while (((int)local_1f4c < LVar4 && (!flag_1))) {
    uStackY_24 = 0x10037bac;
    LVar5 = SendMessageA(hwnd,0x199,local_1f4c,0);
    if (LVar5 == LVar3) {
      local_1f58 = local_1f4c;
      flag_1 = true;
    }
    local_1f4c = local_1f4c + 1;
  }
  uStackY_24 = 0x10037beb;
  SendMessageA(hwnd,0x186,local_1f58,0);
  uStackY_24 = 0x10037c03;
  SendMessageA(param_2,0x186,local_1f58,0);
  lParam = hwnd;
  uval_7 = GetDlgCtrlID(hwnd);
  uval_7 = uval_7 & 0xffff | 0x10000;
  Msg = 0x111;
  uStackY_24 = 0x10037c2b;
  hWnd = GetParent(hwnd);
  uStackY_24 = 0x10037c32;
  SendMessageA(hWnd,Msg,uval_7,(LPARAM)lParam);
  return;
}


