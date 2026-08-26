/*
 * Decompiled function: UI_CreateWindow_004afd50
 * Entry Point: 004afd50
 * Size: 180 bytes
 */
#include "duel.h"


bool UI_CreateWindow_004afd50(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_Register_MAGICGAME_CardClass_004afe55;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x10;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  DAT_005dcd98 = CreatePopupMenu();
  DAT_005dcd80 = CreatePopupMenu();
  AppendMenuA(DAT_005dcd80,0,0x6c,s_Yes__I_m_sure_00506598);
  return AVar1 != 0;
}


