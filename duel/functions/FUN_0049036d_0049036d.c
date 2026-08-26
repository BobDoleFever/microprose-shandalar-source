/*
 * Decompiled function: FUN_0049036d
 * Entry Point: 0049036d
 * Size: 219 bytes
 */
#include "duel.h"


undefined4 FUN_0049036d(LPCSTR param_1)

{
  ATOM AVar1;
  undefined1 local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0;
  local_2c.lpfnWndProc = FUN_00490478;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = param_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  FUN_004d9630(local_138,&DAT_006189a0);
  FUN_004d9640(local_138,s__WINBK_BigCard_pic_004fb140);
  DAT_005daf00 = FUN_0043d713(local_138);
  DAT_0060d498 = 9000;
  return local_30;
}


