/*
 * Decompiled function: UI_Register_WINBK_BigCard_00401e65
 * Entry Point: 00401e65
 * Size: 219 bytes
 */
#include "magic.h"


undefined4 UI_Register_WINBK_BigCard_00401e65(LPCSTR str_1)

{
  ATOM AVar1;
  char local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0;
  local_2c.lpfnWndProc = UI_WndProc_00401f70;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
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
  strcat(local_138,s__WINBK_BigCard_pic_00516054);
  DAT_00536e70 = Pic_Load_00423833(local_138);
  DAT_00696900 = 9000;
  return local_30;
}


