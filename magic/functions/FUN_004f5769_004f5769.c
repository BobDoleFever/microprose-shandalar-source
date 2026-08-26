/*
 * Decompiled function: FUN_004f5769
 * Entry Point: 004f5769
 * Size: 309 bytes
 */
#include "magic.h"


LRESULT FUN_004f5769(HWND hwnd,UINT y,HWND param_3,LPARAM arg_4)

{
  int iVar1;
  HWND hWnd;
  UINT Msg;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((y == 7) || (y == 8)) {
    if (y == 7) {
      local_c = hwnd;
      local_10 = param_3;
    }
    else {
      local_10 = hwnd;
      local_c = param_3;
    }
    iVar1 = FUN_004f589e(local_c);
    if (iVar1 == 0) {
      local_c = (HWND)0x0;
    }
    iVar1 = FUN_004f589e(local_10);
    if (iVar1 == 0) {
      local_10 = (HWND)0x0;
    }
    Msg = 0x4c8;
    hWnd = GetParent(hwnd);
    SendMessageA(hWnd,Msg,(WPARAM)local_c,(LPARAM)local_10);
    local_8 = 0;
  }
  else if ((y == 0x311) || ((y == 0x310 || (y == 0x30f)))) {
    local_8 = CallWindowProcA(DAT_0063eedc,hwnd,y,(WPARAM)param_3,arg_4);
    FUN_004f5d1a(hwnd,y,param_3,arg_4);
  }
  else {
    local_8 = CallWindowProcA(DAT_0063eedc,hwnd,y,(WPARAM)param_3,arg_4);
  }
  return local_8;
}


