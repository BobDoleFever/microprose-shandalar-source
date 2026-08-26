/*
 * Decompiled function: thunk_FUN_10031474
 * Entry Point: 10001299
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t
thunk_FUN_10031474(int32_t arg_1,int arg_2,int32_t *arg_3,BITMAPINFO *arg_4,int32_t *arg_5,
                  int32_t *arg_6,int *arg_7)

{
  int32_t uval_1;
  HDC hdc;
  HBITMAP pHStack_44;
  HDC pHStack_3c;
  BITMAPINFO BStack_38;
  HGDIOBJ pvStack_c;
  void *pvStack_8;
  
  pHStack_3c = (HDC)0x0;
  pHStack_44 = (HBITMAP)0x0;
  pvStack_8 = (void *)0x0;
  if ((arg_3 == (int32_t *)0x0) || (arg_5 == (int32_t *)0x0)) {
    uval_1 = 0;
  }
  else {
    if (arg_4 == (BITMAPINFO *)0x0) {
      arg_4 = &BStack_38;
    }
    hdc = GetDC((HWND)0x0);
    if (hdc != (HDC)0x0) {
      thunk_FUN_10031425(hdc);
      pHStack_3c = CreateCompatibleDC(hdc);
      if (pHStack_3c != (HDC)0x0) {
        thunk_FUN_10023560((int32_t *)arg_4,arg_1,arg_2);
        BStack_38.bmiHeader.biBitCount = 0x20;
        pHStack_44 = CreateDIBSection(hdc,arg_4,0,&pvStack_8,(HANDLE)0x0,0);
        pvStack_c = SelectObject(pHStack_3c,pHStack_44);
        thunk_FUN_10031425(pHStack_3c);
      }
      ReleaseDC((HWND)0x0,hdc);
    }
    if (((pHStack_3c == (HDC)0x0) || (pHStack_44 == (HBITMAP)0x0)) || (pvStack_8 == (void *)0x0)) {
      if (pHStack_3c != (HDC)0x0) {
        DeleteDC(pHStack_3c);
      }
      if (pHStack_44 != (HBITMAP)0x0) {
        DeleteObject(pHStack_44);
      }
      uval_1 = 0;
    }
    else {
      if (arg_3 != (int32_t *)0x0) {
        *arg_3 = pHStack_3c;
      }
      if (arg_5 != (int32_t *)0x0) {
        *arg_5 = pHStack_44;
      }
      if (arg_6 != (int32_t *)0x0) {
        *arg_6 = pvStack_c;
      }
      if (arg_7 != (int *)0x0) {
        *arg_7 = (int)pvStack_8;
      }
      uval_1 = 1;
    }
  }
  return uval_1;
}


