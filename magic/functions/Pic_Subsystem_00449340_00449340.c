/*
 * Decompiled function: Pic_Subsystem_00449340
 * Entry Point: 00449340
 * Size: 401 bytes
 */
#include "magic.h"


bool Pic_Subsystem_00449340(LPCSTR str_1)

{
  ATOM AVar1;
  ATOM AVar2;
  ATOM AVar3;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Pic_Subsystem_004494ff;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0xc;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  local_2c.style = 8;
  local_2c.lpfnWndProc = Pic_Subsystem_00449fbb;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_ExpandedGraveyard_0052223c;
  AVar2 = RegisterClassA(&local_2c);
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Pic_Subsystem_0044a135;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_GraveyardCards_00522250;
  AVar3 = RegisterClassA(&local_2c);
  DAT_00538bcc = CreatePopupMenu();
  return AVar3 != 0 && (AVar2 != 0 && AVar1 != 0);
}


