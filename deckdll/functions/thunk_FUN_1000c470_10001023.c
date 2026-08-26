/*
 * Decompiled function: thunk_FUN_1000c470
 * Entry Point: 10001023
 * Size: 5 bytes
 */
#include "deckdll.h"


bool thunk_FUN_1000c470(void)

{
  ATOM AVar1;
  WNDCLASSA WStack_2c;
  
  WStack_2c.style = 0xb;
  WStack_2c.lpfnWndProc = (WNDPROC)&LAB_10001078;
  WStack_2c.cbClsExtra = 0;
  WStack_2c.cbWndExtra = 6;
  WStack_2c.hInstance = DAT_101cf334;
  WStack_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  WStack_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  WStack_2c.hbrBackground = (HBRUSH)0x0;
  WStack_2c.lpszMenuName = (LPCSTR)0x0;
  WStack_2c.lpszClassName = s_MAGICDECK_CardClass_1004140c;
  AVar1 = RegisterClassA(&WStack_2c);
  return AVar1 != 0;
}


