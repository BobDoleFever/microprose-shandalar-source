/*
 * Decompiled function: thunk_FUN_10004070
 * Entry Point: 10001226
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10004070(void)

{
  ATOM AVar1;
  int32_t uval_2;
  WNDCLASSA WStack_2c;
  
  WStack_2c.style = 0;
  WStack_2c.lpfnWndProc = (WNDPROC)&LAB_1000107d;
  WStack_2c.cbClsExtra = 0;
  WStack_2c.cbWndExtra = 0;
  WStack_2c.hInstance = DAT_101cf334;
  WStack_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  WStack_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  WStack_2c.hbrBackground = (HBRUSH)0x0;
  WStack_2c.lpszMenuName = (LPCSTR)0x0;
  WStack_2c.lpszClassName = s_MAGICDECK_DeckSurfaceClass_10040524;
  AVar1 = RegisterClassA(&WStack_2c);
  if (AVar1 == 0) {
    uval_2 = 0;
  }
  else {
    WStack_2c.style = 0;
    WStack_2c.lpfnWndProc = (WNDPROC)&LAB_100016a4;
    WStack_2c.cbClsExtra = 0;
    WStack_2c.cbWndExtra = 0;
    WStack_2c.hInstance = DAT_101cf334;
    WStack_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    WStack_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    WStack_2c.hbrBackground = (HBRUSH)0x0;
    WStack_2c.lpszMenuName = (LPCSTR)0x0;
    WStack_2c.lpszClassName = s_MAGICDECK_SideboardSurfaceClass_10040540;
    AVar1 = RegisterClassA(&WStack_2c);
    if (AVar1 == 0) {
      uval_2 = 0;
    }
    else {
      WStack_2c.style = 0;
      WStack_2c.lpfnWndProc = (WNDPROC)&LAB_1000133e;
      WStack_2c.cbClsExtra = 0;
      WStack_2c.cbWndExtra = 0;
      WStack_2c.hInstance = DAT_101cf334;
      WStack_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
      WStack_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
      WStack_2c.hbrBackground = (HBRUSH)0x0;
      WStack_2c.lpszMenuName = (LPCSTR)0x0;
      WStack_2c.lpszClassName = s_MAGICDECK_TradeSurfaceClass_10040560;
      AVar1 = RegisterClassA(&WStack_2c);
      if (AVar1 == 0) {
        uval_2 = 0;
      }
      else {
        uval_2 = 1;
      }
    }
  }
  return uval_2;
}


