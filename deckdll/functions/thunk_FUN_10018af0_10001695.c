/*
 * Decompiled function: thunk_FUN_10018af0
 * Entry Point: 10001695
 * Size: 5 bytes
 */
#include "deckdll.h"


bool thunk_FUN_10018af0(void)

{
  ATOM AVar1;
  WNDCLASSA WStack_2c;
  
  WStack_2c.style = 0x23;
  WStack_2c.lpfnWndProc = (WNDPROC)&LAB_100012a8;
  WStack_2c.cbClsExtra = 0;
  WStack_2c.cbWndExtra = 0xe;
  WStack_2c.hInstance = DAT_101cf334;
  WStack_2c.hIcon = (HICON)0x0;
  WStack_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  WStack_2c.hbrBackground = (HBRUSH)0x0;
  WStack_2c.lpszMenuName = (LPCSTR)0x0;
  WStack_2c.lpszClassName = s_MagicFullCardClass_100432dc;
  AVar1 = RegisterClassA(&WStack_2c);
  return AVar1 != 0;
}


