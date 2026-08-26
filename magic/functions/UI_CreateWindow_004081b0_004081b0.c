/*
 * Decompiled function: UI_CreateWindow_004081b0
 * Entry Point: 004081b0
 * Size: 289 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool UI_CreateWindow_004081b0(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  bool bVar2;
  WNDCLASSA local_2c;
  
  local_2c.style = 0x800;
  local_2c.lpfnWndProc = UI_WndProc_0040836a;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  bVar2 = AVar1 != 0;
  DAT_006b2d8c = 0;
  DAT_006a2850 = 500;
  _DAT_007006b8 = 10;
  _DAT_006a4a4c = 0x12;
  DAT_00695f10 = 0x14;
  lplf = (LOGFONTA *)FUN_004f58eb(s_CueCard_00516bf0,0);
  DAT_005382dc = CreateFontIndirectA(lplf);
  DAT_005382e8 = CreateSolidBrush(0x296bed2);
  DAT_005382e4 = CreateSolidBrush(0x27f7f7f);
  DAT_005382e0 = 0x2505050;
  if ((DAT_005382e8 == (HBRUSH)0x0) || (DAT_005382e4 == (HBRUSH)0x0)) {
    bVar2 = false;
  }
  return bVar2;
}


