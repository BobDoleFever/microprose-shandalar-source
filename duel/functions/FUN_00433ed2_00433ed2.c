/*
 * Decompiled function: FUN_00433ed2
 * Entry Point: 00433ed2
 * Size: 516 bytes
 */
#include "duel.h"


LRESULT FUN_00433ed2(HWND param_1,uint param_2,HDC param_3,LPARAM param_4)

{
  HDC hdc;
  LRESULT LVar1;
  tagPAINTSTRUCT local_134;
  CHAR local_f4 [200];
  tagRECT local_2c;
  HDC local_1c;
  tagRECT local_18;
  HBRUSH local_8;
  
  if (param_2 < 0xd) {
    if (param_2 == 0xc) {
      InvalidateRect(param_1,(RECT *)0x0,1);
      LVar1 = DefWindowProcA(param_1,0xc,(WPARAM)param_3,param_4);
      return LVar1;
    }
    if (param_2 == 1) {
      return 0;
    }
  }
  else if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      local_1c = param_3;
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_18);
      local_8 = CreateSolidBrush(0xffff);
      FillRect(local_1c,&local_18,local_8);
      DeleteObject(local_8);
      return 1;
    }
    if (param_2 == 0xf) {
      hdc = BeginPaint(param_1,&local_134);
      if (hdc != (HDC)0x0) {
        FUN_004707a4(hdc);
        GetWindowTextA(param_1,local_f4,200);
        SetTextAlign(hdc,6);
        SetBkMode(hdc,1);
        SetTextColor(hdc,0);
        GetClientRect(param_1,&local_2c);
        FUN_0042233a(hdc,&local_2c,local_f4,1);
        EndPaint(param_1,&local_134);
      }
      return 0;
    }
  }
  else if ((0x30e < param_2) && (param_2 < 0x312)) {
    LVar1 = FUN_00472b60(param_1,param_2,param_3,param_4);
    return LVar1;
  }
  LVar1 = DefWindowProcA(param_1,param_2,(WPARAM)param_3,param_4);
  return LVar1;
}


