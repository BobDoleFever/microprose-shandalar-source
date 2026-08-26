/*
 * Decompiled function: UI_CreateWindow_00478b20
 * Entry Point: 00478b20
 * Size: 181 bytes
 */
#include "magic.h"


byte UI_CreateWindow_00478b20(LPCSTR str_1)

{
  byte bVar1;
  ATOM AVar2;
  int iVar3;
  undefined4 *arg_3;
  BITMAPINFO *arg_4;
  undefined4 *arg_5;
  undefined4 *arg_6;
  int *arg_7;
  WNDCLASSA local_2c;
  
  local_2c.style = 1;
  local_2c.lpfnWndProc = UI_WndProc_00478c08;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x28;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar2 = RegisterClassA(&local_2c);
  arg_7 = (int *)0x0;
  arg_6 = (undefined4 *)0x0;
  arg_5 = &DAT_00538e58;
  arg_4 = (BITMAPINFO *)0x0;
  arg_3 = &DAT_00538e48;
  iVar3 = GetSystemMetrics(3);
  bVar1 = FUN_004f39a4(1000,iVar3 * 5,arg_3,arg_4,arg_5,arg_6,arg_7);
  return AVar2 != 0 & bVar1;
}


