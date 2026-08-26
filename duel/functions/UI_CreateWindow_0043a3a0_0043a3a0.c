/*
 * Decompiled function: UI_CreateWindow_0043a3a0
 * Entry Point: 0043a3a0
 * Size: 401 bytes
 */
#include "duel.h"


bool UI_CreateWindow_0043a3a0(LPCSTR str_1)

{
  ATOM AVar1;
  ATOM AVar2;
  ATOM AVar3;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_WndProc_0043a55f;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0xc;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  local_2c.style = 8;
  local_2c.lpfnWndProc = UI_WndProc_0043b02a;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_ExpandedGraveyard_004f774c;
  AVar2 = RegisterClassA(&local_2c);
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_WndProc_0043b1a4;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_GraveyardCards_004f7760;
  AVar3 = RegisterClassA(&local_2c);
  DAT_005168ec = CreatePopupMenu();
  return AVar3 != 0 && (AVar2 != 0 && AVar1 != 0);
}


