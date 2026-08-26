/*
 * Decompiled function: FUN_0042b2a0
 * Entry Point: 0042b2a0
 * Size: 132 bytes
 */
#include "duel.h"


bool FUN_0042b2a0(LPCSTR param_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 8;
  local_2c.lpfnWndProc = FUN_0042b324;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x10;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = param_1;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}


