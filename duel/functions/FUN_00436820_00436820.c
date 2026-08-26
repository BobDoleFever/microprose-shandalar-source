/*
 * Decompiled function: FUN_00436820
 * Entry Point: 00436820
 * Size: 562 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00436820(LPCSTR param_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  undefined1 local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = FUN_00436af6;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = param_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_00516700 = CreatePopupMenu();
  FUN_004d9630(local_138,&DAT_006189a0);
  FUN_004d9640(local_138,s__FACE_MULTI_pic_004f69d8);
  _DAT_00516708 = FUN_0043d713(local_138);
  FUN_004d9630(local_138,&DAT_006189a0);
  FUN_004d9640(local_138,s__FACE_BLACK_pic_004f69e8);
  _DAT_0051670c = FUN_0043d713(local_138);
  FUN_004d9630(local_138,&DAT_006189a0);
  FUN_004d9640(local_138,s__FACE_BLUE_pic_004f69f8);
  _DAT_00516710 = FUN_0043d713(local_138);
  FUN_004d9630(local_138,&DAT_006189a0);
  FUN_004d9640(local_138,s__FACE_GREEN_pic_004f6a08);
  _DAT_00516714 = FUN_0043d713(local_138);
  FUN_004d9630(local_138,&DAT_006189a0);
  FUN_004d9640(local_138,s__FACE_RED_pic_004f6a18);
  _DAT_00516718 = FUN_0043d713(local_138);
  FUN_004d9630(local_138,&DAT_006189a0);
  FUN_004d9640(local_138,s__FACE_WHITE_pic_004f6a28);
  _DAT_0051671c = FUN_0043d713(local_138);
  lplf = (LOGFONTA *)FUN_00472731(&DAT_004f6a38,0);
  DAT_00516704 = CreateFontIndirectA(lplf);
  DAT_005166e8 = 0x2f6f7f7;
  DAT_005166ec = 0x2565656;
  return local_30;
}


