/*
 * Decompiled function: FUN_1000c470
 * Entry Point: 1000c470
 * Size: 142 bytes
 */
#include "deckdll.h"


bool FUN_1000c470(void)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = (WNDPROC)&LAB_10001078;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 6;
  local_2c.hInstance = DAT_101cf334;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_MAGICDECK_CardClass_1004140c;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}


