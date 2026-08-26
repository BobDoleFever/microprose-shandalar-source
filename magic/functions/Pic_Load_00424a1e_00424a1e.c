/*
 * Decompiled function: Pic_Load_00424a1e
 * Entry Point: 00424a1e
 * Size: 209 bytes
 */
#include "magic.h"


undefined4 Pic_Load_00424a1e(LPCSTR str_1)

{
  ATOM AVar1;
  char local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Pic_Load_004267c5;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_PhaseCombat_pic_00520d90);
  DAT_00538b38 = Pic_Load_00423833(local_138);
  return local_30;
}


