/*
 * Decompiled function: UI_CreateWindow_0050bba0
 * Entry Point: 0050bba0
 * Size: 310 bytes
 */
#include "magic.h"


bool UI_CreateWindow_0050bba0(LPCSTR str_1)

{
  ATOM AVar1;
  ATOM AVar2;
  WNDCLASSA local_2c;
  
  local_2c.style = 3;
  local_2c.lpfnWndProc = UI_CreateWindow_0050bd27;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  local_2c.style = 0;
  local_2c.lpfnWndProc = UI_WndProc_0050c854;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_ShuffleCard_005324ec;
  AVar2 = RegisterClassA(&local_2c);
  DAT_0061e118 = CreatePopupMenu();
  DAT_0061e11c = CreatePopupMenu();
  AppendMenuA(DAT_0061e11c,0,0x65,&DAT_005324f8);
  return AVar2 != 0 && AVar1 != 0;
}


