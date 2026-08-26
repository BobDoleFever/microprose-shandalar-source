/*
 * Decompiled function: Pic_Subsystem_0044b9c0
 * Entry Point: 0044b9c0
 * Size: 195 bytes
 */
#include "magic.h"


bool Pic_Subsystem_0044b9c0(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  WNDCLASSA local_2c;
  
  local_2c.style = 3;
  local_2c.lpfnWndProc = Pic_Subsystem_0044bad4;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x20;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  DAT_00538bf8 = CreatePopupMenu();
  lplf = (LOGFONTA *)FUN_004f58eb(&DAT_00523b14,0);
  DAT_00538bfc = CreateFontIndirectA(lplf);
  DAT_00538bf0 = 0x10000bf;
  DAT_00538bf4 = 0x10000c9;
  return AVar1 != 0;
}


