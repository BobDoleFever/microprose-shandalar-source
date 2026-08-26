/*
 * Decompiled function: FUN_00401000
 * Entry Point: 00401000
 * Size: 183 bytes
 */
#include "duel.h"


bool FUN_00401000(LPCSTR param_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  WNDCLASSA local_2c;
  
  local_2c.style = 0;
  local_2c.lpfnWndProc = FUN_004010e5;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = param_1;
  AVar1 = RegisterClassA(&local_2c);
  lplf = (LOGFONTA *)FUN_00472731(&DAT_004f2030,0);
  DAT_0050abb4 = CreateFontIndirectA(lplf);
  DAT_0050abb0 = 0x2565656;
  return AVar1 != 0;
}


