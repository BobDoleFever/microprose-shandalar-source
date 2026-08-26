/*
 * Decompiled function: FUN_10006154
 * Entry Point: 10006154
 * Size: 502 bytes
 */
#include "magvid.h"


void __cdecl FUN_10006154(LPVOID arg_1,int arg_2)

{
  void *this;
  HWND hWnd;
  bool flag_1;
  HDC hdc;
  int val_2;
  undefined3 extraout_var;
  uint32_t local_14;
  
  if ((arg_1 != (LPVOID)0x0) && (*(int *)((int)arg_1 + 8) != 0)) {
    this = *(void **)((int)arg_1 + 8);
    hWnd = *(HWND *)((int)arg_1 + 0x10);
    if (DAT_1001059c == 0) {
      hdc = GetDC(hWnd);
      val_2 = GetDeviceCaps(hdc,0xc);
      if (val_2 == 0x10) {
        DAT_1001059c = 0x9c49;
      }
      else if (val_2 == 0x18) {
        DAT_1001059c = 0x9c4c;
      }
      else if (val_2 == 0x20) {
        DAT_1001059c = 0x9c4d;
      }
      else {
        DAT_1001059c = 0x9c48;
      }
      ReleaseDC(hWnd,hdc);
    }
    if (arg_2 == 0) {
      arg_2 = DAT_1001059c;
    }
    if (arg_2 < 0) {
      arg_2 = DAT_100105a0;
    }
    DAT_100105a0 = arg_2;
    flag_1 = thunk_FUN_10004c20((int)this);
    if (CONCAT31(extraout_var,flag_1) != 0) {
      if (arg_2 == 0x9c48) {
        local_14 = 8;
      }
      else if (arg_2 == 0x9c49) {
        local_14 = 0x10;
      }
      else if (arg_2 == 0x9c4c) {
        local_14 = 0x18;
      }
      else if (arg_2 == 0x9c4d) {
        local_14 = 0x20;
      }
      else {
        local_14 = 0;
      }
      flag_1 = *(int *)((int)arg_1 + 0x38) != 0;
      if (flag_1) {
        thunk_FUN_10005ef9((int)arg_1);
      }
      val_2 = thunk_FUN_10001f9d(this,1.0,local_14,0,0,0);
      if (val_2 != 0) {
        thunk_FUN_10001f9d(this,1.0,8,1,0,0);
      }
      if (flag_1) {
        thunk_FUN_10005d8d(arg_1);
      }
    }
  }
  return;
}


