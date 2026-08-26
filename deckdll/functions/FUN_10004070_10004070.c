/*
 * Decompiled function: DeckDll_RegisterWindowClasses
 * Entry Point: 10004070
 * Size: 375 bytes
 */
#include "deckdll.h"


int32_t DeckDll_RegisterWindowClasses(void)

{
  ATOM AVar1;
  int32_t uval_2;
  WNDCLASSA local_2c;
  
  local_2c.style = 0;
  local_2c.lpfnWndProc = (WNDPROC)&LAB_1000107d;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = DAT_101cf334;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_MAGICDECK_DeckSurfaceClass_10040524;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    uval_2 = 0;
  }
  else {
    local_2c.style = 0;
    local_2c.lpfnWndProc = (WNDPROC)&LAB_100016a4;
    local_2c.cbClsExtra = 0;
    local_2c.cbWndExtra = 0;
    local_2c.hInstance = DAT_101cf334;
    local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_2c.hbrBackground = (HBRUSH)0x0;
    local_2c.lpszMenuName = (LPCSTR)0x0;
    local_2c.lpszClassName = s_MAGICDECK_SideboardSurfaceClass_10040540;
    AVar1 = RegisterClassA(&local_2c);
    if (AVar1 == 0) {
      uval_2 = 0;
    }
    else {
      local_2c.style = 0;
      local_2c.lpfnWndProc = (WNDPROC)&LAB_1000133e;
      local_2c.cbClsExtra = 0;
      local_2c.cbWndExtra = 0;
      local_2c.hInstance = DAT_101cf334;
      local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
      local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
      local_2c.hbrBackground = (HBRUSH)0x0;
      local_2c.lpszMenuName = (LPCSTR)0x0;
      local_2c.lpszClassName = s_MAGICDECK_TradeSurfaceClass_10040560;
      AVar1 = RegisterClassA(&local_2c);
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


