/*
 * Decompiled function: UI_CreateWindow_0041df60
 * Entry Point: 0041df60
 * Size: 132 bytes
 */
#include "magic.h"


bool UI_CreateWindow_0041df60(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 8;
  local_2c.lpfnWndProc = UI_WndProc_0041dfe4;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x10;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}


