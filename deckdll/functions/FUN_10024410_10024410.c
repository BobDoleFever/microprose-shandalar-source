/*
 * Decompiled function: FUN_10024410
 * Entry Point: 10024410
 * Size: 142 bytes
 */
#include "deckdll.h"


bool FUN_10024410(void)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0x20;
  local_2c.lpfnWndProc = (WNDPROC)&LAB_100013de;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = DAT_101cf334;
  local_2c.hIcon = LoadIconA(DAT_101cf334,(LPCSTR)0x65);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_MAGICDECK_MainClass_100455c4;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}


