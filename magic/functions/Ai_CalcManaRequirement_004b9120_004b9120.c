/*
 * Decompiled function: Ai_CalcManaRequirement_004b9120
 * Entry Point: 004b9120
 * Size: 238 bytes
 */
#include "magic.h"


undefined4 Ai_CalcManaRequirement_004b9120(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  char local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Ai_CalcManaRequirement_004b9284;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_00556b18 = CreatePopupMenu();
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_ManaPool_pic_0052d4d4);
  DAT_00556b20 = Pic_Load_00423833(local_138);
  lplf = (LOGFONTA *)FUN_004f58eb(s_ManaPool_0052d4e8,0);
  DAT_00556b1c = CreateFontIndirectA(lplf);
  return local_30;
}


