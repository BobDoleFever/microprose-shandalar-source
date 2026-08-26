/*
 * Decompiled function: FUN_1002a940
 * Entry Point: 1002a940
 * Size: 133 bytes
 */
#include "deckdll.h"


bool FUN_1002a940(void)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 3;
  local_2c.lpfnWndProc = (WNDPROC)&LAB_10001311;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = DAT_101cf334;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_MAGICDECK_CardListFiltersClass_10046134;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}


