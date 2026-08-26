/*
 * Decompiled function: UI_CreateWindow_004820b0
 * Entry Point: 004820b0
 * Size: 287 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool UI_CreateWindow_004820b0(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_WndProc_00482299;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  DAT_005dadac = CreatePopupMenu();
  DAT_005dada8 = CreatePopupMenu();
  AppendMenuA(DAT_005dada8,0,0x72,&DAT_004fa35c);
  DAT_005dade8 = LoadCursorA(DAT_00664680,s_HAND1_004fa360);
  DAT_005dadd4 = 3;
  _DAT_005dadc8 = LoadCursorA(DAT_00664680,s_HAND2_004fa368);
  _DAT_005dadcc = LoadCursorA(DAT_00664680,s_HAND3_004fa370);
  _DAT_005dadd0 = LoadCursorA(DAT_00664680,s_HAND4_004fa378);
  return AVar1 != 0;
}


