/*
 * Decompiled function: UI_CreateWindow_004b9460
 * Entry Point: 004b9460
 * Size: 195 bytes
 */
#include "duel.h"


bool UI_CreateWindow_004b9460(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  WNDCLASSA local_2c;
  
  local_2c.style = 3;
  local_2c.lpfnWndProc = Pic_Subsystem_0044bad4;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x20;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  DAT_005dce04 = CreatePopupMenu();
  lplf = (LOGFONTA *)FUN_00472731(&DAT_00508760,0);
  DAT_005dce08 = CreateFontIndirectA(lplf);
  DAT_005dcdfc = 0x10000bf;
  DAT_005dce00 = 0x10000c9;
  return AVar1 != 0;
}


