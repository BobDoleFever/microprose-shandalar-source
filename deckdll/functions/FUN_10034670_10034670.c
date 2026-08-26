/*
 * Decompiled function: FUN_10034670
 * Entry Point: 10034670
 * Size: 141 bytes
 */
#include "deckdll.h"


bool FUN_10034670(void)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0;
  local_2c.lpfnWndProc = (WNDPROC)&LAB_10001316;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = DAT_101cf334;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_MAGICDECK_TitleClass_100467cc;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}


