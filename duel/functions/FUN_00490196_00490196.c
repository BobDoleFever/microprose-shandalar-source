/*
 * Decompiled function: FUN_00490196
 * Entry Point: 00490196
 * Size: 146 bytes
 */
#include "duel.h"


bool FUN_00490196(LPCSTR param_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = FUN_00490233;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = param_1;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}


