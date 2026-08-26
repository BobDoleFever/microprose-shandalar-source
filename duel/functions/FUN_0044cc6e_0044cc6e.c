/*
 * Decompiled function: FUN_0044cc6e
 * Entry Point: 0044cc6e
 * Size: 209 bytes
 */
#include "duel.h"


undefined4 FUN_0044cc6e(LPCSTR param_1)

{
  ATOM AVar1;
  undefined1 local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = FUN_0044ea23;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
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
  FUN_004d9640(local_138,s__WINBK_PhaseCombat_pic_004f8254);
  DAT_00516b70 = FUN_0043d713(local_138);
  return local_30;
}


