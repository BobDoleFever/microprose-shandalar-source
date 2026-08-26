/*
 * Decompiled function: Duel_RegisterChildCardWindowClass
 * Entry Point: 004f04e0
 * Size: 183 bytes
 */
#include "magic.h"


bool Duel_RegisterChildCardWindowClass(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  WNDCLASSA local_2c;
  
  local_2c.style = 0;
  local_2c.lpfnWndProc = Duel_ChildCard_WndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  lplf = (LOGFONTA *)FUN_004f58eb(&DAT_0052fffc,0);
  DAT_00565a04 = CreateFontIndirectA(lplf);
  DAT_00565a00 = 0x2565656;
  return AVar1 != 0;
}


