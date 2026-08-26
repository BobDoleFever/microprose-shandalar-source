/*
 * Decompiled function: FUN_10030df0
 * Entry Point: 10030df0
 * Size: 142 bytes
 */
#include "deckdll.h"


bool FUN_10030df0(void)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0x800;
  local_2c.lpfnWndProc = (WNDPROC)&LAB_10001753;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = DAT_101cf334;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_CueCardClass_10046614;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}


