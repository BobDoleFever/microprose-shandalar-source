/*
 * Decompiled function: FUN_10031474
 * Entry Point: 10031474
 * Size: 387 bytes
 */
#include "deckdll.h"


int32_t
FUN_10031474(int32_t arg_1,int arg_2,int32_t *arg_3,BITMAPINFO *arg_4,int32_t *arg_5,
            int32_t *arg_6,int *arg_7)

{
  int32_t uval_1;
  HDC hdc;
  HBITMAP local_44;
  HDC local_3c;
  BITMAPINFO local_38;
  HGDIOBJ local_c;
  void *local_8;
  
  local_3c = (HDC)0x0;
  local_44 = (HBITMAP)0x0;
  local_8 = (void *)0x0;
  if ((arg_3 == (int32_t *)0x0) || (arg_5 == (int32_t *)0x0)) {
    uval_1 = 0;
  }
  else {
    if (arg_4 == (BITMAPINFO *)0x0) {
      arg_4 = &local_38;
    }
    hdc = GetDC((HWND)0x0);
    if (hdc != (HDC)0x0) {
      thunk_FUN_10031425(hdc);
      local_3c = CreateCompatibleDC(hdc);
      if (local_3c != (HDC)0x0) {
        thunk_FUN_10023560((int32_t *)arg_4,arg_1,arg_2);
        local_38.bmiHeader.biBitCount = 0x20;
        local_44 = CreateDIBSection(hdc,arg_4,0,&local_8,(HANDLE)0x0,0);
        local_c = SelectObject(local_3c,local_44);
        thunk_FUN_10031425(local_3c);
      }
      ReleaseDC((HWND)0x0,hdc);
    }
    if (((local_3c == (HDC)0x0) || (local_44 == (HBITMAP)0x0)) || (local_8 == (void *)0x0)) {
      if (local_3c != (HDC)0x0) {
        DeleteDC(local_3c);
      }
      if (local_44 != (HBITMAP)0x0) {
        DeleteObject(local_44);
      }
      uval_1 = 0;
    }
    else {
      if (arg_3 != (int32_t *)0x0) {
        *arg_3 = local_3c;
      }
      if (arg_5 != (int32_t *)0x0) {
        *arg_5 = local_44;
      }
      if (arg_6 != (int32_t *)0x0) {
        *arg_6 = local_c;
      }
      if (arg_7 != (int *)0x0) {
        *arg_7 = (int)local_8;
      }
      uval_1 = 1;
    }
  }
  return uval_1;
}


