/*
 * Decompiled function: Adventure_PromptConfirmDialog
 * Entry Point: 004ecee0
 * Size: 180 bytes
 */
#include "magic.h"


bool Adventure_PromptConfirmDialog(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Duel_MainArena_WndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x10;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  DAT_005659f8 = CreatePopupMenu();
  DAT_005659e0 = CreatePopupMenu();
  AppendMenuA(DAT_005659e0,0,0x6c,s_Yes__I_m_sure_0052fc98);
  return AVar1 != 0;
}


