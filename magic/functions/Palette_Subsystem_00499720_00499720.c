/*
 * Decompiled function: Palette_Subsystem_00499720
 * Entry Point: 00499720
 * Size: 152 bytes
 */
#include "magic.h"


bool Palette_Subsystem_00499720(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0x803;
  local_2c.lpfnWndProc = Palette_Subsystem_004997e6;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  DAT_0054b360 = CreatePopupMenu();
  return AVar1 != 0;
}


