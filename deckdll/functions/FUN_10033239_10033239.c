/*
 * Decompiled function: FUN_10033239
 * Entry Point: 10033239
 * Size: 309 bytes
 */
#include "deckdll.h"


LRESULT FUN_10033239(HWND hwnd,uint32_t y,HWND param_3,LPARAM arg_4)

{
  int val_1;
  HWND hWnd;
  UINT Msg;
  int32_t local_10;
  int32_t local_c;
  int32_t local_8;
  
  if ((y == 7) || (y == 8)) {
    if (y == 7) {
      local_c = hwnd;
      local_10 = param_3;
    }
    else {
      local_10 = hwnd;
      local_c = param_3;
    }
    val_1 = thunk_FUN_1003336e(local_c);
    if (val_1 == 0) {
      local_c = (HWND)0x0;
    }
    val_1 = thunk_FUN_1003336e(local_10);
    if (val_1 == 0) {
      local_10 = (HWND)0x0;
    }
    Msg = 0x4c8;
    hWnd = GetParent(hwnd);
    SendMessageA(hWnd,Msg,(WPARAM)local_c,(LPARAM)local_10);
    local_8 = 0;
  }
  else if ((y == 0x311) || ((y == 0x310 || (y == 0x30f)))) {
    local_8 = CallWindowProcA(DAT_1013f198,hwnd,y,(WPARAM)param_3,arg_4);
    thunk_FUN_100337ea(hwnd,y,param_3,arg_4);
  }
  else {
    local_8 = CallWindowProcA(DAT_1013f198,hwnd,y,(WPARAM)param_3,arg_4);
  }
  return local_8;
}


