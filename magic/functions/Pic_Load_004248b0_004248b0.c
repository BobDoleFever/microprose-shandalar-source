/*
 * Decompiled function: Pic_Load_004248b0
 * Entry Point: 004248b0
 * Size: 248 bytes
 */
#include "magic.h"


undefined4 Pic_Load_004248b0(LPCSTR str_1)

{
  ATOM AVar1;
  char local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Pic_Load_00424b1f;
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
  DAT_00538b40 = CreatePopupMenu();
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_Phase_pic_00520d7c);
  DAT_00538b20 = Pic_Load_00423833(local_138);
  DAT_00538b78 = 2;
  DAT_00538b3c = CreateHatchBrush(3,0x808080);
  return local_30;
}


