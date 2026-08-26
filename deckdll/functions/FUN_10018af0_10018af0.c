/*
 * Decompiled function: FUN_10018af0
 * Entry Point: 10018af0
 * Size: 133 bytes
 */
#include "deckdll.h"


bool FUN_10018af0(void)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0x23;
  local_2c.lpfnWndProc = (WNDPROC)&LAB_100012a8;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0xe;
  local_2c.hInstance = DAT_101cf334;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_MagicFullCardClass_100432dc;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}


