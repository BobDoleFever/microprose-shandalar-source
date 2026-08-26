/*
 * Decompiled function: UI_CreateWindow_00501ad0
 * Entry Point: 00501ad0
 * Size: 132 bytes
 */
#include "magic.h"


bool UI_CreateWindow_00501ad0(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 3;
  local_2c.lpfnWndProc = UI_WndProc_00501b54;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}


