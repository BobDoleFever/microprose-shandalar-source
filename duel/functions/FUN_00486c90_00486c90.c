/*
 * Decompiled function: FUN_00486c90
 * Entry Point: 00486c90
 * Size: 310 bytes
 */
#include "duel.h"


bool FUN_00486c90(LPCSTR param_1)

{
  ATOM AVar1;
  ATOM AVar2;
  WNDCLASSA local_2c;
  
  local_2c.style = 3;
  local_2c.lpfnWndProc = FUN_00486e17;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = param_1;
  AVar1 = RegisterClassA(&local_2c);
  local_2c.style = 0;
  local_2c.lpfnWndProc = FUN_0048794d;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_ShuffleCard_004faac8;
  AVar2 = RegisterClassA(&local_2c);
  DAT_005dadec = CreatePopupMenu();
  DAT_005dadf0 = CreatePopupMenu();
  AppendMenuA(DAT_005dadf0,0,0x65,&DAT_004faad4);
  return AVar2 != 0 && AVar1 != 0;
}


