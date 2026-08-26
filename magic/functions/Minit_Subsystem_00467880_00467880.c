/*
 * Decompiled function: Minit_Subsystem_00467880
 * Entry Point: 00467880
 * Size: 287 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool Minit_Subsystem_00467880(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Card_Setup_00467a68;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  DAT_00538db4 = CreatePopupMenu();
  DAT_00538db0 = CreatePopupMenu();
  AppendMenuA(DAT_00538db0,0,0x72,&DAT_005248f4);
  DAT_00538df0 = LoadCursorA(g_AppHInstance,s_HAND1_005248f8);
  DAT_00538ddc = 3;
  _DAT_00538dd0 = LoadCursorA(g_AppHInstance,s_HAND2_00524900);
  _DAT_00538dd4 = LoadCursorA(g_AppHInstance,s_HAND3_00524908);
  _DAT_00538dd8 = LoadCursorA(g_AppHInstance,s_HAND4_00524910);
  return AVar1 != 0;
}


