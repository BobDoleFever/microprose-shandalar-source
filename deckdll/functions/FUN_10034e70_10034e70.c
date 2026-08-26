/*
 * Decompiled function: FUN_10034e70
 * Entry Point: 10034e70
 * Size: 589 bytes
 */
#include "deckdll.h"


LRESULT FUN_10034e70(HWND hwnd,uint32_t y,uint32_t width,LPARAM arg_4)

{
  int val_1;
  LRESULT LVar2;
  LRESULT LVar3;
  uint32_t uval_4;
  HWND hWnd;
  LRESULT LVar5;
  UINT Msg;
  HWND lParam;
  
  if (y < 0x116) {
    if (y == 0x115) {
      LVar5 = SendMessageA(hwnd,0x18e,0,0);
      LVar2 = CallWindowProcA(DAT_10175ec4,hwnd,0x115,width,arg_4);
      LVar3 = SendMessageA(hwnd,0x18e,0,0);
      if (LVar3 == LVar5) {
        return LVar2;
      }
      SendMessageA(DAT_101cfb80,0x114,CONCAT31((int3)((uint32_t)(LVar3 << 0x10) >> 8),4),0);
      return LVar2;
    }
    if ((0xff < y) && (y < 0x103)) {
      LVar5 = SendMessageA(hwnd,0x188,0,0);
      LVar2 = CallWindowProcA(DAT_10175ec4,hwnd,y,width,arg_4);
      LVar3 = SendMessageA(hwnd,0x188,0,0);
      if (LVar3 == LVar5) {
        return LVar2;
      }
      lParam = hwnd;
      uval_4 = GetDlgCtrlID(hwnd);
      uval_4 = uval_4 & 0xffff | 0x10000;
      Msg = 0x111;
      hWnd = GetParent(hwnd);
      SendMessageA(hWnd,Msg,uval_4,(LPARAM)lParam);
      return LVar2;
    }
  }
  else if (y == 0x201) {
    GetCursorPos((LPPOINT)&DAT_1013f190);
    GetCursorPos((LPPOINT)&DAT_1013f178);
    ScreenToClient(DAT_10176868,(LPPOINT)&DAT_1013f190);
    ScreenToClient(DAT_101cfb80,(LPPOINT)&DAT_1013f178);
    LVar5 = CallWindowProcA(DAT_10175ec4,hwnd,0x201,width,arg_4);
    SendMessageA(hwnd,0x202,width,arg_4);
    if ((width & 4) == 0) {
      val_1 = thunk_FUN_10037c37(hwnd,1,0);
      if (val_1 != 0) {
        return LVar5;
      }
      MessageBeep(0);
      return LVar5;
    }
    val_1 = thunk_FUN_10037c37(hwnd,1,1);
    if (val_1 != 0) {
      return LVar5;
    }
    MessageBeep(0);
    return LVar5;
  }
  LVar5 = CallWindowProcA(DAT_10175ec4,hwnd,y,width,arg_4);
  return LVar5;
}


