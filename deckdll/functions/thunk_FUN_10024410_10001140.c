/*
 * Decompiled function: thunk_FUN_10024410
 * Entry Point: 10001140
 * Size: 5 bytes
 */
#include "deckdll.h"


bool thunk_FUN_10024410(void)

{
  ATOM AVar1;
  WNDCLASSA WStack_2c;
  
  WStack_2c.style = 0x20;
  WStack_2c.lpfnWndProc = (WNDPROC)&LAB_100013de;
  WStack_2c.cbClsExtra = 0;
  WStack_2c.cbWndExtra = 0;
  WStack_2c.hInstance = DAT_101cf334;
  WStack_2c.hIcon = LoadIconA(DAT_101cf334,(LPCSTR)0x65);
  WStack_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  WStack_2c.hbrBackground = (HBRUSH)0x0;
  WStack_2c.lpszMenuName = (LPCSTR)0x0;
  WStack_2c.lpszClassName = s_MAGICDECK_MainClass_100455c4;
  AVar1 = RegisterClassA(&WStack_2c);
  return AVar1 != 0;
}


