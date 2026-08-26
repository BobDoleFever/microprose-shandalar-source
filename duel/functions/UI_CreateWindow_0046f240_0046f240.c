/*
 * Decompiled function: UI_CreateWindow_0046f240
 * Entry Point: 0046f240
 * Size: 181 bytes
 */
#include "duel.h"


byte UI_CreateWindow_0046f240(LPCSTR str_1)

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
  local_2c.lpfnWndProc = UI_WndProc_0046f328;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x28;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar2 = RegisterClassA(&local_2c);
  arg_7 = (int *)0x0;
  arg_6 = (undefined4 *)0x0;
  arg_5 = &DAT_00522458;
  arg_4 = (BITMAPINFO *)0x0;
  arg_3 = &DAT_00522448;
  iVar3 = GetSystemMetrics(3);
  bVar1 = FUN_004707f3(1000,iVar3 * 5,arg_3,arg_4,arg_5,arg_6,arg_7);
  return AVar2 != 0 & bVar1;
}


