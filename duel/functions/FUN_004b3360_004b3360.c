/*
 * Decompiled function: FUN_004b3360
 * Entry Point: 004b3360
 * Size: 145 bytes
 */
#include "duel.h"


bool FUN_004b3360(LPCSTR param_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0x20;
  local_2c.lpfnWndProc = FUN_004b33f1;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA(DAT_00664680,(LPCSTR)0x66);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = param_1;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}


